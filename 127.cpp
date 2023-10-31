// minimum steps -> bfs
// check whether an element exists -> a hash set

class Solution {
public:
    unordered_set<string> wordset;
    unordered_set<string> seen;
    

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        wordset = unordered_set<string>(wordList.begin(), wordList.end());
        seen.insert(beginWord);
        queue<string> queue;
        queue.push(beginWord);
        int level = 0;
        if(wordset.find(endWord)==wordset.end())
            return 0;

        while(!queue.empty())
        {
            int layer_num = queue.size();
            level ++;
            for(int i=0;i<layer_num;i++)
            {
                string curr = queue.front();
                queue.pop();
                if(curr==endWord)
                    return level;
                for(int j=0;j<curr.size();j++)
                {
                    for(int k=0;k<26;k++)
                    {
                        char a = 'a' + k;
                        string neighbour = curr;
                        neighbour[j] = a;
                        if(wordset.find(neighbour)!=wordset.end()&&seen.find(neighbour)==seen.end())
                        {
                            seen.insert(neighbour);
                            queue.push(neighbour);
                        }
                    }
                }               
            }
        } 
        return 0;  
    } 
};