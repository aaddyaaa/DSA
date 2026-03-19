class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0; // check starting valid point 
        int total = 0; // whether completeing circle is valid or not
        int start = 0;
        for (int i = 0;i<n;i++){
            int diff = gas[i]-cost[i];
            tank+= diff;
            total+= diff;
        if (tank < 0){
            start = i+1;
            tank = 0;
        }
        }
        return (total >=0) ? start : -1;
    }
};