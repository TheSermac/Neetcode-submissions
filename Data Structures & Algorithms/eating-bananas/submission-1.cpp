class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int first = 1; int last = 0; 

        //Grab maximum of bananas 
        for(int pile : piles){
            last = std::max(pile, last);
        }
        
        // Binary search from 1 to K
        while(first <= last){
            int result = (first + last)/2;
            int hours_needed = 0;

            //How many hours needed
            for(int pile : piles){
                hours_needed += pile / result;
                if(pile % result > 0){
                    hours_needed++;
                }
            }

            if(hours_needed <= h){
                last = result - 1;
            }
            else {
                first = result + 1;
            }
        }

        return std::max(first, last); 
    }
};
