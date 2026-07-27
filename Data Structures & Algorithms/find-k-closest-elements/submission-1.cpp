class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0,r=n-1;
        int start;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==x)
            {
                start=mid;
                break;
            }
            else if(arr[mid]>x)
            r=mid-1;
            else
            l=mid+1;
        }
        if(l>r&&l<n&&r>=0)
        {
            if(abs(arr[l]-x)<abs(arr[r]-x))
            start=l;
            else 
            start=r;
        }
        else if(l>r&&r>=0)
        start=r;
        else if(l>r&&l<n)
        start=l;
        l=r=start;

        int count=1;
        while(count<k)
        {
            if(l>0&&r<n-1)
            {
                if(abs(arr[l-1]-x)>abs(arr[r+1]-x))
                r++;
                else
                l--;
            }
            else if(l>0)
            {
                l--;
            }
            else 
            r++;
            count++;
        }

        vector <int> v;
        for(int i=l;i<=r;i++)
        {
            v.push_back(arr[i]);
        }

        return v;
    }
};