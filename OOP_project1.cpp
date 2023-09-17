#include <iostream>

using namespace std;

typedef struct client{
    int account_num;
    string name;
    int left;
} client;

client c[100];
int acc_count=0;

//메뉴 출력
void print_menu(){
    cout<<"-----Menu------\n";
    cout<<"1. create account'\n";
    cout<<"2. deposit\n";
    cout<<"3. withdrawal\n";
    cout<<"4. print account detail\n";
    cout<<"5. finish\n";
}

//계좌 개설
void account_create(){
    cout<<"[create account]\n";
    cout<<"account ID: ";
    cin>>c[acc_count].account_num;
    cout<<"name: ";
    cin>>c[acc_count].name;
    cout<<"deposit: ";
    cin>>c[acc_count].left;
    cout<<'\n';

    acc_count++;
}

//입금
void deposit(){
    int aid, deposit;

    cout<<"[deposit]\n";
    cout<<"account ID: ";
    cin>>aid;
    cout<<"deposit: ";
    cin>>deposit;

    for(int i=0;i<acc_count;i++){
        if(c[i].account_num==aid){
            c[i].left+=deposit;
            cout<<"finish deposit\n\n";
            return;
        }
    }
    cout<<"Invalid ID\n\n";
}

//출금
void withdrawal(){
    int aid, withdrawal;

    cout<<"[withdrawal]\n";
    cout<<"account ID: ";
    cin>>aid;
    cout<<"withdrawal: ";
    cin>>withdrawal;

    for(int i=0;i<acc_count;i++){
        if(c[i].account_num==aid){
            if(c[i].left<withdrawal){
                cout<<"Transaciton rejected\n\n";
                return;
            }
            c[i].left-=withdrawal;
            cout<<"finish withdrawal\n\n";
            return;
        }
    }
    cout<<"Invalid ID\n\n";
  
}

// 전체 계좌 정보 출력
void print_accounts(){
    for(int i=0;i<acc_count;i++){
        cout<<"account ID: "<<c[i].account_num<<'\n';
        cout<<"name: "<<c[i].name<<'\n';
        cout<<"left: "<<c[i].left<<"\n\n";
    }
}

int main(){
    int choose;

    while(1){
        print_menu();
        cout<<"choice: ";
        cin>>choose;
        cout<<'\n';

        switch(choose){
            case 1:
                account_create();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdrawal();
                break;
            case 4:
                print_accounts();
                break;
            case 5:
                return 0;
            default:
                cout<<"Illegal selection"<<endl;
        }
        
    }
}