class TimeMap {
private:
    map<string, vector<pair<int,string>>> storage;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(storage[key].empty()){
            return "";
        }
        else{
            return search(storage[key], timestamp);
        }
    }

    string search(const vector<pair<int, string>>& nums, int target) {
        int a = 0; int b = nums.size() - 1;
        int m;
        while(a <= b){
            m = (b + a)/2;
            if(nums[m].first == target){
                return nums[m].second;
            }
            else if(nums[m].first < target){
                a = m + 1;
            }
            else{
                b = m - 1;
            }
        }


        if(b < 0){
            return "";
        }

        return nums[b].second;
    }
};
