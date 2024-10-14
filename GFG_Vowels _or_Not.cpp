#problem link : https://www.geeksforgeeks.org/problems/vowel-or-not0831/1

class Solution{
    String isVowel(char c){
        // code here
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return "YES";
        }else{
            return "NO";
        }
    }
}
