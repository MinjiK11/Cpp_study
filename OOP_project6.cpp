#include <iostream>
#include <cstring>

using namespace std;

//고객 신용 등급에 따른 추가 이율
namespace CREDIT_LEVEL{
    enum{
        LEVEL_A=7, LEVEL_B=4, LEVEL_C=2
    };
}

// Entity 클래스
// 계좌 정보 저장
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

        //입금 (가상함수)
        virtual void deposit(int money){
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

//보통예금계좌 - client 클래스 상속
class NormalAccount : public client{
    private:
        int interest;
    public:
        NormalAccount(int account_num,char * name, int left, int rate)
            :client(account_num,name,left),interest(rate){

        }

        virtual void deposit(int money){
            client::deposit(money);
            client::deposit(money*(interest/100.0));
        }
};

//신용신뢰계좌 - NormalAccount 클래스 상속
class HighCreditAccount : public NormalAccount{
    private:
        int special_inter;
    public:
        HighCreditAccount(int account_num,char *name, int left, int rate, int special)
            : NormalAccount(account_num,name,left,rate),special_inter(special){

        }

        virtual void deposit(int money){
            NormalAccount::deposit(money);
            client::deposit(money*(special_inter/100.0));
        }
};

//Control 클래스
// 계좌 개설, 입금, 출금, 계좌정보 전체 출력 기능 담당
// Control 클래스만 봐도 프로그램의 전체 기능과 흐름 파악 가능ㄴ
class ClientHandler{
    private:
        client * carr[100]; //객체 포인터 배열
        int clientNum;
    public:
        ClientHandler() : clientNum(0){}
        
        //메뉴 출력
        void print_menu(){
            cout<<"-----Menu------\n";
            cout<<"1. create account'\n";
            cout<<"2. deposit\n";
            cout<<"3. withdrawal\n";
            cout<<"4. print account detail\n";
            cout<<"5. finish\n";
        }

        void account_create(){
            cout<<"[select account type]\n";
            cout<<"1. Normal account 2. High Credit account\n";
            int sel;
            cout<<"choice: ";
            cin>>sel;

            if(sel==1)
                MakeNormalAccount();
            else    
                MakeCreditAccount();
        }

        void MakeNormalAccount(){
            int account_num, left,interest;
            char name[20];

            cout<<"[create account]\n";
            cout<<"account ID: ";
            cin>>account_num;
            cout<<"name: ";
            cin>>name;
            cout<<"deposit: ";
            cin>>left;
            cout<<"interest: ";
            cin>>interest;
            cout<<'\n';

            carr[clientNum++]=new NormalAccount(account_num, name, left,interest);
        }
        void MakeCreditAccount(){
            int account_num, left,interest,credit_level;
            char name[20];

            cout<<"[create account]\n";
            cout<<"account ID: ";
            cin>>account_num;
            cout<<"name: ";
            cin>>name;
            cout<<"deposit: ";
            cin>>left;
            cout<<"interest: ";
            cin>>interest;
            cout<<"credit level(1toA, 2toB, 3toC): ";
            cin>>credit_level;
            cout<<'\n';

            switch(credit_level){
                case 1:
                    carr[clientNum++]=new HighCreditAccount(account_num, name, left,interest,CREDIT_LEVEL::LEVEL_A);
                    break;
                case 2:
                    carr[clientNum++]=new HighCreditAccount(account_num, name, left,interest,CREDIT_LEVEL::LEVEL_B);
                    break;
                case 3:
                    carr[clientNum++]=new HighCreditAccount(account_num, name, left,interest,CREDIT_LEVEL::LEVEL_C);
                    break;                                        

            }
        }


        //입금
        void deposit(){
            int aid, deposit;

            cout<<"[deposit]\n";
            cout<<"account ID: ";
            cin>>aid;
            cout<<"deposit: ";
            cin>>deposit;

            for(int i=0;i<clientNum;i++){
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

            for(int i=0;i<clientNum;i++){
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
            for(int i=0;i<clientNum;i++){
                carr[i]->printAccount();
            }
        }
};



int main(){
    ClientHandler handler; 

    int choose;

    while(1){
        handler.print_menu();
        cout<<"choice: ";
        cin>>choose;
        cout<<'\n';

        switch(choose){
            case 1:
                handler.account_create();
                break;
            case 2:
                handler.deposit();
                break;
            case 3:
                handler.withdrawal();
                break;
            case 4:
                handler.print_accounts();
                break;
            case 5:
                return 0;
            default:
                cout<<"Illegal selection"<<endl;
        }
        
    }
}