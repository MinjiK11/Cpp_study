#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y)
        { }
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        //+= 연산자 오버로딩 - 멤버함수 기반
        Point& operator+=(const Point& ref){
            xpos+=ref.xpos;
            ypos+=ref.ypos;
            return *this;
        }
        //-= 연산자 오버로딩 - 멤버 함수 기반
        Point& operator-=(const Point& ref){
            xpos-=ref.xpos;
            ypos-=ref.ypos;
            return *this;
        }

        friend Point operator-(const Point &ref1, const Point &ref2);
        friend bool operator==(const Point &ref1, const Point &ref2);
        friend bool operator!=(const Point &ref1,const Point &ref2);
};

//- 연산자 오버로딩 - 전역 함수 기반
Point operator-(const Point &ref1, const Point &ref2){
    Point pos(ref1.xpos-ref2.xpos,ref1.ypos-ref2.ypos);
    return pos;
}

//==연산자 오버로딩 - 전역 함수 기반
bool operator==(const Point &ref1, const Point &ref2){
    if(ref1.xpos==ref2.xpos&&ref1.ypos==ref2.ypos)
        return true;
    else   
        return false;
}

//!=연산자 오버로딩(==연산자 오버로딩 이용) - 멤버 함수 기반
bool operator!=(const Point &ref1,const Point &ref2){
    if(ref1==ref2)
        return false;
    else   
        return true;
}

int main(){
    Point pos1(3,4);
    Point pos2(10,20);
    Point pos3=pos1-pos2;

    pos3.ShowPosition();
    cout<<(pos1==pos2)<<endl;
    cout<<(pos1!=pos2)<<endl;
}

