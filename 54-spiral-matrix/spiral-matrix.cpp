class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>result;


        int top = 0;
        int right = cols-1;
        int bottom = rows-1;
        int left = 0;

        while(left <= right && top <= bottom){
            //top row
            for(int i=left; i<=right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            //right row
            for(int i=top; i<=bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
                //bottom row
                for(int i=right; i>=left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                //left row
                for(int i=bottom; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};