
#include <iostream>
#include <string>

using namespace std;

class Contacto {
public:
    string nombre, email, telefono;

    
    Contacto(string n, string e, string t) : nombre(n), email(e), telefono(t) {}
};

class Agenda {
public:
    vector<Contacto> lista; 

    Agenda(const vector<Contacto>& iniciales) {
        lista = iniciales;
    }

    void agregar(const Contacto& nuevo) {
        
        for(const auto& c : lista) {
            if(c.nombre == nuevo.nombre) {
                cout << "El contacto ya existe en la agenda." << endl;
                return;
            }
        }
        lista.push_back(nuevo);
    }

    void eliminar(string nombreABuscar) {
        for(size_t i = 0; i < lista.size(); i++) {
            if(lista[i].nombre == nombreABuscar) {
                lista.erase(lista.begin() + i);
                cout << "Contacto eliminado." << endl;
                return;
            }
        }
        cout << "No se encontro el contacto a eliminar." << endl;
    }

    void buscar(string nombreABuscar) {
        for(const auto& c : lista) {
            if(c.nombre == nombreABuscar) {
                cout << "Nombre: " << c.nombre << "\nEmail: " << c.email << "\nTel: " << c.telefono << endl;
                return;
            }
        }
        cout << "Contacto no encontrado." << endl;
    }

    void mostrarTodos() {
        if(lista.empty()) {
            cout << "La agenda esta vacia." << endl;
            return;
        }
        for(const auto& c : lista){
            cout << "Nombre: " << c.nombre << " | Email: " << c.email << " | Tel: " << c.telefono << endl;
        }
    }
};

int main() {
    vector<Contacto> iniciales;

    Contacto c1("Luis", "Luis@mail.com", "382792098");
    iniciales.push_back(c1);

    Agenda miAgenda(iniciales);

    
    miAgenda.agregar(Contacto("Maria Fernanda", "maria@mail.com", "928370987"));
    miAgenda.mostrarTodos();

    return 0;
}