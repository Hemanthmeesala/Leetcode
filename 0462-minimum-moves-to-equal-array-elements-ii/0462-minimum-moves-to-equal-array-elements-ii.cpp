class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        if(n == 1) return 0;

        int mid1 = nums[n/2];
        int ope1 = 0;

        for(int i=0;i<n;i++){
            ope1 += abs(mid1 - nums[i]);
        }

        // if(n % 2 == 1){
        //     int mid2 = nums[n/2 + 1];
        //     int ope2 = 0;
        //     for(int i=0;i<n;i++){
        //         ope2 += abs(mid2 - nums[i]);
        //     }
        //     ope1 = min(ope1,ope2);
        // }

        return ope1;
    }
};