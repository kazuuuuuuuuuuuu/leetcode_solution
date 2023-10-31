class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        for(int num : arr)
        {
            frequency[num] ++;
        }
        unordered_set<int> unique;
        for(auto [key, value] : frequency)
        {
            if(unique.find(value)!=unique.end())
                return false;
            else
                unique.insert(value);
        }
        return true;
    }
};

// method2
// sort the frequency in the array first, then sort it and check if the adjacent freqs are equal
class Solution {
public:
    // Constant to make elements non-negative.
    static constexpr int K = 1000;
    
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2 * K  + 1);
    
        // Store the frequency of elements in the unordered map.
        for (int num : arr) {
            freq[num + K]++;
        }
        
        // Sort the frequency count.
        sort(freq.begin(), freq.end());
        
        // If the adjacent freq count is equal, then the freq count isn't unique.
        // 一共2*k+1 个元素 检查前2k个元素 是否和后一个相等即可
        for (int i = 0; i < 2 * K; i++) {
            if (freq[i] && freq[i] == freq[i + 1]) {
                return false;
            }
        }
        
        // If all the elements are traversed, it implies frequency counts are unique.
        return true;
    }
};

// method 3 using a set to check if all frequencies are unique, which means the size of set equals size of map
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Store the frequency of elements in the unordered map.
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Store the frequency count of elements in the unordered set.
        unordered_set<int> freqSet;
        for (auto [key, value] : freq) {
            freqSet.insert(value);
        }
        
        // If the set size is equal to the map size, 
        // It implies frequency counts are unique.
        return freqSet.size() == freq.size();
    }
};