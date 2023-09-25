// 클래스의 정의
#include <iostream>

using namespace std;

class Calculator{
    private:
        int add_cnt;
        int div_cnt;
        int min_cnt;
        int mul_cnt;
    public:
        void Init(){
            add_cnt=0;
            div_cnt=0;
            min_cnt=0;
            mul_cnt=0;
        }

        float Add(float n1, float n2){
            add_cnt++;
            return n1+n2;
        }
        float Div(float n1, float n2){
            div_cnt++;
            return n1/n2;
        }
        float Min(float n1, float n2){
            min_cnt++;
            return n1-n2;
        }
        float Mul(float n1, float n2){
            mul_cnt++;
            return n1*n2;
        }
        void ShowOpCount(){
            cout<<"Addition: "<<add_cnt<<" Minus: "<<min_cnt;
            cout<<" Multiplication: "<<mul_cnt<<" Division: "<<div_cnt<<'\n';
        }

};

int main(){
    Calculator cal;
    cal.Init();

    cout<<"3.2 + 2.4 = "<<cal.Add(3.2,2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5,1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9,1.2)<<endl;
    cal.ShowOpCount();

    return 0;
}