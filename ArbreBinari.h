// LLUIS TORRES PROCAS
// u1940589
// SESSIO 5

#ifndef ARBREBINARI_H
#define ARBREBINARI_H


class ArbreBinari {
public:
	ArbreBinari() {} //no cal en la classe virtual
	ArbreBinari(ArbreBinari *a, ArbreBinari *b, int c) { };
	virtual ~ArbreBinari() { } // cal una implementacio buida
	virtual bool esBuit() const = 0;
	virtual int Contingut() const = 0;
	virtual ArbreBinari * FillEsquerre() const = 0;
	virtual ArbreBinari * FillDret() const = 0;
};


#endif // ARBREBINARI_H
