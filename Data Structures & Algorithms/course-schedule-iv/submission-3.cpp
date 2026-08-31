class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<bool>> fw(numCourses,vector<bool>(numCourses,false));

        for(int i=0;i<prerequisites.size();i++)
        {
            auto temp=prerequisites[i];
            fw[temp[0]][temp[1]]=true;
        }

        for(int i=0;i<numCourses;i++)
        {
            for(int j=0;j<numCourses;j++)
            {
                if(fw[i][j]==true)
                {
                    for(int k=0;k<numCourses;k++)
                    {
                        if(fw[j][k]==true)
                        fw[i][k]=true;
                    }
                }
            }
        }


        vector <bool> result(queries.size(),false);
        for(int i=0;i<queries.size();i++)
        {
            auto temp=queries[i];
            if(fw[temp[0]][temp[1]])
            result[i]=true;
        }
        return result;
    }
};


//now this is application of floyd Warshals Algorithm 