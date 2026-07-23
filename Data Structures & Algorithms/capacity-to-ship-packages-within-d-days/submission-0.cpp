class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int mid,d1;

        while(l<=r)
        {
            mid=(l+r)/2;
            d1=days_taken(weights,days,mid);

            if(d1>days)
            l=mid+1;
            else
            r=mid-1;
        }
        return l;
    }
private:
    int days_taken(vector<int>& weights, int days,int capacity)
    {
        int count=1;
        int i=0;
        int sum=0;
        while(i<weights.size())
        {
            if(sum+weights[i]<=capacity)
            {
                sum+=weights[i];
            }
            else
            {
                count++;
                sum=weights[i];
            }
            i++;
        }
        return count;
    }
};