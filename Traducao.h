/*
 * Traducao.h
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#ifndef TRADUCAO_H_
#define TRADUCAO_H_
#include "Producao.h"

class Traducao : public Producao{
	string traducao;

public:
	Traducao(const string, const string, const string, const string, const string, const string);
	string getTraducao();
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream&);
	virtual ~Traducao();
};

#endif /* TRADUCAO_H_ */
