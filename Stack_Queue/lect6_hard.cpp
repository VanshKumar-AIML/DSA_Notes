#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

class stockspanner {
public:
    stack<pair<int,int>> st;
    stockspanner() {};

    int next(int p) {
        int cnt = 1;
        while(!st.empty() && st.top().first <= p) {
            cnt += st.top().first;
            st.pop();
        }
        st.push({p,cnt});
        return cnt;
    }
};

class LRUcache {
public:
    struct Node {
        int k;
        int val;
        Node* prev;
        Node* next;
        Node(int k1,int v1) : k(k1), val(v1), prev(nullptr), next(nullptr) {}
    };

    int c;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void addNode(Node* n) {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
    }

    void removehead(Node* n) {
        Node* pn = n->prev;
        Node* nn = n->next;
        pn->next = nn;
        nn->prev = pn;
    }

    void movetohead(Node* n) {
        removehead(n);
        addNode(n);
    }

    Node* poptail() {
        Node* r = tail->prev;
        removehead(r);
        return r;
    }

    public:
    LRUcache(int ci) {
        c = ci;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int k) {
        if(cache.count(k) == 0)
            return -1;
        
        Node* n = cache[k];
        movetohead(n);
        return n->val;
    }

    void put(int k,int v) {
        if(cache.count(k) > 0) {
            Node* n = cache[k];
            n->val = v;
            movetohead(n);
        }
        else {
            Node* nn = new Node(k,v);
            cache[k] = nn;
            addNode(nn);

            if(cache.size() > c) {
                Node* ln = poptail();
                cache.erase(ln->k);
                delete ln;
            }
        }
    }
};

// Sliding window maximum sum :
vector<int> f(vector<int> arr, int k) {
    vector<int> l;
    deque<int> dq;
    for(int i=0; i<arr.size(); i++) {
        if(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        
        dq.push_front(i);
        if(i >= k-1)
            l.push_back(arr[dq.front()]);
    }
    return l;
}

// Celebrity problem :
int find(vector<vector<int>> mat) {
    int t=0, d=mat.size()-1;

    while(t < d) {
        if(mat[t][d] == 1)
            t++;
        else if(mat[d][t] == 1)
            d--;
        else {
            t++;
            d--;
        }
    }

    if(t > d)
        return -1;
    for(int i=0; i<mat.size(); i++)
        if(i != t)
            if(mat[t][i] != 1 || mat[i][t] != 1)
                return -1;

    return t;
}



int main() {
    vector<int> i = {1,2,3,4,5};
    vector<int> ans = f(i,3);   
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}