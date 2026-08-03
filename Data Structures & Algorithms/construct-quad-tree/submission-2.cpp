/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool add(vector<vector<int>>& grid,int l,int r,int n)
    {
        int sum=0;
        for(int i=l;i<l+n;i++)
        {
            for(int j=r;j<r+n;j++)
            {
                sum+=grid[i][j];
            }
        }
        if (sum==0)
        return true;
        else 
        return false;
    }


    bool multiply(vector<vector<int>>& grid,int l,int r,int n)
    {
        int product=1;
        for(int i=l;i<l+n;i++)
        {
            for(int j=r;j<r+n;j++)
            {
                product*=grid[i][j];
            }
        }
        if (product==1)
        return true;
        else 
        return false;
    }


    Node* check(vector<vector<int>>& grid,int l,int r,int n)
    {
        Node * temp;
        if(n==1||add(grid,l,r,n)||multiply(grid,l,r,n))
        {
            temp=new Node(grid[l][r],true);
            return temp;
        }

        n=n/2;
        temp=new Node(0,false);

        temp->topLeft=check(grid,l,r,n);
        temp->topRight=check(grid,l,r+n,n);
        temp->bottomLeft=check(grid,l+n,r,n);
        temp->bottomRight=check(grid,l+n,r+n,n);

        return temp;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        Node * root=check(grid,0,0,grid.size());
        return root;
    }
};