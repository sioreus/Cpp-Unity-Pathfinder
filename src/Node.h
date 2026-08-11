#pragma once

struct Node {
    int x, y;
    float gCost;
    bool walkable;
    int parentX, parentY;
};