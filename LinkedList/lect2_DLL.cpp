#include "ll.h"
#include<stack>

Node* deletehead(Node* head) {
    if(!head)
        return nullptr;
    
    Node* c = head;
    head = head->next;

    if(head)
        head->prev = nullptr;
    
    delete c;
    return head;
}

Node* deletetail(Node* head) {
    if(!head) 
        return nullptr;
    if(!head->next) {
        delete head;
        return nullptr;
    }

    Node* c = head;
    while(c->next)
        c = c->next;

    c->prev->next = nullptr;
    delete c;
    return head;
}

Node* kth_delete(Node* head, int k) {
    if(!head)
        return nullptr;

    Node* c = head;
    int cnt = 0;
    while(c) {
        cnt++;
        if(cnt == k)
            break;
        c = c->next;
    }

    Node* b = c->prev;      // back
    Node* f = c->next;      // front

    if(!b && !f) {
        delete c;
        return nullptr;
    }
    else if(!b) 
        return deletehead(head);
    else if(!f) 
        return deletetail(head);
    
    b->next = f;
    f->prev = b;
    c->next = nullptr;
    c->prev = nullptr;
    delete c;
    return head;
}

Node* kth_insert(Node* head,int k,int value) {
    Node* n = new Node(value);
    if(k <= 1) {
        n->next = head;
        if(head)
            head->prev = n;
        return n;
    }

    Node* c = head;
    int cnt = 1;
    while(c && cnt<k) {
        c = c->next;
        cnt++;
    }

    if(!c) {
        Node* t = head;
        if(!t)
            return n;
        while(t->next)
            t = t->next;
        t->next = n;
        n->prev = t;
        return head;
    }

    Node* pn = c->prev;
    n->next = c;
    n->prev = pn;
    if(pn)
        pn->next = n;
    c->prev = n;
    return head;
}
/*
Node* reverse_dll(Node* head) {      // By Stack -> O(2n)
    Node* c = head;
    stack<int> st;      // sc -> O(n)
    while(c) {          // O(n)
        st.push(c->val);
        c = c->next;
    }
    Node* t = head;
    while(t) {          // O(n)
        t->val = st.top();
        st.pop();
        t = t->next;
    }
    return head;
}
*/

Node* reverse_dll(Node* head) { // sc -> O(1)
    if(!head || !head->next)
        return head;

    Node* prev = nullptr;
    Node* c = head;
    while(c) {      // tc -> O(n)
        prev = c->prev;
        c->prev = c->next;
        c->next = prev;
        c = c->prev;
    }
    return prev->prev;
}

Node* deletekey(Node* head, int key) {
    Node* c = head;
    while(c) {
        if(c->val == key) {
            if(c == head)
                head = head->next;
            Node* next = c->next;
            Node* prev = c->prev;
            if(next)
                next->prev = prev;
            if(prev)
                prev->next = next;
            free(c);
            c = next;
        }
        else
            c = c->next;
    }
    return head;
}

Node* f_tail(Node* head) {
    Node* c = head;
    while(c->next)
        c = c->next;
    return c;
}

vector<pair<int,int>> findpairs(Node* head,int k) {     // sorted doubly linked list
    vector<pair<int,int>> ans;
    if(!head)
        return ans;

    Node* left = head;
    Node* right = f_tail(head);

    while(left->val < right->val) {         // two pointer approach
        if(left->val+right->val == k) {
            ans.push_back({left->val,right->val});
            left = left->next;
            right = right->prev;
        }
        else if(left->val+right->val < k)
            left = left->next;
        else
            right = right->prev;
    }

    return ans;
}

Node* deleteduplicate(Node* head) {
    Node* c = head;
    while(c && c->next) {
        Node* nh = c->next;
        while(nh  && nh->val == c->val) {
            Node* d = nh;
            nh = nh->next;
            free(d);
        }
        c->next = nh;
        if(nh)
            nh->prev = c;

        c = c->next;
    }
    return head;
}

int main() {
    vector<int> v = {1,2,3,4,5};
    /*
    Node* dh = inputdll(v);
    printdll(dh);
    cout << endl;

    Node* hr = kth_delete(dh,2);
    printdll(hr);
    cout << endl;

    Node* hi = kth_insert(dh,2,2);
    printdll(hi);
    cout << endl;

    Node* r = reverse_dll(hi);
    printdll(r);
    cout << endl;
    
    Node* dh = inputdll({10,4,10,10,6,10});
    Node* res = deletekey(dh,10);
    printdll(res);
    cout << endl;
    
    Node* h = inputdll({1,1,1,2,2,3,3,3,4,4});
    Node* dh = deleteduplicate(h);
    printdll(dh);
    cout << endl;
    */
    return 0;
}