class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long low=1;
        long high=INT_MAX;
        int ans=high;
        while(low<=high){
            long mid=(low+high)/2;
            // check if poss 
            int req=0;
            for(auto it:piles) req+=((it+mid-1)/mid);
            if(req <= h){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};
