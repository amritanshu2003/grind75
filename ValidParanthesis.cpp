class Solution {
public:
/*
"([])"
Traverse through the string.
if the char is open braces of type eg (, [, {
then insert it into the stack
if the char is closing braces of the type eg: }, ], )
then get the top element from the stack
compare it with the current element if matches the pair then remove it & continue
otherwise return invalid paranthesis
check the size of the stack at the end it should be empty
if its not then also return invalid paranthesis

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Complexity: O(n) time & O(n) space required to store all the char in stack
*/
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        std::stack<char> stk;
        for(int i=0; i<s.size();++i){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                stk.push(ch);
            } else if(ch == ')' || ch == '}' || ch == ']'){
                if(stk.empty()){
                    return false;
                }
                char op = stk.top(); stk.pop();
                if(ch == ')' && op != '('){
                    return false;
                }
                if(ch == '}' && op != '{'){
                    return false;
                }
                if(ch == ']' && op != '['){
                    return false;
                }
            }
            
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};
