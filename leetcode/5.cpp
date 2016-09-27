/**
1 time limit ex
**/
class Solution {
public:

    bool isPalindrome(string s)
    {
        for(int i = 0; i < s.length() / 2; i++)
        {
            if(s[i] != s[s.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string s_temp = "";
        string s_result = "";
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j < s.length(); j++)
            {
               s_temp += s[j];
                if(isPalindrome(s_temp))
                {
                    //result = result > s_temp.length()?result:s_temp.length();
                    s_result = result > s_temp.length()?s_result:s_temp;
                    result = s_result.length();
                }
            }
            s_temp = "";
        }
        return s_result;
    }
};

/**
2
**/
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int longestBegin = 0;
        int maxlen = 1;
        bool p[1000][1000] = {false};
        for(int i = 0; i < n; i++)
        {
            p[i][i] = true;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i + 1])
            {
                p[i][i + 1] = true;
                longestBegin = i;
                 maxlen = 2;
            }
        }

        for(int len = 3; len <= n; len++)
        {
            for(int i = 0; i < n - len + 1; i++)
            {
                int j = len + i -1;
                if(s[i] == s[j] && p[i + 1][j - 1])
                {
                    p[i][j] = true;
                    longestBegin = i;
                    maxlen = len;
                }
            }
        }

        return s.substr(longestBegin, maxlen);
    }
};
