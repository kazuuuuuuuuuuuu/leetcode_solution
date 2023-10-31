// 这道题利用数字的有限数量 -》 一共十个数字
// 分前部分和后部分
// 反转后半部分
class Solution {
public:
string largestPalindromic(string num)
{
    vector<int> count(10, 0);
    for(char a : num)
        count[a-'0'] ++;

    string front, back;

    for(int j=9;j>=0;j--)
    {
        while(count[j]>=2&&(j!=0||front.size()!=0))
        {
            front += '0' + j;
            back += '0' + j;
            count[j] -= 2;
        }
    }

    for(int j=9;j>=0;j--)
    {
        if(count[j]>0)
        {
            front += '0' + j;
            break;
        }
    }

    reverse(back.begin(), back.end());

    return front + back;
}
};