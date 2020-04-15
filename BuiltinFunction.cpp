#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<__builtin_popcount(n)<<"\n";		// This function is used to count the number of one’s(set bits) in an integer.
	cout<<__builtin_parity(n)<<"\n";			//This function is used to check the parity of a number. This function returns true(1) if the number has odd parity else it returns false(0) for even parity.
	cout<<__builtin_clz(n)<<"\n";			//This function is used to count the leading zeros of the integer. Note : clz = count leading zero’s
	cout<<__builtin_ctz(n)<<"\n";			//This function is used to count the trailing zeros of the given integer. Note : ctz = count trailing zeros.
}
