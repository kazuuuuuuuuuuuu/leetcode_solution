class Solution
{
public:
	bool fun(string s, string t)
	{
		int i = 0;
		int j = 0;
		while(i<s.size()&&j<t.size())
		{
			if(s[i]==t[j])
				i ++;
			j ++;
		}
		return i == s.size();
	}
};