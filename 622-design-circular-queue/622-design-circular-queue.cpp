class MyCircularQueue {
public:
    int *arr,f,r,c,size;
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        f = 0;
        r = -1;
        c = 0;
    }
    
    bool enQueue(int value) {
        if(c == size)
            return false;
        else{
            r = (r+1)%size;
            arr[r] = value;
            c++;
            return true;
        }
    }
    
    bool deQueue() {
        if(c == 0)
            return false;
        else{
            f = (f+1)%size;
            c--;
            return true;
        }
    }
    
    int Front() {
        if(c == 0)
            return -1;
        
        return arr[f];
    }
    
    int Rear() {
        if(c == 0)
            return -1;
        
        return arr[r];
    }
    
    bool isEmpty() {
        if(c == 0)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(c == size)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */