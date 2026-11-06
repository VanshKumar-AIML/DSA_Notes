#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> st;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '[' || str[i] == '{' || str[i] == '(')
            st.push(str[i]);

        else {
            if(st.empty())
                return false;

            char ch = st.top();
            st.pop();

            if((str[i] == ')' && ch != '(') ||
            (str[i] == '}' && ch != '{') ||
            (str[i] == ']' && ch != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string s = "{{{}}}";
    cout << isBalanced(s);
    return 0;
}