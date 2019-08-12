/*
 * Anal.h
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#ifndef ANAL_H_
#define ANAL_H_
#include "Producao.h"

class Anal : public Producao{
	string evento;

public:
	Anal(const string, const string, const string, const string, const string);
	string getEvento();
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream& out);
	virtual ~Anal();
};

#endif /* ANAL_H_ */
