class MyCircularDeque {
public:
        int *arr,f,r,size;
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        f = -1;
        r = -1;
    }
    
    bool insertFront(int value) {
        if(f == 0 && r == size - 1 ||f != 0 && r == (f - 1) % (size - 1))
            return false;
        else if(f == -1)
            f = r = 0;
        else if(f == 0 && r != size - 1)
            f = size - 1;
        else
            f--;
        
        arr[f] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (f == 0 && r == size - 1 ||f != 0 && r == (f - 1) % (size - 1))
            return false;
        else if (f == -1)
            f = r = 0;
        else if (r == size - 1 && f != 0)
            r = 0;
        else
            r++;

        arr[r] = value;
        return true;
    }
    
    bool deleteFront() {
        if (f == -1)
            return false;
        if (f == r) // single element
            f = r = -1;
        else if (f == size - 1)
            f = 0; // to maintain cyclic nature
        else
            f++;

        return true;
    }
    
    bool deleteLast() {
        if (f == -1)
            return false;
        if (f == r) // single element
            f = r = -1;
        else if (r == 0)
            r = size - 1 ; // to maintain cyclic nature
        else
            r--;

        return true;
    }
    
    int getFront() {
        if(f == -1)
            return -1;
        
        return arr[f];
    }
    
    int getRear() {
        if(f == -1)
            return -1;
        
        return arr[r];
    }
    
    bool isEmpty() {
        if(f == -1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(f == 0 && r == size - 1 ||f != 0 && r == (f - 1) % (size - 1))
             return true;
        else 
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */