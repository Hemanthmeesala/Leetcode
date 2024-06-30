class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int i=0;
        int n=num.length();
        if(k==n)return "0";
        for(char c:num){
            while(ans.size()>0 && k>0 && int(ans.back())>int(c)){
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while(k){
            ans.pop_back();
            k--;
        }
        int ans_len=ans.length();
        while(i<ans_len-1 && ans[i]=='0')i++;
        return ans.substr(i,ans_len-i);
    }
};