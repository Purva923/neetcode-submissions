class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int max_ele=*max_element(nums.begin(),nums.end());
        int min_ele=*min_element(nums.begin(),nums.end());

        if(min_ele==1)
        return false;

        vector <int> odd_no(max_ele+1,1);
        odd_no[0]=-1;
        odd_no[1]=-1;

        for(int i=2;i*i<=max_ele;i++)
        {
            if(odd_no[i]==1)
            {
                for(int j=2;i*j<=max_ele;j++)
                {
                    odd_no[i*j]=0;
                }
            }
        }

        int count=1;
        vector<bool> visited(nums.size(),false);
        visited[0]=true;

        set <int> s1;
        queue <int> q1;
        q1.push(nums[0]);

        while(!q1.empty())
        {
            int temp=q1.front();
            q1.pop();

            if(odd_no[temp]==1)
            {
                s1.insert(temp);
            }
            else
            {
                int curr=temp/2;
                while(curr>1)
                {
                    if(temp%curr==0 && odd_no[curr]==1)
                    {
                        
                        s1.insert(curr);

                        while(temp%curr==0)
                            temp/=curr;
                    }
                    else
                    curr--;
                }
            }

            for(int i=0;i<nums.size();i++)
            {
                if(visited[i])
                continue;

                for(auto d:s1)
                {
                    if(nums[i]%d==0)
                    {
                        q1.push(nums[i]);
                        visited[i]=true;
                        count++;
                        break;
                    }
                }
            }
            if(count==nums.size())
            return true;
        }
        return false;
    }
};