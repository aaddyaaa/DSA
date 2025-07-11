class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST;  // s -> t
        unordered_map<char, char> mapTS;  // t -> s (to prevent multiple s-chars → same t-char)

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check if s[i] was seen before and maps to something different
            if (mapST.count(c1) && mapST[c1] != c2) return false;

            // Check if t[i] was already mapped by some other character in s
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;

            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
        
    }
};