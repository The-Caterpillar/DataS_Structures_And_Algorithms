class Solution {
public:
    int mySqrt(int x) 
    {
        long long mid;
        int low=1, high = 100000;

        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid>x) high = mid-1;
            else if(mid*mid<x) low = mid+1;
        }
        if(mid*mid<=x) return mid;
    return mid-1;        
    }
};
