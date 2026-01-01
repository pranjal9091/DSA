#include<bits/stdc++.h>
using namespace std;
int lb(vector<int> &arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<x){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr (n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int cnt=0;
    int ind=-1;
    for(int i=0;i<n;i++){
        int cnt1=m-lb(arr[i],m,1);   
        if(cnt1>cnt){
            cnt=cnt1;
            ind=i;
        }
    }
    cout<<ind<<endl;
}