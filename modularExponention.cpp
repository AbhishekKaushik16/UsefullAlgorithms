#include<bits/stdc++.h>
using namespace std;
int modularExponention(int a,int b,int p){
    int ans = 1;
    while(b>0){
        if(b&1)
            ans = (ans*a)%p;
        b=b>>1;
        a = (a*a)%p;
    }
    return ans;
}
int main(int argc, const char** argv) {
    cout<<modularExponention(2,5,13);
    return 0;
}