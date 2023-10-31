
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // handle exceptional case
        if(find(deadends.begin(), deadends.end(), "0000")!=deadends.end())
            return -1;

        // using seen set and queue to traverse(bfs) all neighbours of the current node
        unordered_set<string> seen(deadends.begin(), deadends.end());
        queue<pair<string, int>> queue;
        queue.push(pair("0000", 0));
        seen.insert("0000");

        while(!queue.empty())
        {
            auto [curr, steps] = queue.front();
            queue.pop();

            if(curr==target)
                return steps;

            for(string neighbour : neighbours(curr))
            {
                if(seen.find(neighbour)==seen.end())
                {
                    seen.insert(neighbour);
                    queue.push(pair(neighbour, steps+1));
                }
            }    
        }
        return -1;
    }

    // find all neighbours
    vector<string> neighbours(string curr)
    {
        vector<string> ans;
        for(int i=0;i<4;i++)
        {
            int num = curr[i];
            for(int change : {-1, 1})
            {
                int new_num = (num - '0' + change + 10) % 10 + '0';
                string neighbour = curr;
                neighbour[i] = new_num;
                ans.push_back(neighbour);
            }
        }
        return ans;
    }
};