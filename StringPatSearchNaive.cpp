#include<bits/stdc++.h>
using namespace std;
void search(string s,string pat){
	int n = s.length();
	int m = pat.length();
	for(int i=0,j=0;i<n-m;i++){
		if(s[i] == pat[0]){
			int t = i;
			while(j<m){
				++j;
				++t;
				if(s[t] != pat[j])
					break;
			}
			if(j==m)
				cout<<"Pattern is found at "<<i<<endl;
			j=0;
		}
	}
}
	
int main(){
	string s,pat;
	cin>>s>>pat;
	search(s,pat);
}

