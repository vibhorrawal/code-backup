// O(N) space time
class CircularQueue {
    vector<int> a;
    int _cap, _size, _front, _back;
    public:
    CircularQueue(int capacity) {
        _cap = capacity;
        a = vector<int> (_cap);
        _size = 0;
        _front = 0;
        _back = 0;
    }

    bool enqueue(int val) {
        if(_size == _cap) return false;
        a[_back++] = val;
        _back %= _cap;
        _size++;
        return true;
    }

    bool dequeue() {
        if(_size == 0) return false;
        int val = a[_front++];
        _front %= _cap;
        _size--;
        return true;
    }

    int front() {
        if(_size == 0) return -1;
        int val = a[_front];
        _front %= _cap;
        // _size--;
        return val;
    }

    int top() {
        if(_size == 0) return -1;
        int b = _back - 1;
        if(b < 0) b += _cap;
        int val = a[b];
        return val;
    }

    bool isFull() {
        return _size == _cap;
    }

    bool isEmpty() {
        return _size == 0;
    }
};
