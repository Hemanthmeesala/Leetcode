class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // @alert: corner case
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            if (nums[low - 1] < nums[low] && nums[low] > nums[low + 1]) {
                return low;
            } else if (nums[high - 1] < nums[high] && nums[high] > nums[high + 1]) {
                return high;
            } else {
                low++;
                high--;
            }
        }
        return 0;
    }
};