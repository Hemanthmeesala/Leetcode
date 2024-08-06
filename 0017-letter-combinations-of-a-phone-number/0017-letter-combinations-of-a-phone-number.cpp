class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        int totalCombinations = 1;

        // Calculate the total number of combinations
        for (char digit : digits) {
            totalCombinations *= phone[digit].size();
        }

        result.resize(totalCombinations, "");

        int repeat = totalCombinations;

        for (int i = 0; i < digits.size(); ++i) {
            char digit = digits[i];
            const string& letters = phone[digit];
            int lettersSize = letters.size();
            repeat /= lettersSize;

            int count = 0;
            for (int j = 0; j < totalCombinations; ++j) {
                result[j] += letters[(j / repeat) % lettersSize];
            }
        }

        return result;
    }
};