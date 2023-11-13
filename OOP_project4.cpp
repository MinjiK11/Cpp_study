#include <iostream>
#include <cstring>

using namespace std;

class client{
    private:
        int account_num;
        char * name;
        int left;

    public:
        client(){}
        client(int account_num,char * name, int left){
            this->account_num=account_num;
            this->left=left;
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
        }
        
        client(const client& copy)
            :account_num(copy.account_num), left(copy.left){
            name=new char[strlen(copy.name)+1];
            strcpy(name,copy.name);
        }

        //계좌 번호 return
        int GetID() const{
            return account_num;
        }
        
        //입금
        void deposit(int money){
            left+=money;
        }

        //출금
        int withdrawal(int money){
            if(left<money){
                return 0;
            }
            left-=money;
            return money;
        }

        //계좌 정보 출력
        void printAccount() const{
            cout<<"account ID: "<<account_num<<'\n';
            cout<<"name: "<<name<<'\n';
            cout<<"left: "<<left<<"\n\n";
        }

        //소멸자
        ~client() {
            delete [] name;
        }

};


client * carr[100]; //객체 포인터 배열
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
    int account_num, left;
    char * name;
    cout<<"[create account]\n";
    cout<<"account ID: ";
    cin>>account_num;
    cout<<"name: ";
    cin>>name;
    cout<<"deposit: ";
    cin>>left;
    cout<<'\n';

    carr[acc_count]=new client(account_num, name, left);

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
        if(carr[i]->GetID()==aid){
            carr[i]->deposit(deposit);
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
        if(carr[i]->GetID()==aid){
            if(carr[i]->withdrawal(withdrawal)==0){
                cout<<"Transaction rejected\n";
                return;
            }
            cout<<"finish withdrawal\n\n";
            return;
        }
    }
    cout<<"Invalid ID\n\n";
  
}

// 전체 계좌 정보 출력
void print_accounts(){
    for(int i=0;i<acc_count;i++){
        carr[i]->printAccount();
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