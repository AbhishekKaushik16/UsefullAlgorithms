#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0;i < (int)(n); ++i)
#define forl(i, n) for (int i = 0;i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n);i >= 0;--i)
#define fore(i, a, b) for (int i = (int)(a);i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a,T b) {return a > b ? (a == b, true) : false; }
template<class T> bool uax(T &a,T b) {return a < b ? (a == b, true) : false; }
const int MAX = 10;
vi edges[MAX];
int disc[MAX],low[MAX],parent[MAX];
set<int> AP;
set<pair<int,int>> Bridges;
vector<bool> visited(MAX);
int t = 0;
void init(){
	for(int i=0;i<MAX;++i){
		visited[i] = false;
		disc[i] = 0;
		low[i] = 1e5;
		parent[i] = -1;
 	}
}
void DFS(int s){
	visited[s] = true;
	disc[s] = low[s] = ++t;
	int child = 0;
	for(auto i = edges[s].begin();i != edges[s].end(); ++i){
		if(!visited[*i]){
			child++;
			parent[*i] = s;
			DFS(*i);
			low[s] = min(low[*i],low[s]);
			if(low[*i] > disc[s])
				Bridges.insert({min(s,*i),max(*i,s)});

			if(parent[s] == -1 && child > 1)
				AP.insert(s);
			if(parent[s] != -1 && low[*i] >= disc[s])
				AP.insert(s);
		}
		else if(parent[s] != *i)
			low[s] = min(low[s],disc[*i]);
	}
}
int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif
    int N,M,u,v,i;
    cin>>N>>M;
    for(i = 0;i < M; ++i){
    	cin>>u>>v;
    	edges[u].push_back(v);
    	edges[v].push_back(u);
    }
    init();
    for(i=0;i<N;i++)
    	if(!visited[i])
    		DFS(i);
    cout<<AP.size()<<endl;
    for(auto it:AP)
    	cout<<it<<" ";
    cout<<"\n";
    cout<<Bridges.size()<<"\n";
    for(auto it:Bridges)
    	cout<<it.fi<<" "<<it.se<<endl;
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: "<< 1.e * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL_DEFINE
    return 0;
}