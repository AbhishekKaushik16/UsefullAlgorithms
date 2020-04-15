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

const int MAX = 1e4;
vpi edges[MAX];
vi dis(MAX);
vector<bool> visited(MAX);
void init(){
	for(auto i = 0;i < MAX; ++i){
		dis[i] = 1e5;
        visited[i] = false;
	}
}
void dijkstra(){
    dis[0] = 0;
    multiset<pair<int,int>> q;
    q.insert({0,0});
    while(!q.empty()) {
        pair<int, int> p = *q.begin();
        q.erase(q.begin());

        int x = p.second;int wei = p.first;
        if(visited[x])
            continue;
        visited[x] = true;

        for(auto i = edges[x].begin();i != edges[x].end(); ++i){
            int e = i->first; int w = i->second;
            if(dis[e] > dis[x] + w){
                dis[e] = dis[x] + w;
                q.insert({dis[e], e});
            }
        }
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
    int N,M,u,v,w,i,j;
    cin>>N>>M;
    for(i=0;i<M;++i){
    	cin>>u>>v>>w;
    	--u;--v;
    	edges[u].push_back({v,w});
    }
    init();
    dijkstra();  
    for(i=1;i<N;i++){
        if(dis[i] == 1e5)
            cout<<(long long)1e9<<" ";
        else
            cout<<dis[i]<<" ";
    }  
    cout<<endl;
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: "<< 1.e * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL_DEFINE
    return 0;
}