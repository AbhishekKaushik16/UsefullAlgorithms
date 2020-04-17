#include<bits/stdc++.h>

using namespace std;
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define rep(i, a, b) for (int i = (int)(a);i <= (int)(b); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef double ld;

template<class T> bool uin(T &a,T b) {return a > b ? (a == b, true) : false; }
template<class T> bool uax(T &a,T b) {return a < b ? (a == b, true) : false; }
const int MAXN = 1e5;
int x[MAXN][26];
int nxt = 1;
void init(){
	memset(x,-1,sizeof(x));
	nxt = 1;
}
void build(string s){
	int i = 0,v = 0;
	while(i<s.size()) {
	    if(x[v][s[i]] == -1)
	    	v = x[v][s[i++]] = nxt++;
	    else
	    	v = x[v][s[i++]];
	}
}

bool search(string s){
	int i = 0,v = 0;
	while(i<s.size()) {
	    if(x[v][s[i]] == -1)
	    	return false;
	    else
	    	v = x[v][s[i++]];
	}
	return true;
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
	init();
	int n,i;
	cin>>n;
	vector<string> str(n);
	for(i=0;i<n;++i){
		cin>>str[i];
		build(str[i]);
	}
	string s;
	cin>>s;
	if(search(s))
		cout<<"YES\n";
	else
		cout<<"NO\n";
    
#ifndef LOCAL_DEFINE
    cerr << "Time elapsed: "<< 1e1 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL_DEFINE
    return 0;
}