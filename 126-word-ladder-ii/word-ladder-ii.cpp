class Solution {
public:
    bool isOneLetterDiff(const string &a, const string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i] && ++diff > 1)
            return false;
    return diff == 1;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) return {};

    unordered_map<string, vector<string>> parents;  // word -> all possible parents
    unordered_map<string, int> levels;              // word -> shortest level
    queue<string> q;

    q.push(beginWord);
    levels[beginWord] = 0;

    while (!q.empty()) {
        string word = q.front(); q.pop();
        int level = levels[word];
        string temp = word;

        for (int i = 0; i < temp.size(); ++i) {
            char original = temp[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                temp[i] = c;
                if (dict.find(temp) == dict.end()) continue;

                if (!levels.count(temp)) {
                    levels[temp] = level + 1;
                    q.push(temp);
                    parents[temp].push_back(word);
                } else if (levels[temp] == level + 1) {
                    parents[temp].push_back(word);
                }
            }
            temp[i] = original;
        }
    }

    vector<vector<string>> results;
    vector<string> path;

    function<void(string)> backtrack = [&](string word) {
        path.push_back(word);
        if (word == beginWord) {
            vector<string> revPath = path;
            reverse(revPath.begin(), revPath.end());
            results.push_back(revPath);
        } else {
            for (string p : parents[word]) {
                backtrack(p);
            }
        }
        path.pop_back();
    };

    if (levels.find(endWord) != levels.end())
        backtrack(endWord);

    return results;
        
    }
};