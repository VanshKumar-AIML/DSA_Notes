#include"ll.h"

ListNode* kth_insert(ListNode* head,int k,int val) {
    ListNode* ln = new ListNode(val);
    if(k == 1) {
        ln->next = head;
        return ln;
    }

    ListNode* c = head;
    int cnt = 1;
    while(c && cnt < k-1) {
        c = c->next;
        cnt++;
    }

    if(!c) {
        delete ln;
        return head;
    }

    ln->next = c->next;
    c->next = ln;
    return head;
}

ListNode* kth_delete(ListNode* head,int k) {
    if(k < 1) 
        return head;

    ListNode* c = head;
    int cnt = 1;
    while(c && cnt < k-1) {
        c = c->next;
        cnt++;
    }

    if(!c)
        return head;
    
    ListNode* d = c->next;
    c->next = d->next;
    delete d;
    return head;
}

int main() {
    vector<int> v = {1,2,3,4,5,6};
    ListNode* h = inputll(v);
    ListNode* nh = kth_insert(h,4,2);   // insert 2 at 4th position
    printll(nh);
    cout << endl;

    ListNode* h2 = kth_delete(h,4);     // delete from kth position
    printll(h2);
    cout << endl;
    return 0;
}