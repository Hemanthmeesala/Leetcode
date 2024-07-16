class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        int size = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=ans[size][1]){
                if(ans[size][1]<intervals[i][1]) ans[size][1] = intervals[i][1];
            }
            else{
                ans.push_back(intervals[i]);
                size++;
            }
        }
        return ans;
    }
};