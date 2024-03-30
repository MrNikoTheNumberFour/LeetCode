class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0) return false;
        int dup = n;
        long revNum = 0;
        int lastDigit;
        while (n) {
            lastDigit = n % 10;
            n /= 10;
            revNum = (revNum * 10) + lastDigit;
        }
        return (dup==revNum);
    }
};