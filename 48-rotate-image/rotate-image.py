class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #tranpose the matrix first
        for i in range(len(matrix)):       
            for j in range(i, len(matrix[0])):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        #reverse each row
        for i in range(len(matrix)):
            matrix[i].reverse()