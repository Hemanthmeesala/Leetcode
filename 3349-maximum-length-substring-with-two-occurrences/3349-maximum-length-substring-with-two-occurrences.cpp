class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans = 0;
        
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        
        while (r < n) {
            
            mp[s[r]]++;

            while (l < r && mp[s[r]] > 2) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};