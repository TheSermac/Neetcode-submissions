class Solution {
public:
    int carFleet(int t, vector<int>& position, vector<int>& speed) {
        
        if(position.size() == 1){
            return 1;
        }

        float target = t;
        int car_fleets = position.size();
        vector<pair<float,float>> cars(position.size());

        for(int i = 0; i < position.size(); i++){
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end());
        std::reverse(cars.begin(), cars.end());

        for(int i = 1; i < cars.size(); i++){
            float next_car_cycles = (target - cars[i-1].first)/cars[i-1].second;
            
            float prev_car_cycles = (target - cars[i].first)/cars[i].second;
            
            //Comparison
            if(prev_car_cycles <= next_car_cycles){
                cars[i].first = cars[i-1].first; cars[i].second = cars[i-1].second;
                car_fleets--;
            }
        }
        
        return car_fleets;
    }
};
