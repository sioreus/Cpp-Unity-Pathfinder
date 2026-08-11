#pragma once
#include <string>
#include "Node.h"

class Pathfinder {
    public:
        void FindPath(Node startNode, std::string method = "dijkstra");
    private:
        void DijkstraAlgorithm(Node startNode);
        void AStarAlgorithm(Node startNode);
};