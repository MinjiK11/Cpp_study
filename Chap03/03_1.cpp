//구조체 내에 함수 정의하기
#include <iostream>

using namespace std;

struct Point{
    int xpos;
    int ypos;

    void MovePos(int x, int y){
        xpos=xpos+x;
        ypos=ypos+y;
    }

    void AddPoint(const Point &pos){
        xpos=pos.xpos+xpos;
        ypos=pos.ypos+ypos;
    }

    void ShowPosition(){
        cout<<'['<<xpos<<" ,"<<ypos<<"]\n";
    }
};

int main(void){
    Point pos1={12,4};
    Point pos2={20,30};

    pos1.MovePos(-7,10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();

    return 0;
}