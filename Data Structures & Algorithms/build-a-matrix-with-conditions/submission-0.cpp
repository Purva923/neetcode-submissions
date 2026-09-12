class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector <int> row_no(k+1,-1);
        vector <int> col_no(k+1,-1);

        vector<vector<int>> adj_row(k+1);
        vector<vector<int>> adj_col(k+1);

        vector <int> ind_row(k+1,0);
        vector <int> ind_col(k+1,0);

        for(auto edge:rowConditions)
        {
            ind_row[edge[1]]++;
            adj_row[edge[0]].push_back(edge[1]);
        }

        for(auto edge:colConditions)
        {
            ind_col[edge[1]]++;
            adj_col[edge[0]].push_back(edge[1]);
        }

        queue <int> row_q;
        queue <int> col_q;

        for(int i=1;i<=k;i++)
        {
            if(ind_row[i]==0)
            {
                row_q.push(i);
            }
        }

        int count=-1;
        while(!row_q.empty())
        {
            count++;
            int temp=row_q.front();
            row_q.pop();
            row_no[temp]=count;

            for(auto edge:adj_row[temp])
            {
                ind_row[edge]--;
                if(ind_row[edge]==0)
                {
                    row_q.push(edge);
                }
            }
        }

        if(count<k-1)
        return {};

        for(int i=1;i<=k;i++)
        {
            if(ind_col[i]==0)
            {
                col_q.push(i);
            }
        }

        count=-1;
        while(!col_q.empty())
        {
            count++;
            int temp=col_q.front();
            col_q.pop();
            col_no[temp]=count;

            for(auto edge:adj_col[temp])
            {
                ind_col[edge]--;
                if(ind_col[edge]==0)
                {
                    col_q.push(edge);
                }
            }
        }
        if(count<k-1)
        return {};

        vector<vector<int>> result(k,vector<int>(k,0));

        for(int i=1;i<=k;i++)
        {
            result[row_no[i]][col_no[i]]=i;
        }

        return result;
    }
};