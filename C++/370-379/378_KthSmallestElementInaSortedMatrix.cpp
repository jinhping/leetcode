class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < matrix.size(); i++) {
                vector<int> row = matrix[i];
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};