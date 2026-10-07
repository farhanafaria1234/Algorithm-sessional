#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector <int> ranki;
bool sortbywt(const tuple<int,int,int>&a, const tuple<int,int,int>&b)
{
return get<2>(a)< get<2>(b);
}
int findRoot(int u)
{
    if(parent[u]==-1)
    return u;
    return parent[u]= findRoot(parent[u]);
}
void unionRoot(int u, int v)
{
if(ranki[u]>ranki[v])
parent[v]=u;
else if(ranki[v]>ranki[u])
parent[u]=v;
else{
    parent[u]=v;
    ranki[v]++;
}
}
int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges:"<<endl;
    cin>>v>>e;
    vector <tuple<int,int,int>> edges;
    cout<<"Enter edges :"<<endl;
    for(int i=0; i<e; i++)

    {
        int src, des,wt;
        cin>>src>>des>>wt;
        edges.push_back(make_tuple(src,des,wt));
    }
    sort(edges.begin(), edges.end(), sortbywt);
    parent.assign(v,-1);
    ranki.assign(v,0);
    vector<tuple<int, int, int>>mst;
    long long totalweight =0;
   for(const auto& edge: edges) {
    int src = get<0>(edge);
    int des = get<1>(edge);
    int wt = get<2>(edge);
    int rootsrc = findRoot(src);
    int rootdes = findRoot(des);

    if(rootsrc != rootdes) {
        unionRoot(rootsrc, rootdes);
        mst.push_back(edge);
        totalweight += wt;
    }
}


if((int)mst.size() == v-1) {
    cout << "Edges in the mst: " << endl;
    for(const auto& edge: mst) {
        cout << get<0>(edge) << " " << get<1>(edge) << " " << get<2>(edge) << endl;
    }
    cout << "total weight: " << totalweight << endl;
} else {
    cout << "The graph is disconnected; no mst" << endl;
}

            return 0;
        }
