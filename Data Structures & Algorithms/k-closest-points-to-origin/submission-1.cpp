class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b){
            int da=(a[0]*a[0]+a[1]*a[1]);
            int db=(b[0]*b[0]+b[1]*b[1]);
            return da<db;
        });
        vector<vector<int>> res(points.begin(), points.begin()+k);
        return res;
    }
};
