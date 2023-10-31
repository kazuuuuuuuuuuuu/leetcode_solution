// using a map to record the original freqency and comparing it with the freqency of the substring
// without violating the frequency of the original string
// if the length reaches the right number, return true;
// otherwise return false

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> freq_1;
    for(char a : s1)
        freq_1[a] ++;
    unordered_map<char, int> freq_2;
    int right = 0, left = 0;
    int length = 0;
    while(right<s2.size())
    {
        int a = s2[right];
        freq_2[a] ++;
        length ++;
        if(freq_1.find(a)==freq_1.end())
        {
            length = 0;
            freq_2.clear();
            right = right + 1;
            left = right;
            continue;
        }
        else
        {
            while(freq_2[a]>freq_1[a])
            {
                length --;
                freq_2[s2[left]] --;
                left ++;
            }
        }
        if(length==s1.size())
            return true;
        right ++;
    }
    return false;
    }
};

// treaverse every subtring of s2 
// then sort and compare it with the s1 sorted
// equal return ture
// otherwise return false
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        s1 = sort(s1);
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (s1.equals(sort(s2.substring(i, i + s1.length()))))
                return true;
        }
        return false;
    }
    
    public String sort(String s) {
        char[] t = s.toCharArray();
        Arrays.sort(t);
        return new String(t);
    }
}

bool checkInclusion(string s1, string s2)
{
    string curr;
    sort(s1.begin(), s1.end());
    for(int i=0;i<=s2.size()-s1.size();i++)
    {
        curr = s2.substr(i, s1.size());
        sort(curr.begin(), curr.end());
        if(curr==s1)
            return true;
    }
    return false;
}

//method 3
// using array of length 26 to track the frequency of all characters
// every time the window slide, check if the array is the same by using a variable count to count the number of the character having the same frequency 
// if they are the same, return true
// finally, return the count == 26
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] s1map = new int[26];
        int[] s2map = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            s1map[s1.charAt(i) - 'a']++;
            s2map[s2.charAt(i) - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1map[i] == s2map[i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2.charAt(i + s1.length()) - 'a', l = s2.charAt(i) - 'a';
            if (count == 26)
                return true;
            s2map[r]++;
            if (s2map[r] == s1map[r]) {
                count++;
            } else if (s2map[r] == s1map[r] + 1) {
                count--;
            }
            s2map[l]--;
            if (s2map[l] == s1map[l]) {
                count++;
            } else if (s2map[l] == s1map[l] - 1) {
                count--;
            }
        }
        return count == 26;
    }
}