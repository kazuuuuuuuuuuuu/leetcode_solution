class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) 
    {
        long long curr = 0;
        int i = 1;
        vector<long long> ans;

        if(finalSum%2!=0)
            return ans;

        while(1)
        {
            long long num = i *2;
            i ++;
            curr += num;
            ans.push_back(num);
            if(curr>finalSum)
            {
                curr -= num;
                ans.pop_back();
                break;
            }
        }    

        long long residue = finalSum - curr;
        ans[ans.size()-1] += residue;
        return ans;
    }
};