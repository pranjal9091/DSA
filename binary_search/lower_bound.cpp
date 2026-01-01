#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    int lb;
    cin>>lb;
    
    int ans=n;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<lb){
            low=mid+1;
        }
   else{
    ans=mid;
    high=mid-1;

   }
    }
    cout<<ans<<endl;}
