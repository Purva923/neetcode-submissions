class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> in_degree(numCourses, 0);
        queue<int> q;
        unordered_map<int, vector<int>> mp1;

        // Build graph and calculate in-degree
        for(int i = 0; i < prerequisites.size(); i++)
        {
            in_degree[prerequisites[i][0]]++;
            mp1[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // Courses having 0 prerequisites
        for(int i = 0; i < numCourses; i++)
        {
            if(in_degree[i] == 0)
                q.push(i);
        }

        vector<int> path;

        // Kahn's Algorithm
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();

            path.push_back(temp);

            for(int i = 0; i < mp1[temp].size(); i++)
            {
                int temp1 = mp1[temp][i];

                in_degree[temp1]--;

                if(in_degree[temp1] == 0)
                {
                    q.push(temp1);
                }
            }
        }

        if(path.size()!=numCourses)
        path.clear();

        return path;
    }
};