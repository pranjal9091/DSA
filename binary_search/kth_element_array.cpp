#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>nums1(n);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    vector<int>nums2(m);
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    int p=n+m;
    vector<int>nums(p);
    int i=0;
    int j=0;
    int ind=0;
    int ans=-1;
    while(i<p && j<p){
        if(nums1[i]<nums2[j]){
            if(ind==k){
                ans=nums1[i];
            }
            i++;
            ind++;
        }
        else{
            if(ind==k){
                ans=nums[j];
            }
            j++;
            ind++;
        }
    }
    while(i<p){
        if(ind==k){
                ans=nums1[i];
            }
            i++;
            ind++;
    }
    while(j<p){
        if(ind==k){
                ans=nums[j];
            }
            j++;
            ind++;
    }
    

}
