#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
struct Edge{
    int w = INF;
    int to = -1;
    bool operator<(Edge const& other) const{
        return w < other.w;
    }
};
int n;
vector<vector<Edge>> edges;
void prim(){
    int total_weight=0;
    set<Edge> q;
    vector<Edge> min_edges(n);
    vector<int> parent(n,-1);
    min_edges[0].w = 0;
    q.insert({0,0});
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(q.empty()){
            cout<<"NO MST!\n";
            exit(0);
        }
        int v = q.begin()->to;
        visited[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());
        if(min_edges[v].to != -1)
            parent[min_edges[v].to] = v;
        for(Edge e: edges[v]){
            if(!visited[e.to] && e.w < min_edges[v].w){
                q.erase({min_edges[e.to].w,e.to});
                min_edges[e.to] = {e.w,v};
                q.insert({e.w,e.to});
            }

        }
    }
    cout<<total_weight<<endl;
}
int main(int argc, const char** argv) {
    int m,i,u,v,w;
    cin>>n>>m;
    edges.resize(n);
    for(i=0;i<m;i++){
        cin>>u>>v>>w;
        edges[u].push_back({w,v});
    }
    prim();
    return 0;
}