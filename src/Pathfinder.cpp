#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
#include "Node.h"
#include "Pathfinder.h"

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
    openSet.push(current);

    while (!openSet.empty()) {
        Node* current = openSet.top();

        openSet.pop();

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for (int i = 0; i < 4; i++) {
            int nextX = current->x + dx[i];
            int nextY = current->y + dy[i];

            if (nextX >= 0 && nextX < _grid.size() ** nextY >= 0 && nextY < _grid[0].size()) {

            }
            
        }

    }
    
}