#include <iostream>
#include <ctype.h>
#include <stdexcept>
#include <windows.h>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;
    int menu;			
    char ulangi;                  //looping
    string pass, user;
    string username ="user";    //username
    string password = "pass";   //password
    string login = "block";       //pembatasan jumlah kesalahan login
    string nm;                    //str nama
    string input;                 //str untuk validasi input menu dengan stoi()
    
int main(){
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######             Login di Aplikasi             ######"<<endl;
	cout<<"######             Catatan Keuangan              ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;	   
//perulangan login
do{        
       cout << " Username: "; cin>>user;        
       cout << " Password: "; cin>>pass;        
       if (user == username && pass == password) {    
	       system("cls");
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######        Selamat Datang di Aplikasi         ######"<<endl;
	cout<<"######                 Celengin                  ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;	   
    cout<<" Nama : ";
    cin.ignore();
    getline(cin, nm);
//perulangan menu
do{
    system("cls");
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######        Selamat Datang di Aplikasi         ######"<<endl;
	cout<<"######                 Celengin                  ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;	   
    cout<<"1."<<endl;
    cout<<"2."<<endl;
    cout<<"3."<<endl;
    cout << "Masukkan angka menu (1-3): ";
    cin >> input;

        // Validasi input
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            menu = stoi(input);
            switch (menu) {    
                case 1:
                    system("cls");
                    cout << "Masih Progress" << endl;
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>ulangi;
                    break;
                case 2:
                    system("cls");
                    cout << "Masih Progress" << endl;
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>ulangi;
                    break;
                case 3:
                    system("cls");
                    cout << "Masih Progress" << endl;
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>ulangi;
                    break;
                default:
                    cout << "Input menu salah, menu: " << endl;
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>ulangi;
                    continue;
            }
        }
		else {
            cout << "Input menu salah, menu: " << endl;
            cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>ulangi;
            continue;
        }
    
} while(ulangi == 'y' || ulangi == 'Y');
    i = 4;
           login = "berhasil";        } 
       else {
	       system("cls");            
           cout<<"#################################################"<<endl;            
           cout<<"#      Username atau Password salah!! ("<<i<<"x)      #"<<endl;
           cout<<"#################################################"<<endl;           
           i = i +1; 
       }
} while (i <= 3);
    if(login != "berhasil"){
       cout<<" "<<endl;     
	   for (int i = 15; i >= 1; i--) {
	system("cls");
    cout<<"Kamu sudah login lebih dari 3x"<<endl;       
    cout<<"Silahkan coba lagi tunggu beberapa saat: "<<i<<endl;
    this_thread::sleep_for(chrono::seconds(1));
  } 
      system("cls");
      main();
	}   
    return 0;
}