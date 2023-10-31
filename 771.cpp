class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> count;
        for(char a : stones)
        {
            count[a] ++;
        }      
        
        unordered_set<char> jew(jewels.begin(), jewels.end());

        int num = 0;
        for(auto [key, value] : count)
        {
            if(jew.find(key)!=jew.end())
                num += value;
        }
        return num;

    }
};