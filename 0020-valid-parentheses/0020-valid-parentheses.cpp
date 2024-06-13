class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i == '(' || i == '{' || i == '[' ){  // If new bracket is introduced then me push it into our stack
                st.push(i);
            }
            else if(st.empty()){  // If our stack is empty and we get closing brackets i.e. ( { [ 
                return false;
            }
            else if(st.top() == '(' && i == ')' || st.top() == '{' && i == '}' || st.top() == '[' && i == ']'){  // If our stack is not empty then we check if the top of stack is the opening of the same bracket
                st.pop();
            }
            else{
                return false;
            }
        }        
        return st.empty();
    }
};