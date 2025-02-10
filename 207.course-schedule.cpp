// @leet start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int num_taken = 0;
        unordered_set<int> taken;
        unordered_map<int, unordered_set<int>> needs;
        unordered_map<int, vector<int>> unlocks;

        for (int i = 0; i < numCourses; i++) {
            needs[i] = unordered_set<int>();
            unlocks[i] = vector<int>();
        }

        for (const vector<int> vecs : prerequisites) {
            unlocks[vecs[1]].push_back(vecs[0]);
            needs[vecs[0]].insert(vecs[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!needs[i].empty()) {
                continue;
            }

            if (taken.find(i) != taken.end()) {
                continue;
            }

            num_taken++;
            taken.insert(i);

            if (num_taken == numCourses)  {
                return true;
            }

            queue<int> todo;
            for (int c : unlocks[i]) {
                todo.push(c);
                if (needs[c].find(i) != needs[c].end()) {
                    needs[c].erase(i);
                }
            }

            while(!todo.empty()) {
                int curr = todo.front();
                todo.pop();

                if (taken.find(curr) != taken.end()) {
                    continue;
                }

                if (needs[curr].empty()) {
                    num_taken++;
                    taken.insert(curr);
                    for (int c : unlocks[curr]) {
                        todo.push(c);
                        if (needs[c].find(curr) != needs[c].end()) {
                            needs[c].erase(curr);
                        }
                    }
                }

                if (num_taken == numCourses)  {
                    return true;
                }
            }
        }

        return num_taken == numCourses;
    }
};
// @leet end
