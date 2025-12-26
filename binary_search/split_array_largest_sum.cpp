#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possible(vector<int>& nums, long long p) {
        int n = nums.size();
        long long cnt = 0;
        int t = 1;
        for(int i = 0; i < n; i++) {
            if(cnt + nums[i] <= p) {
                cnt = cnt + nums[i];
            }
            else {
                t++;
                cnt = nums[i];
            }
        }
        return t;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long high = 0;
        long long low = INT_MIN;
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            low = max(low, (long long)nums[i]);
            high += nums[i];
        }
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(possible(nums, mid) <= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution sol;
    cout << sol.splitArray(nums, k) << endl;

    return 0;
}