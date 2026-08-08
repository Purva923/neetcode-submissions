class Solution {
private:
    struct Compare
    {
        bool operator()(vector<int> &a,vector<int> &b)
        {
            return a[2]>b[2];
        }
    };
    vector<vector<int>> v;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> minHeap;

        for(vector<int> point:points)
        minHeap.push({point[0],point[1],point[0]*point[0]+point[1]*point[1]});

        while(k--)
        {
            v.push_back({minHeap.top()[0],minHeap.top()[1]});
            minHeap.pop();
        }
        return v;
    }
};
