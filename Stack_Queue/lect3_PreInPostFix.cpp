#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int priority(char ch) {
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(string s) {
    int i=0;
    string ans = "";
    stack<char> st;

    while(i < s.length()) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
                i++;
            }
        else if(s[i] == '(') { 
            st.push(s[i]);
            i++;
        }
        else if(s[i] == ')') { 
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
            i++;
        }
        else {
            while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string InfixToPrefix(string s) {
    reverse(s.begin(), s.end());

    int i=0;
    string ans = "";
    stack<char> st;

    while(i < s.length()) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
                i++;
            }
        else if(s[i] == '(') { 
            st.push(s[i]);
            i++;
        }
        else if(s[i] == ')') { 
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
            i++;
        }
        else {
            if(s[i] == '^') {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else {
                while(!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string PostfixToInfix(string s) {
    stack<string> st;
    int i=0;

    while(i < s.length()) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            string s1 = "";
            s1 += s[i];
            st.push(s1);
        }
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string con = '(' + t2 + s[i] + t1 + ')';
            st.push(con);
        }
        i++;
    }

    return st.top();
}

string PrefixToInfix(string s) {
    stack<string> st;

    for(int i=s.length()-1; i >= 0; i--) {
        if(isalnum(s[i]))
            st.push(string(1,s[i]));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = '(' + op1 + " " + s[i] + " " + op2 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

string PostfixToPrefix(string s) {
    stack<string> st;

    for(int i=0; i<s.length(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] == 'Z') || (s[i] >= '0' && s[i] <= '9'))
            st.push(string(1,s[i]));
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push(s[i] + t2 + t1);
        }
    }

    return st.top();
}

string PrefixToPostfix(string s) {
    stack<string> st;

    for(int i=s.length(); i>=0; i--) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] == 'Z') || (s[i] >= '0' && s[i] <= '9'))
            st.push(string(1,s[i]));
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            st.push(t1+t2+s[i]);
        }
    }

    return st.top();
}

int main() {
    string str = "1+2*(5-6)+6/2";
    string s1 = InfixToPostfix(str);
    cout << s1 << endl;
    cout << PostfixToInfix(s1);
    return 0;
}