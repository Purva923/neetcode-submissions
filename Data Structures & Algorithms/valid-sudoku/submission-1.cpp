class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            unordered_map<char,int> mp;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    mp[board[i][j]]++;
                    if(mp[board[i][j]]>1)
                    return false;
                }
            }
        }

        for(int i=0;i<9;i++)
        {
            unordered_map<char,int> mp;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    mp[board[j][i]]++;
                    if(mp[board[j][i]]>1)
                    return false;
                }
            }
        }

        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                unordered_map<char,int> mp;
                for(int i1=0;i1<3;i1++)
                {
                    for(int j1=0;j1<3;j1++)
                    {
                        if(board[i+i1][j+j1]!='.')
                        {
                            mp[board[i+i1][j+j1]]++;
                            if(mp[board[i+i1][j+j1]]>1)
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
