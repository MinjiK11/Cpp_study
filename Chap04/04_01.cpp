#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	
public:
	void InitMembers(int price, int num, int money)
	{
        APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
        
	}

	int SaleApples(int money)  
	{
        if(money<0){
            cout<<"money should be greater than 0"<<endl;
            return 0;
        }
       
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
        
	}

	void ShowSalesResult() const
	{
		cout<<"apple left: "<<numOfApples<<endl;
		cout<<"income: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:
	void InitMembers(int money)
	{
		myMoney=money;
		numOfApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
        if(money<0){
            cout<<"money should be greater than 0"<<endl;
        }
        
		numOfApples+=seller.SaleApples(money);
		myMoney-=money;
	}
	void ShowBuyResult() const
	{
		cout<<"money left: "<<myMoney<<endl;
		cout<<"number of apple: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"status of seller: "<<endl;
	seller.ShowSalesResult();
	cout<<"status of buyer: "<<endl;
	buyer.ShowBuyResult();
	return 0;
}
