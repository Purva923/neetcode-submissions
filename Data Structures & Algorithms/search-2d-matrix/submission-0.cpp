class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=m*n-1;
        int m1,n1,mid,a;

        while(l<=r)
        {
            mid=(l+r)/2;
            m1=mid/n;
            n1=mid%n;
            a=matrix[m1][n1];

            if(a==target)
            return true;
            else if(a<target)
            l=mid+1;
            else
            r=mid-1;
        }
        return false;
    }
};
