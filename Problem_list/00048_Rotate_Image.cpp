//
//  00048_Rotate_Image.cpp
//  
//
//  Created by 용균 on 5/4/26.
//

// in-place memory use.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for(int i=0; i<n/2; ++i){
            for(int j=i; j<n-i-1; ++j){
                int temp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
