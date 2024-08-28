class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;

        if (s.length() < total_len)
            return result;

        // Frequency map of the words in 'words'
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        // Check all possible starting points (0 to word_len - 1) to cover every
        // possibility
        for (int i = 0; i < word_len; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j <= s.length() - word_len; j += word_len) {
                string word = s.substr(j, word_len);

                if (word_count.find(word) != word_count.end()) {
                    seen[word]++;
                    count++;

                    // If the word appears more times than it should
                    while (seen[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }

                    // If all words are matched
                    if (count == num_words) {
                        result.push_back(left);

                        // Move the window right to try and find the next
                        // possible match
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }
                } else {
                    // Reset the window
                    seen.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }

        return result;
    }
};