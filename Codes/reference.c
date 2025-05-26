#include <stdio.h>
int Increment_1(int a){
    a = a + 1;
    return a;
}

void Increment_2(int* a){
    *a = *a + 1;
}

void Increment_3(int a){
    a = a + 1;
}

int main(){
    int a = 5;
    a = Increment_1(a);
    printf("Increment_1: %d\n", a);
    Increment_2(&a);
    printf("Increment_2: %d\n", a);
    Increment_3(a);
    printf("Increment_3: %d\n", a);
    return 0;
}