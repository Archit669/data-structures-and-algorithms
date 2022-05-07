class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans = -1;
        
        while (start <= end){
            long long int mid = start + (end -start)/2;
            if (mid*mid == x){
                return mid;
            }else if (mid*mid < x){
                start = mid +1;
            }else{
                end = mid - 1;
                ans = end;
            }
        }
        
        return ans;
    }
};


// approach 2

class Solution {
public:
    int mySqrt(int x) {
        if (x==0){
            return 0;
        }
        int low = 1 , high = x;
        while (low<=high){
            int mid = low + (high - low)/2;
            if (mid > x/mid){
                high = mid - 1;
            }else{
                if (mid+1 > x/(mid+1))
                    return mid;
                low = mid + 1;
            }
        }
        
        return -1;
    }
};


// approach 3 (newton's method)

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;   
    }
};

