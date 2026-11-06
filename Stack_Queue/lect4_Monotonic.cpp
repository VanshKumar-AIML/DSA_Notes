#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NGE(vector<int> arr) {          // next greater element
    vector<int> ans(arr.size());
    stack<int> st;

    for(int i=arr.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i])     // remove smaller elements
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return ans;
}

vector<int> findpge(vector<int> arr) {      // previous greater element
    vector<int> ans(arr.size());
    stack<int> st;

    for(int i=0; i<arr.size(); i++) {
        while(!st.empty() && st.top() <= arr[i])     // remove smaller elements
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();        
        st.push(arr[i]);
    }

    return ans;
}

vector<int> NGE2(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=2*n-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i%n])
            st.pop();

        if(i < n) 
            ans[i] = st.empty() ? -1 : st.top();

        st.push(arr[i%n]);
    }
    
    return ans;
}

vector<int> findnse(vector<int> arr) {      // next smallest element
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
        
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return ans;
}

vector<int> findpse(vector<int> arr) {      // previous smallest element
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
        
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return ans;
}

int sumMax(vector<int> arr) {       // maximum subarray sum
    vector<int> nge = NGE(arr);
    vector<int> pge = findpge(arr);

    long long ans = 0; 
    int mod = (int)(1e9+7);

    for(int i=0; i<arr.size(); i++) {
        int l = i-pge[i];
        int r = nge[i]-i;

        ans += ((1LL*r*l*arr[i])%mod)%mod;
    }

    return ans;
}

int sumMin(vector<int> arr) {       // minimum subarray sum
    vector<int> nse = findnse(arr);
    vector<int> pse = findpse(arr);

    long long ans = 0;
    int mod = (int)(1e9+7);

    for(int i=0; i<arr.size(); i++) {
        int l = i-pse[i];
        int r = nse[i]-i;

        ans += ((1LL*r*l*arr[i])%mod)%mod;
    }

    return ans;
}

int Sumranges(vector<int> arr) {
    return sumMax(arr) - sumMin(arr);
}

int main() {
    vector<int> v = {1,3,9,4,2};
    vector<int> a = NGE2(v);
    for(int i=0; i<a.size(); i++)
        cout << a[i] << " ";
    return 0;
}