// @leet start
class Coord {
    public int x;
    public int y;

    public Coord (int x, int y) {
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int numIslands(char[][] grid) {
        int result = 0;
        int height = grid.length;
        int width = grid[0].length;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == '0') {
                    continue;
                }
                Queue<Coord> queue = new LinkedList<>();
                queue.add(new Coord(x, y));
                result++;

                while(queue.size() > 0) {
                    Coord curr = queue.poll();
                    if (grid[curr.y][curr.x] == '0') {
                        continue;
                    }

                    grid[curr.y][curr.x] = '0';

                    if (curr.y - 1 >= 0 && grid[curr.y - 1][curr.x] == '1') {
                        queue.add(new Coord(curr.x, curr.y - 1));
                    }

                    if (curr.y + 1 < height && grid[curr.y + 1][curr.x] == '1') {
                        queue.add(new Coord(curr.x, curr.y + 1));
                    }

                    if (curr.x - 1 >= 0 && grid[curr.y][curr.x - 1] == '1') {
                        queue.add(new Coord(curr.x - 1, curr.y));
                    }

                    if (curr.x + 1 < width && grid[curr.y][curr.x + 1] == '1') {
                        queue.add(new Coord(curr.x + 1, curr.y));
                    }
                }
            }
        }

        return result;
    }
}
// @leet end
