// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

class Solution {
    private:
        bool isOperator(char c) {
            return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
        }
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        reverse(pre_exp.begin(), pre_exp.end()); 
        for (int i = 0; i < pre_exp.length(); i++) {
            char symbol = pre_exp[i];
            if (isalpha(symbol)) {
                string operand(1, symbol); 
                st.push(operand);
            }
            else if (isOperator(symbol)) {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();
                string infix = "(" + operand1 + symbol + operand2 + ")";
                st.push(infix);
            }
        }
        return st.top();
    }
};