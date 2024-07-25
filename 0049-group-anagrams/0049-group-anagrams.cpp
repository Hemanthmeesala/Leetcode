class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> m;
        
        for(int i = 0; i < n; i++){
            string temp = s[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(s[i]);
        }
        
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};