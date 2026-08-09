class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        else if(n==2)
        return 1;

        int sum=2;
        vector <int> v(n+1);
        v[0]=0,v[1]=1,v[2]=1;

        for(int i=0,j=3;i<=n-3,j<=n;i++,j++)
        {
            v[j]=sum;
            sum+=(v[j]-v[i]);
        }
        return v[n];
    }
};