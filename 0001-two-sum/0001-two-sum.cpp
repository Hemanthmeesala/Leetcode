class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m; //hashmap
    vector<int> result;  
    for(int i=0;i<nums.size();i++){ 
        int second_num=target-nums[i];
        if(m.find(second_num)!=m.end()){
            result.push_back(i); //first index
            result.push_back(m[second_num]);  //second index
            break;
         }  
         m[nums[i]]=i; //insert key value pair in hashmap
       }
       return result;
    }
};