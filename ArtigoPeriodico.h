/*
 * ArtigoPeriodico.h
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#ifndef ARTIGOPERIODICO_H_
#define ARTIGOPERIODICO_H_
#include "Producao.h"

class ArtigoPeriodico : public Producao {
	string issn;
	int volume;
	int fasciculo;
	int serie;

public:
	ArtigoPeriodico(const string, const string, const string, const string, const string, const string, const string, const string, const string);
	string getIssn();
	int getFasciculo();
	int getVolume();
	int getSerie();
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream&);
	virtual ~ArtigoPeriodico();
};

#endif /* ARTIGOPERIODICO_H_ */
