class MyQueue {
public:
    stack<int> s1;
    
    void push(int x){

        if(s1.empty()){
            s1.push(x);
            return;
        }

        int top=s1.top();
        s1.pop();
        push(x);
        s1.push(top);

    return;
    }
    
    int pop() {
        int top=s1.top();
        s1.pop();
        return top;
    }
    
    int peek(){
        return s1.top();
    }
    
    bool empty(){
        return s1.empty();
    }
};

