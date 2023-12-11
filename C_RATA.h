#include<iostream>
#include<ctime>
#include<cstdlib>
#include<ncurses/ncurses.h>
#include<windows.h>

using namespace std;

void loading(){
    initscr();
    int load=0;
    mvprintw(13, 40, "HALLOO WELCOME TO GAME RATA!!");
    mvprintw(14, 40, "           LOADING");
    
    for (int x=40; x<70; x++){
        refresh();
        mvprintw(15, x, "-***** ");
        Sleep(100);
        mvprintw(15, x, " ");
        if (x==69&&load<1){
            mvprintw(15, x, "      "); 
            load++;
            x=40;
        }
    }
    refresh();
    endwin();
}

void rules()
{ 
    system("cls");
    cout << "\n\n";
    cout << "\t   Kamu titan eren yang mempunyai misi memindahkan batu agar titan-titan noob gak masuk lagi      "<<endl;
    cout << "\t1. Anggap @ adalah batu kemudian pindahkan ke x! Misi kamu adalah menutup lubang di Trost! "<<endl;
    cout << "\t2. Klik WSAD untuk bergerak. Atas-W. Bawah-S. Kanan-D. Kiri-A. Lanjut-L. Refresh-R. Keluar-Q."<<endl;
}

void awalan()
{
    system("color 60");
    string nama_pemain;			       		  
    char pilih;				
    srand(time(0)); 
    loading();		
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Siapakah Namamu wahai MC : ";	
    cin >> nama_pemain;

    system("cls");
    rules();
    cout << "\n" << endl;
    cout << "       Haiii " << nama_pemain << ", Apakah kamu ingin menyelesaikan misi? (y/n)? ";
    cin >> pilih;
    
    if(pilih == 'n' || pilih == 'N'){
        system("cls");
        cout << "\n\n\t Terima kasih telah bermain sebenernya nama asli game ini 'pindahin batu hehe' <3" <<endl;	
        exit(0);
    }
    else{
        system("cls");
        cout << "\n\n\t Terima kasih telah bermain sebenernya nama asli game ini 'pindahin batu' hehe <3" <<endl;	
    }
}

