//Problem Link:https://leetcode.com/problems/roman-to-integer/description/

import java.util.*;
public class LT_Roman_to_Integer
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the roman number");
        String inp=sc.next();
        LT_Roman_to_Integer ob=new LT_Roman_to_Integer();
        System.out.println("Integer is : "+ob.romanToInt(inp));
        sc.close();
        
    }
    public int romanToInt(String s) {
         int ans = 0, num = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            switch(s.charAt(i)) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if (4 * num < ans) ans -= num;
            else ans += num;
        }
        return ans;
    }
}