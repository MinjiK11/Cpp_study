#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y)
        {}
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        //부호 연산자 - 오버 로딩 - 멤버 함수 기반
        Point operator-(){
            Point pos(-xpos,-ypos);
            return pos;
        }

        friend Point operator~(const Point& ref);
};

//~연산자 오버로딩 (xpos,ypos)->(ypos,xpos) - 전역 함수 기반
Point operator~(const Point& ref){
    Point pos(ref.ypos,ref.xpos);
    return pos;
}

int main(){
    Point pos(1,2);
    Point pos2=-pos;
    Point pos3=~pos;

    pos.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
}
