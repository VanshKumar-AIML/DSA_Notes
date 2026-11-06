#include "ll.h"

int getl(ListNode* head) {
    int n = 0;
    while(head) {
        n++;
        head = head->next;
    }
    return n;
}

ListNode* is_intersect(ListNode* l1,ListNode* l2) {
    int n1 = getl(l1);
    int n2 = getl(l2);
    int d = abs(n1-n2);

    if(n1 > n2) 
        while(d--)
            l1 = l1->next;
    else
        while(d--)
            l2 = l2->next;

    while(l1 && l2) {
        if(l1 == l2)
            return l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    return nullptr;
}

bool is_cycle(ListNode* head) {
    ListNode* s = head;
    ListNode* f = head;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;

        if(s == f)
            return true;
    }
    return false;
}

int len(ListNode* s,ListNode* f) {
    int cnt = 1;
    f = f->next;
    while(s != f) {
        cnt++;
        f = f->next;
    }
    return cnt;
}

int lengthofcycle(ListNode* head) {
    ListNode* s = head;
    ListNode* f = head;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;
        if(s == f)
            return len(s,f);
    }
    return 0;
}

ListNode* findfirstincycle(ListNode* head) {
    ListNode* s = head;
    ListNode* f = head;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;
        if(s == f) {
            s = head;       // move to head
            while(s != f) {
                s = s->next;
                f = f->next;
            }
            return s;
        }
    }
    return nullptr;
}

int main() { 
    ListNode* h1 = inputll({1,2,3,4,5,6,7,8,9});
    cout << lengthofcycle(h1);
    return 0;
}