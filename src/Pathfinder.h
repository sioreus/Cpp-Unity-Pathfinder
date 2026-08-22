#pragma once
#include <vector>
#include <string>
#include <csdint>
#include "Node.h"

class Pathfinder {
    public:
        Pathfinder(std::vector<std::vector<Node>>& grid);
        std::vector<Node> FindPath(Node startNode, Node targetNode, std::string method = "dijkstra");
        
    private:
        std::vector<std::vector<Node>>& _grid;
        uint32_t _currentSearch = 0;
        std::vector<Node> RunPathFinding(Node startNode, Node targetNode, bool useAStar);
        float GetAStarHeuristic(const Node& a, const Node& b);
        float GetDijikstraHeuristic(const Node&a, const Node& b);
};