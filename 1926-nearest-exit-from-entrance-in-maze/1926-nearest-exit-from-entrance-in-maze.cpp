struct position {
    int x;
    int y;
    int distance;
};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<position> todo;

        int right = maze[0].size() - 1;        
        int bottom = maze.size() - 1;
        int shortest = INT_MAX;

        position pos1 = {entrance[1] + 1, entrance[0], 1};        
        position pos2 = {entrance[1] - 1, entrance[0], 1};
        position pos3 = {entrance[1], entrance[0] + 1, 1};
        position pos4 = {entrance[1], entrance[0] - 1, 1};

        todo.push(pos1);
        todo.push(pos2);
        todo.push(pos3);
        todo.push(pos4);      

        maze[entrance[0]][entrance[1]] = '+';  

        while (!todo.empty()) {
            position curr = todo.front();
            todo.pop();

            if (curr.y <= bottom && curr.y >= 0 && curr.x <= right && curr.x >= 0 && maze[curr.y][curr.x] == '.') {
                maze[curr.y][curr.x] = '+';
                if (curr.y == 0) {
                    shortest = min(shortest, curr.distance);
                } else if (curr.y == bottom) {
                    shortest = min(shortest, curr.distance);
                } else if (curr.x == 0) {
                    shortest = min(shortest, curr.distance);
                } else if (curr.x == right) {
                    shortest = min(shortest, curr.distance);
                } else {
                    position left = {curr.x - 1, curr.y, curr.distance + 1};
                    position right = {curr.x + 1, curr.y, curr.distance + 1};
                    position up = {curr.x, curr.y + 1, curr.distance + 1};
                    position down = {curr.x, curr.y - 1, curr.distance + 1};
                    todo.push(left);
                    todo.push(right);
                    todo.push(down);
                    todo.push(up);
                }
            }
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
};