#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void login();
void reg();
void forgot();


int main()
{
    int choice;
    cout <<"***********************************************"<<endl;
    cout <<"******************** WELCOME *******************"<<endl;
    cout <<"MENU: "<<endl;
    cout <<"1. Login"<<endl;
    cout <<"2. Register"<<endl;
    cout <<"3. Forgot username or password"<<endl;
    cout <<"4. Exit"<<endl;
    cout <<"Enter your choice: "<<endl;
    cin >> choice;

    switch (choice)
    {
        case 1:
        login();
        break;

        case 2:
        reg();
        break;

        case 3:
        forgot();
        break;

        case 4:
        system("cls");
        cout << "You have made mistake, please try again";
        main();
    }
}

void login()
{
    int count;
    string user,pass,u,p;
    system("cls");
    cout <<"Please enter the following details: "<<endl;
    cout <<"Username: ";
    cin >> user;
    cout << "Password: ";
    cin >>pass;

    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if(count == 1)
    {
        cout <<"Hello "<<user<<"\n <LOGIN SUCCESSFUL>\n";
        cin.get();
        main();
    }
    else{
        cout <<"\nLOGIN ERROR\n please check your username and password."<<endl;
    }
}
// register first
void reg()
{
    string reguser,regpass,rw,pw;
    system("cls");
    cout << "Please enter your username: ";
    cin >> reguser;
    cout <<"Enter your password: ";
    cin >> regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<" "<<regpass<<endl;
    cout<<"Registration sucessifull"<<endl;
    main();
}