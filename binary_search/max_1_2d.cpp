#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr (n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int maxi=-1;
    int ind=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                cnt++;
                
            }
        }
        if(cnt>maxi){
                    maxi=cnt;
                    ind=i;
                }
        
    }
    cout<<ind<<endl;
}