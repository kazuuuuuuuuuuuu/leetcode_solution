// solution by myself
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> record;
        unordered_set<int> win;
        for(auto match : matches)
        {
            win.insert(match[0]);
            record[match[1]] ++;
        }

        vector<int> lose_1;
        vector<int> lose_0;


        for(auto pair : record)
        {
            if(pair.second==1)
                lose_1.push_back(pair.first);
        }
        for(auto x : win)
        {
            if(record.find(x)==record.end())
                lose_0.push_back(x);
        }
        vector<vector<int> > ans;
        sort(lose_0.begin(), lose_0.end());
        sort(lose_1.begin(), lose_1.end());
        ans.push_back(lose_0);
        ans.push_back(lose_1);
        return ans;

    }
};

// using 3 set to track every player
vector<vector<int>> findWinners(vector<vector<int>>& matches)
{
    unordered_set<int> zero_loss;
    unordered_set<int> one_loss;
    unordered_set<int> more_losses;

    int winner;
    int loser;
    for(auto match : matches)
    {
        winner = match[0];
        loser = match[1];

        if((one_loss.find(winner)==one_loss.end())&&(more_losses.find(winner)==more_losses.end()))
            zero_loss.insert(winner);
        if(more_losses.find(loser)!=more_losses.end())
        {
            
        }
        else if(one_loss.find(loser)!=one_loss.end())
        {
            one_loss.erase(loser);
            more_losses.insert(loser);
        }
        else if(zero_loss.find(loser)!=zero_loss.end())
        {
            zero_loss.erase(loser);
            one_loss.insert(loser);
        }
        else
        {
            one_loss.insert(loser);
        }
    }
    vector<vector<int> > ans(2, vector<int>());
    ans[0].assign(zero_loss.begin(), zero_loss.end());
    ans[1].assign(one_loss.begin(), one_loss.end());
    sort(ans[0].begin(), ans[0].end());
    sort(ans[1].begin(), ans[1].end());
    return ans;
}

// map + set to solve this problem
vector<vector<int>> findWinners(vector<vector<int>>& matches)
{
    unordered_set<int> seen;
    unordered_map<int, int> losses;

    for(auto match : matches)
    {
        seen.insert(match[0]);
        seen.insert(match[1]);
        losses[match[1]] ++;
    }
    
    vector<int> lose_1;
    vector<int> lose_0;

    for(auto player : seen)
    {
        if(losses.find(player)==losses.end())
            lose_0.push_back(player);
        else if(losses[player]==1)
            lose_1.push_back(player);
    }
 
    vector<vector<int> > ans;
    sort(lose_0.begin(), lose_0.end());
    sort(lose_1.begin(), lose_1.end());
    ans.push_back(lose_0);
    ans.push_back(lose_1);
    return ans;
}

// using one hash map
vector<vector<int>> findWinners(vector<vector<int>>& matches)
{
    unordered_map<int, int> losses;
    for(auto match : matches)
    {
        int winner = match[0];
        int loser = match[1];
        if(losses.find(winner)==losses.end())
            losses[winner] = 0;
        losses[loser] ++;
    }

    vector<int> lose_1;
    vector<int> lose_0;

    for(auto pair : losses)
    {
        if(pair.second==0)
            lose_0.push_back(pair.first);
        else if(pair.second==1)
            lose_1.push_back(pair.first);
    }
 
    vector<vector<int> > ans;
    sort(lose_0.begin(), lose_0.end());
    sort(lose_1.begin(), lose_1.end());
    ans.push_back(lose_0);
    ans.push_back(lose_1);
    return ans;    
}

//using array to record the number of losses for each player
//need to map each player to a index within a specific range
vector<vector<int>> findWinners(vector<vector<int>>& matches)
{
    vector<int> losses(100001, -1);
    
    for(auto match : matches)
    {
        int winner = match[0];
        int loser = match[1];
        if(losses[winner]==-1)
            losses[winner] = 0;
        if(losses[loser]==-1)
            losses[loser] = 1;
        else
            losses[loser] ++;
    }

    vector<int> lose_1;
    vector<int> lose_0;

    for(int i=0;i<100001;i++)
    {
        if(losses[i]==0)
            lose_0.push_back(i);
        else if(losses[i]==1)
            lose_1.push_back(i);
    }
 
    vector<vector<int> > ans;
    ans.push_back(lose_0);
    ans.push_back(lose_1);
    return ans;  
}

   


  

 
