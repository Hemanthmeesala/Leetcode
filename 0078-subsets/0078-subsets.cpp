class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        int sub= 1<<nums.size();
        for(int i=0;i<=sub-1;i++){
            vector<int> output;
            for(int j=0;j<nums.size();j++){
                if(i & (1<<j))
                    output.push_back(nums[j]);
            }
            ans.push_back(output);
        }
        return ans;
    }
};