class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1; // s → t
        unordered_map<char, char> mp2; // t → s

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Check s → t mapping
            if (mp1.count(c1)) {
                if (mp1[c1] != c2) return false;
            } else {
                mp1[c1] = c2;
            }

            // Check t → s mapping (to ensure one-to-one)
            if (mp2.count(c2)) {
                if (mp2[c2] != c1) return false;
            } else {
                mp2[c2] = c1;
            }
        }

        return true;
    }
};