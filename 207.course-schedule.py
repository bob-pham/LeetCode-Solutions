# @leet start
from collections import deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        taken = 0
        unlock_map, require_map = {}, {}

        for prereq in prerequisites:
            a, b = prereq

            if b not in unlock_map:
                unlock_map[b] = []

            if a not in require_map:
                require_map[a] = set()

            unlock_map[b].append(a)
            require_map[a].add(b)

        for i in range(numCourses):
            if i not in require_map:
                todo = deque()
                todo.append(i)

                while len(todo) > 0:
                    c = todo.popleft()
                    taken += 1

                    if c not in unlock_map:
                        continue

                    for u in unlock_map[c]:
                        require_map[u].remove(c)
                        if len(require_map[u]) == 0:
                            todo.append(u)

        return taken == numCourses

        
# @leet end
