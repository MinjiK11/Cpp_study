//참조자 기반의 call-by reference

#include <iostream>

using namespace std;

void increase(int &ref){
    ref++;
}

void change_sign(int &ref){
    ref=-ref;
}

int main(){
    int num=3;

    increase(num);
    cout<<num<<'\n';
    change_sign(num);
    cout<<num<<'\n';
}

//문제 3
void SwapPointer(int *(&pref1), int *(&pref2)){
    int *temp = pref1;
    pref1=pref2;
    pref2=temp;
}
