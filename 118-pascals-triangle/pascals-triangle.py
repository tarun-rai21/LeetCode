class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        result = [[1]]
        for _ in range(1, numRows):
            prev = result[-1]
            curr = [1]
            for i in range(len(prev)-1):
                curr.append(prev[i]+prev[i+1])
            curr.append(1)
            result.append(curr)    
        return result