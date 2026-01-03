/**
 * Problem: Search a 2D Matrix II (LeetCode 240)
 * Approach: Staircase Search (Start from Top-Right)
 * Time Complexity: O(M + N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();       // Number of Rows
        int n = matrix[0].size();    // Number of Columns
        
        // Start from Top-Right corner
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Target found
            }
            else if (matrix[row][col] < target) {
                // Current element is smaller than target, so move Down
                row++;
            }
            else {
                // Current element is larger than target, so move Left
                col--;
            }
        }
        
        return false; // Target not found
    }
};

// Driver Code for Testing
int main() {
    Solution sol;
    
    // Example Matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    int target = 5;
    
    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix!" << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }

    return 0;
}