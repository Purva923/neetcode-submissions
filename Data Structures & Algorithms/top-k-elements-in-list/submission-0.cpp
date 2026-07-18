class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;

        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

        vector <pair<int,int>> v;

        for(auto &pair:mp)
        {
            v.push_back({pair.second,pair.first});
        }

        sort(v.begin(),v.end(),[](const auto &a,const auto&b){
            return a.first>b.first;
        });

        vector <int> list;

        for(int i=0;i<k;i++)
        {
            list.push_back(v[i].second);
        }
        return list;
    }
};
