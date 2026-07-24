class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        auto lb=lower_bound(arr.begin(), arr.end(), x);
        if(lb==arr.end()){
            // all are small then x
            vector<int> ans(arr.end()-k, arr.end());
            return ans;
        }
        if(lb==arr.begin()){
            vector<int> ans(arr.begin(), arr.begin()+k);
            return ans;
        }
        int j=lb-arr.begin();
        int i=j-1;
        vector<int> ans;
        while(ans.size() < k){
            if(j>=n){
                ans.push_back(arr[i--]);
            }
            else if(i<0){
                ans.push_back(arr[j++]);
            }
            else{
                if(abs(arr[j]-x) < abs(arr[i]-x)){
                    ans.push_back(arr[j++]);
                }
                else ans.push_back(arr[i--]);
            }
        }
        vector<int> res(arr.begin()+i+1, arr.begin()+j);
        return res;
    }
};