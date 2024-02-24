#include "push_swap.h"

void func(int *ptr) {
    *ptr = 10; // Modifies the value at the address pointed to by ptr
}

void func_with_address(int **ptr_ptr) {
    *ptr_ptr = malloc(sizeof(int)); // Modifies where the original pointer points to
    **ptr_ptr = 20; // Modifies the value at the address pointed to by the pointer at ptr_ptr
}

int main() {
    int a = 5;
    int *ptr = &a;

    func(ptr); // Passes a pointer, modifies the value of 'a'
    printf("%d\n", a); // Output will be 10

    // int *ptr_ptr = NULL;
    func_with_address(&ptr); // Passes the address of a pointer, modifies where 'ptr_ptr' points to
    printf("%d\n", *ptr); // Output will be 20
    printf("%d\n", a); // Output will be 10

    return 0;
}
