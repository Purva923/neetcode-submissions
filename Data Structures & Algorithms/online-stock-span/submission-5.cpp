class StockSpanner {
private: 
    vector <pair<int,int>> v;
public:
    StockSpanner() {}
    
    int next(int price) {
        int count=1;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i].first>price)
            break;
            else if(v[i].first<price)
            count++;
            else if(v[i].first==price) 
            {
                count=v[i].second+1;
                break;
            }
        }
        v.push_back({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */