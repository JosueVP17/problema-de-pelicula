/*
    TAREA PRÁCTICA 0901: UN PROBLEMA DE PELÍCULA
    Búsqueda Primero en Profundidad (DFS)
*/
#include <iostream>
#include <vector> // Vector para guardar los estados posibles de un nodo hijo

using namespace std;

// Variables globales
const int CAP1 = 5;
const int CAP2 = 3;
const int META1 = 4;
bool visitados[CAP1 + 1][CAP2 + 1] = {false};

// Estado de las jarras
struct Estado {
    int jarra1;
    int jarra2;
};

// Nodo de árbol con estado y su padre
struct Nodo {
    Estado estado;
    Nodo* padre;

    Nodo() {
        Estado e = {0, 0};
        estado = e;
        padre = nullptr;
    }
    Nodo(Estado e, Nodo* p) : estado(e), padre(p) {}
};

// Reglas de transición entre estados
bool MetaAlcanzada(int jarra1, int jarra2);
bool Regla1(int &jarra1);
bool Regla2(int &jarra2);
bool Regla3(int &jarra1);
bool Regla4(int &jarra2);
bool Regla5(int &jarra1, int &jarra2);
bool Regla6(int &jarra1, int &jarra2);
bool Regla7(int &jarra1, int &jarra2);
bool Regla8(int &jarra1, int &jarra2);

// Imprimir solución
void ImprimirCamino(Nodo* nodo);
// Generar estados posibles de un nodo hijo
vector<Estado> generarHijos(const Estado& e);
// Búsqueda en profundidad
void DFS(Nodo* padre);

int main(void) {
    Nodo *raiz = new Nodo();

    DFS(raiz);

    return 0;
}

// Imprimir camino de atrás hacia delante
void ImprimirCamino(Nodo* nodo) {
    if(nodo == nullptr) return;
    ImprimirCamino(nodo->padre);
    cout << "(" << nodo->estado.jarra1 << ", " << nodo->estado.jarra2 << ")" << endl;
}

// Generar hijos para un estado
vector<Estado> generarHijos(const Estado& e) {
    vector<Estado> hijos;

    int jarra1 = e.jarra1;
    int jarra2 = e.jarra2;
    int x, y;

    x = jarra1; y = jarra2;
    if(Regla1(x)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla2(y)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla3(x)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla4(y)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla5(x, y)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla6(x, y)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla7(x, y)) hijos.push_back({x, y});

    x = jarra1; y = jarra2;
    if(Regla8(x, y)) hijos.push_back({x, y});

    return hijos;
}

// Búsqueda primero en profundidad
void DFS(Nodo* padre) {
    Estado estado = padre->estado;
    if (MetaAlcanzada(estado.jarra1, estado.jarra2)) {
        ImprimirCamino(padre);
        return;
    }

    visitados[estado.jarra1][estado.jarra2] = true;
    vector<Estado> hijos = generarHijos(estado);
    
    for(Estado e : hijos) {
        if(!visitados[e.jarra1][e.jarra2]) {
            Nodo* hijo = new Nodo(e, padre);
            DFS(hijo);
        }
    }
}

// Meta
bool MetaAlcanzada(int jarra1, int jarra2) {
    if (jarra1 == META1) {
        return true;
    }
    return false;
}

// Llenar la jarra 1
bool Regla1(int &jarra1) {
    if (jarra1 < CAP1) {
        jarra1 = CAP1;
        return true;
    }
    return false;
}

// Llenar la jarra 2
bool Regla2(int &jarra2) {
    if (jarra2 < CAP2) {
        jarra2 = CAP2;
        return true;
    }
    return false;
}

// Vaciar la jarra 1
bool Regla3(int &jarra1) {
    if (jarra1 > 0) {
        jarra1 = 0;
        return true;
    }
    return false;
}

// Vaciar la jarra 2
bool Regla4(int &jarra2) {
    if (jarra2 > 0) {
        jarra2 = 0;
        return true;
    }
    return false;
}

// Vaciar toda la jarra 1 a la jarra 2
bool Regla5(int &jarra1, int &jarra2) {
    if (jarra1 > 0 && jarra1 + jarra2 <= CAP2) {
        jarra2 += jarra1;
        jarra1 = 0;
        return true;
    }
    return false;
}

// Vaciar toda la jarra 2 a la jarra 1
bool Regla6(int &jarra1, int &jarra2) {
    if (jarra2 > 0 && jarra1 + jarra2 <= CAP1) {
        jarra1 += jarra2;
        jarra2 = 0;
        return true;
    }
    return false;
}

// Vaciar la jarra 1 a la jarra 2 hasta llenarla
bool Regla7(int &jarra1, int &jarra2) {
    if (jarra1 > 0 && jarra2 < CAP2 && jarra1 + jarra2 > CAP2) {
        jarra1 -= CAP2 - jarra2;
        jarra2 = CAP2;
        return true;
    }
    return false;
}

// Vaciar la jarra 2 a la jarra 1 hasta llenarla
bool Regla8(int &jarra1, int&jarra2) {
    if (jarra2 > 0 && jarra1 < CAP1 && jarra1 + jarra2 > CAP1) {
        jarra1 = CAP1;
        jarra2 -= CAP1 - jarra1;
        return true;
    }
    return false;
}