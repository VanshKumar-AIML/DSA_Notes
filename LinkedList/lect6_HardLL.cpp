#include "ll.h"
#include<algorithm>

int getl(ListNode* head) {
    ListNode* c = head;
    int cnt = 0;
    while(c) {
        cnt++;
        c = c->next;
    }
    return cnt;
}

ListNode* reversell(ListNode* head) {
    ListNode* c = head;
    ListNode* p = nullptr;
    while(c) {
        ListNode* nxt = c->next;
        c->next = p;
        p = c;
        c = nxt;
    }
    return p;
}

ListNode* reverse(ListNode* head, int left, int right) {
    if (!head || left == right) 
        return head;

    ListNode* d = new ListNode(0);
    d->next = head;
    ListNode* prev = d;

    for (int i=1; i<left; i++) 
        prev = prev->next;

    
    ListNode* c = prev->next;
    ListNode* p = nullptr;

    for (int i=0; i <= right-left; i++) {
        ListNode* nxt = c->next;            // reverse
        c->next = p;
        p = c;
        c = nxt;
    }

    prev->next->next = c;  
    prev->next = p;     

    return d->next;
}
/*                              
ListNode* reverseinKgrp(ListNode* head,int k) {     -> not optimal
    for(int i=1; i+k-1 <= getl(head); i+=k) 
        head = reverse(head,i,i+k-1);
    return head;
}

ListNode* rotate(ListNode* head,int k) {
    int n = getl(head);
    if(n == 0 || k%n == 0) 
        return head;

    k = k % n;
    head = reverse(head, 1, n-k);
    head = reverse(head, n-k+1, n);
    head = reverse(head, 1, n);
    return head;
}   
*/
ListNode* getKthNode(ListNode* c,int k) {
    k -= 1;
    while(c && k>0) {
        k--;
        c = c->next;
    }
    return c;
}

ListNode* Kreverse(ListNode* head,int k) {
    ListNode* c = head;
    ListNode* pl = nullptr;
    while(c) {
        ListNode* kthNode = getKthNode(c,k);
        if(!kthNode) {
            if(pl)
                pl->next = c;
            break;
        }

        ListNode* nxt = kthNode->next;
        kthNode->next = nullptr;
        reversell(c);

        if(c == head)
            head = kthNode;
        else
            pl->next = kthNode;

        pl = c;
        c = nxt;
    }
    return head;
}

ListNode* findNthnode(ListNode* head,int n) {
    ListNode* c = head;
    while(c && n) {
        n--;
        c = c->next;
    }
    return c;
}

ListNode* rotate(ListNode* head,int k) {
    if(!head || k == 0)
        return head;

    int len=1;
    ListNode* tail = head;
    while(tail->next) {
        tail = tail->next;
        len++;
    }
    if(k%len == 0)
        return head;

    k = k%len;
    tail->next = head;
    ListNode* nl = findNthnode(head,len-k-1);
    head = nl->next;        // new last node
    nl->next = nullptr;
    return head;
}
/*
struct Node {
    int val;
    Node* next;
    Node* child;
    Node(int val1) {
        val = val1;
        next = nullptr;
        child = nullptr;
    }
};

Node* merge(Node* l1,Node* l2) {
    Node* d = new Node(-1);
    Node* res = d;
    while(l1 && l2) {
        if(l1->val < l2->val) {
            res->child = l1;
            res = l1;
            l1 = l1->next;
        }
        else {
            res->child = l2;
            res = l2;
            l2 = l2->next;
        }
        res->next = nullptr;
    }

    if(l1)
        res->child = l1;
    else
        res->child = l2;

    return d->child;
}

Node* flatten(Node* head) {
    if(!head || !head->next)
        return head;

    Node* mh = flatten(head->next);
    return merge(head,mh);    
}
    */

ListNode* mergeKLists(vector<ListNode*>& lists) {       // brute force
    vector<int> arr;
    for(int i=0; i<lists.size(); i++) {
        ListNode* c = lists[i];
        while(c) {
            arr.push_back(c->val);
            c = c->next;
        }
    }
    sort(arr.begin(),arr.end());

    ListNode* res = inputll(arr);
    return res;
}

ListNode* merge(ListNode* l1,ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* c = res;
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            c->next = l1;
            l1 = l1->next;
        }
        else {
            c->next = l2;
            l2 = l2->next;
        }
        c = c->next;
    }

    c->next = (l1 ? l1 : l2);
    return res->next;
}

ListNode* mergek(vector<ListNode*>& lists) {
    ListNode* head = lists[0];
    for(int i=1; i<lists.size(); i++)
        head = merge(head,lists[i]);
    return head;
}

ListNode* findmid(ListNode* head) {
    ListNode* s = head;
    ListNode* f = head->next;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

ListNode* mergeSort(ListNode* head) {        // Merge sort algorithm 
    if(!head || !head->next)
        return head;

    ListNode* mid = findmid(head);
    ListNode* righth = mid->next;
    mid->next = nullptr;
    ListNode* lefth = head;

    lefth = mergeSort(lefth);
    righth = mergeSort(righth);

    return merge(lefth,righth);
}

int main() {
    /*
    ListNode* h = inputll({1,2,3,4,5,6,7,8,9});
    ListNode* res = rotate(h,3);
    printll(res);
    
    vector<ListNode*> lists = {inputll({1,2,3}),inputll({4,5,6}),inputll({2,3,4})};
    ListNode* ans = mergek(lists);
    printll(ans);
    
    ListNode* h = inputll({1,4,3,2,5});
    ListNode* ans = mergeSort(h);
    printll(ans);
    */
    return 0;
}