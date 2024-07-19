class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> hash;

        for(int i=0; i<arr.size(); i++) {
            if(arr[i] >= 0) {
                sum += arr[i];
            } else {
                sum += k + (arr[i] % k);
            }

            hash[sum % k] ++;

            if(sum % k != 0) res += hash[sum % k] - 1;
            else res += hash[sum % k];
            sum = sum % k;
        }
        return res;
    }
};