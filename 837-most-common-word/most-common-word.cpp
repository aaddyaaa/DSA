class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map <string, int> freq;
        unordered_set <string> bannedwords(banned.begin(),banned.end());
        for(char &c: paragraph){
            if(isalpha(c)){
                c = tolower(c);
            }
            else c =' ';
        }
        stringstream ss(paragraph);
        string word;
        while (ss >> word){
            if (bannedwords.find(word)==bannedwords.end()){
                freq[word]++;
            }
        }
        string mostcommon;
        int max_freq = 0;
        for (const auto& [w, count] : freq){
            if (count > max_freq){
                mostcommon = w;
                max_freq = count;
            }
        }
        return mostcommon;
    }
};