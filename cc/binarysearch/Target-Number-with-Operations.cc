// O(logN) time | O(1) space
int solve(int start, int end) {
    int count = 0;
    while(end/2 >= start){
        if(end % 2 == 0){
            end /= 2;
        }
        else{
            end--;
        }
        count++;
    }
    return count + (end - start);
}
