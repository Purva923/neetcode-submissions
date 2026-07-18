class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> mp; 
        vector <vector<string>> v;

        for(const auto & s : strs)
        {
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(s);
        }

        for(const auto&pair : mp)
        {
            v.push_back(pair.second);
        }

        return v;
    }
};
