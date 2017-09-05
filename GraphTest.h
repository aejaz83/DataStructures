#pragma once
#include "Graph.h"
#include <iostream>
namespace graph
{

    bool testGraphBFS()
    {
        // Create a graph given in the above diagram
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        std::cout << "Following is Breadth First Traversal "
                  << "(starting from vertex 2) \n";
        g.bfs(2);
        std::cout << "Following is Depth First Traversal "
                  << "(starting from vertex 2) \n";

        // g.dfs(2);
        return true;
    }
    bool testGraphDFS()
    {
        // Create a graph given in the above diagram
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        std::cout << "Following is Depth First Traversal (starting from vertex 2) \n";
        g.dfs(2);

        return 0;

    }
}