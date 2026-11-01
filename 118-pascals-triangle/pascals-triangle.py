class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        result = [[1]]
        row = 2
        while(row<=numRows):
            prev = result[-1]
            curr = [1]
            for i in range(len(prev)-1):
                curr.append(prev[i]+prev[i+1])
            curr.append(1)
            result.append(curr)
            row+=1
        return result