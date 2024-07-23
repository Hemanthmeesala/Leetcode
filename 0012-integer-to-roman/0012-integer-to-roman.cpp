class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, 
            {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, 
            {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
        };

        string result = "";
        for (int i = romanMap.size() - 1; i >= 0; --i) {
            while (num >= romanMap[i].first) {
                num -= romanMap[i].first;
                result += romanMap[i].second;
            }
        }
        return result;
    }
};