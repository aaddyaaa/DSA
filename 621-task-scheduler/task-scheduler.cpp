class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        int max_freq = *max_element(freq.begin(), freq.end());

        int count = 0;
        for (int f : freq) {
            if (f == max_freq) count++;
        }

        int part_count = max_freq - 1;
        int part_length = n - (count - 1);
        int empty_slots = part_count * part_length;
        int available_tasks = tasks.size() - max_freq * count;
        int idles = max(0, empty_slots - available_tasks);

        return tasks.size() + idles;
    }
};
