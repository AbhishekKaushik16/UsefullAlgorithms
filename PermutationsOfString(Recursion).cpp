#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void permutations(char* a,int l,int r){
	int i;
	if(l==r)
		cout<<++cnt<<": "<<a<<endl;
	else
		for(i=l;i<=r ;i++){
			swap(a[i],a[l]);
			permutations(a,l+1,r);
			swap(a[i],a[l]);
		}		
}
int main(){
	char s[100];
	cin>>s;
	int n = strlen(s);
	permutations(s,0,n-1);
	//cout<<ans;
}
