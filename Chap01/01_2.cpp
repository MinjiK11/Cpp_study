// 함수 오버로딩

#include <iostream>

using namespace std;

void swap(int* num1, int* num2){
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

void swap(char* ch1, char* ch2){
    int temp;
    temp=*ch1;
    *ch1=*ch2;
    *ch2=temp; 
}

void swap(double* dbl1, double* dbl2){
    int temp;
    temp=*dbl1;
    *dbl1=*dbl2;
    *dbl2=temp; 
}