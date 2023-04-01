// *********************************************************************
// * Driver for hashtable project                                      *
// * Menu provided by Dr. Gaitros in assignment                        *
// * Last updated: 7/11/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros project assignment                        *
// * Past projects with menus utilizing switch statements              *
// *     also used in chapter 7 of course book.                        *
// *********************************************************************


#include <iostream>
#include "hashtable.h"
#include "passserver.h"
#include "base64.h"
#include <utility>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;
using namespace cop4530;

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}
int main(){

    char sel = 'a';
    int cap = 100;
    string uname; 
    string pass; 
    string npass; 
    char *filename;

    PassServer Server(cap); 
    
    do{
        Menu();
        cin >> sel;
        switch(sel){

            case 'l': 
                cout << "Enter file name to load from: " << endl;
                cin >> filename;
                Server.load(filename);
                break;

            case 'a':     
                cout << "Enter username: " << endl; 
                cin >> uname;
                cout << "Enter password: " << endl; 
                cin >> pass; 
                Server.addUser(make_pair(uname, pass));
                break;
            
            case 'r':     
                cout << "Enter username: " << endl; 
                cin >> uname; 
                Server.removeUser(uname); 
                break;

            case 'c':     
                cout << "Enter username: " << endl; 
                cin >> uname; 
                cout << "Enter password: " << endl; 
                cin >>pass; 
                cout << "Enter new password: " << endl; 
                cin >> npass; 
                Server.changePassword(make_pair(uname,pass),npass);
                break;

            case 'f':     
                cout << "Enter username: " << endl; 
                cin >> uname; 
                if(Server.find(uname)) 
                    cout << "Found " << uname << endl; 
                else  
                    cout << uname << " not found. " << endl; 
                break;

            case 'd':     
                Server.dump(); 
                break;
                
            case 's':     
                cout << "The size of the hashtable is: " << Server.size() << endl; 
                break;

            case 'w':    
                char ch[100];
                cout << "Enter password file to write to: " << endl; 
                cin >> filename; 
                Server.write_to_file(filename); 
                break;

            case 'x':     
                exit(1);
                
            default:    
                cout << "Invalid selection. Try again. " << endl; 
                break;

        }
    }
    while(sel != 'x');
    return 0;

}