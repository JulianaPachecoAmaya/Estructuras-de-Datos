/************************************
 Nombres: JULIANA PACHECO, DANIEL GONZALES, NICOLAS ALGARA
 TEMA: TALLER ARBOLES
 FECHA: 24/09/2024
 ***********************************/
#include <iostream>
#include <string>

using namespace std;

// Definici�n de la estructura para un nodo del �rbol de decisi�n
struct Nodo {
    string pregunta; // Pregunta o condici�n en el nodo
    Nodo* si;       // Sub�rbol si la respuesta es "s�"
    Nodo* no;       // Sub�rbol si la respuesta es "no"
};

// TAD �rbol de Decisi�n
class ArbolDecision {
private:
    Nodo* raiz; // Ra�z del �rbol

    // Funci�n recursiva para liberar la memoria del �rbol
    void liberarArbol(Nodo* nodo) {
        if (nodo != nullptr) {
            liberarArbol(nodo->si);
            liberarArbol(nodo->no);
            delete nodo;
        }
    }

    // Funci�n recursiva para realizar el �rbol de decisi�n
    void decision(Nodo* nodo) {
        if (nodo->si == nullptr && nodo->no == nullptr) {
            cout << "Decisi�n final: " << nodo->pregunta << endl; // Imprimir la decisi�n final
            return;
        }

        string respuesta;
        cout << nodo->pregunta << " (si/no): ";
        cin >> respuesta;

        if (respuesta == "si") {
            decision(nodo->si);
        } else {
            decision(nodo->no);
        }
    }

public:
    // Constructor
    ArbolDecision() {
        raiz = nullptr;
    }

    // Destructor
    ~ArbolDecision() {
        liberarArbol(raiz);
    }

    // M�todo para crear un nodo
    Nodo* crearNodo(string pregunta) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->pregunta = pregunta;
        nuevoNodo->si = nullptr;
        nuevoNodo->no = nullptr;
        return nuevoNodo;
    }

    // M�todo para establecer la ra�z del �rbol
    void establecerRaiz(Nodo* nodo) {
        raiz = nodo;
    }

    // M�todo para iniciar la toma de decisiones
    void iniciarDecision() {
        if (raiz != nullptr) {
            decision(raiz);
        } else {
            cout << "El �rbol est� vac�o." << endl;
        }
    }
};

// Funci�n para construir un ejemplo de �rbol de decisi�n
void construirArbolEjemplo(ArbolDecision &arbol) {
    Nodo* raiz = arbol.crearNodo("�Es un animal?");
    Nodo* nodoSi = arbol.crearNodo("�Es un mam�fero?");
    Nodo* nodoNo = arbol.crearNodo("�Es una planta?");
    Nodo* nodoSiMamifero = arbol.crearNodo("Es un perro.");
    Nodo* nodoNoMamifero = arbol.crearNodo("Es un pez.");
    Nodo* nodoSiPlanta = arbol.crearNodo("Es un roble.");
    Nodo* nodoNoPlanta = arbol.crearNodo("Es un mineral.");

    raiz->si = nodoSi;
    raiz->no = nodoNo;
    nodoSi->si = nodoSiMamifero;
    nodoSi->no = nodoNoMamifero;
    nodoNo->si = nodoSiPlanta;
    nodoNo->no = nodoNoPlanta;

    arbol.establecerRaiz(raiz);
}

int main() {
    ArbolDecision arbol;
    construirArbolEjemplo(arbol); // Construir un ejemplo de �rbol
    arbol.iniciarDecision(); // Iniciar la toma de decisiones
    return 0;
}

