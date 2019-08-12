/*
 * OutraProducao.h
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#ifndef OUTRAPRODUCAO_H_
#define OUTRAPRODUCAO_H_
#include "Producao.h"

class OutraProducao : public Producao{

public:
	OutraProducao(const string, const string, const string, const string, const string);
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream&);
	virtual ~OutraProducao();
};

#endif /* OUTRAPRODUCAO_H_ */
