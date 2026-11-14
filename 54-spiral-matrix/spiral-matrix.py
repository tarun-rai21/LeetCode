class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        top = 0
        right = len(matrix[0])-1
        bottom = len(matrix)-1
        left = 0

        result = []
        while left <= right and top <= bottom:
            #print top row
            i = left
            while i <= right:
                result.append(matrix[top][i])
                i+=1
            top += 1
            
            #print right column
            j=top
            while j <= bottom:
                result.append(matrix[j][right])
                j+=1
            right -= 1
            
            #print bottom row
            if(bottom >= top):
                k=right
                while k >= left:
                    result.append(matrix[bottom][k])
                    k-=1
                bottom -= 1

            #print left column
            if(left <= right):
                m=bottom
                while m >= top:
                    result.append(matrix[m][left])
                    m-=1
                left += 1
        return result