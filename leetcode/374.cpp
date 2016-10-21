// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int large = 0;
    int small = 1;
    int flag = 0;
    int guessNumber(int n) {
        if(flag == 0) {
            large = n;
            int temp = guess(1 + (n - 1) / 2);
            if(temp == 0) {
                return (n + 1) / 2;
            } else if(temp == 1) {
                small = (n + 1) / 2;
                flag = 1;
                return guessNumber(small + (large - small) / 2);
            } else {
                large = (n + 1) / 2;
                flag = 1;
                return guessNumber(small + (large - small) / 2);
            }
        } else {
            if(guess(small) == 0) {
                return small;
            }
            if (guess(large) == 0) {
                return large;
            }
            int temp = guess(n);
            if(temp == 0) {
                return n;
            } else if (temp == 1) {
                small = n;
                return guessNumber(small + (large - small) / 2);
            } else {
                large = n;
                return guessNumber(small + (large - small) / 2);
            }
        }
    }
};
