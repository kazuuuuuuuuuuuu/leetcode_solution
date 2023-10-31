// two method my method
class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
    	int right = 0;
    	int left;
    	for(left=0;left<word.size();left++)
    	{
    		if(word[left]==ch)
    		{
    			while(right<left)
    			{
    				swap(word[right], word[left]);
    				right ++;
    				left --;
    			}
    			break;
    		}
    	}    
    	return word;
    }
};