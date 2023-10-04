#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS{
    enum{CLERK, SENIOR, ASSIST, MANAGER};

    void showPosition(int pos){
        switch(pos){
                case 0:
                    cout<<"Clerk\n\n";
                    break;
                case 1:
                    cout<<"Senior\n\n";
                    break;
                case 2:
                    cout<<"Assist\n\n";
                    break;
                case 3:
                    cout<<"Manager\n\n";
                    break;
        }
    }
};

class NameCard{
    private:
        char * name;
        char * coName;
        char * phoneNum;
        int position;
    public:
        NameCard(char * name, char * coName, char * phoneNum, int position){
            // 메모리 동적 할당
            this->name=new char[strlen(name)+1];
            this->coName=new char[strlen(coName)+1];
            this->phoneNum=new char[strlen(phoneNum)+1];
            this->position=position;
            strcpy(this->name,name);
            strcpy(this->coName,coName);
            strcpy(this->phoneNum,phoneNum);
        }

        void ShowNameCardInfo(){
            string pos;
            cout<<"Name: "<<name<<endl;
            cout<<"Company: "<<coName<<endl;
            cout<<"Phone Number: "<<phoneNum<<endl;
            cout<<"Position: ";
            COMP_POS::showPosition(position);
        }
        //소멸자
        ~NameCard(){
            delete [] name;
            delete [] coName;
            delete [] phoneNum;
        }
};

int main(){
    NameCard manClerk("Lee","ABCEng","010-1111-2222",COMP_POS::CLERK);
    NameCard manSenior("Hong","OrangeEng","010-3333-4444",COMP_POS::SENIOR);
    NameCard manAssist("Kim","SoGoodComp","010-5555-6666",COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    
}