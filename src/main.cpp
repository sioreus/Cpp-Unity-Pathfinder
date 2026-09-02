#include <iostream>
#include <vector>
#include "Node.h"
#include "Pathfinder.h"

int main() {
    std::cout << "Starting Standalone Pathfinder Test..." << std::endl;

    int width = 10;
    int height = 10;

    // 1. Build a dummy grid
    std::vector<std::vector<Node>> grid(height, std::vector<Node>(width));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x].x = x;
            grid[y][x].y = y;
            grid[y][x].movementCost = 1.0f;
            grid[y][x].walkable = true;
        }
    }

    // 2. Instantiate Pathfinder
    Pathfinder pathfinder(grid);

    // 3. Set up start and target nodes
    Node start = grid[0][0];
    Node target = grid[5][5];

    // 4. Run FindPath
    std::vector<Node> path = pathfinder.FindPath(start, target, "aStar");

    std::cout << "Path found! Steps: " << path.size() << std::endl;
    for (const auto& node : path) {
        std::cout << "(" << node.x << ", " << node.y << ") -> ";
    }
    std::cout << "END" << std::endl;

    return 0;
}