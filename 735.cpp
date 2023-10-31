// part of this solution is correct
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> ans;
        int i;
        for(i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
            {
                ans.push_back(asteroids[i]);
            }    
            else
                break;
        }
        while(!ans.empty()&&i<asteroids.size())
        {
            int right = ans.back();
            int left = asteroids[i];
            if(abs(right)>abs(left))
                i ++;
            else if(abs(right)<abs(left))
                ans.pop_back();
            else
            {
                i ++;
                ans.pop_back();
            }
        }
        while(i<asteroids.size())
        {
            ans.push_back(asteroids[i]);
            i ++;
        }
        return ans;
    }
};

//

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ans;
        // get the each asteroid
        for(int asteroid : asteroids)
        {
            // decide if it should be pushed
            if(ans.empty())
            {
                ans.push_back(asteroid);
            }
            else
            {
                // deal with collisions           
                while(!ans.empty()&&asteroid<0&&ans.back()>0)
                {
                    if(abs(asteroid)==abs(ans.back()))
                    {
                        ans.pop_back();
                        asteroid = 0;
                        break;
                    }    
                    else if(abs(asteroid)<abs(ans.back()))
                    {
                        asteroid = 0;
                        break;
                    }
                    else
                    {
                        ans.pop_back();
                    }
                }
                if(asteroid!=0)
                    ans.push_back(asteroid);                
            }
        }
        return ans;
    }
};


