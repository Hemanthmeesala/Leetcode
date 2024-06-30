#include<bits/stdc++.h>
class Solution {
public:
    struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(int num:nums){
        mp[num]++;
       } 
        priority_queue<pair<int, int>, vector<pair<int, int>> , compare> minHeap;
        for(auto& [num,freq]:mp){
            minHeap.push({num,freq});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return ans;
    }
};