// 1 sort
// 2 iterate all asteroids

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
  		sort(asteroids.begin(), asteroids.end());

  		// int类型存储不够 
  		long curr = mass;
  		for(int asteroid : asteroids)
  		{
  			if(asteroid>curr)
  				return false;

  			curr += asteroid
  		} 
  		return true;
    }
};