class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total = 0;
        int start = 0;
        int curr = 0;
        for(int i=0;i<gas.size();i++)
        {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            cout << curr;
            if(curr<0)
            {
                curr = 0;
                start = i + 1;
            }
        }    

        if(total<0)
            return -1;

        return start;
    }
};