class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0}; // Frequency array for all ASCII characters

        // Step 1: Fill hash[] with character counts from t
        for (char c : t) hash[c]++;

        int left = 0;                // Left pointer of window
        int minLen = INT_MAX;       // Minimum length of a valid window found
        int start = 0;              // Start index of the minimum window
        int count = 0;              // Count of characters matched from t
        int m = t.length();         // Total characters we need to match

        // Step 2: Expand the window with the right pointer
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            hash[c]--;              // We take this character into the window

            // If it's a needed character (still ≥ 0 after decrement), we matched one
            if (hash[c] >= 0) {
                count++;            // We matched one character from t
            }

            // Step 3: When all characters from t are matched
            while (count == m) {
                // Update result if the current window is smaller
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Try to shrink the window from the left
                hash[s[left]]++;   // Remove s[left] from the window

                // If this character was part of t and its count is now > 0,
                // that means we are missing one required character
                if (hash[s[left]] > 0) {
                    count--;        // Lost a matched character
                }

                left++;             // Move left pointer to shrink window
            }
        }

        // Step 4: Return the result substring
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
