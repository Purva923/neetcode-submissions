class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector <vector<bool>> visited(board.size(),vector <bool> (board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(word.length()==1)
                    return true;

                    visited[i][j]=true;
                    bool present=dfs(board,word,1,i,j,visited);
                    visited[i][j]=false;

                    if(present)
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string &word,int curr,int i,int j,vector<vector<bool>> &visited)
    {
        vector <pair<int,int>> moves={{1,0},{0,1},{0,-1},{-1,0}};

        for(int k=0;k<4;k++)
        {
            int i1=i+moves[k].first;
            int j1=j+moves[k].second;

            if(i1<board.size() && i1>=0 && j1<board[0].size() && j1>=0)
            {
                if(board[i1][j1]==word[curr] && !visited[i1][j1])
                {
                    if(word.length()==curr+1)
                    return true;

                    visited[i1][j1]=true;
                    bool present=dfs(board,word,curr+1,i1,j1,visited);
                    visited[i1][j1]=false;

                    if(present)
                    return true;
                }
            }
        }
        return false;
    }
};
