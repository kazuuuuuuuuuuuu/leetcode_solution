class Solution {
public:
    string reverseWords(string s) 
    {
    	string ans = s;
    	int right = 0, left = 0;
    	char temp;
    	for(int i=0;i<ans.size();i++)
    	{
    		if(ans[i]==' ')
    		{
    			left = i - 1;
    			while(right<left)
    			{
    				temp = ans[right];
    				ans[right] = ans[left];
    				ans[left] = temp;
    				right ++;
    				left --;
    			}
    			right = i + 1;
    		}
    		if(i==ans.size()-1)
    		{
    			left = i;
      			while(right<left)
    			{
    				temp = ans[right];
    				ans[right] = ans[left];
    				ans[left] = temp;
    				right ++;
    				left --;
    			}
    		}
    	}  
    	return ans;  
    }
};
