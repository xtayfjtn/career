/**1
*** Time Limit Exceeded
***Last executed input:
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopq
**/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> substr;
        int maxlenth = 0;
        int lenth = s.length();
        for(int i = 0; i < lenth; i++)
        {
            substr.clear();
            int templenth = 0;
            for(int j = i; j < lenth; j++)
            {
                if(substr.count(s[j]) != 1)
                {
                    substr.insert(s[j]);
                    templenth++;
                } else
                {
                    break;
                }
            }
            if(templenth >= maxlenth)
            {
                maxlenth = templenth;
            }
        }
        return maxlenth;
    }
};
