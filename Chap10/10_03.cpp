#include <iostream>

using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0):xpos(x),ypos(y)
        {}
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        friend istream& operator>>(istream& is,Point &ref);
        friend ostream& operator<<(ostream &os, Point& ref);
};

//<<연산자 오버로딩
ostream& operator<<(ostream& os, Point& ref){
    os<<'['<<ref.xpos<<", "<<ref.ypos<<']'<<endl;
    return os;
}

//>>연산자 오버로딩
istream& operator>>(istream& is, Point& ref){
    is>>ref.xpos;
    is>>ref.ypos;
    return is;
}

int main(){
    Point pos1;
    cout<<"x, y coordinate: ";
    cin>>pos1;
    cout<<pos1;

    Point pos2;
    cout<<"x, y coordinate: ";
    cin>>pos2;
    cout<<pos2;
}