#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>

namespace graph
{
    class Graph
    {
        int num_verticies;
        std::list<int>* adjacency_list;
        void dfsUtil(int root, bool visited[]);

    public:
        Graph(int vertices) : num_verticies(vertices)
        {
            adjacency_list = new std::list<int>[vertices];
        }
        void addEdge(int src, int dest)
        {
            adjacency_list[src].push_back(dest);
        }
        void bfs(int root);
        void dfs(int root);
        void RoutePresent(int start, int end);

    };

    void Graph::bfs(int root)
    {
        std::list<int> que;
        que.push_back(root);
        bool* visited = new bool[num_verticies];

        for(int i = 0; i < num_verticies; i++)
        {
            visited[i] = false;
        }

        visited[root] = true;

        while(!que.empty())
        {
            int node = que.front();
            std::cout << "Visit: " << node << std::endl;
            que.pop_front();
            std::list<int> current = adjacency_list[node];

            for(auto& it = begin(current); (it != end(current)) && (visited[*it] == false); it++)
            {
                visited[*it] = true;
                que.push_back(*it);
            }
        }

    }
    void Graph::dfs(int root)
    {

        bool* visited = new bool[num_verticies];

        for(int i = 0; i < num_verticies; i++)
        {
            visited[i] = false;
        }

        dfsUtil(root, visited);

    }
    void Graph::dfsUtil(int root, bool visited[])
    {
        //if (visited[root] == false) {
        visited[root] = true;
        std::cout << "visit: " << root << " ";
        std::list<int> current = adjacency_list[root];

        for(auto& it = begin(current); (it != end(current)) ; it++)
            if(visited[*it] == false)
            {
                dfsUtil(*it, visited);
            }

        //}

    }
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
    ///////// problems /////////////////////////////////////////////////////////////

    //4.1 Route Between Nodes: Given a directed graph find if route is present between two nodes
    void Graph::RoutePresent(int start, int end)
    {
        std::list<int> que;
        bool isRoutePresent = false;
        que.push_back(start);
        bool* visited = new bool[num_verticies];

        for(int i = 0; i < num_verticies; i++)
        {
            visited[i] = false;
        }

        visited[start] = true;

        while(!que.empty())
        {
            int node = que.front();

            //std::cout << "Visit: " << node << std::endl;
            if(node == end)
            {
                isRoutePresent = true;
                break;
            }

            que.pop_front();
            std::list<int> current = adjacency_list[node];

            for(auto& it = begin(current); (it != current.end()) && (visited[*it] == false); it++)
            {
                visited[*it] = true;
                que.push_back(*it);
            }
        }

    }
}
