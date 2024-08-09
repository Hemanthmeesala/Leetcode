class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        int prev1=0;
        int prev2=0;
        prev1=nums[0];
        prev2=max(nums[0],nums[1]);
        int curr=prev2;
       for(int i=2;i<n;i++){
       curr=max(nums[i]+prev1,prev2);
       prev1=prev2;
       prev2=curr;
       }
       return curr;
    }
};