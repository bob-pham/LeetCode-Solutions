# @leet start

from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        result = []
        unlock_map, require_map = {}, {}

        for preq in prerequisites:
            a, b = preq
            if a not in require_map:
                require_map[a]= set()
            if b not in unlock_map:
                unlock_map[b]= []

            unlock_map[b].append(a)
            require_map[a].add(b)

        for i in range(numCourses):
            if i not in require_map:
                todo = deque()
                todo.append(i)

                while len(todo) > 0:
                    c = todo.popleft()
                    result.append(c)

                    if c not in unlock_map:
                        continue
                    
                    for u in unlock_map[c]:
                        require_map[u].remove(c)
                        if len(require_map[u]) == 0:
                            todo.append(u)


        return result if len(result) == numCourses else []
        
# @leet end
