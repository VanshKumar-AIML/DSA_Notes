#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {           // structure of linked list
    public : 
    int val;
    ListNode* next;

    public:
    ListNode(int val1,ListNode* next1) {
        val = val1;
        next = next1;
    }
    ListNode(int val1) {
        val = val1;
        next = nullptr;
    }
};

inline void printll(ListNode* head) {          // print linked list
    if(!head) {
        cout << "NULL";
        return ; 
    }
    cout << head->val << " -> ";
    printll(head->next);
}

inline ListNode* inputll(const vector<int> &arr) {       // linked list input from vector
    ListNode* c = new ListNode(0);
    ListNode* h = c; 
    for(int i=0; i<arr.size(); i++) {
        c->next = new ListNode(arr[i]);
        c = c->next;
    }
    return h->next;
}

struct Node {       // structure of doubly linked list
    public:
    int val;
    Node* next;
    Node* prev;
    public:
    Node(int val1,Node* prev1,Node* next1) {
        val = val1;
        prev = prev1;
        next = next1;
    }
    Node(int val1) {
        val = val1;
        prev = nullptr;
        next = nullptr;
    }
};

inline Node* inputdll(vector<int> arr) {        // input from vector
    Node* h = new Node(arr[0]);
    Node* p = h;
    for(int i=1; i<arr.size(); i++) {
        Node* t = new Node(arr[i],p,nullptr);
        p->next = t;
        p = t;
    }
    return h;
}

inline void printdll(Node* head) {          // output
    if(!head) {
        cout << "NULL";
        return ;
    }
    cout << head->val << " <-> ";
    printdll(head->next);
}