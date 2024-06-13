class Solution {
public:

    bool binSearch(vector<vector<int>>& matrix,int target,int row,int col){
        int s=0;
        int e=col-1;

        int mid=s+(e-s)/2;

        while(s<=e){
            if(matrix[row][mid]==target){
                return 1;
            }else if(matrix[row][mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return 0;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0;i<row-1;i++){
            if(matrix[i][0]<=target && matrix[i+1][0]>target){
                return binSearch(matrix,target,i,col);
            }
        }

        if(matrix[row-1][0]<=target && matrix[row-1][col-1]>=target){
            return binSearch(matrix,target,row-1,col);
        }
        return 0;

    }
};