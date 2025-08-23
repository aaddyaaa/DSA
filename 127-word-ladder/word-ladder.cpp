class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> wordset (wordList.begin(), wordList.end());
        if (wordset.find(endWord)==wordset.end()) return 0;
        queue <pair<string, int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string w = q.front().first;
            int level = q.front(). second;
            q.pop();
            for (int i =0 ;i<w.size();i++)  {
                char oc = w[i];

                for (char c = 'a'; c<= 'z';c++){
                    w[i]= c;
                    if (w==endWord) return level + 1;
                    if (wordset.find(w)!=wordset.end()){
                        q.push ({w, level+ 1});
                        wordset.erase(w);
                    }

                }
                w[i] = oc;
            }    
        }
        return 0;
    }
};