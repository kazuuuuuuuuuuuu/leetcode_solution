// minimum steps -> bfs -> unordered_set and queue -> traverse all neighbours of a node
// using the level variable to count the steps or an additional variable
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> seen;
        queue<pair<string, int>> queue;

        seen.insert(startGene);
        queue.push(pair(startGene, 0));

        while(!queue.empty())
        {
            auto [curr, steps] = queue.front();
            queue.pop();

            if(curr==endGene)
                return steps;

            for(string s : bank)
            {
                if(seen.find(s)==seen.end()&&is_neighbour(curr, s))
                {
                    seen.insert(s);
                    queue.push(pair(s, steps+1));
                }
            }
        }
        return -1;
    }

    bool is_neighbour(string a, string b)
    {
        int n = a.size();
        int diff = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                diff ++;
        }
        return diff==1;
    }
};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> queue;
        unordered_set<string> seen;
        queue.push(start);
        seen.insert(start);
        
        int steps = 0;
        while (!queue.empty()) {
            int nodesInQueue = queue.size();
            
            for (int j = 0; j < nodesInQueue; j++) {
                string node = queue.front();
                queue.pop();

                if (node == end) {
                    return steps;
                }
                
                for (char c: "ACGT") {
                    for (int i = 0; i < node.size(); i++) {
                        string neighbor = node;
                        neighbor[i] = c;
                        if (!seen.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            queue.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};