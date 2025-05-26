#include <stdio.h>
#include <stdlib.h>
void printHello(){
    printf("Hello, World!\n");
}

int* Add_1(int* a, int* b){
    int c = *a + *b;
    return (&c); // 编译器会在这里发出警报，但是不会报错
}

int* Add_2(int* a, int* b){
    int* c = (int*)malloc(sizeof(int)); // 使用 malloc 分配内存
    *c = *a + *b;
    return c; // 返回指向新分配内存的指针
}

int main(){
    int x = 5;
    int y = 10;
    int* ptr_1 = Add_1(&x, &y);
    printf("Sum of Add_1: %d\n", *ptr_1); // 这里是正常的
    int* ptr_2 = Add_2(&x, &y);
    printf("Sum of Add_2: %d\n", *ptr_2); // 这里是正常的
    printHello(); // 调用函数打印 "Hello, World!""
    // 注意，这个在运行时栈中会覆盖上一个函数的地址里的东西
    printf("Sum of Add_1: %d\n", *ptr_1); // 现在这里的值是未定义的
    printf("Sum of Add_2: %d\n", *ptr_2); // 这里是正常的
    return 0;
}