#include <iostream>
#include <ctype.h>    
#include <stdexcept>  
#include <windows.h>  
#include <chrono>     
#include <thread>     
#include <ctime>      
#include <fstream>	  
#include <cstdlib>	  
using namespace std;
struct Beranda{		
    char ulangi;                                    
    string input;
};                    
    
struct Login{
    string pass, user;
    string username ="user";     
    string password = "pass";    
    string login = "block";       	
};

struct Celengan{
    int targetTabungan;
	int tabungan=0;
};

struct Tabungan{
	int tambahan,ambil;
	Tabungan *lanjut;
};

struct Node {
    string motivasi;
    Node *next;
};

void motiv(){
	srand(time(0));
	string motivasi[10] = {
        "Semangat menabungnya ya!!",
        "Ayo lebih giat menabung lagii!",
        "Kamu pandai menabung",
        "Kamu hebat, teruskan menabungnya",
        "kamu bisa jadi jutawan jika sering menabung hehe",
        "Semangat, menabung itu seperti menanam pohon uang",
        "Semangat, menabung untuk mencapai yang di inginkan",
        "Semoga kamu bisa terus konsisten ya!!",
        "Ayo semangat menabung lebih besar lagi",
        "Kamu hebat, kamu bisa mencapai keinginanmu dengan tepat"
    };
    
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < 10; i++) {
        Node *newNode = new Node;
        newNode->motivasi=motivasi[i];
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int index = rand() % 10;
    Node *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    cout<<"-------------------------------------------------------"<<endl;
	cout << current->motivasi << endl;
    cout<<"-------------------------------------------------------"<<endl;
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void MembuatTabungan(Celengan celengan){
	Tabungan *tabungan;
    tabungan = new Tabungan();
    
	system("cls");
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######        Selamat Datang di Aplikasi         ######"<<endl;
	cout<<"######                 Celengin                  ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;	
    cout<<"Masukkan jumlah target menabung: ";
    cin>>celengan.targetTabungan;
    ofstream mytarget("target.txt");
    if (mytarget.is_open()) {
        mytarget<<celengan.targetTabungan;
        mytarget.close();
    } else {
        cout<<"Gagal save"<<endl;
    }
	system("cls");
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######        Selamat Datang di Aplikasi         ######"<<endl;
	cout<<"######                 Celengin                  ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    bool inputBenar = false;
    do {	
	cout<<"Masukkan jumlah tabungan yang ingin ditambahkan: ";
    cin>>tabungan->tambahan;
        if (tabungan->tambahan < 0) {
            cout << "-------------------------------------------------------" << endl;
            cout << "Maaf, jumlah tabungan yang ditambahkan tidak boleh minus" << endl;
            cout << "-------------------------------------------------------" << endl;
        } else {
            inputBenar = true;
    
            }

    } while (!inputBenar);
    ofstream buatTabungan("tabungan.txt");
    if (buatTabungan.is_open()) {
        buatTabungan<<tabungan->tambahan;
        buatTabungan.close();
        cout<<"Berhasil save"<<endl;
    } else {
        cout<<"Gagal save"<<endl;
    }
}

void menambah(Celengan celengan){
    Tabungan *tabungan;
    tabungan = new Tabungan();
    
    system("cls");
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######        Selamat Datang di Aplikasi         ######"<<endl;
	cout<<"######                 Celengin                  ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    bool inputBenar = false;
    do {	
	cout<<"Masukkan jumlah tabungan yang ingin ditambahkan: ";
    cin>>tabungan->tambahan;
        if (tabungan->tambahan < 0) {
            cout << "-------------------------------------------------------" << endl;
            cout << "Maaf, jumlah tabungan yang ditambahkan tidak boleh minus" << endl;
            cout << "-------------------------------------------------------" << endl;
        } else {
            inputBenar = true;
    
            }

    } while (!inputBenar);
    celengan.tabungan += tabungan->tambahan;
    ofstream myfile("tabungan.txt");
    if (myfile.is_open()){
        myfile<<celengan.tabungan;
        myfile.close();
        cout<<"Berhasil save"<<endl;
    } else {
        cout<<"Gagal save"<<endl;
    }
}

void mengambil(Celengan celengan){
	Tabungan *tabungan;
    tabungan = new Tabungan();
    
    system("cls");
    cout<<"#######################################################"<<endl;
    cout<<"######                                           ######"<<endl;
    cout<<"######        Selamat Datang di Aplikasi         ######"<<endl;
    cout<<"######                 Celengin                  ######"<<endl;
    cout<<"######                                           ######"<<endl;
    cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    bool inputBenar = false;
    do {
        cout<<"Masukkan jumlah tabungan yang ingin diambil: ";
        cin>>tabungan->ambil;
        if (tabungan->ambil > celengan.tabungan) {
        	cout<<"-------------------------------------------------------"<<endl;
            cout << "Maaf, jumlah tabungan yang diambil melebihi jumlah tabungan yang tersimpan. Silahkan ulangi." << endl;
            cout<<"-------------------------------------------------------"<<endl;
        } else {
            inputBenar = true;
        }
    } while (!inputBenar);

    celengan.tabungan -= tabungan->ambil;
    ofstream myfile("tabungan.txt");
    if (myfile.is_open()){
        myfile<<celengan.tabungan;
        myfile.close();
        cout<<"Berhasil save"<<endl;
    } else {
        cout<<"Gagal save"<<endl;
    }
}

void bukaTabungan(Celengan celengan){
	Tabungan *tabungan;
    tabungan = new Tabungan();
    
    ifstream myfile2("tabungan.txt");
    if (myfile2.is_open()) {
        myfile2>>celengan.tabungan;
        myfile2.close();
        cout<<"Tabungan saat ini: "<<celengan.tabungan<<endl;
    } else {
        cout<<"Tabungan Anda: 0."<<endl;
        celengan.tabungan = 0;
    }
    
    ifstream mytarget("target.txt");
    if (mytarget.is_open()){
        mytarget>>celengan.targetTabungan;
        mytarget.close();
        cout<<"Target tabungan Anda: "<<celengan.targetTabungan<<endl;
        double persentase = ((double)celengan.tabungan / celengan.targetTabungan) * 100;
        if(persentase >= 100){
            cout<<"Persentase tabungan telah mencapai target 100%"<<endl;
        }
        else{
            cout<<"Persentase tabungan memenuhi target: "<<persentase<<"%"<<endl;
        }
    } else{
        cout<<"Target tabungan Anda: 0"<<endl;
    }

    int pilihan;
    	cout<<endl;
        cout<<"====== APLIKASI CELENGAN ======" << endl;
        cout<<"1. Tambah tabungan" << endl;
        cout<<"2. Ambil tabungan" << endl;
        cout<<"Pilihan Anda: ";
        cin>>pilihan;
        switch (pilihan) {
            case 1:
                menambah(celengan);
                break;
            case 2:
            	mengambil(celengan);
                ;
                break;
            default:
                cout << "coba lagi" << endl;
                break;
        }
}
int menu,i,counter=0;    
int main(){
	Login login;
	Beranda beranda;
	Celengan celengan;
    Node *currcent;	

	i = 1;
    cout<<"#######################################################"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"######             Login di Aplikasi             ######"<<endl;
	cout<<"######                 Celengin                  ######"<<endl;
	cout<<"######                                           ######"<<endl;
	cout<<"#######################################################"<<endl;
    cout<<"-------------------------------------------------------"<<endl;	   
//perulangan login
do{        
       cout << " Username: "; cin>>login.user;        
       cout << " Password: "; cin>>login.pass;        
       if (login.user == login.username && login.pass == login.password) {    

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
    cout<<"1. Membuat Tabungan"<<endl;
    cout<<"2. Membuka Tabungan"<<endl;
    cout<<"3. Logout"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Masukkan angka menu (1-4): ";
    cin>>beranda.input;

        bool valid = true;
        for (char c : beranda.input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            menu = stoi(beranda.input);
            switch (menu) {    
                case 1:
                    system("cls");
					MembuatTabungan(celengan);
					motiv();
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>beranda.ulangi;
                    break;
                case 2:
                    system("cls");
					bukaTabungan(celengan);
					motiv();
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>beranda.ulangi;
                    break;
                case 3:
                    system("cls");
                    cout << "logout" << endl;
                    main();
                    break;
                case 4:
                    system("cls");
                    cout << "Exit" << endl;
                    return 0;;
                    break;
                default:
                    cout<<"Input menu salah, menu: "<<endl;
                    cout<<"Kembali ke menu awal? (y/t): ";
                    cin>>beranda.ulangi;
                    continue;
            }
        }
		else {
            cout<<"Input menu salah, menu: "<<endl;
            cout<<"Kembali ke menu awal? (y/t): ";
            cin>>beranda.ulangi;
            continue;
        }
    counter++;
} while(beranda.ulangi == 'y' || beranda.ulangi == 'Y');
    i = 4;
           login.login = "berhasil";        } 
       else {
	       system("cls");            
           cout<<"#################################################"<<endl;            
           cout<<"#      Username atau Password salah!! ("<<i<<"x)      #"<<endl;
           cout<<"#################################################"<<endl;           
           i = i +1; 
       }
} while (i <= 3);
    if(login.login != "berhasil"){
       cout<<" "<<endl;     
	   for (int i = 10; i >= 1; i--) {
	system("cls");
    cout<<"Kamu gagal login beberapa kali"<<endl;       
    cout<<"Silahkan coba lagi tunggu beberapa saat: "<<i<<endl;
    this_thread::sleep_for(chrono::seconds(1));
  } 
      system("cls");
      main();
	}   
    return 0;
}