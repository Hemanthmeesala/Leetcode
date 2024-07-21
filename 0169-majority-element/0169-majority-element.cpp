class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c= nums.size();
        return  nums[c/2];
    }
};