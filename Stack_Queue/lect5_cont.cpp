#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// Aestroid collision :
vector<int> func(vector<int> arr) {
    stack<int> st;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > 0)  
            st.push(arr[i]);
        else {
            while(!st.empty() && st.top() > 0 && st.top() < abs(arr[i]))
                st.pop();
            if(!st.empty() && st.top() == abs(arr[i]))
                st.pop();
            else if(st.empty() || st.top() < 0)
                st.push(arr[i]);
        }   
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

// Trapping rainwater :
int tw(vector<int> arr) {
    int lm = 0, rm=0, ans=0;
    int l=0, r=arr.size()-1;

    while(l < r) {
        if(arr[l] <= arr[r]) {
            if(lm > arr[l])
                ans += lm-arr[l];
            else
                lm = arr[l];
            l++;
        }
        else {
            if(rm > arr[r])
                ans += rm-arr[r];
            else
                rm = arr[r];
            r--;
        }
    }

    return ans;
}

// Largest rantangle area : 
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            int top_height = heights[st.top()];  st.pop();
            int nse = i;
            int pse = (st.empty()) ? -1 : st.top();
            max_area = max(max_area, top_height*(nse-pse-1));
        }
        st.push(i);
    }

    while(!st.empty()) {
        int nse = heights.size();
        int ele = st.top(); st.pop();
        int pse = st.empty() ? -1 : st.top();

        max_area = max(max_area,(nse-pse-1)*heights[ele]);
    }
    return max_area;
}

// Maximal rectangle :
int maxr(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    int maxArea = 0;
    vector<vector<int>> ps(n, vector<int> (m,0));

    for(int j=0; j<m; j++) {
        int s = 0;
        for(int i=0; i<n; i++) {
            if(mat[i][j] == 0)
                s = 0;
            else
                s++;
            ps[i][j] = s;
        }
    }

    for(int i=0; i<n; i++)
        maxArea = max(maxArea, largestRectangleArea(ps[i]));

    return maxArea;
}

// Remove k digits :
string kd(string s, int k) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        while(!st.empty() && k>0 && (st.top()-'0') > (s[i] -'0')) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while(k>0) {
        st.pop();
        k--;
    }

    if(st.empty())
        return "0";
    
    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    while(ans.size() && ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());

    return ans.empty() ? "0" : ans;
}

int main() {
    vector<int> arr = {1,3,4,-5};
    vector<int> a = func(arr);

    for(int i=0; i<a.size(); i++)
        cout << a[i] << " ";

    vector<vector<int>> n1 = {{1,0,1,0,1},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout << maxr(n1);
    return 0;
}