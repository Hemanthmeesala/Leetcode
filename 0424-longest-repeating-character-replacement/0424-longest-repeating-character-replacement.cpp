class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;

        // Two pointers for the sliding window: left and right
        int left = 0;
        int right = 0;
        
        int result = 0;

        // Iterate through the string with the 'right' pointer
        while (right < s.size()) {
            count[s[right] - 'A']++; // Increment the frequency of the current character in the window

            maxCount = max(maxCount, count[s[right] - 'A']);

            // Check if the current window size minus the maximum frequency character is greater than k
            if (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--; // If yes, shrink the window from the left
                left++;
            }
            result = max(result, right - left + 1);
            right++; // Move the 'right' pointer to the right
        }
        
        return result;
    }
};