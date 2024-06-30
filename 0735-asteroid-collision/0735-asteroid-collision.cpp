class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        vector<int> v;
        for(int a : asteroids)
        {
            while(!s.empty() && a < 0 && s.top() > 0)
            {
                int diff = a + s.top();
                if(diff < 0)
                {
                    s.pop();
                }
                else if(diff > 0)
                {
                    a = 0;
                }
                else
                {
                    s.pop();
                    a = 0;
                }
            }
            if(a != 0)
            {
                s.push(a);
            }
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};