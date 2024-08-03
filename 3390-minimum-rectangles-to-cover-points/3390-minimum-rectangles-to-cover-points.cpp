class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto p : points)
        {
            minHeap.push(p[0]);
        }

        int prev = -1;
        int res = 0;
        while (!minHeap.empty())
        {
            prev = minHeap.top();
            minHeap.pop();

            while (minHeap.top() - prev <= w && !minHeap.empty())
            {
                minHeap.pop();
            }
            
            res++;
        }

        return res;
    }
};