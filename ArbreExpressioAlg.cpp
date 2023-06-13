// LLUIS TORRES PROCAS
// u1940589
// SESSIO 5

#include "ArbreExpressioAlg.h"
#include <iostream>

using namespace std;

//CONSTRUCTORS I DESTRUCTORS
ArbreExpressioAlg::Nus::Nus()
{
// pre: -
// post: s’inicialitza el node
	fe = fd = NULL;
	// int: valor per defecte
}


ArbreExpressioAlg::Nus::Nus(Nus *a, Nus *b, const int &c)
{
// pre: cert
// post: posa a com a fill esquerra, b com a fill dret i c com a contingut
	fe = a;
	fd = b;
	cont = c;
}

ArbreExpressioAlg::Nus::~Nus()
{
// pre: cert
// post: elimina recursivament la memòria dels nodes de l’arbre
	if (fe != NULL)
		delete fe;
	if (fd != NULL)
		delete fd;
}

ArbreExpressioAlg::ArbreExpressioAlg()
{
	arrel = NULL;
}


ArbreExpressioAlg::ArbreExpressioAlg(ArbreExpressioAlg *a, ArbreExpressioAlg *b, const int &c)
{
	arrel = new Nus(a->arrel, b->arrel, c);
	a->arrel = NULL;
	b->arrel = NULL;
}


ArbreExpressioAlg::ArbreExpressioAlg(string cadena)
{
    int n=0;
    arrel=iArbreExpressioAlg(cadena,n);
}

ArbreExpressioAlg::~ArbreExpressioAlg()
{
	if (arrel != NULL)
		delete arrel;
}

//CONSULTORS
float ArbreExpressioAlg::operar() const
{
    if (esBuit())throw "Arbre buit";
    else return iOperar(arrel);
}

bool ArbreExpressioAlg::esBuit() const
{
	return (arrel == NULL);
}

int ArbreExpressioAlg::Contingut() const
{
	if (esBuit())throw "Arbre buit";
	else return arrel->cont;
}

string ArbreExpressioAlg::mostraExp() const
{
    stringstream res;
    if (esBuit())throw "Arbre buit";
    else if (arrel->fe != NULL){
        res << iExpAlg(arrel->fe) << " " << char(arrel->cont+'0') << " " << iExpAlg(arrel->fd);
    }
    else res << arrel->cont;
    return res.str();
}

string ArbreExpressioAlg::preOrdre() const
{
    if (esBuit())throw "Arbre buit";
	else return iPreOrdre(arrel);
}

ArbreBinari * ArbreExpressioAlg::FillEsquerre() const
{
	ArbreExpressioAlg * res = new ArbreExpressioAlg;
	if (esBuit()) throw "Arbre buit";
	else res->arrel = arrel->fe;
	return res;
}

ArbreBinari * ArbreExpressioAlg::FillDret() const
{
	ArbreExpressioAlg * res = new ArbreExpressioAlg;
    if (esBuit()) throw "Arbre buit";
	else res->arrel = arrel->fd;
	return res;
}

//METODES PRIVATS
ArbreExpressioAlg::Nus* ArbreExpressioAlg::iArbreExpressioAlg(const string & arbre, int &n)
{
    Nus * tree, *aux1, *aux2;
    int num = 0;
    if (arbre[n] == '-' and (arbre[n+1]-48)>=0 and (arbre[n+1]-48<=9)){
        n++;
        num = -(arbre[n]-'0');
    }
    else num = arbre[n]-'0';
    n++;
    while((arbre[n]-48)>=0 and (arbre[n]-48)<=9){
        if (num < 0) num = num*10 - (arbre[n]-48);
        else num = num*10 + (arbre[n]-48);
        n++;
    }
    if (arbre[n]!='('){
        tree = new Nus;
        tree->cont = num;
        tree->fd = tree->fe = NULL;
    }
    else {
        n++;
        aux1 = iArbreExpressioAlg(arbre,n);
        n++;
        aux2 = iArbreExpressioAlg(arbre,n);
        n++;
        tree = new Nus;
        tree->fe = aux1;
        tree->fd = aux2;
        tree->cont = num;
    }
    return tree;
}

float ArbreExpressioAlg::iOperar(const Nus *a) const
{
    float res;
    if(a->fe == NULL and a->fd == NULL){
        res=a->cont;
    }
    else {
        if(a->cont+'0' == '+') res = iOperar(a->fe) + iOperar(a->fd);
        else if(a->cont+'0' == '-') res = iOperar(a->fe) - iOperar(a->fd);
        else if(a->cont+'0' == '*') res = iOperar(a->fe) * iOperar(a->fd);
        else{
            if(iOperar(a->fd) == 0) throw "Divisio per 0"; //cerr << "...";
            else res = iOperar(a->fe) / iOperar(a->fd);
        }
    }
    return res;
}

string ArbreExpressioAlg::iExpAlg(Nus *a) const
{
    stringstream res;
    if (a->fe != NULL){
        res << "(" << iExpAlg(a->fe);
        res << " " << char(a->cont + '0') << " ";
        res << iExpAlg(a->fd) << ")";
    }
    else res << a->cont;
    return res.str();
}

string ArbreExpressioAlg::iPreOrdre(Nus *a) const
{
    stringstream res;
    if (a->fe != NULL){
        res << char(a->cont + '0');
        res << "(" << iPreOrdre(a->fe) << " ";
        res << iPreOrdre(a->fd) << ")";
    }
    else res << a->cont;
    return res.str();
}
