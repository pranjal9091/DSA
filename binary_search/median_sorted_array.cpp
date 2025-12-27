#include <iostream>
#include <vector>
#include <algorithm> // max, min ke liye
#include <climits>   // INT_MIN, INT_MAX ke liye
#include <iomanip>   // setprecision ke liye (Ye missing tha)

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while(low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if(l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    int m;
    cin >> m;
    vector<int> nums1(m);
    for(int i = 0; i < m; i++) cin >> nums1[i];

    int n;
    cin >> n;
    vector<int> nums2(n);
    for(int i = 0; i < n; i++) cin >> nums2[i];

    Solution sol;
    cout << fixed << setprecision(5) << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}