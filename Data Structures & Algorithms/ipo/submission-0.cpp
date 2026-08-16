class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        // {capital, profit}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        // Maximum profit among currently affordable projects
        priority_queue<int> maxHeap;

        for(int i = 0; i < capital.size(); i++)
        {
            minHeap.push({capital[i], profits[i]});
        }

        while(k--)
        {
            // Move all affordable projects into maxHeap
            while(!minHeap.empty() && minHeap.top().first <= w)
            {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            // No project can currently be afforded
            if(maxHeap.empty())
                break;

            // Take the project with maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};