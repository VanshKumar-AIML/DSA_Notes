#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

// Array implementation
class myst {
    int top = -1;
    int st[10];
    void push(int x) {
        if(top < 10) {
            st[top] = x;
            top++;
        }
        else 
            cout << "Overflow";
    }

    int top() {
        if(top == -1)
            return -1;
        return st[top];
    }

    void pop() {
        if(top == -1)
            return ;
        top = top-1;
    }

    int size() {
        return top+1;
    }
};

class myq {
    int cs = 0;     // current size 
    static constexpr int size = 10;
    int q[size];
    int st = -1, end = -1;
    void push(int x) {
        if(cs == size)
            return ;
        if(cs == 0) {
            st=0;
            end=0;
        }
        else
            end = (end+1)%size;

        q[end] = x, cs += 1;
    }

    int top() {
        if(cs == 0)
            return -1;
        return q[st];
    }

    int pop() {
        if(cs == 0)
            return ;
        end = q[st];
        if(cs == 1) {
            st = -1; 
            end = -1;
        }
        else
            st = (st+1)%size;
        cs -= 1;
        return end;
    }

    int size() {
        return cs;
    }
};

// Linked list implementation

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class mystll {
    Node* top;
    mystll (): top(nullptr) {};

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!top) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

class myqll {
    Node* front;
    Node* rear;
    myqll() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Dequeued: " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr; 
        delete temp;
    }

    int peek() {
        if (!front) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Implement stack using queue

class mystq {
    queue<int> q;

    void push(int x) {
        q.push(x);

        for(int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int size() {
        return q.size();
    }

    int top() {
        return q.front();
    }
};

// Implement queue using stack

class myqst {
    stack<int> s1,s2;

    void push(int x) {
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int size() {
        return s1.size();
    }
};

class minStack {
    stack<int> st;
    int mini = INT8_MAX;

    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else {
            if(val > mini)
                st.push(val);
            else {
                st.push(2*val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if(st.empty())
            return ;
        
        int x = st.top(); st.pop();

        if(x < mini) {
            mini = 2*mini - x;
        }
    }

    int getmin() {
        return mini;
    }

    int top() {
        if(st.empty())
            return -1;
        
        int x = st.top();
        if(mini < x)
            return x;
        
        return mini;
    }
};

int main() {
    stack<int> st;
    return 0;
}