class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        for (char c : tasks) {
            hash[c]++;
        }

        // Max heap to store the frequency of tasks (priority queue stores frequency in reverse order)
        priority_queue<int> taskQueue;
        for (auto& entry : hash) {
            taskQueue.push(entry.second);
        }

        int cnt = 0;

        while (!taskQueue.empty()) {
            vector<int> temp;
            int cycleTime = 0;

            // Process up to n + 1 tasks in this cycle
            for (int i = 0; i <= n; ++i) {
                if (!taskQueue.empty()) {
                    int top = taskQueue.top();
                    taskQueue.pop();
                    if (top > 1) {
                        temp.push_back(top - 1);
                    }
                }
                cycleTime++;
                if (taskQueue.empty() && temp.empty()) {
                    break;
                }
            }

            // Push back the tasks with updated frequencies after the cycle
            for (int t : temp) {
                taskQueue.push(t);
            }

            // If the task queue is not empty, we need to account for waiting time (idle time)
            cnt += taskQueue.empty() ? cycleTime : n + 1;
        }

        return cnt;
    }
};
