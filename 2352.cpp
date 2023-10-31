class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> dic_row;
        for(vector<int> row : grid)
        {
            dic_row[row] ++;
        } 

        map<vector<int>, int> dic_col;
        for(int i=0;i<grid[0].size();i++)
        {
            vector<int> col;
            for(int j=0;j<grid.size();j++)
            {
                col.push_back(grid[j][i]);
            }
            dic_col[col] ++;
        }   
        int ans = 0;
        for(auto [key1, value1] : dic_row)
        {
            for(auto [key2, value2] : dic_col)
            {
                if(key1==key2)
                    ans += value1 * value2;
            }
        }   
        return ans;    
        }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // C++ map can take vectors as keys
        // However, map instead of unordered_map has O(log n)
        // operations, but it is still much faster than O(n)
        map<vector<int>, int> dic;
        for (vector<int> row: grid) {
            dic[row]++;
        }
        
        map<vector<int>, int> dic2;
        for (int col = 0; col < grid[0].size(); col++) {
            vector<int> currentCol;
            for (int row = 0; row < grid.size(); row++) {
                currentCol.push_back(grid[row][col]);
            }
            
            dic2[currentCol]++;
        }
        
        int ans = 0;
        for (auto [arr, val]: dic) {
            ans += val * dic2[arr];
        }
        
        return ans;
    }
};