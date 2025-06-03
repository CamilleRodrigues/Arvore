#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "arvore.h"

int main() {
    Arvore *arvore = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int valor = rand() % 100;
        cout << "Inserindo: " << valor << endl;
        arvore = inserir(valor, arvore); 
    }

    exibirOrdenado(arvore);
    cout << endl;

    int numero;
    cout << "Numero para pesquisa: ";
    cin >> numero;
    cout << numero << " localizado? " << localizar(numero, arvore) << endl;

    cout << "Total de folhas: " << contarFolhas(arvore) << endl;

    mostrarFolhas(arvore);
    cout << endl;

    arvore = podar(arvore);
    cout << "Total de elementos apos a poda: " << contar(arvore) << endl;
    exibirOrdenado(arvore);
    cout << endl;

    arvore = deletar(arvore);
    cout << "Total de elementos apos a delecao: " << contar(arvore) << endl;
    exibirOrdenado(arvore);
    cout << endl;
}
