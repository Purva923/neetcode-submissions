class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> maxHeap;
        for(int stone:stones)
        maxHeap.push(stone);

        while(maxHeap.size()>1)
        {
            int s1=maxHeap.top();
            maxHeap.pop();
            int s2=maxHeap.top();
            maxHeap.pop();

            if(s1!=s2)
            maxHeap.push(abs(s1-s2));
        }
        if(maxHeap.size())
        return maxHeap.top();
        else 
        return 0;
    }
};
