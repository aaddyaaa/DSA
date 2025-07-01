class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        
        for (int i = 0; i < sentences.size(); ++i) {
            int spaceCount = 0;
            for (int j = 0; j < sentences[i].size(); ++j) {
                if (sentences[i][j] == ' ') {
                    spaceCount++;
                }
            }
            int wordCount = spaceCount + 1;
            if (wordCount > maxWords) {
                maxWords = wordCount;
            }
        }
        
        return maxWords;
    }
};
