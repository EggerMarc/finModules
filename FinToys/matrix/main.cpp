#include "stack.cpp"

int call_stack() {
    class Stack init_stack;
    //init_stack.push(5);
    init_stack.push(15);
    // Overflow below:
    init_stack.push(10);
    std::cout << init_stack.peek() << std::endl;
    std::cout << init_stack.pop() << ", now peek: " << init_stack.peek();
    std::cout << "\nIs empty? "<< init_stack.isempty() << std::endl;
    return 0;
}

int main() {
    call_stack();
}