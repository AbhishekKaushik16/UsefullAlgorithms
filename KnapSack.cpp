#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,W,i,j;
	cin>>N>>W;
	int weight,value;
	int dp[N+1][W+1]={0};
	for(i=0;i<=W;++i)
		dp[0][i] = 0;
	for(i=1;i<=N;++i){
		cin>>weight>>value;
		for(j=0;j<=W;++j){
			if(weight > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight]+value);
		}
	}
	cout<<dp[N][W]<<endl;
}
