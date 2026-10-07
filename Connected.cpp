#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>visited;
void dfs(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    for(int u: adj[v])
    {
        if(!visited[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter number of vertices and edge: ";
    cin>> n>>m;
    adj.resize(n);
    visited.assign(n,false);
    cout<<"Enter edges: "<<endl;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int components =0;
    cout<<"Connected components: "<<endl;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            components++;
            cout<<"Components: "<<components<<" ";
            dfs(i);
            cout<<endl;
        }
    }
    cout<<"Total components: "<<components<<endl;
    return 0;
}
