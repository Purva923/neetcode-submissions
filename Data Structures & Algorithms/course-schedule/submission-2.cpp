class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int,vector<int>> mp1;

        for(int i = 0; i < numCourses; i++)
        {
            mp1[i];
        }
        for(int i=0;i<prerequisites.size();i++)
        {
            mp1[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }   

        unordered_map <int,vector<int>> mp2;

        for(int i = 0; i < numCourses; i++)
        {
            mp2[i];
        }
        for(int i=0;i<prerequisites.size();i++)
        {
            mp2[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }   

        vector <bool> visited(numCourses,false);
        vector <int> v1;


        //pushed into the vector the onces with 0 prerequisite
        for (auto pr:mp1)
        {
            if(pr.second.empty())
            {
                v1.push_back(pr.first);
                visited[pr.first]=true;
            }
        }

        for(int i=0;i<v1.size();i++)
        {  
            int temp=v1[i];

            for(int j=0;j<mp2[temp].size();j++)
            {
                int temp1=mp2[temp][j];
                if(visited[temp1]==true)
                continue;
                int flag=0;

                for(int k=0;k<mp1[temp1].size();k++)
                {
                    int temp2=mp1[temp1][k];
                    if(visited[temp2]==false)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                continue;
                else
                {
                    v1.push_back(temp1);
                    visited[temp1]=true;
                }
            }
        }
        if(v1.size()==numCourses)
        return true;
        else 
        return false;
    }
}; 
