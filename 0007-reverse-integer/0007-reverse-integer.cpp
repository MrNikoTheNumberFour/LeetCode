class Solution {
public:
    int reverse(int n) {
        long revNum = 0;
        int lastDigit;
        while (n) {
            lastDigit = n % 10;
            n /= 10;
            revNum = (revNum * 10) + lastDigit;
        }
        if (revNum > INT_MAX || revNum < INT_MIN)
            return 0;
        return revNum;
    }
};