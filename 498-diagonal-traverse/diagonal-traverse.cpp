class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> result;
        result.reserve(rows * cols);

        int row = 0, col = 0;

        for(int i=0; i < (rows*cols); i++){
            result.push_back(mat[row][col]);

            if((row + col)%2==0){
                //moving upward
                if(col == cols-1){  //hit right boundary
                    row++;
                }
                else if(row==0){  //hit top
                    col++;
                }
                
                else{
                    row--;
                    col++;
                }
            }

            else{
                //moving downward
                if(row == rows-1){ //bottom boundary
                    col++;
                }
                else if(col == 0){ //left boundary
                    row++;
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};