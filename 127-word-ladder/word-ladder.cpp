class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
    
    if (wordSet.find(endWord) == wordSet.end())
        return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        for (int i = 0; i < word.size(); ++i) {
            char originalChar = word[i];

            for (char c = 'a'; c <= 'z'; ++c) {
                word[i] = c;
                if (word == endWord)
                    return level + 1;
                if (wordSet.find(word) != wordSet.end()) {
                    q.push({word, level + 1});
                    wordSet.erase(word);
                }
            }

            word[i] = originalChar;
        }
    }

    return 0;
        
    }
};