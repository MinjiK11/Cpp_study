#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        /* 생성자 사용
        Point(int x, int y){
            xpos=x;
            ypos=y;
        }
        */
        void Init(int x, int y){
            xpos=x;
            ypos=y;
        }
        void ShowPointInfo() const{
            cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
        }
};

class Circle{
    private:
        Point p;
        int radius;
    public:
        /*생성자 사용
        Circle(int r, int x, int y):p(x,y){
            radius=r;
        }
        */
        void CircleInit(int r, int x, int y){
            p.Init(x,y);
            radius=r;
        }
        void circleInfo(){
            cout<<"radius: "<<radius<<endl;
            p.ShowPointInfo();
        }
};

class Ring{
    private:
        Circle inner, outer;
    public:
        /* 생성자 사용
        Ring(int inner_x,int inner_y, int inner_r, int outer_x,int outer_y, int outer_r)
        :inner(inner_r,inner_x,inner_y), outer(outer_r,outer_x,outer_y){}
        */
        void Init(int inner_x,int inner_y, int inner_r, int outer_x,int outer_y, int outer_r){
            inner.CircleInit(inner_r,inner_x,inner_y);
            outer.CircleInit(outer_r,outer_x,outer_y);
        }
        void ShowRingInfo(){
            cout<<"Inner Circle Info...\n";
            inner.circleInfo();
            cout<<"Outter Circle Info...\n";
            outer.circleInfo();
        }
};

int main(void){
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}