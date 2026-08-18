#pragma once
#include <vector>
#include <string>
#include "Node.h"

class Pathfinder {
    public:
        PathFinder(std::vector<std::vector<Node>>& grid);
        void FindPath(Node startNode, std::string method = "dijkstra");
    private:
        std::vector<std::vector<Node>>& _grid;
        void DijkstraAlgorithm(Node startNode);
        void AStarAlgorithm(Node startNode);
};