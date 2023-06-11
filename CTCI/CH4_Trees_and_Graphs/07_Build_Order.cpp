//& Question: You are given a list of projects and a list of dependencies. All of the project's dependencies must be built before the project is. find a build order that will alow the project to be built. If there is no valid order, return an error.

//& I/P:-
//* projects:a,b,c,d,e,f
//* Dependencies: (a,d), (f,b), (b,d), (f,a), (d,c)
//* Output: f, e, a, b, d, c

//^ Solution:

//~ Brain Storming
//* We can build that node which has no incoming edges i.e. Not dependent on anyone
//* Then we can delete it's outgoing edges and do the same

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)
typedef vector<int> vi;

void addEdge(vector<vi> &graph, int u, int v) //* In case of weight
{
    graph[u][v] = 1;
}

//* That's topological sort from the scratch!!
//* Also works for disconnected graph as well as can detect cycles!!
vi makeOrder(vector<vi> graph)
{
    //* Topological order
    vi path;
    while (1)
    {

        int flag = -1;
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph.size(); j++)
            {
                //* Note that we're checking for vertical line
                if (graph[j][i] == 1 || graph[j][i] == -1)
                {
                    flag = -2;
                    break;
                }
            }
            //* If there's node with no incoming edges
            if (flag != -2)
            {
                flag = i;
                break;
            }
            //* Check for next columns
            flag = -1;
        }
        //* If no columns satisfies
        if (flag == -1)
        {
            //* If there is any edge left then there's error
            for (auto i : graph)
            {
                for (auto j : i)
                {
                    if (j == 1)
                    {
                        vi err = {-1};
                        return err;
                    }
                }
            }
            return path;
        }
        //* If no incoming edge node exists
        if (flag != -2)
        {
            //* Flag contains node index0
            path.push_back(flag);
            for (int i = 0; i < graph.size(); i++)
            {
                //* make it's outgoing as 0
                graph[flag][i] = 0;
                //* make it's incoming as visited
                graph[i][flag] = -1;
            }
        }
        //* For next iteration
        flag = -1;
    }
    return path;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 5;
    vector<vi> graph(v, vi(v, 0));
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    // addEdge(graph, 3, 4);
    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    vi path = makeOrder(graph);
    if (path[0] == -1)
    {
        cout << "Cycle Found!!" << endl;
        return 0;
    }
    cout << "Build Order: " << endl;
    for (auto i : path)
    {
        cout << i << " ";
    }

    return 0;
}
