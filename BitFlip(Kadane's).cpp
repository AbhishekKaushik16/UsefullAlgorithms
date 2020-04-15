#include<bits/stdc++.h>
using namespace std;
#define fora(i,a,b) for(int i=a;i<b;i++)
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @coding_abhi
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
int maxZero(bool arr[],int n){
    int max_diff =0,orig_zero=0,curr_max=0;

    fora(i,0,n){
        if(arr[i]==0)
            orig_zero++;
        int val = (arr[i]==1)? 1 : -1;
        curr_max = max(val,curr_max+val);
        max_diff = max(curr_max,max_diff);

    }
    max_diff = max(0,max_diff);
    return (max_diff+orig_zero);
}
int main(int argc, const char** argv) {
    int n,i;
    cin>>n;
    bool arr[n];
    fora(i,0,n)   cin>>arr[i];
    int ans = 0;
    ans = maxZero(arr,n);
    cout<<ans;
    return 0;
}