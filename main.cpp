#include<iostream>
#include<me.cpp>
#include<Book.h>
#include<Library.h>
#include<string>

int main(){
    Library mylibrary;
    string comand;

    while(true){
        cout<<"Enter command (add, remove or list): ";
        getline(cin,command);
        if (command == "add"){
            string title, author; int year;
            cout<<"Enter title: "; getline(cin,title);
            cout<<"Enter author:"; getlin(cin,author);
            cout<<"Enter publication year: ";cin>>year;
            cin.ignore();
            mylibrary.addBook(Book(title,author,year));
        }     
        else if(command=="remove"){
            cout<<"Enter the title of the book: ";
            getline(cin,title);
            mylibrary.removeBook(title);
        }
        else if(command=="list"){
            mylibrary.listBooks();
        }
    }
    return 0;
}
