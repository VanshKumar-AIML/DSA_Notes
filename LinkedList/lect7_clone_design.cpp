#include <iostream>
using namespace std;

struct ListNode {           // structure of linked list
    public : 
    int val;
    ListNode* next;
    ListNode* random;
    public:
    ListNode(int val1,ListNode* next1) {
        val = val1;
        next = next1;
        random = nullptr;
    }
    ListNode(int val1) {
        val = val1;
        next = nullptr;
        random = nullptr;
    }
};

ListNode* clone(ListNode* head) {
    ListNode* c = head;
    while(c) {      // inserting copy nodes
        ListNode* cn = new ListNode(c->val);        // copy node
        cn->next = c->next;
        c->next = cn;
        c = c->next->next;
    }

    c = head;
    while(c) {      // random connected
        ListNode* cn = c->next;     // random pointer
        if(c->random)
            cn->random = c->random;
        else
            cn->random = nullptr;
        c = c->next->next;
    }

    ListNode* d = new ListNode(-1);
    ListNode* res = d;
    c = head;
    while(c) {
        res->next = c->next;
        c = c->next->next;

        res = res->next;
        c = c->next; 
    }  
    return d->next;
}

struct Node {
    string val;
    Node* next;
    Node* back;
    Node() : val(0),next(nullptr),back(nullptr) {};
    Node(string x) : val(x), next(nullptr),back(nullptr) {};
    Node(string x,Node* n1,Node* b1) : val(x),next(n1),back(b1) {};
};

class Browser {
    Node* c;

    public:
    Browser(string &homepage) {
        c = new Node(homepage);
    }
    void visit(string &url) {
        Node* nh = new Node(url);
        c->next = nh;
        nh->back = c;
        c = nh;
    }
    string back(int steps) {
        while(steps) {
            if(c->back)
                c = c->back;
            else
                break;
            steps--;
        }
        return c->val;
    }
    string forward(int steps) {
        while(steps) {
            if(c->next)
                c = c->next;
            else
                break;
            steps--;
        }
        return c->val;
    }
};

int main() {

    return 0;
}