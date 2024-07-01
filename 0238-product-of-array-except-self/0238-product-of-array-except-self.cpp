class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product, right_product;
        left_product.push_back(1);
        for(int i= 0; i<nums.size(); i++){
            left_product.push_back(left_product[i] * nums[i]);
        }
        int product = 1;
        for(int i= nums.size() - 1; i>0; i--){
            int initial = nums[i];
            nums[i] = left_product[i] * product;
            product = product * initial;
        }
        nums[0] = product;
        return nums;
    }
};