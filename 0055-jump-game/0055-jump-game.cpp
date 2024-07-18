class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPosition = 0;
        int currentPosition = 0;

        while (currentPosition <= maxPosition && maxPosition < nums.size() - 1)
        {
            maxPosition = max(maxPosition, currentPosition + nums[currentPosition]);
            currentPosition += 1;
        }
        
        return maxPosition < nums.size() - 1 ? false : true;
    }
};