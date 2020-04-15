/* Segment Trees Implementation of Sum and Updation Queries */
#include<bits/stdc++.h>
using namespace std;
void build(int arr[],int t[],int v,int tl,int tr){
    if(tl==tr)
        t[v] = arr[tl];
    else{
        int tm = (tl + tr)/2;
        build(arr,t,2*v,tl,tm);
        build(arr,t,2*v+1,tm+1,tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int sum(int t[],int v,int tl,int tr,int l,int r){
    if(l>r){
        return 0;
    }
    if(l==tl && r==tr)
        return t[v];

    int tm = (tl + tr)/2;
    return (sum(t,2*v,tl,tm,l,min(r,tm)) + sum(t,2*v+1,tm+1,tr,max(l,tm+1),r));
}

void update(int t[],int v,int tl,int tr,int pos,int new_val){
    if(tl==tr)
        t[v] = new_val;
    else{
        int tm = (tl + tr)/2;
        if(pos<=tm)
            update(t,2*v,tl,tm,pos,new_val);
        else
            update(t,2*v+1,tm+1,tr,pos,new_val);
        t[v] = t[2*v] + t[2*v+1];
    }
}
int main(int argc, const char** argv) {
    int n,i;
    //cout<<"Enter The Size of an Array\n";
    //cin>>n;
    int arr[5]={1,3,-2,8,-7};
    //cout<<"Enter the elements of an array\n";
    n = sizeof(arr)/sizeof(int);
    int t[4*n+1]={0};
    
    build(arr,t,1,0,n-1);
    
    cout<<sum(t,1,0,n-1,2,4)<<endl;
    update(t,1,0,n-1,2,3);
    cout<<sum(t,1,0,n-1,2,4);
    return 0;
}