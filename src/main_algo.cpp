#include <iostream>
#include <string>
#include <limits>
#include "../projects/algorithms/include/graph.h"

void print_menu()
{
   std::cout << "\nCity Route Planner\n";
   std::cout << "1. Add City\n";
   std::cout << "2. Add Road (Edge)\n";
   std::cout << "3. Find Shortest Path\n";
   std::cout << "4. Exit\n";
   std::cout << "Select: ";
}

std::string get_input(const std::string &prompt)
{
   std::cout << prompt;
   std::string input;
   std::cin >> input;
   return input;
}

int main()
{
   Graph city_map;

   city_map.add_node("Hamburg");
   city_map.add_node("Berlin");
   city_map.add_node("Munich");
   city_map.add_edge("Hamburg", "Berlin", 5500);
   city_map.add_edge("Berlin", "Munich", 9500);
   city_map.add_edge("Hamburg", "Munich", 14000);

   bool running = true;
   while (running)
   {
      print_menu();
      int choice;

      if (!(std::cin >> choice))
      {
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         continue;
      }

      try
      {
         switch (choice)
         {
         case 1:
         {
            std::string city = get_input("City name: ");
            city_map.add_node(city);
            std::cout << "City added.\n";
            break;
         }
         case 2:
         {
            std::string src = get_input("From: ");
            std::string dest = get_input("To: ");
            int dist;
            std::cout << "Distance: ";
            std::cin >> dist;
            city_map.add_edge(src, dest, dist);
            std::cout << "Road constructed.\n";
            break;
         }
         case 3:
         {
            std::string start = get_input("Start City: ");
            std::string end = get_input("Destination: ");

            auto result = city_map.shortest_path(start, end);

            if (result.has_value())
            {
               std::cout << "\n--- Route Found! ---\n";
               std::cout << "Total Distance: " << result->total_distance << " km\n";
               std::cout << "Path: ";
               for (size_t i = 0; i < result->path.size(); ++i)
               {
                  std::cout << result->path[i];
                  if (i < result->path.size() - 1)
                     std::cout << " -> ";
               }
               std::cout << "\n";
            }
            else
            {
               std::cout << "\nNo route exists between these cities.\n";
            }
            break;
         }
         case 4:
            running = false;
            break;
         default:
            std::cout << "Invalid option.\n";
         }
      }
      catch (const std::exception &e)
      {
         std::cout << "Error: " << e.what() << "\n";
      }
   }
   return 0;
}