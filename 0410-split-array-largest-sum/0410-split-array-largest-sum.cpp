class Solution {
public:
int check(vector<int>& nums,int mid,int k){
    int sum=0 ,c=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            return 0;
        }
        sum=sum+nums[i];
        if(sum>mid){
            sum=nums[i];
            c++;
        }
    }
    if(c<=k)return 1;
    return 0;
}
    int splitArray(vector<int>& nums, int k) {
        long long  high=0;
        for(int i=0;i<nums.size();i++){
               high+=nums[i];
        }
        long long  low=0;   
        long long  ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(nums,mid,k)){
                ans=mid;
                 high=mid-1;
               
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};