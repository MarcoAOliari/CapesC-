/*
 * Livro.h
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#ifndef LIVRO_H_
#define LIVRO_H_
#include "Producao.h"

class Livro : public Producao{
	string isbn;

public:
	Livro(const string, const string, const string, const string, const string, const string);
	string getIsbn();
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream&);
	virtual ~Livro();
};

#endif /* LIVRO_H_ */
