#include <iostream>
#include <string> 

using namespace std;

class Cadena {
private:
    char* datos;
    size_t tam;

public:
    
    Cadena(const char* s = "") {
        tam = strlen(s);
        datos = new char[tam + 1];
        strcpy(datos, s);
    }

    
    Cadena(const Cadena& otra) {
        tam = otra.tam;
        datos = new char[tam + 1];
        strcpy(datos, otra.datos);
    }

    
    ~Cadena() {
        delete[] datos;
    }

    
    Cadena& operator=(const Cadena& otra) {
        if (this != &otra) {
            char* aux = new char[otra.tam + 1]; 
            strcpy(aux, otra.datos);
            
            delete[] datos;
            datos = aux;
            tam = otra.tam;
        }
        return *this;
    }

    
    Cadena operator+(const Cadena& otra) const {
        size_t nuevoTam = tam + otra.tam;
        char* temp = new char[nuevoTam + 1];
        
        strcpy(temp, datos);
        strcat(temp, otra.datos);
        
        Cadena resultado(temp);
        delete[] temp; 
        return resultado;
    }

    bool operator==(const Cadena& otra) const {
        return strcmp(datos, otra.datos) == 0;
    }

    
    char& operator[](size_t i) {
        if (i >= tam) throw out_of_range("Fuera de rango");
        return datos[i];
    }

    const char& operator[](size_t i) const {
        if (i >= tam) throw out_of_range("Fuera de rango");
        return datos[i];
    }

    size_t getLongitud() const {
        return tam;
    }

    void pasarAMayusculas() {
        for (size_t i = 0; i < tam; i++) {
            if (datos[i] >= 'a' && datos[i] <= 'z') {
                datos[i] -= 32; 
            }
        }
    }

    Cadena extraer(size_t pos, size_t n) const {
        if (pos >= tam) throw out_of_range("Posicion invalida");
        
        size_t cantidad = (n > tam - pos) ? tam - pos : n;
        char* buffer = new char[cantidad + 1];
        
        for(size_t i = 0; i < cantidad; i++) {
            buffer[i] = datos[pos + i];
        }
        buffer[cantidad] = '\0';
        
        Cadena res(buffer);
        delete[] buffer;
        return res;
    }

    friend ostream& operator<<(ostream& out, const Cadena& c) {
        out << c.datos;
        return out;
    }
};

int main() {
    Cadena texto1("Hola");
    Cadena texto2(" Mundo");
    
    Cadena unido = texto1 + texto2;
    cout << "Resultado: " << unido << endl;

    unido.pasarAMayusculas();
    cout << "En mayusculas: " << unido << endl;

    Cadena parte = unido.extraer(0, 4);
    cout << "Parte: " << parte << " (Longitud: " << parte.getLongitud() << ")" << endl;

    Cadena clon("HOLA MUNDO");
    if (unido == clon) {
        cout << "Las cadenas son iguales." << endl;
    }

    return 0;
}