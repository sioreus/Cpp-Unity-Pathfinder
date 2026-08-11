#include <queue>
#include <vector>
#include <string>
#include "Node.h"
#include "Pathfinder.h"


std::vector<Node> Pathfinder::FindPath(std::vector<std::vector<Node>>& grid, Node startNode, std::string method) {
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