#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


#define MAX_SIZE 100 

class Stack {
private:
    int Begin; 
    int arr[MAX_SIZE]; 
public:
    Stack() { Begin = -1; } 
    bool push(int x); 
    int pop(); 
    int StackTop(); 
    bool isEmpty(); 
    bool isFull(); 
    void Display(); 
};


bool Stack::push(int x) {
    if (isFull()) {
        cout << "Error: stack overflow\n";
        return false;
    }
    arr[++Begin] = x;
    return true;
}


int Stack::pop() {
    if (isEmpty()) {
        cout << "Error: stack underflow\n";
        return -1;
    }
    return arr[Begin--];
}

// function to get the top element from the stack
int Stack::StackTop() {
    if (isEmpty()) {
        cout << "Error: stack underflow\n";
        return -1;
    }
    return arr[Begin];
}

// function to check if the stack is empty
bool Stack::isEmpty() {
    return Begin == -1;
}

// function to check if the stack is full
bool Stack::isFull() {
    return Begin == MAX_SIZE - 1;
}

// function to display elements in the stack
void Stack::Display() {
    if (isEmpty()) {
        cout << "Error: stack underflow\n";
        return;
    }
    cout << "Elements in the stack are: ";
    for (int i = Begin; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// sample usage
int main() {
    auto start_time = high_resolution_clock::now();
    Stack stack;
    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.Display();
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    stack.Display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);
    stack.Display();
    auto end_time = high_resolution_clock::now();
    auto execution_time = duration_cast<microseconds>(end_time - start_time);
    cout << "Execution time: " << execution_time.count() << " us" << endl;
    return 0;
}
