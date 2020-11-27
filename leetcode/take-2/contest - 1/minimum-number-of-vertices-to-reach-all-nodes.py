class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        seen = set()
        for i in edges:
            seen.add(i[1])
        # print(seen)
        visited =[]
        for i in range(n):
            if i not in seen:
                visited.append(i)
        return visited
        
                
