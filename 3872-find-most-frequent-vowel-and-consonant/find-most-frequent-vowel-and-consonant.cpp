class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    string vowels = "aeiou";
    int maxVowel = 0, maxCons = 0;

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (freq[i] > 0) {
            if (vowels.find(c) != string::npos) {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxCons = max(maxCons, freq[i]);
            }
        }
    }

    return maxVowel + maxCons;
    }
};