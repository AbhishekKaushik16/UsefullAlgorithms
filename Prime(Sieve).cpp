#include<bits/stdc++.h>
using ll = long long;
using namespace std;
void seiveOfErastosthenes(bool prime[],ll n){
	for(ll i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(ll j = 2*i;j<=n;j+=i)
				prime[j]=false;
		}
	}
}
int main(){
	ll n;
	cin>>n;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));

}
