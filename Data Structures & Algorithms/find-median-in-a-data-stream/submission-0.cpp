class MedianFinder {
private:
    priority_queue<double> max_heap;
    priority_queue<double,vector<double>,greater<double>> min_heap;
    int count=0;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        count++;
        if(max_heap.empty()&&min_heap.empty())
        {
            max_heap.push(num);
        }
        else if(min_heap.empty())
        {
            if(num>=max_heap.top())
            min_heap.push(num);
            else 
            max_heap.push(num);
        }
        else if(max_heap.empty())
        {
            if(num<=min_heap.top())
            max_heap.push(num);
            else 
            min_heap.push(num);
        }
        else
        {
            if(num>min_heap.top())
            min_heap.push(num);
            else
            max_heap.push(num);
        }
        
        if(count%2==0)
        {
            while(max_heap.size()>min_heap.size())
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            while(max_heap.size()<min_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        else 
        {
            while(max_heap.size()<min_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    
    double findMedian() {
        if(count%2==0)
        return (min_heap.top()+max_heap.top())/2.0;
        else 
        return max_heap.top();
    }
};
