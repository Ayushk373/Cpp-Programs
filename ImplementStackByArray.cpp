#include <iostream>
using namespace std;

class MyStack {

public:
    int* arr;
    int top;
    int capacity;
    MyStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push element x onto stack
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    // Remove top element from stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int poppedElement = arr[top];
        top--;
        return poppedElement;
    }

    // Get the top element
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
    
    // Destructor to free memory
    ~MyStack() {
        delete[] arr;
    }
};

int main() {
    MyStack s(5);
    s.push(10);
    s.push(20);
    cout << "Top element is: " << s.peek() << "\n";
    cout << "Popped element is: " << s.pop() << "\n";
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    return 0;
}
