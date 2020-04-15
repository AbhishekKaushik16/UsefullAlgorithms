#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
using namespace std;
#define ll long long
ll block;
struct Query 
{ 
    ll L, R; 
}; 
bool compare(Query x, Query y) { 
    if (x.L/block != y.L/block) 
        return x.L/block < y.L/block; 
    
    return x.R < y.R; 
}
void queryResults(ll a[], ll n, Query q[], ll m) 
{ 
    block = (ll)sqrt(n); 
  
    sort(q, q + m, compare); 
  
    ll currL = 0, currR = 0; 
    ll currSum = 0; 
  
    for (ll i=0; i<m; i++) 
    { 
        ll L = q[i].L, R = q[i].R; 
  
        while (currL < L) 
        { 
            currSum -= a[currL]; 
            currL++; 
        } 
  
        while (currL > L) 
        { 
            currSum += a[currL-1]; 
            currL--; 
        } 
        while (currR <= R) 
        { 
            currSum += a[currR]; 
            currR++; 
        } 
  
        while (currR > R+1) 
        { 
            currSum -= a[currR-1]; 
            currR--; 
        } 
  
        cout << "Sum of [" << L << ", " << R 
             << "] is "  << currSum << endl; 
    } 
} 
int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif

	ll n,i,q,l,r;
	cin>>n;
	ll a[n];
	for(i=0;i<n;++i)
		cin>>a[i];
	cin>>q;
	i = 0;
	Query Q[q];
	while(i<q) {
	    cin>>l>>r;
	    Q[i++] = {l,r};
	}
	queryResults(a,n,Q,q);

    
#ifndef LOCAL_DEFINE
    cerr << "Time elapsed: "<< 1e1 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL_DEFINE
    return 0;
}