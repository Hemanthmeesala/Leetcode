class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int agas=0;
        int acost=0;
        for(int i=0;i<gas.size();i++)
        {
            agas+=gas[i];
            acost+=cost[i];
        }
        if(agas<acost) return -1;
        int s=0;
        int currentamountofgas=0;
        for (int i = 0; i <cost.size();i++) 
        {
            currentamountofgas += gas[i] - cost[i];
            if (currentamountofgas < 0) 
            {
                s = i + 1;
                currentamountofgas = 0;
            }
        }
        return s;
    }
};