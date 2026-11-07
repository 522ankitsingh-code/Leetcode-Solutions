
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using P = pair<long long, int>;

        priority_queue<P, vector<P>, greater<P>> available;
        priority_queue<P, vector<P>, greater<P>> busy;

        for (int i = 0; i < servers.size(); i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while (!busy.empty() && busy.top().first <= time) {
                auto [freeTime, idx] = busy.top();
                busy.pop();
                available.push({servers[idx], idx});
            }

            if (available.empty()) {
                time = busy.top().first;

                while (!busy.empty() && busy.top().first <= time) {
                    auto [freeTime, idx] = busy.top();
                    busy.pop();
                    available.push({servers[idx], idx});
                }
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans.push_back(idx);
            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};
