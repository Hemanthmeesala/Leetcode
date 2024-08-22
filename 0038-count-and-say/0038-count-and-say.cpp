class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for(int N=2; N<=n; N++){
            string temp = "";
            int cnt = 0;
            char ch = ans[0];
            for(int i=0; i<ans.size(); i++){
                if(ans[i]==ch)
                    cnt++;
                else{
                    temp += to_string(cnt) + ch;
                    ch = ans[i];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + ch;
            ans = temp;
        }

        return ans;
    }
};