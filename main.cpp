// LLUIS TORRES PROCAS
// u1940589
// SESSIO 5

#include <string>
#include <iostream>
#include "ArbreExpressioAlg.h"
using namespace std;

/*PROGRAMA amb el cual creem la forma infixa d'una expressio algebraica i mostrem el seu resultat.
INPUT: l'algorisme entra sempre tenint primer el signe de l'operacio, seguit de dos parentesis amb els dos operands separats amb un espai a dins. Si hi han suboperacions, es repeteix el format els nivells que calguin.
OUTPUT: mostra la forma infixa d'una expressio algebraica i el seu resultat. */

int main() {
    ArbreExpressioAlg *a;
    string entrada;
    getline(cin,entrada);
    try {
        if (entrada.empty())throw "Cadena buida";
        else {
            a = new ArbreExpressioAlg(entrada);
            cout << "Entrada: " << a->preOrdre() << endl;
            cout << "Expressio algebraica: " << a->mostraExp() << endl;
            cout << "Resultat: " << a->operar() << endl;
        }
    }
    catch (const char *missatge){
        cerr << missatge << endl;
    }
    return(0);
}
