#include <iostream>
#include <cassert>
#include <vector>
#include "../../projects/algorithms/include/graph.h"

#define RUN_TEST(test_func)                         \
   std::cout << "Running " << #test_func << "... "; \
   test_func();                                     \
   std::cout << "PASSED\n";

void test_simple_dijkstra()
{
   Graph g;
   g.add_node("A");
   g.add_node("B");
   g.add_node("C");

   g.add_edge("A", "C", 100);
   g.add_edge("A", "B", 10);
   g.add_edge("B", "C", 10);

   auto result = g.shortest_path("A", "C");

   assert(result.has_value());
   assert(result->total_distance == 20);
   assert(result->path.size() == 3);
   assert(result->path[0] == "A");
   assert(result->path[1] == "B");
   assert(result->path[2] == "C");
}

void test_dissconnected_graph()
{
   Graph g;
   g.add_node("cityOne");
   g.add_node("cityTwo");

   auto result = g.shortest_path("cityOne", "cityTwo");

   assert(!result.has_value());
}

void test_complex_path()
{
   Graph g;
   g.add_node("A");
   g.add_node("B");
   g.add_node("C");
   g.add_node("D");
   g.add_node("E");

   g.add_edge("A", "B", 2);
   g.add_edge("A", "C", 5); // exp
   g.add_edge("A", "E", 1); // ch

   g.add_edge("B", "C", 2); // path A->B->C = 4 (better than direct A->C)

   g.add_edge("E", "C", 1); // path A->E->C = 2 (best!)

   g.add_edge("C", "D", 3);

   auto result = g.shortest_path("A", "D");

   assert(result.has_value());
   assert(result->total_distance == 5);

   std::vector<std::string> expected = {"A", "E", "C", "D"};
   assert(result->path == expected);
}

void test_exceptions()
{
   Graph g;
   g.add_node("A");
   g.add_node("B");

   try
   {
      g.add_edge("A", "B", -5);
      assert(false); // should be exception
   }
   catch (const std::invalid_argument &)
   {
      // ok
   }

   try
   {
      g.add_edge("A", "GhostCity", 10);
      assert(false);
   }
   catch (const std::invalid_argument &)
   {
      // ok
   }
}

int main()
{
   std::cout << "starting graph algorithms test\n";

   RUN_TEST(test_simple_dijkstra);
   RUN_TEST(test_dissconnected_graph);
   RUN_TEST(test_complex_path);
   RUN_TEST(test_exceptions);

   std::cout << "graph test passed\n";
   return 0;
}