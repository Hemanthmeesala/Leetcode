class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = -1;

        int direction = 1;

        vector<int> result;

        while (rows > 0 && cols > 0){
            for(int i = 0 ; i < cols; i++){
                col += direction;
                result.push_back(matrix[row][col]);
            }
            rows--;
            
        for(int i = 0; i<rows; i++){
            row += direction;
            result.push_back(matrix[row][col]);
        }
        cols--;
        direction *= -1;
        }
    return result;
    }
};