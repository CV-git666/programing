#include <iostream>
#include <string>
using namespace std;
string formatearDato(int n)
class reloj {
    private:
    int horas,minutos,segundos;
    public:
    Reloj(int h,int m, int s){
        int hora1= h;
        int minutos1=m;
        int segundos1=s;
        if (h<0||h>=60||m<0||m>=60||s<0||s>=60||{
            while (hora1 < 0|| hora1 >=60||minutos1 <0||segundos1 <0||segundos1>=60)
            {
            cout<< "Hora no valida\n";
            cout<< "Ingrese un valor de hora valida\n";
        cin>> hora1;
                cout<<"Ingrese un valor de minutos validos\n";
                cin>> minutos1;
                cout<< "Ingrse un valor de segundos validosn";
                cin>> segundos1;
        }
        }
        hora=hora1;
        minutos=minutos1;
        segundos=segundos1;
    }
    void nextSegundo(){
        if (segundos==59){
            segundos=0;
            if (minutos==59){
                minutos=0;
                if (horas=23){
                    horas=0;
                }else{
                    horas++;
                }
            }else{
                minutos++;
            }        
        }else{
            segundos++;
        }
        
    }
    void mostrarHora(){
        cout<<formatearDato
        (horas)<<""<<formatearDato
        (minutos)<<""<<formatearDato
        (segundos)<<endl;
    }
    };
    int  main(){
        auto reloj = new reloj(70,33,9);
        reloj->mostarHora();
        reloj->nextSegundo();
        reloj->mostrarHora9(); 
        return 0;
    }