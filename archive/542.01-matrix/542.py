from typing import List
from collections import deque


class Solution:
    def updateMatrix_dfs(self, mat: List[List[int]]) -> List[List[int]]:
        R, C = len(mat), len(mat[0])

        # return steps to closest zero
        def bfs(m, n) -> int:

            # coordinate and step
            q = deque([(m, n, 0)])
            visited = set()

            while q:
                (r, c, step) = q.popleft()

                if not (0 <= r < R and 0 <= c < C):
                    continue
                if (r, c) in visited:
                    continue
                if mat[r][c] == 0:
                    return step

                visited.add((r, c))

                q.append((r + 1, c, step + 1))
                q.append((r - 1, c, step + 1))
                q.append((r, c + 1, step + 1))
                q.append((r, c - 1, step + 1))

        ret = [[0 for _ in range(C)] for _ in range(R)]
        for i in range(R):
            for j in range(C):
                if mat[i][j] == 1:
                    ret[i][j] = bfs(i, j)

        return ret

    # DP solution
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        dist = [[float('inf') for _ in range(n)] for _ in range(m)]

        # first pass
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                if i > 0:
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1)
                if j > 0:
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1)

        # second pass
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i < m - 1:
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1)
                if j < n - 1:
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1)

        return dist


mat = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
myans = Solution().updateMatrix(mat)
expected = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
assert myans == expected
print("(1) passed")

mat = [[0, 0, 0], [0, 1, 0], [1, 1, 1]]
myans = Solution().updateMatrix(mat)
expected = [[0, 0, 0], [0, 1, 0], [1, 2, 1]]
assert myans == expected
print("(2) passed")

mat = [[0, 0, 0, 1],
       [0, 1, 1, 1],
       [1, 1, 1, 1]]
myans = Solution().updateMatrix(mat)
expected = [[0, 0, 0, 1],
            [0, 1, 1, 2],
            [1, 2, 2, 3]]
assert myans == expected
print("(3) passed")
