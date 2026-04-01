class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int high = cols-1;
        int low = 0;

        int row = 0;

        while (low<=high){
            if(target > matrix[row][cols-1]){
                if (row < rows-1) row++;
                else return 0;
            }
            else{
                int mid = low + (high-low)/2;
                if(matrix[row][mid]==target) return 1;
                else if (matrix[row][mid] > target) high = mid-1;
                else low = mid + 1;
            }
        }
        return 0;
    }
};