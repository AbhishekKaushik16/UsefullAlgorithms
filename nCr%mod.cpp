#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll fac[100001]={-1};                //Precompute the values of factorial till 10^5
ll power(ll x, ll y, ll p) 
{ 
	ll res = 1;	 
	x = x % p;  

	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 

		y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
} 
ll modInverse(ll n, ll p) 
{ 
	return power(n, p-2, p);        // Calculate the modulo inverse
} 
ll nCrModPFermat(ll n, ll r, ll p) 
{ 
if (r==0) 
	return 1; 

	return (fac[n]* modInverse(fac[r], p) % p * 
			modInverse(fac[n-r], p) % p) % p; 
} 
int main(int argc, const char** argv) {
    fastio;
    fac[0] = 1;
    for (ll i=1 ; i<=100001; i++) 
		fac[i] = fac[i-1]*i%mod;
    ll n,r;
    cin>>n>>r;
    //Calculate nCr%mod using fermat little theorem 
    cout<<nCrModPFermat(n,r,mod);
    return 0;
}