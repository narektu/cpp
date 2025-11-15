#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <optional>

class Graph
{
public:
   struct Node; // forward decloration

   struct Edge
   {
      std::weak_ptr<Node> destination; // link of close city
      int weight;
   };

   struct Node
   {
      std::string name;
      std::vector<Edge> edges; // road list from this city

      explicit Node(std::string n) : name(std::move(n)) {} // protection of implicit type
   };

   struct PathResult
   {
      int total_distance;
      std::vector<std::string> path; // list of roads in order
   };

   void add_node(const std::string &name); // new city in graph

   void add_edge(const std::string &src, const std::string &dest, int weight); // add road between cities

   [[nodiscard]] std::optional<PathResult> shortest_path(const std::string &start_node, const std::string &end_node) const;

private:
   std::unordered_map<std::string, std::shared_ptr<Node>> nodes_; // repo of all nodes
};

#endif