// 구조체에 대한 new & delete 연산

#include <iostream>

using namespace std;

typedef struct ___Point{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point *result=new Point;

    result->xpos=p1.xpos+p2.xpos;
    result->ypos=p1.ypos+p2.ypos;

    return *result;
}

int main(){
    Point * dot1=new Point;
    dot1->xpos=3;
    dot1->ypos=4;

    Point * dot2=new Point;
    dot2->xpos=5;
    dot2->ypos=2;

    Point * result=new Point;
    *result=PntAdder(*dot1,*dot2);
    
    cout<<result->xpos<<' '<<result->ypos;

    delete dot1;
    delete dot2;
    delete result;
}