#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX 1000000
#define M 3
ll n;
string s;
ll BIT[MAX+3];
ll modExp(ll x,ll n)
{
ll result=1;
while(n>0)
{
if(n % 2 ==1)
result=(result * x)%M;
x=(x*x)%M;
n=n/2;
}
return result;
}
ll modInv(ll A)// when M is PRIME
{
return modExp(A,M-2);
}
void update(ll x,ll v){
for(;x<=n;x+=x&-x)
  BIT[x]=(BIT[x]+v)%M;
}
ll query_sum(ll x)
{
ll s=0;
for(;x>0;x-=x&-x)
s=(s+BIT[x])%M;
return s;
}
int main(int argc, char const *argv[]) {
  cin>>n;
  cin>>s;
  for (ll i = 0; i < n; i++) {
    ll k = s[i] - '0';
    update(i+1,k*modExp(2,n-i-1));
  }
  ll q,x,y,t;
  cin>>q;
  while(q--) {
      cin>>t;
      if(t == 0){
        cin>>x>>y;
        cout<<((query_sum(y+1)%M-query_sum(x)%M+M)%M*(modInv(modExp(2,n-y-1)))%M)%M<<endl;
      }
      else if(t == 1){
        cin >> x;
        if(s[x]=='0')
          update(x+1,modExp(2,n-x-1));
          s[x]=1;
      }
  }
  return 0;
}
