//데이터 입출력

#include <iostream>

using namespace std;

int main(){
    int input;

    while(true){
        cout<<"sales price(-1 to end): ";
        cin>>input;
        if(input==-1)
            break;
        int output=50+input*0.12;
        cout<<"pay for this month: "<<output<<"man won\n";
    }
    cout<<"finish program";
}
