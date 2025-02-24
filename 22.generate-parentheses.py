# @leet start
class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        result = set() 
        visited = set() 

        def validParenthesis(p):
            stack = deque()
            for i in p:
                if i == "(":
                    stack.append(i)
                else:
                    if stack.pop() != "(":
                        return False
            return len(stack) == 0

        def dfs(curr, count):
            if count <= 0:
                if (validParenthesis(curr)):
                    result.add(curr)
                return


            for back in range(len(curr)):
                for front in range(back + 1, len(curr)):
                    next = curr[:back] + "(" + curr[back:front] + ")" + curr[front:]
                    if not validParenthesis(next) or next in visited:
                        continue
                    else:
                        dfs(next, count - 1)
                    visited.add(next)

            dfs(curr + "()", count - 1)
            dfs("()" + curr, count - 1)

        dfs("()", n - 1)

        return list(result)

        
# @leet end
