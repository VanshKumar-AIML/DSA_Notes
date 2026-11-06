#include "ll.h"
#include<cmath>

ListNode* add(ListNode* l1,ListNode* l2) {
    ListNode* d = new ListNode(0);
    ListNode* c = d;
    int carry = 0;
    while(l1 || l2) {
        int s = carry;
        if(l1) 
            s += l1->val;
        if(l2)
            s += l2->val;
        c->next = new ListNode(s%10);
        carry = s/10;
        c = c->next;

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }

    if(carry)
        c->next = new ListNode(carry);

    return d->next;
}

ListNode* odd_even(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* o = head;
    ListNode* e = head->next;
    ListNode* eh = e;

    while(e && e->next) {
        o->next = o->next->next;
        e->next = e->next->next;
        o = o->next;
        e = e->next;
    }

    o->next = eh;
    return head;
}

ListNode* sort012(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* l0 = new ListNode(-1);
    ListNode* l1 = new ListNode(-1);
    ListNode* l2 = new ListNode(-1);
    ListNode* t0 = l0,*t1 = l1, *t2 = l2;

    ListNode* c = head;
    while(c) {
        if(c->val == 0) {
            t0->next = c;
            t0 = t0->next;
        }
        else if(c->val == 1) {
            t1->next = c;
            t1 = t1->next;
        }
        else {
            t2->next = c;
            t2 = t2->next;
        }
        c = c->next;
    }

    t0->next = (l1->next) ? l1->next : l2->next;
    t1->next = l2->next;
    t2->next = nullptr;

    ListNode* ans = l0->next;
    delete l0;
    delete l1;
    delete l2;

    return ans;
}

int main() { /*
    vector<int> v = {1,2,3,4,5};
    ListNode* h = inputll(v);
    int k = 2;  
    ListNode* l1 = inputll({9,9,9});
    ListNode* l2 = inputll({9,9,9});
    ListNode* ans = add(l1,l2);
    printll(ans);   */
    ListNode* heo = inputll({1,2,3,4,5});
    ListNode* ans = odd_even(heo);
    printll(ans);
    cout << endl;

    ListNode* h = inputll({0,0,0,1,1,2,2,2});
    ListNode* hs = sort012(h);
    printll(hs);
    return 0;
}