#include<iostream>
using namespace std;

template <class T>
class Library
{
    private:
        T bookID;
        string bookName ;
        string Author;
        bool issue;

    public:
        Library(T id, string na, string au)
        {
            bookID=id;
            bookName=na;
            Author=au;
        }
        void display()
        {
            cout<<"\nBook Id:"<<bookID;
            cout<<"\nBook Name:"<<bookName;
            cout<<"\nBook Author:"<<Author;

            if(issue)
                cout<<"\nIssued";
            else
                cout<<"\nAvailable\n";
        }    
        void issueBook()
        {
            if(!issue)
            {
                issue = true;
                cout<<"\nBook Issued Successfully\n";
            }
            else
            {
                cout<<"Book is Already Issued";
            }
        }
        void returnBook()
        {
            if(issue)
            {
                issue = false;
                cout<<"\nBook Returned Successfully.\n";
            }
            else
            {
                cout<<"Book was not issued.";
            }
        }    

};

int main()
{
    
    Library<int> book1(101, "Object Oriented Programming","Mr.Prasad Dhore Sir");
    Library<string> book2("CS102", "Database Mangement System","Mr.Prasad Dhore Sir");

    cout<<" ====================Library Management System====================";
    
    cout<<"\nBook 1 Details\n";
    book1.display();

    cout<<"\nBook 2 Details\n";
    book2.display();

    cout<<"Book 1 Issue Operation";
    book1.issueBook();
    book1.display();

    cout<<"Book 1 Return Operation";
    book1.returnBook();
    book1.display();

    return 0;
}
