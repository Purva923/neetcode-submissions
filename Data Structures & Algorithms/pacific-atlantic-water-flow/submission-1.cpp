class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector <vector<int>> ao(n,vector<int>(m,0));
        vector <vector<int>> po(n,vector<int>(m,0));
        vector <vector<int>> av(n,vector<int>(m,0));
        vector <vector<int>> pv(n,vector<int>(m,0));
        vector <vector<int>> mv={{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<heights[0].size();i++)
        {
            po[0][i]=1;
        }
        for(int i=0;i<heights.size();i++)
        {
            po[i][0]=1;
        }
        for(int i=0;i<heights[0].size();i++)
        {
            ao[n-1][i]=1;
        }
        for(int i=0;i<heights.size();i++)
        {
            ao[i][m-1]=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(po[i][j]==1)
                {
                    pv[i][j]=1;
                    stack<pair<int,int>> st;
                    st.push({i,j});

                    while(!st.empty())
                    {
                        int i1=st.top().first;
                        int j1=st.top().second;
                        st.pop();
                        for(int k=0;k<4;k++)
                        {
                            int i2=i1+mv[k][0];
                            int j2=j1+mv[k][1];

                            if(i2>=0 && j2>=0 && i2<n && j2<m)
                            {
                                if(pv[i2][j2]==0 
                                && heights[i2][j2]>=heights[i1][j1])
                                {
                                    pv[i2][j2]=1;
                                    st.push({i2,j2});
                                }
                            }

                        }
                    }
                }
            }
        }


        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ao[i][j]==1)
                {
                    av[i][j]=1;
                    stack <pair<int,int>> st;
                    st.push({i,j});

                    while(!st.empty())
                    {
                        int i1=st.top().first;
                        int j1=st.top().second;
                        st.pop();
                        for(int k=0;k<4;k++)
                        {
                            int i2=i1+mv[k][0];
                            int j2=j1+mv[k][1];

                            if(i2>=0 && j2>=0 && i2<n && j2<m)
                            {
                                if(av[i2][j2]==0 &&
                                heights[i2][j2]>=heights[i1][j1])
                                {
                                    av[i2][j2]=1;
                                    st.push({i2,j2});
                                }
                            }

                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pv[i][j] && av[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};
