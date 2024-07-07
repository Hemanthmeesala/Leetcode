class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int maxSum = 0;
        int currSum = 0;

        for (int i = 0; i < k; i++) {

            currSum += cardPoints[i];
        }
        int start = 0; // for maintaining size k
        for (int i = k-1; i >=0; i--) {
              maxSum = max(currSum, maxSum);
                currSum -= cardPoints[i];
                currSum += cardPoints[cardPoints.size()-k+i];
        }
        maxSum = max(currSum, maxSum);
        return maxSum;
    }
};