
class Solution {
public:
    bool check(vector<int>& nums,int mid,int threshold){
        int div=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid!=0){
                div+=nums[i]/mid + 1;
            }
            else{
                div+=nums[i]/mid;
            }
        }
        return div<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};