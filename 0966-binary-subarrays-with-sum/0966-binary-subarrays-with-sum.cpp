class Solution {
public:
    int f(vector<int>& nums, int goal) {
        if(goal < 0)    return 0;
        int n = nums.size();
        int l=0, r=0, cnt = 0, sum = 0;
        while(r<n)
        {
            sum += nums[r]; //Add the elements while moving right
            while(sum > goal) // Check if sum greater than goal
            {
                sum -= nums[l]; // if Yes , remove ele from left
                l++;
            }
            cnt += (r-l+1); //Number of subarrays possible when u               are standing at particulr idx = size of the window
            r++; // Move r
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return (f(nums, goal)-f(nums,goal-1));
    }
};