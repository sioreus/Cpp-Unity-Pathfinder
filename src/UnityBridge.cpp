#include "Pathfinder.h"
#include <vector>
#include <string>

#if defined(_MSC_VER)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

// Global DLL variables
static std::vector<std::vector<Node>> g_Grid;
static Pathfinder* g_Pathfinder = nullptr;

extern "C" {
    // 3 functions, intiialize grid from unity, set node data, findpathnative
    EXPORT void InitGrid(int width, int height) {
        // .resize makes it larger and smaller according to our parameter as the vector starts at size 0 by default
        g_Grid.resize(height);
        for (int y = 0; y < height; y++) {
            g_Grid[y].resize(width);
            for (int x = 0; x < width; x++) {
                g_Grid[y][x].x = x;
                g_Grid[y][x].y = y;
                g_Grid[y][x].movementCost = 1.0f;
                g_Grid[y][x].walkable = true;
                g_Grid[y][x].parentX = -1;
                g_Grid[y][x].parentY = -1;
                g_Grid[y][x].visitedInSearch = 0;
            }
        }
        if (g_Pathfinder) {
            delete g_Pathfinder;
        }

        g_Pathfinder = new Pathfinder(g_Grid);
    }

    EXPORT void SetNodeData(int x, int y, float movementCost, bool isWalkable) {
        if (0 <= y && y < g_Grid.size() && 0 <= x && x < g_Grid[0].size()) {
            g_Grid[y][x].movementCost = movementCost;
            g_Grid[y][x].walkable = isWalkable;
        }
    }

    EXPORT int FindPathNative(int startX, int startY, int targetX, int targetY, const char* method, int* outPathX, int* outPathY, int maxPathSize) {
        if (!g_Pathfinder) {
            return 0;
        }
        // Use {} so it forces zero intialization
        Node startNode = {};
        startNode.x = startX;
        startNode.y = startY;

        Node targetNode = {};
        targetNode.x = targetX;
        targetNode.y = targetY;

        std::string methodName = "dijkstra";

        if (method != nullptr) {
            methodName = method;
        }

        std::vector<Node> path = g_Pathfinder->FindPath(startNode, targetNode, methodName);

        if (path.size() <= 0) {
            return 0;
        }

        // Copy the coordinates into the output array provided by Unity C#
        for (int i = 0; i < path.size(); i++) {
            if (i >= maxPathSize) {
                return maxPathSize;
            }
            outPathX[i] = path[i].x;
            outPathY[i] = path[i].y;
        }

        return static_cast<int>(path.size());
    }

}