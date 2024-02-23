class Solution {
public:
    struct TrieNode
    {
        vector<string> suggestions;
        unordered_map<char, TrieNode *> children;
        TrieNode():
        suggestions(vector<string>()), children(unordered_map<char, TrieNode *>())
        {}
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        TrieNode *root = new TrieNode();
        for(string product : products)
        {
            TrieNode *curr = root;
            for(char c : product)
            {
                if(curr->children.find(c)==curr->children.end())
                {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];

                curr->suggestions.push_back(product);
                sort(curr->suggestions.begin(), curr->suggestions.end());
                if(curr->suggestions.size()>3)
                {
                    curr->suggestions.pop_back();
                }
            }
        }

        TrieNode *curr = root;
        vector<vector<string>> ans;
        for(char c : searchWord)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                curr->children.clear();
                ans.push_back({});    
            }
            else
            {
                curr = curr->children[c];
                ans.push_back(curr->suggestions);            
            }
        }
        return ans;
    }
};