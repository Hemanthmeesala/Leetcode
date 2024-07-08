class Solution {
public:
    string minWindow(string s, string t) {
        // count of char in t
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        
        int left = 0;
        int right = 0;
        
        // # of chars in t that must be in s
        int counter = t.size();
        
        int minStart = 0;
        int minLength = INT_MAX;
        
        while (right < s.size()) {
            // if char in s exists in t, decrease
            if (m[s[right]] > 0) {
                counter--;
            }
            // if char doesn't exist in t, will be -'ve
            m[s[right]]--;
            // move right to find valid window
            right++;
            
            // when window found, move left to find smaller
            while (counter == 0) {
                if (right - left < minLength) {
                    minStart = left;
                    minLength = right - left;
                }
                
                m[s[left]]++;
                // when char exists in t, increase
                if (m[s[left]] > 0) {
                    counter++;
                }
                left++;
            }
        }
        
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }
};