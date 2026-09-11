class Solution {
private:
    priority_queue<int,std::vector<int>, std::less<int>> ordered_rocks;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i = 0; i < stones.size(); i++){
            ordered_rocks.push(stones[i]);
        }

        while(ordered_rocks.size() > 1){
            int r1 = ordered_rocks.top(); 
            ordered_rocks.pop();
            int r2 = ordered_rocks.top();
            ordered_rocks.pop();

            if(r1 != r2){
                ordered_rocks.push(std::abs(r1-r2));
            }
        }

        return ordered_rocks.empty() ? 0 : ordered_rocks.top();
    }
};
