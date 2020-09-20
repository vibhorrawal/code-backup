// O(1) addNum() and fndMedian() time
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() {

    }
    
    int size(){ return maxpq.size() - minpq.size(); };
    
    void addNum(int num) {
        if(!maxpq.size() && !minpq.size()){
            maxpq.push(num);
        }
        else{
            if(num < maxpq.top()){
                int t = maxpq.top();
                maxpq.pop();
                maxpq.push(num);
                minpq.push(t);
            }
            else{
                minpq.push(num);
            }
        }
        
        if(size() > 1){
            int t = maxpq.top();
            maxpq.pop();
            minpq.push(t);
        }
        if(size() < -1){
            int t = minpq.top();
            minpq.pop();
            maxpq.push(t);
        }
    }
    
    double findMedian() {
        if(size() == 0){
            double t = minpq.top() + maxpq.top();
            return t/2;
        }
        else if(size() > 0) return maxpq.top();
        else return minpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */