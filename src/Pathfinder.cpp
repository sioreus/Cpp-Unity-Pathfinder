#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
#include "Node.h"
#include "Pathfinder.h"
#include <iostream>

Pathfinder::Pathfinder(std::vector<std::vector<Node>>& grid) : _grid(grid) {

}

std::vector<Node> Pathfinder::FindPath(Node startNode, Node targetNode, std::string method) {
    if (method == "dijkstra") {
        return RunPathFinding(startNode, targetNode, false);
    } 
    else {
        return RunPathFinding(startNode, targetNode, true);
    }
}

float Pathfinder::GetDijikstraHeuristic(const Node& a, const Node& b) {
    return 0.0f;
}

float Pathfinder::GetAStarHeuristic(const Node& a, const Node& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->GetFCost() > b->GetFCost();
    }
};

std::vector<Node> Pathfinder::RunPathFinding(Node startNode, Node targetNode, bool useAStar) {
    
    _currentSearch++;

    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> openSet;

    Node* current = &_grid[startNode.y][startNode.x];
    Node* goal = &_grid[targetNode.y][targetNode.x];

    current->visitedInSearch = _currentSearch;
    openSet.push(current);

    while (!openSet.empty()) {
        current = openSet.top();

        openSet.pop();
        
        if (current->x == goal->x && current->y == goal->y) {
            std::cout << "[DEBUG] Goal reached!" << std::endl;
            break;
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for (int i = 0; i < 4; i++) {
            int nextX = current->x + dx[i];
            int nextY = current->y + dy[i];

            if (nextY >= 0 && nextY < _grid.size() && nextX >= 0 && nextX < _grid[0].size()) {
                Node* neighbor = &_grid[nextY][nextX];
                if (neighbor->walkable) {
                    
                    if (neighbor->visitedInSearch != _currentSearch) {
                        neighbor->visitedInSearch = _currentSearch;
                        neighbor->parentX = current->x;
                        neighbor->parentY = current->y;
                        if (useAStar) {
                            neighbor->hCost = GetAStarHeuristic(*neighbor, *goal);
                        } 
                        else {
                            neighbor->hCost = GetDijikstraHeuristic(*neighbor, *goal);
                        }
                        neighbor->gCost = current->gCost + neighbor->movementCost;
                        openSet.push(neighbor);
                    } 
                    else if (current->gCost + neighbor->movementCost < neighbor->gCost) {
                        neighbor->parentX = current->x;
                        neighbor->parentY = current->y;
                        neighbor->gCost = current->gCost + neighbor->movementCost;
                    }

                }
            }
            
        }
    }

    if (current->x != goal->x || current->y != goal->y) {
        return {};
    }
    std::vector<Node> finalPath;

    while (current != nullptr && (current->x != -1 && current->y != -1) && 
    (current->parentY >= 0 && current->parentY < _grid.size() && current->parentX >= 0 && current->parentX < _grid[0].size())) {
        finalPath.push_back(*current);
        current = &_grid[current->parentY][current->parentX];
    }
    if (current != nullptr) {
        finalPath.push_back(*current);
    }
    

    std::vector<Node> reversedFinalPath(finalPath.rbegin(), finalPath.rend());
    return reversedFinalPath;
    
}