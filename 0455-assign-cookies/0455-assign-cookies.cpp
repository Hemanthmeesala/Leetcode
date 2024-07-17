class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), i = 0, ans = 0;
        int m = s.size(), j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i<n && j<m){
            if(g[i] <= s[j]) {
                ans ++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};