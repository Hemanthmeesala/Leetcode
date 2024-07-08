// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
        
//     }
// };
class Solution {
public:
    int f(vector<int>& nums, int k) {
        if(k < 0)    return 0;
        int n = nums.size();
        int l=0, r=0, cnt = 0, sum = 0;
        while(r<n)
        {
            sum += nums[r]%2; //Add the elements while moving right
            while(sum > k) // Check if sum greater than goal
            {
                sum -= nums[l]%2; // if Yes , remove ele from left
                l++;
            }
            cnt += (r-l+1); //Number of subarrays possible when u               are standing at particulr idx = size of the window
            r++; // Move r
        }
        return cnt;
    }
     int numberOfSubarrays(vector<int>& nums, int k) {
        
        return (f(nums,k)-f(nums,k-1));
    }
};