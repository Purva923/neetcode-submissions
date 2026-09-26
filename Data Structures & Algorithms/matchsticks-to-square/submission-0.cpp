class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end());
        vector <bool> visited(matchsticks.size(),false);

        int sum=0;
        for(int i=0;i<matchsticks.size();i++)
        {
            sum+=matchsticks[i];
        }

        if(sum%4!=0)
        return false;

        int side=sum/4;

        visited[0]=true;
        sum=matchsticks[0];
        int poss=dfs(matchsticks,visited,sum,side,0);

        return poss;
    }

private:    
    bool dfs(vector<int>& matchsticks,vector<bool> &visited,int sum,int side,int count)
    {
        if(count==3)
        return true;

        if(sum == side)
        {
            return dfs(matchsticks, visited, 0, side, count + 1);
        }

        for(int i=1;i<matchsticks.size();i++)
        {
            if(visited[i])
            continue;

            int poss=false;
            if(matchsticks[i]!=matchsticks[i-1]||visited[i-1])
            {
                if(sum+matchsticks[i]>side)
                return false;

                visited[i]=true;
                poss=dfs(matchsticks,visited,sum+matchsticks[i],side,count);
                visited[i]=false;
            }

            if(poss)
            return true;
        }

        return false;
    }
};