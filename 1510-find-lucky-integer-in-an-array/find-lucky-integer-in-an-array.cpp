class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        vector <int> vec;
        unordered_map <int,int> mpp;
        for (int i =0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto it : mpp){
            if(it.second == it.first){
                vec.push_back(it.first);
            }
        }
        if (vec.empty()) return -1;
        int aa = *max_element(vec.begin(),vec.end());
        return aa;
    }
};