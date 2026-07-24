class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        int ans=0;
        sort(people.begin(), people.end());
        while(i<=j){
            if(i==j){
                ans++;
                break;
            }
            int sum=people[i]+people[j];
            if(sum<=limit){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};