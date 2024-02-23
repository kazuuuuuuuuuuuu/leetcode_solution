class Trie {
public:
    struct TireNode
    {
        bool is_end;
        unordered_map<char, TireNode *> children;
        TireNode(): is_end(false), children(unordered_map<char, TireNode *>()) {}
    };

    TireNode *root;

    Trie() {
        root = new TireNode();
    }
    
    void insert(string word) {
        TireNode *curr = root;
        for(char c : word)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                curr->children[c] = new TireNode();
            }
            curr = curr->children[c];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        TireNode *curr = root;
        for(char c : word)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                return false;
            }
            else
            {
                curr = curr->children[c];
            }
        }
        if(curr->is_end)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        TireNode *curr = root;
        for(char c : prefix)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */