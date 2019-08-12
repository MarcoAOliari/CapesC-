/*
 * Producao.h
 *
 *  Created on: 30 de jun de 2019
 *      Author: marco
 */

#ifndef PRODUCAO_H_
#define PRODUCAO_H_
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class Producao {
protected:
	string natureza;
	string titulo;
	string idioma;
	string cidade;
	string editora;
	int npags;

public:
	Producao(const string, const string, const string, const string, const string);
	string getNatureza();
	string getTitulo();
	string getIdioma();
	string getCidade();
	string getEditora();
	int getPags();
	void setPags(int pags);
	friend ostream& operator <<(ostream&, const Producao&);
	virtual void print(ostream&) const = 0;
	bool iguais(Producao* p2);
	virtual string getIdentificador() = 0;
	virtual void imprimeCabecalho(ostream&) = 0;
	virtual ~Producao();
};

#endif /* PRODUCAO_H_ */
