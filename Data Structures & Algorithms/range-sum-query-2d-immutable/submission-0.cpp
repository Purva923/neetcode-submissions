class NumMatrix {
    private:
    vector <vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total_sum=0;
        for(int i=row1;i<=row2;i++)
        {
            total_sum+=accumulate(matrix[i].begin()+(col1),matrix[i].begin()+(col2+1),0);
        }
        return total_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */