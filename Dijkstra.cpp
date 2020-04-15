#include<bits/stdc++.h>
using namespace std;
//Dijkstra using set
vector<vector<pair<int,int>>> edges;
set<pair<long long,int>> d;
vector<int> parent;
vector<long long> dist;
int main(int argc, char const *argv[]){
    int n,i,j,m,source,u,v,w;
    cin>>n>>m;
    edges.resize(n);
    source=0;
    for(i=0;i<m;i++){
        cin>>u>>v>>w;
        u--;
        v--;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    d.insert(make_pair(0,source));
    parent.assign(n,-1); 
    long long M = 1000000000;
	M *= M;
	dist.assign(n, M);
    dist[source]=0;
    while(!d.empty()){
        pair<long long ,int> v = *d.begin();
        d.erase(d.begin());

        for(int i = 0; i < edges[v.second].size(); i++){
            if(dist[edges[v.second][i].first] > v.first + edges[v.second][i].second){
                if(d.count(make_pair(dist[edges[v.second][i].first], edges[v.second][i].first)))
                    d.erase(make_pair(dist[edges[v.second][i].first], edges[v.second][i].first));
                				dist[edges[v.second][i].first] = v.first + edges[v.second][i].second;
				d.insert(make_pair(dist[edges[v.second][i].first], edges[v.second][i].first));
				parent[edges[v.second][i].first] = v.second;
            }
        }
    }

    if(dist[n-1]==M){
        cout<<"-1\n";
    }
    else{
        int t = n-1;
        vector<int> res;
        while(t!=0){
            res.push_back(t+1);
            t = parent[t];
        }
        res.push_back(1);
        reverse(res.begin(),res.end());
        for(auto it:res)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}