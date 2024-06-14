class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum_of_n = n*(n+1)/2;
        long sum = 0;
        for(int i=0; i<n;i++){
            sum+=nums[i];
        }
        return sum_of_n-sum;
    }
};