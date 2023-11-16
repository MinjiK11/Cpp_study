#include <iostream>

using namespace std;

class Rectangle{
    private:
        int x;
        int y;
    public:
        Rectangle(){}
        Rectangle(int x_in, int y_in)
            : x(x_in),y(y_in){

        }
        int ShowAreaInfo(){
            cout<<"Area: "<<x*y<<endl;
        }
};

class Square : public Rectangle{
    private:
        int length;
    public:
        Square(int in)
            : Rectangle(in,in),length(in){

        }
        
};

int main(void){
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}