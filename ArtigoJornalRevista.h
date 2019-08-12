/*
 * ArtigoJornalRevista.h
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#ifndef ARTIGOJORNALREVISTA_H_
#define ARTIGOJORNALREVISTA_H_
#include <exception>
#include <ctime>
#include "Producao.h"
#include "DateUtils.h"

using namespace cpp_util;

class ArtigoJornalRevista : public Producao{
	string issn;
	time_t data;
public:
	ArtigoJornalRevista(const string, const string, const string, const string, const string, const string, const string);
	time_t getData();
	string getIssn();
	virtual void print(ostream&) const;
	virtual string getIdentificador();
	virtual void imprimeCabecalho(ostream&);
	virtual ~ArtigoJornalRevista();
};

#endif /* ARTIGOJORNALREVISTA_H_ */
