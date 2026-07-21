class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int,double>> v;

        for(int i=0;i<speed.size();i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());

        for(int i=0;i<speed.size();i++)
        {
            v[i].second=((double)(target-v[i].first)/(double)v[i].second);
        }

        int count=1;
        double max=v[speed.size()-1].second;
        int i=speed.size()-2;
        while(i>=0)
        {
            while(i>=0&&v[i].second<=max)
            i--;

            if(i>=0)
            count++;
            else
            break;

            if(i>=0)
            {
                max=v[i].second;
                i--;
            }
        }
        return count;
    }
};
