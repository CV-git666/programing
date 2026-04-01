#include <iostream>
#include <string>
using namespace std;
class rectangulo {
    private:
    double base, altura;
    public:
    rectangulo( double b, double a)
{
    setBase(b);
    setAltura(a);
}
void setBase (double b ){
    base=abs(b);
}
void setAltura(double a ){
    altura=abs(a);
}
double getBase(){
    return base;
}
double calcularArea(){
    return base * altura;
}
double calcularPerimetro(){
    return 2 * (base * altura);
}
};
int main(){
    auto rect1 = new rectangulo(1.5,3.5);
    cout<<rect1->calcularArea();
    return 0;
}
