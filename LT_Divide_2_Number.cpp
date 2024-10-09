// https://leetcode.com/problems/divide-two-integers/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
        {
            return 1;
        }
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            sign = -1;
        }

        long ans = 0;
        long n = abs(dividend), d = abs(divisor);

        while (n >= d)
        {
            int cnt = 0;
            while (n > (d << (cnt + 1)))
            {
                cnt++;
            }
            n = n - (d << cnt);
            ans += (1 << cnt);
        }

        if ((ans == (1 << 31)) || (ans > (INT_MAX)))
        {
            if (sign == 1)
            {
                return INT_MAX;
            }
        }
        return sign * ans;
    }
};

int main()
{
    Solution a = Solution();
    int ans = a.divide(22, 3);
    // int ans = a.divide(-2147483648, -1);
    // int ans = a.divide(7, -3);
    // int ans = a.divide(10, 3);
    cout << "The answer is: " << ans << endl;
    return 1;
}