# C++ Unity Pathfinding Demo

A custom C++ pathfinding library integrated into Unity via P/Invoke. Features dynamic obstacle toggling and live path recalculation using A* and Dijkstra algorithms.

![Pathfinding Demo](PathFinderVideoDemo.gif)

## Main Features
* **Native Interop:** Built a custom C++ dynamic link library (DLL) communicating  with C# via P/Invoke.
* **Performance:** Implemented efficient graph traversal (A* & Dijkstra) on flat grid buffers.
* **Interactivity:** Handled runtime state changes, allowing instant obstacle toggling and live path recalculation.

## Running the Project

1. Run the build script to compile the C++ backend:
   ```bash
   ./build.sh
