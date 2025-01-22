#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Gra{
    protected:
    string plansza[3][3];
    bool tura = false;
    string *prt = &plansza[0][0];
    int row, col;
    public:
    Gra(){set_plan();}
    ~Gra(){}
    string set_plan(){
        for(int i=0; i<3*3; i++){
            *(prt+i)=" ";
        }
        return **plansza;
    }
    void plan(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<"|"<<plansza[i][j];
            }
            cout<<"|";
            cout<<endl;
            cout<<"-------";
            cout<<endl;
        }
    }

    bool move(){
        if(tura==true){
            cout<<"Kolej na krzyzyk! "<<endl;
            return tura = false;
        }
        else{
            cout<<"Kolej na kolko! "<<endl;
            return tura = true;
        }
    }

    void check_if_end(){
        bool check = false;
        for(int i=0; i<3*3; i++){
            if(*(prt+i)==" "){
                check = true;
                break;
            }
        }
        if(!check){
            cout<<"Koniec mozliwych ruchow, zatem koniec rozgrywki! Dzieki!"<<endl;
            exit(0);
        }
    }

    void do_move(){
        cout<<"Czas na wykonanie Twojego ruchu! "<<endl<<"Podaj najpierw rzad: ";
        cin>>row;
        cout<<endl<<"Teraz kolumne! ";
        cin>>col;
        cout<<endl;
        if(row<0 || row>2 || col<0 || col>2){
            cout<<"nieprawidlowe wspolrzedne!"<<endl;
        }
        if(plansza[row][col]==" "){
            if(tura==false){
                cout<<"Wpisuje ruch! "<<endl;
                *(prt + row * 3 + col) = "x";
            }
            else{
            cout<<"Wpisuje ruch! "<<endl;
            *(prt + row * 3 + col) = "o";
            }
        }
        else{
            cout<<"Nieprawidlowy ruch, tam jest juz przeciwnik. Tracisz ture! "<<endl;
        }
    }
    void check_if_win(){
        bool win = false;
        for(int z=0; z<3; z++){
            if(plansza[z][0]==plansza[z][1]&&plansza[z][1]==plansza[z][2]&&plansza[z][0]!=" "){
                win = true;
            }
            if(plansza[0][z]==plansza[1][z]&&plansza[1][z]==plansza[2][z]&&plansza[0][z]!=" "){
                win = true;
            }
        }
        if(plansza[0][0]==plansza[1][1]&&plansza[1][1]==plansza[2][2]&&plansza[0][0]!=" "){
            win = true;
        }
        if(plansza[0][2]==plansza[1][1]&&plansza[1][1]==plansza[2][0]&&plansza[0][2]!=" "){
            win = true;
        }
        if(win==true){
            cout<<"Mamy zwyciesce! Gratulacje!!";
            exit(0);
        }
    }
};

int main(){
    Gra gra;
    cout<<"Witaj w grze kolko i krzyzyk! Rozpoczyna krzyzyk"<<endl;
    while(true){
        gra.plan();
        gra.check_if_end();
        gra.check_if_win();
        gra.do_move();
        gra.move();
    }
    return 0;
}
