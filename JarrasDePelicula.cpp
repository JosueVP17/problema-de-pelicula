/*
    TAREA PRÁCTICA 0901: UN PROBLEMA DE PELÍCULA
    Búsqueda Primero en Profundidad (DFS)
*/
#include <iostream>
#include <vector> // Hijos de un nodo
using namespace std;

// Variables globales
int CAP1 = 5;
int CAP2 = 3;
int META1 = 4;

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

// Nodo de árbol con n hijos
struct Nodo {
    int jarra1;
    int jarra2;
    vector<Nodo*> hijos;

    Nodo() : jarra1(0), jarra2(0), hijos() {}
};

int main(void) {
    Nodo raiz();



    return 0;
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
        jarra1 = 0;
        jarra2 += jarra1;
        return true;
    }
    return false;
}

// Vaciar toda la jarra 2 a la jarra 1
bool Regla6(int &jarra1, int &jarra2) {
    if (jarra2 > 0 && jarra1 + jarra2 <= CAP1) {
        jarra2 = 0;
        jarra1 += jarra2;
        return true;
    }
    return false;
}

// Vaciar la jarra 1 a la jarra 2 hasta llenarla
bool Regla7(int &jarra1, int &jarra2) {
    if (jarra1 > 0 && jarra2 < CAP2 && jarra1 + jarra2 > CAP2) {
        jarra1 += jarra2 - CAP2;
        jarra2 = CAP2;
        return true;
    }
    return false;
}

// Vaciar la jarra 2 a la jarra 1 hasta llenarla
bool Regla8(int &jarra1, int&jarra2) {
    if (jarra2 > 0 && jarra1 < CAP1 && jarra1 + jarra2 > CAP1) {
        jarra1 = CAP1;
        jarra2 += jarra1 - CAP1;
    }
    return false;
}