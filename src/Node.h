#pragma once
#include <cstdint>

struct Node {
    int x, y;
    float gCost = 0;
    float hCost = 0;
    float movementCost = 1.0f;
    bool walkable = true;
    int parentX = -1, parentY = -1;
    uint32_t visitedInSearch = 0;

    float GetFCost() const {
        return gCost + hCost;
    }
};