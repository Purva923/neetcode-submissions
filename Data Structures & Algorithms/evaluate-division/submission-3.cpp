class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> mtx;

        for(int i=0;i<equations.size();i++)
        {
            mtx[equations[i][0]][equations[i][1]]=values[i];
            mtx[equations[i][1]][equations[i][0]]=1/values[i];
        }

        for(auto &k : mtx)
        {
            for(auto &i : mtx)
            {
                for(auto &j : mtx)
                {
                    if(mtx[i.first].count(k.first) &&
                    mtx[k.first].count(j.first))
                    {
                        if(!mtx[i.first].count(j.first))
                        {
                            mtx[i.first][j.first] =
                                mtx[i.first][k.first] *
                                mtx[k.first][j.first];
                        }
                    }
                }
            }
        }

        vector <double> result;
        for(int i=0;i<queries.size();i++)
        {
            if(mtx[queries[i][0]][queries[i][1]]==0)
            result.push_back(-1);
            else 
            result.push_back(mtx[queries[i][0]][queries[i][1]]);
        }
        return result;
    }
};