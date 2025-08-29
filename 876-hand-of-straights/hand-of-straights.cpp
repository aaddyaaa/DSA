class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int h = hand.size();
        if ((h%groupSize)!=0) return false;
        map<int, int> count; 
        for (int card : hand) {
            count[card]++;
        }
        while (!count.empty()) {
            int start = count.begin()->first; 
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (count.find(card) == count.end()) return false;
                count[card]--;
                if (count[card] == 0) {
                    count.erase(card);
                }
            }
        }

        return true;

        
    }
};