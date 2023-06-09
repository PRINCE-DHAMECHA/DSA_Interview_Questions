//& Write a function to detect cycle in an undirected graph

//~ Input: n = 4, e = 4 , 0 1, 1 2, 2 3, 3 1
//~ Output: Yes

//& Explanation: The graph is represented as follows in adjacency list representation: 0->1 1->2 2->3 3->1 From the above representation, we can see that there exists a cycle: 1→2→3→1

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void addEdge(vector<vector<int>> &graph, vector<pair<int, int>> &allEdges, int u, int v)
{
    graph[u].push_back(v);
}

//~ Approach:
//* We just do DFS traversal if in the same traversal we visit the node again then we can say that given graph contains cycle

bool DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &rec, int i)
{
    int ans = false;
    visited[i] = true;
    rec[i] = true;
    for (auto i : graph[i])
    {
        //* If we encounter node again
        if (rec[i] || DFS(graph, visited, rec, i))
        {
            return true;
        }
    }
    //* Backtrack to use rec in next iteration
    rec[i] = false;
    return false;
}

bool isCycle(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false), rec(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            if (DFS(graph, visited, rec, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<vector<int>> graph(6);
    vector<pair<int, int>> allEdges;
    addEdge(graph, allEdges, 0, 1);
    addEdge(graph, allEdges, 0, 2);
    addEdge(graph, allEdges, 1, 3);
    addEdge(graph, allEdges, 3, 2);
    addEdge(graph, allEdges, 2, 1);
    // addEdge(graph, allEdges, 1, 0);
    // addEdge(graph, allEdges, 2, 3);
    addEdge(graph, allEdges, 3, 4);
    addEdge(graph, allEdges, 4, 5);
    cout << isCycle(graph) << endl;
    return 0;
}