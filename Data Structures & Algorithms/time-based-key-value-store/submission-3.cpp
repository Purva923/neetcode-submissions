class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> value_table;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        value_table[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {

        if(value_table.find(key)!=value_table.end())
        {
            int r=value_table[key].size()-1;
            int l=0;

            while(l<=r)
            {
                int mid=(l+r)/2;
                int mid_ts=value_table[key][mid].first;

                if(mid_ts==timestamp)
                return value_table[key][mid].second;
                else if(mid_ts>timestamp)
                r=mid-1;
                else
                l=mid+1;
            }
            if(r>=0)
            return value_table[key][r].second;
        }
        return "";
    }
};
