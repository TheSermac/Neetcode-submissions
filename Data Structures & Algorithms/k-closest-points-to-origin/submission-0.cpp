class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) 
        { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; }); 

        while(points.size() > k){
            points.pop_back();
        }

        return points;
    }  
};
