class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);

        for (char c : tasks) {
            frequencies[c - 'A']++;
        }

        priority_queue<int> next;

        for (int freq : frequencies) {
            if (freq > 0) {
                next.push(freq);
            }
        }

        // {frecuencia restante, ciclo en el que vuelve}
        queue<pair<int, int>> waiting;

        int cycles = 0;

        while (!next.empty() || !waiting.empty()) {

            // Una tarea cuyo cooldown ha terminado
            // vuelve a estar disponible.
            if (!waiting.empty() &&
                waiting.front().second == cycles) {

                next.push(waiting.front().first);
                waiting.pop();
            }

            if (!next.empty()) {
                int task = next.top();
                next.pop();

                task--;

                if (task > 0) {
                    // Si ejecutamos en el ciclo 'cycles',
                    // puede volver en cycles + n + 1.
                    waiting.push({task, cycles + n + 1});
                }
            }

            cycles++;
        }

        return cycles;
    }
};