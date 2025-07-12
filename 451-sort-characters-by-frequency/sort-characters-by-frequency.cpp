class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s){
            freq[c]++;
        }
        
        vector <pair<int,char>> vecc;
        for (auto& [ch, count] : freq) {
            vecc.push_back({count, ch});
        }
        sort(vecc.begin(), vecc.end(), [](auto& a, auto& b){
            return a.first>b.first;
        });
        stringstream result;
        for (auto& [count, ch] : vecc){
            for (int i = 0; i < count; ++i) {
            result << ch;
        } 
        }
        return result.str();
        
    }
};