struct compare
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        if (a[1] == b[1])
            return a[2] > b[2];

        return a[1] > b[1];
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());

        auto process=tasks.begin();
        int curr_time=(*process)[0];
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        vector<int> seq;

        pq.push(*process);
        process=process+1;

        while(!pq.empty())
        {
            seq.push_back(pq.top()[2]);
            curr_time+=pq.top()[1];
            pq.pop();

            while(process!=tasks.end()&&(*process)[0]<=curr_time)
            {
                pq.push(*process);
                process++;
            }
            if(pq.empty()&&process!=tasks.end())
            {
                pq.push(*process);
                process++;
            }
        }
        return seq;
    }
};