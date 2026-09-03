using UnityEngine;
using System.Runtime.InteropServices;


public class PathfinderManager : MonoBehaviour
{
    const string DLLName = "Pathfinder";

    [DllImport(DLLName)]
    private static extern void InitGrid(int width, int height);

    [DllImport(DLLName)]
    private static extern void SetNodeData(int x, int y, float movementCost, bool isWalkable);

    [DllImport(DLLName)]
    private static extern int FindPathNative(int startX, int startY, int targetX, int targetY, string method, int[] outPathX, int[] outPathY, int maxPathSize);

    private GameObject[,] tileGrid;


    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Debug.Log("Testing C++ Dll connection");

        int gridWidth = 10;
        int gridHeight = 10;

        InitGrid(gridWidth, gridHeight);

        tileGrid = new GameObject[gridWidth, gridHeight];
        for (int x = 0; x < gridWidth; x++)
        {
            for (int y = 0; y < gridHeight; y++)
            {
                GameObject tile = GameObject.CreatePrimitive(PrimitiveType.Cube);
                tile.transform.position = new Vector3(x, 0, y);
                tile.transform.localScale = new Vector3(0.9f, 0.1f, 0.9f);
                tileGrid[x, y] = tile;
            }
        }

        // Set a test wall
        SetNodeData(5, 3, 3.0f, true);
        RecalculatePath(0, 0, 7, 7);

    }
    private void ModifyTile(int x, int y)
    {
        
        Renderer rend = tileGrid[x, y].GetComponent<Renderer>();
        if (rend.material.color == Color.red)
        {
            SetNodeData(x, y, 0f, true);
            rend.material.color = Color.white;
        }
        else
        {
            SetNodeData(x, y, 0f, false);
            rend.material.color = Color.red;
        }

            RecalculatePath(0, 0, 7, 7);
    }

    private void RecalculatePath(int startX, int startY, int targetX, int targetY)
    {
        for (int x = 0; x < tileGrid.GetLength(0); x++)
        {
            for (int y = 0; y < tileGrid.GetLength(1); y++)
            {
                Renderer rend = tileGrid[x, y].GetComponent<Renderer>();
                if (rend.material.color != Color.red)
                {
                    rend.material.color = Color.white;
                }
            }
        }
        int[] outPathX = new int[120];
        int[] outPathY = new int[120];
        int pathLength = FindPathNative(0, 0, 7, 7, "aStar", outPathX, outPathY, 50);

        // Color our path
        for (int i = 0; i < pathLength; i++)
        {
            Renderer rend = tileGrid[outPathX[i], outPathY[i]].GetComponent<Renderer>();
            rend.material.color = Color.green;
        }
    }
    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Vector2 mousePos = UnityEngine.InputSystem.Mouse.current.position.ReadValue();
            Ray ray =  Camera.main.ScreenPointToRay(mousePos);
            if (Physics.Raycast(ray, out RaycastHit hit))
            {
                Vector3 pos = hit.collider.transform.position;
                int clickedX = Mathf.RoundToInt(pos.x);
                int clickedY = Mathf.RoundToInt(pos.z);
                ModifyTile(clickedX, clickedY);
            }
        }
    }
}
