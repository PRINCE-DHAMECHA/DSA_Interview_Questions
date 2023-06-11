//& Question: Given a directed graph find out whether there's a route between two nodes or not.

//^ Solution:

//* We can do simple BFS or DFS traversal from one of and see whether we encounter other or not.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)
typedef vector<int> vi;

void addEdge(vector<vi> &graph, int u, int v)
{
    graph[u].push_back(v);
}

bool BFS(vector<vi> &graph, int node1, int node2)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(node1);
    visited[node1] = true;
    vi traversal;
    while (!q.empty())
    {
        int v = q.front();
        // cout << v << " ";
        traversal.push_back(v);
        q.pop();
        for (auto i : graph[v])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return visited[node2];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 7;
    vector<vi> graph(v, vi(v, 0));
    // addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    cout << BFS(graph, 0, 2) << endl;
    return 0;
}
