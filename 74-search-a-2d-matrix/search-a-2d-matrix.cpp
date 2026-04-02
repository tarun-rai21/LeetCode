class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows*cols - 1;

        int row;
        int col;

        while(start <= end){
            int mid = start + (end-start)/2;
            row = mid/cols;
            col = mid%cols;

            if(matrix[row][col]==target) return 1;
            else if (matrix[row][col]>target) end = mid-1;
            else start = mid+1;
        }

        return 0;
    }
};