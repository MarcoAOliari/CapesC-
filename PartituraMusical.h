/*
 * PartituraMusical.h
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#ifndef PARTITURAMUSICAL_H_
#define PARTITURAMUSICAL_H_
#include "Producao.h"

class PartituraMusical : public Producao{
	string formacaoMusical;
public:
	PartituraMusical(const string, const string, const string, const string, const string, const string);
	string getFormacaoMusical();
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream&);
	virtual ~PartituraMusical();
};

#endif /* PARTITURAMUSICAL_H_ */
