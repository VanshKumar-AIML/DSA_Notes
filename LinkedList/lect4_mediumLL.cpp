#include"ll.h"

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

ListNode* mid(ListNode* head) {
    if(!head || !head->next)
        return head;
    
    ListNode* s = head;
    ListNode* f = head;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

bool isp(ListNode* head) {
    if(!head || !head->next)
        return true;
    
    ListNode* m = mid(head);
    ListNode* rm = reversell(m);
    while(rm) {
        if(rm->val != head->val)
            return false;
        rm = rm->next;
        head = head->next;
    }
    return true;    
}

ListNode* brute_add1(ListNode* head) {
    head = reversell(head);
    ListNode* t = head;
    int carry = 1;
    while(t) {
        t->val = t->val + carry;
        if(t->val < 10) {
            carry = 0;
            break;
        }
        else {
            t->val = 0;
            carry = 1;
        }
        t = t->next;
    }

    if(carry == 1) {
        ListNode* nh = new ListNode(1);
        head = reversell(head);
        nh->next = head;
        return nh;
    }
    head = reversell(head);
    return head;
}

int helper(ListNode* t) {
    if(!t) 
        return 1;
    int carry = helper(t->next);

    t->val = t->val + carry;
    if(t->val < 10)
        return 0;
    t->val = 0;
    return 1;
}

ListNode* optimal_add1(ListNode* head) {
    int carry = helper(head);
    if(carry == 1) {
        ListNode* nh = new ListNode(1);
        nh->next = head;
        return nh;
    }
    return head;
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

    if(l1) 
        c->next = l1;
    else
        c->next = l2;

    return res->next;
}

int main() {
    ListNode* h1 = inputll({1,2,3});
    ListNode* h2 = inputll({4,5,6});
    ListNode* ans = merge(h1,h2);
    printll(ans);
    return 0;
}