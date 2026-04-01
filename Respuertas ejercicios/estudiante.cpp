#include<iostream>
#include<string>
using namespace std;

class Estudiante {
    public:
        string nombre, carnet;
        vector<float> calificaciones;
        Estudiante(string name, string dni) {
            nombre = name;
            carnet = dni;
        }
        void agregarCalificacion(double nota) {
                if (nota < 0 || nota > 100) {
                    cout << "Calificacion invalida\n";
                    return;
                }
                calificaciones.push_back(nota);
        }

        double calcularPromedio() {
            if (calificaciones.empty()) return 0.0;
            double suma = 0.0;
            for (double c : calificaciones) suma += c;
            return suma / calificaciones.size();
        }

};
int main() {

    Estudiante e("Gabriel", "60123678");
    e.agregarCalificacion(80);
    e.agregarCalificacion(89);
    e.agregarCalificacion(66);
    cout << "Promedio de " << e.nombre << ": " << e.calcularPromedio() << endl;

    return 0;
}