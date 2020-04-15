#include<bits/stdc++.h>
using namespace std;
void computeLPS(string pat,int m,int *lps){
	int len = 0; 
  
    lps[0] = 0; 
  
    int i = 1; 
    while (i < m) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else { 
            if (len != 0) { 
                len = lps[len - 1]; 
  
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 

}
void KMPSearch(string s,string pat){
	int n = s.length();
	int m = pat.length();
	int lps[m];
	computeLPS(pat,m,lps);
	int i=0,j=0;
	while(i<n){
		if(pat[j]==s[i]){
			++i;
			++j;
		}
		if(j==m){
			cout<<"Pattern is found at index "<<i-m<<endl;
			j = lps[j-1];
		}
		else if(i<n && pat[j]!=s[i]){
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
}
int main(){
	string s,pat;
	cin>>s>>pat;
	KMPSearch(s,pat);
	return 0;
}
	
