// LLUIS TORRES PROCAS
// u1940589
// SESSIO 5

#ifndef ARBREEXPRESSIOALG_H
#define ARBREEXPRESSIOALG_H
#include "ArbreBinari.h"
#include <iostream>
#include <sstream>

using namespace std;

/*SUBCLASSE d'arbre binari orientat a llegir i calcular expresions algebraiques guardant-les en un arbre binari dinamic. l'algorisme sentrarà sempre tenint primer el signe de l'operacio, seguit de dos
parentesis amb els dos operands separats amb un espai a dins. Si hi han suboperacions, es repeteix el format els nivells que calguin. Retorna dos strings amb la forma infixa d'una expressio algebraica
 i el seu resultat. */

class ArbreExpressioAlg : public ArbreBinari {
public:
    //CONSTRUCTORS
	ArbreExpressioAlg();
	// Pre: --;
	// Post: crea un arbre buit;
	ArbreExpressioAlg(ArbreExpressioAlg*a, ArbreExpressioAlg*b, const int &c);
	// Pre: a<>NULL ^ b<>NULL;
	// Post: crea un arbre amb els parametres donats;
	ArbreExpressioAlg(string cadena);
	// Pre: cadena conte el recorregut en preordre d'un arbre d'enters en el format vist a teoria
	// Post: s'ha creat un arbre que correspon al recorregut en preordre que hi ha a cadena

	//DESTRUCTOR
	~ArbreExpressioAlg();
	// Pre: --;
	// Post: elimina la memòria que té reservada l’arbre;

    //CONSULTORS
    float operar() const;
    // Pre: l'arbre ha de contenir una expressio algebraica amb '*', '+', '/' o '-';
    // Post: llegeix i retorna el resultat de l'expressio o ceer si arbre buit;;
	bool esBuit() const;
	// Pre: --;
	// Post: cert si l’arbre és buit;
	int Contingut() const;
	// Pre: --;
	// Post: retorna l’int que hi ha a l’arrel o ceer si arbre buit;;
	string mostraExp() const;
    // Pre: --;
    // Post: retorna cadena amb el recorregut en inordre d'aquest arbre amb el format de la forma infixa d'una expressió algebraica o ceer si arbre buit;
    string preOrdre() const;
    // Pre: --;
    // Post: retorna cadena amb el recorregut en preordre d'aquest arbre amb el format normal o ceer si arbre buit;
	ArbreBinari * FillEsquerre() const;
	// Pre: no buit;
	// Post: retorna el fill esquerre o ceer si arbre buit;
	ArbreBinari * FillDret() const;
	// Pre: no buit;
	// Post: retorna el fill dret o ceer si arbre buit;

private:
	struct Nus {
		int cont;
		Nus *fe, *fd;

		Nus();
		Nus(Nus *a, Nus *b, const int &c);
		~Nus();
	};

    //METODES
    Nus*iArbreExpressioAlg(const string&arbre, int &n);
    //Pre: arbre en el string escrit segons teoria;
    // Post: s'ha creat un arbre que correspon al recorregut en preordre que hi ha al string
    float iOperar(const Nus *a) const;
    // Pre: l'arbre ha de contenir una expressio algebraica amb '*', '+', '/' o '-'. Arbre no buit;
    // Post: llegeix i retorna el resultat de l'expressio;
    string iExpAlg(Nus *a) const;
    // Pre: arbre no buit;
    // Post: retorna cadena amb el recorregut en inordre d'aquest arbre en el format d'una expressió algebraica;
    string iPreOrdre(Nus *a) const;
    // Pre: arbre no buit;
    // Post: retorna cadena amb el recorregut en preordre d'aquest arbre amb el format normal o ceer si arbre buit;
    ArbreExpressioAlg(const ArbreExpressioAlg &a); // no es pot usar el ct de còpia;
	ArbreExpressioAlg & operator=(const ArbreExpressioAlg &a); // no es pot usar l'op =;

	// inv: arrel=NULL o arrel és un punter a una jerarquia disjunta de nodes
	Nus * arrel; // representació de l’arbre

};

#endif // ArbreExpressioAlg_H
