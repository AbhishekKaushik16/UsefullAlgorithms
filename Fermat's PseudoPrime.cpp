#include<bits/stdc++.h>
using namespace std;
// if 1) A>1
//    2) N is composite number
//    3) N divides a^N-1 - 1
bool isComposite(int N){
	int i;
	for(i=2;i<sqrt(N);i++)
		if(N%i==0)
			return true;
	return false;
}
int calculate(int a,int N,int mod){
	int res = 1;
	while(N){
		if(N&1)
			res = (res*a)%mod;
		N = N>>1;
		a = (a*a)%mod;
	}
	return res;
}
bool check(int a,int N){
	if(a>1 && isComposite(N) && calculate(a,N-1,N)==1)
		return true;
	return false;
}
int main(){
	int N,a;
	cin>>N>>a;
	cout<<check(a,N);
	return 0;
}
