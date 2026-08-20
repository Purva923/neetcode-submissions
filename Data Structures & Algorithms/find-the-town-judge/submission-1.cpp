class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> j_count(n+1,0);
        vector <int> judge;

        for(int i=0;i<trust.size();i++)
        {
            j_count[trust[i][0]]=-1;

            if(j_count[trust[i][1]]!=-1)
            {
                j_count[trust[i][1]]++;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(j_count[i]==n-1)
            return i;
        }
        return -1;
    }
};