// method by myself 
// two pointer
class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int right = 0;
        int left = s.size() - 1;
        while(right<left)
        {
            while(right<left&&!isalpha(s[right]))
                right ++;
            while(right<left&&!isalpha(s[left]))
                left --;
            // two pinter find the right place and then swap them
            if(right<left)
            {
                char temp = s[right];
                s[right] = s[left];
                s[left] = temp;
                right ++;
                left --;
            }

        }
        return s;
    }
};

//method 2
// use stack
class Solution
{
public:
    string reverseOnlyLetters(string s) 
    {
        string ans;
        SeqStack<char> character;
        for(char a : s)
        {
            if(isalpha(a))
                character.push(a);
        }
        for(char a : s)
        {
            if(isalpha(a))
            {

                ans += character.top();
                character.pop();
            }
            else
                ans += a;
        }
        return ans;
    }
};

// very like the privious answer, just use a pointer 
// that iterated through the string backwards
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        string ans;
        int j = s.size() - 1;
        for(char a : s)
        {
            if(isalpha(a))
            {
                while(!isalpha(s[j]))
                    j -= 1;
                ans += s[j];
                j -= 1;
            }
            else
               ans += a; 
        }
        return ans;
    }
};