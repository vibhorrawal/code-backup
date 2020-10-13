// O(n) time | O(1) space
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int petrol = gas[0] - cost[0];
        int start = 0, end = 1;
        if(gas.size() == 1)
            return petrol >= 0 ? start : -1;

        while(1){
            while(petrol < 0 && start != end){
                petrol -= gas[start] - cost[start];
                start = (start + 1) % gas.size();
                if(start == 0)
                    return -1;
            }
            petrol += gas[end] - cost[end];
            end = (end + 1) % gas.size();
            if(start == end)
                return petrol >= 0 ? start : -1;
        }
        return 0;
    }
};

//
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for(int i = 0; i < gas.size(); i++)
            total += gas[i] - cost[i];
        if(total < 0)
            return -1;

        int start = 0;
        total = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                start = i + 1;
                total = 0;
            }
        }
        return start;
    }
};

//
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size()-1;
        int end = 0, total = gas[start] - cost[start];
        while(start > end){
            if(total >= 0){
                total += gas[end] - cost[end];
                end++;
            }
            else{
                start--;
                total += gas[start] - cost[start];
            }
        }
        return total >= 0 ? start : -1;
    }
};
