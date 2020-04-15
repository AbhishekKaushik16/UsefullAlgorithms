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
bool visited[MAX][MAX];
int arr[MAX][MAX];
void init(){
	for(int i=0;i<MAX;++i)
		for(int j=0;j<MAX;++j)
			visited[i][j] =false;
}
bool DFS(int i,int j,int n,int m){
	if(i >=n || j>=m || j<0 || i<0)
		return false;

	if(i == n-1 && j == m-1)
		return true;
	if(visited[i][j] == true)
		return false;
	visited[i][j] = true;
	if(arr[i+1][j] && i+1<n)
    	if (DFS(i+1, j, n, m) == true)
        	return true;
    if(arr[i-1][j] && i-1>=0)
    	if (DFS(i-1, j, n, m) == true)
        	return true;
    if(arr[i][j+1] && j+1<m)
    	if (DFS(i, j+1, n, m) == true)
        	return true;
    if(arr[i][j-1] && j-1>=0)
    	if (DFS(i, j-1, n, m) == true)
        	return true;
    return false;
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
    int N,M,i,j;
    cin>>N>>M;
    for(i=0;i<N;++i)
    	for(j=0;j<M;++j)
    		cin>>arr[i][j];
    init();
    if(DFS(0,0,N,M))
    	cout<<"Yes\n";
    else
    	cout<<"No\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: "<< 1.e * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL_DEFINE
    return 0;
}