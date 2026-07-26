class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long low=*max_element(weights.begin(), weights.end());
        long high=INT_MAX;
        int ans=high;
        while(low <= high){
            int mid=(low+high)/2;
            int req=0;
            int sum=0;
            for(int i=0;i<weights.size();i++){
                sum+=weights[i];
                if(sum > mid){
                    req++;
                    sum=weights[i];
                }
            }
            if(sum!=0) req++;
            if(req<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};