class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index=0;
        for(int i=0;i<t.length();i++){
            if(index<s.length() && s[index] == t[i]){
                index++;
            }
        }
        if(index == s.length()){
            return true;
        }
        return false;
    }
};