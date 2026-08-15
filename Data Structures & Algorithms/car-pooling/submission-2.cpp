struct compare1
{
    bool operator()(const vector<int> &a,const vector<int> &b)
    {
        return a[1]>b[1];
    }
};

struct compare2
{
    bool operator()(const vector<int> &a,const vector<int> &b)
    {
        return a[2]>b[2];
    }
};


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>,vector<vector<int>>,compare1> pq1;
        priority_queue<vector<int>,vector<vector<int>>,compare2> pq2;

        for(int i=0;i<trips.size();i++)
        {
            pq1.push(trips[i]);
        }

        int seats=0;

        while(!pq1.empty())
        {
            int station=pq1.top()[1];

            while(!pq2.empty()&&pq2.top()[2]<=station)
            {
                seats-=pq2.top()[0];
                pq2.pop();
            }

            if(seats+pq1.top()[0]>capacity)
            return false;

            while(seats+pq1.top()[0]<=capacity)
            {
                pq2.push(pq1.top());
                seats+=pq1.top()[0];
                pq1.pop();
                if(!pq1.empty())
                station=pq1.top()[1];
                else 
                return true;
            }
        }
        return true;
    }
};