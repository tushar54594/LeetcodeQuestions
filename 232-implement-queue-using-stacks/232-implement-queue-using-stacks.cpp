class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int element = output.top();
            output.pop();
            return element;
        }
        else{
            while(!input.empty()){
                int element = input.top();
                input.pop();
                output.push(element);
            }
            
            int element = output.top();
            output.pop();
            return element;
        }
    }
    
    int peek() {
        if(!output.empty())
            return output.top();
        else{
            while(!input.empty()){
                int element = input.top();
                input.pop();
                output.push(element);
            }
            return output.top();
        }
    }
    
    bool empty() {
        
         while(!input.empty()){
                int element = input.top();
                input.pop();
                output.push(element);
        }
        
        return output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */