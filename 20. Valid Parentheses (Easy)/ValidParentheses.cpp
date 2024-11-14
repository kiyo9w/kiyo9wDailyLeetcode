//class Solution {
//public:
//    // using a stack to keep track of opening brackets and ensuring they match a closing one
//    bool isValid(string s) {
//        string st; // stack to keep track of opening brackets
//        map<char, char> mp; // map to define matching pairs
//        mp['('] = ')';
//        mp['{'] = '}';
//        mp['['] = ']';
//
//        st.push_back(s[0]); // push the first character onto the stack
//
//        for (int i = 1; i < s.size(); i++) {
//            // if the current character matches the expected closing bracket, pop from stack
//            if(mp[st.back()] == s[i])
//                st.pop_back(); // found a matching pair, remove the opening bracket
//            else
//                st.push_back(s[i]); // no match, push the current character onto the stack
//        }
//
//        return st.empty(); // if stack is empty then all matched, else false
//    }
//};

class Solution {
public:
    // initially thought using a stack would be straightforward, then got a lot of run time error
    bool isValid(string s) {
        string st; // stack to keep track of opening brackets

        for(char c : s){
            // if it's an opening bracket, push the expected closing bracket
            if(c == '('){
                st.push_back(')');
            }
            else if(c == '{'){
                st.push_back('}');
            }
            else if(c == '['){
                st.push_back(']');
            }
            else{
                // if stack is empty or the top doesn't match, it's invalid
                if(st.empty() || st.back() != c){
                    return false;
                }
                st.pop_back(); // found a matching pair, remove the matching closing bracket
            }
        }

        return st.empty(); // if stack is empty then all matched, else false
    }
};
