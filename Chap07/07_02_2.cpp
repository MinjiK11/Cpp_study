#include <iostream>
#include <cstring>

using namespace std;

class Book{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(char * title_in,char *isbn_in, int price_in)
            : price(price_in)
        {
            title=new char[strlen(title_in)+1];
            strcpy(title,title_in);
            isbn=new char[strlen(isbn_in)+1];
            strcpy(isbn,isbn_in);
        }

        void ShowBookInfo(){
            cout<<"Title: "<<title<<endl;
            cout<<"ISBN: "<<isbn<<endl;
            cout<<"Price: "<<price<<endl;
        }

        ~Book(){
            delete []title;
            delete []isbn;
        }
};

class EBook : public Book{
    private:
        char *DRMKey;
    public:
        EBook(char * title_in, char *isbn_in, int price_in, char * DRMKey_in)
            : Book(title_in,isbn_in,price_in)
        {
            DRMKey=new char[strlen(DRMKey_in)+1];
            strcpy(DRMKey,DRMKey_in);
        }

        ~EBook(){
            delete []DRMKey;
        }

};

int main(){
    Book book("Good C++","555-12345-890-0",20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("Good C++ ebook","555-12345-890-1",10000,"fdx9w0i8kiw");
    ebook.ShowBookInfo();

    return 0;
}