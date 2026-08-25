class Solution {
public:
    void solve(vector<vector<char>>& board) {
        stack<pair<int,int>> st1;
        stack<pair<int,int>> st2;

        vector<pair<int,int>> mv = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int flag = 0;

                if(board[i][j] == 'O' && visited[i][j] == 0)
                {
                    st1.push({i,j});
                    visited[i][j] = 1;

                    while(!st1.empty())
                    {
                        int i1 = st1.top().first;
                        int j1 = st1.top().second;

                        st2.push(st1.top());
                        st1.pop();

                        for(int k = 0; k < 4; k++)
                        {
                            int i2 = i1 + mv[k].first;
                            int j2 = j1 + mv[k].second;

                            // Cell is outside board
                            if(i2 < 0 || j2 < 0 || i2 >= n || j2 >= m)
                            {
                                flag = 1;
                            }
                            else if(board[i2][j2] == 'O' &&
                                    visited[i2][j2] == 0)
                            {
                                visited[i2][j2] = 1;
                                st1.push({i2,j2});
                            }
                        }
                    }

                    // If component is surrounded, flip all O -> X
                    if(flag == 0)
                    {
                        while(!st2.empty())
                        {
                            int r = st2.top().first;
                            int c = st2.top().second;

                            board[r][c] = 'X';
                            st2.pop();
                        }
                    }
                    else
                    {
                        // Boundary-connected component: don't flip it
                        while(!st2.empty())
                            st2.pop();
                    }
                }
            }
        }
    }
};