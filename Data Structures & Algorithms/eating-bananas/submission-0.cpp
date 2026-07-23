class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int mid,h1;

        while(l<=r)
        {
            mid=(l+r)/2;
            h1=hours(mid,piles,h);

            if(h1>h)
            l=mid+1;
            else
            r=mid-1;
        }
        return l;
    }

    int hours (int n,vector<int>& piles,int h)
    {
        int count=0;
        for(int i=0;i<piles.size();i++)
        {
            count+=(piles[i]+n-1)/n;
        }
        return count;
    }
};
