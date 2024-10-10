// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

class Solution {
    private:
        int precedence(char c){
            if(c == '^') return 3;
            else if(c == '/' || c == '*') return 2;
            else if(c == '+' || c == '-') return 1;
            else return -1;
        }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string postfix;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                postfix += c;
            }
            else if (c == '('){
                st.push('(');
            }
            else if (c == ')'){
                while(st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{ // Operator
                while(!st.empty() && precedence(st.top()) >= precedence(c)){
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
};