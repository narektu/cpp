#include "../../include/backtracking/graph_coloring.h"
#include <iostream>
#include <vector>

bool isSafe(int v, const std::vector<std::vector<int>>& graph, const std::vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && c == color[i]) return false;
    }
    return true;
}

bool graphColoringUtil(const std::vector<std::vector<int>>& graph, int m, std::vector<int>& color, int v) {
    if (v == graph.size()) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) return true;
            color[v] = 0;
        }
    }
    return false;
}

void run_graph_coloring() {
    std::cout << "Running Algorithm: Graph Coloring" << std::endl;
    std::vector<std::vector<int>> graph = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    int m = 3;
    std::vector<int> color(4, 0);
    if (graphColoringUtil(graph, m, color, 0)) {
        for (int c : color) std::cout << c << " ";
        std::cout << std::endl;
    } else {
        std::cout << "No solution" << std::endl;
    }
}
