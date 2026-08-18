#include <queue>
#include <vector>
#include <string>
#include "Node.h"
#include "Pathfinder.h"

Pathfinder::Pathfinder(std::vector<std::vector<Node>>& grid) : _grid(grid) {

}

std::vector<Node> Pathfinder::FindPath(Node startNode, std::string method) {
    if (method == "dijkstra") {
        DijkstraAlgorithm(startNode);
    } 
    else if (method == "aStar") {
        AStarAlgorithm(startNode);
    }
}

void Pathfinder::DijkstraAlgorithm(Node startNode) {
    
}

void Pathfinder::AStarAlgorithm(Node startNode) {

}