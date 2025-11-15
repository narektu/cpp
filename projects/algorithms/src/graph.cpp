#include "../include/graph.h"
#include <queue>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <unordered_set>

void Graph::add_node(const std::string &name)
{
   if (nodes_.find(name) == nodes_.end())
   {
      nodes_.emplace(name, std::make_shared<Node>(name));
   }
}

void Graph::add_edge(const std::string &src, const std::string &dest, int weight)
{
   if (weight < 0)
   {
      throw std::invalid_argument("Edge weight can not be negative");
   }

   auto src_it = nodes_.find(src);
   auto dest_it = nodes_.find(dest);

   if (src_it == nodes_.end() || dest_it == nodes_.end())
   {
      throw std::invalid_argument("Source or destination node does not exist");
   }

   src_it->second->edges.push_back({dest_it->second, weight});
   dest_it->second->edges.push_back({src_it->second, weight});
}

std::optional<Graph::PathResult> Graph::shortest_path(const std::string &start_node, const std::string &end_node) const
{
   if (nodes_.find(start_node) == nodes_.end() || nodes_.find(end_node) == nodes_.end())
   {
      return std::nullopt;
   }

   std::unordered_map<std::string, int> distances;
   std::unordered_map<std::string, std::string> previous;

   for (const auto &pair : nodes_)
   {
      distances[pair.first] = std::numeric_limits<int>::max();
   }

   distances[start_node] = 0;

   using QueueElement = std::pair<int, std::string>; // priority queue for Dijkstra, saving pair distance and node_name
   std::priority_queue<QueueElement, std::vector<QueueElement>, std::greater<QueueElement>> pq;

   pq.push({0, start_node});

   while (!pq.empty())
   {
      auto [current_dist, current_name] = pq.top();
      pq.pop();

      if (current_dist > distances[current_name])
      {
         continue;
      }

      if (current_name == end_node)
      {
         break;
      }

      auto current_node_ptr = nodes_.at(current_name);

      for (const auto &edge : current_node_ptr->edges)
      {
         if (auto neighbor_ptr = edge.destination.lock())
         {
            int new_dist = current_dist + edge.weight;

            if (new_dist < distances[neighbor_ptr->name])
            {
               distances[neighbor_ptr->name] = new_dist;
               previous[neighbor_ptr->name] = current_name;
               pq.push({new_dist, neighbor_ptr->name});
            }
         }
      }
   }

   if (distances[end_node] == std::numeric_limits<int>::max())
   {
      return std::nullopt;
   }

   std::vector<std::string> path;
   for (std::string at = end_node; at != "";)
   {
      path.push_back(at);
      if (at == start_node)
         break;

      auto it = previous.find(at);
      if (it == previous.end())
         break;
      at = it->second;
   }

   std::reverse(path.begin(), path.end());

   return PathResult{distances[end_node], path};
}