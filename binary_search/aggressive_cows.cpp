#include <bits/stdc++.h>
using namespace std;
bool can(vector<int>&arr,int k,int cows){
    int cnt=1;
    int last=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        if((arr[i]-last)>=k){
            cnt++;
            last=arr[i];
        }
        if(cnt>=cows){
            return true;
        }

    }
    return false;

}
int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cows;
    cin>>cows;

    sort(arr.begin(),arr.end());
    int low=0;
    int high=arr[n-1]-arr[0];
    int ans=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(can(arr,mid,cows)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;


    
}