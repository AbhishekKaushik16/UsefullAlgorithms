#include<bits/stdc++.h>
using namespace std;
// A Linear diophantine equaton in two variable is of the form ax+by=c where a,b,c are integers
//if c=0 then x=0 and y=0 if c!=0 then there are infinitely many solution
//We find solution using Euclid Extended Theorem 
//To have a solution c%gcd(a,b)==0
// One Solution is x = x'*c/g  y = y'*c/g
int gcdExtended(int a,int b,int *x,int *y){
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int gcd = gcdExtended(b%a , a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
} 
int main(){
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	int g = gcdExtended(a,b,&x,&y);
	printf("x = %d , y = %d ,gcd = %d",x,y,g);
}
