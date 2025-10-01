class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles; 
        int empties = numBottles;
        
        while (empties >= numExchange) {
            int newFull = empties / numExchange;  
            drank += newFull;
            empties = (empties % numExchange) + newFull;
        }
        
        return drank;
        
    }
};