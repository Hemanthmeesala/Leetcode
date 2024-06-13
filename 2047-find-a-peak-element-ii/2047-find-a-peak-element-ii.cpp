class Solution {
    public: vector < int > findPeakGrid(vector < vector < int >> & mat) {
        int n = mat.size(), m = mat[0].size();

        // low = 1st column, high = last column
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) >> 1;

            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int currElement = mat[maxRow][mid];
            int leftElement = (mid == 0) ? -1 : mat[maxRow][mid - 1];
            int rightElement = (mid == m - 1) ? -1 : mat[maxRow][mid + 1];

            if (currElement > leftElement && currElement > rightElement) {
                return { maxRow, mid };
            }

            if (currElement < leftElement) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};