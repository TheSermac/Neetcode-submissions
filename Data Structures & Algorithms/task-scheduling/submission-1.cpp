class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);

        //Count frequencies
        for (char c : tasks) {
            frequencies[c - 'A']++;
        }

        priority_queue<int> next;

        //Add frequencies to the priority queue
        for (int freq : frequencies) {
            if (freq > 0) {
                next.push(freq);
            }
        }

        // {frequency, cycle it comes back}
        queue<pair<int, int>> waiting;
        int cycles = 0;

        while (!next.empty() || !waiting.empty()) {
            // Push task waiting back in execution
            if (!waiting.empty() && waiting.front().second == cycles) {
                next.push(waiting.front().first);
                waiting.pop();
            }

            if (!next.empty()) {
                int task = next.top(); next.pop(); task--;
                if (task > 0) {
                    waiting.push({task, cycles + n + 1});
                }
            }

            cycles++;
        }

        return cycles;
    }
};