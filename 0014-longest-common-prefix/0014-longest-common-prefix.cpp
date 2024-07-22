class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        int minLen = min(strs[0].size(), strs.back().size());
        
        int i = 0;
        string ans = "";
        while (i < minLen && strs[0][i] == strs.back()[i]) {
            ans += strs[0][i];
            i++;
        }
        
        return ans;
    }
};