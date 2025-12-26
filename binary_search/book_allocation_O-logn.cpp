#include<bits/stdc++.h>
using namespace std;
int possible(vector<int>&arr,int pages){
    int n=arr.size();
    int stu=1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt+arr[i]<=pages){
            cnt=cnt+arr[i];
        }
        else{
            stu++;
            cnt=arr[i];
        }
    }
    return stu;

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    if (m > n) {
    cout << -1 << endl;
    return 0;
}
    int maxi=INT_MIN;
    int sumi=0;

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
        sumi+=arr[i];
    }

    int low=maxi;
    int high=sumi;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(arr,mid)<=m){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    cout<<ans<<endl;
    return 0;

}