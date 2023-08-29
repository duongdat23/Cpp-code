// 5.pointer_function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// đầu vào floata,b 
// đầu ra res = a op b 
// đầu vào op = 0 -> phép cộng
// đầu vào op = 1 -> phép trừ 
// đầu vào op = 2 -> phép nhân 

#include <iostream>

float add(float a, float b) {
    return a + b; 
}
float sub(float a, float b) {
    return a - b; 
}
float multi(float a, float b) {
    return a * b; 
}

float alu(float a, float b, int op) {
    float (*p_ptr_arr[])(float, float) = { add, sub , multi }; 
    printf("call function at the address %p\n ", p_ptr_arr[op]); 
    return (*p_ptr_arr[op])(a, b); 
        
}


int main()
{
 //   std::cout << "Hello World!\n";
    int choosen_op; 
    printf("Address of add = %p , sub = %p , multi = %p \n", add, sub, multi);
    while (1) {
        printf("ALU programe - enter the operation ( 0-add, 1-sub, 2-mult)");
        scanf("%d", &choosen_op); 
        if (choosen_op == 3) break; 
        printf("result = %f ", alu(10.1, 5.5, choosen_op)); 
    }


}

