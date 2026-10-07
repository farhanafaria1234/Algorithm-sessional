#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int findRoot(int u)
{
    if(parent[u] == -1)
        return u;

    return findRoot(parent[u]);
}

void unionSet(int u, int v)
{
    parent[v] = u;
}

bool isCycle(vector<pair<int,int>> edges)
{
    for(auto edge : edges)
    {
        int src = edge.first;
        int des = edge.second;

        int srcRoot = findRoot(src);
        int desRoot = findRoot(des);

        if(srcRoot == desRoot)
            return true;

        unionSet(srcRoot, desRoot);
    }

    return false;
}

int main()
{
    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<pair<int,int>> edges;

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        edges.push_back({a, b});
    }

    parent.resize(v, -1);

    if(isCycle(edges))
        cout << "Cycle exists" << endl;
    else
        cout << "No cycle found" << endl;

    return 0;
}
