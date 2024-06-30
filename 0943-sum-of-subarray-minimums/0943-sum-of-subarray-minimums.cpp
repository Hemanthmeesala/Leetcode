class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);

        stack<int> st1;
        for (int i=0;i<n;i++){
            int k = 0;
            if (st1.empty()){
                st1.push(i);
            }
            else{
                while(!st1.empty() && arr[i]<=arr[st1.top()]){
                    k = (left[st1.top()]+i-st1.top());
                    st1.pop();
                }
                st1.push(i);
            }
            left[i] = k;
        }

        vector<int> right(n);
        stack<int> st2;
        for (int i=n-1;i>=0;i--){
            int k = 0;
            if (st2.empty()){
                st2.push(i);
            }
            else{
                while(!st2.empty() && arr[i]<arr[st2.top()]){
                    k = right[st2.top()]+(st2.top()-i);
                    st2.pop();
                }
                st2.push(i);
            }
            right[i] = k;
        }
        
        long long ans = 0;
        for (int i=0;i<n;i++){
            ans = (ans+((arr[i])*((static_cast<long long>(left[i]+1)*(right[i]+1)))))%mod;
        }
        return ans;
    }
};