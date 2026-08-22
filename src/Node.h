#pragma once
#include <csdint>

struct Node {
    int x, y;
    float gCost = 0;
    float hCost = 0;
    bool walkable = true;
    int parentX = -1, parentY = -1;
    uint32_t visitedInSearch = 0;

    float GetFCost() const {
        return gCost + hCost;
    }
};