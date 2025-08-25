class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set <int> seen ;
        int r = 0;
        int l = 0; 
        int minLen = INT_MAX;
        int n = cards.size();
        for (r=0; r<n ; r++){
            while(seen.count(cards[r])){
                minLen = min(minLen,r-l+1);
                seen.erase(cards[l]);
                l++;
            }
            seen.insert(cards[r]);
        }
        return (minLen == INT_MAX ? -1 : minLen);;
    }
};