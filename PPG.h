/*
 * PPG.h
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#ifndef PPG_H_
#define PPG_H_
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include "StringUtils.h"
#include "Tokenizer.h"
#include "ordenadoresProducao.h"

using namespace std;
using namespace cpp_util;

class PPG {
	vector<string> instituicoes;
	string codigo;
	string nome;
	vector<Producao*> producoes;
public:
	PPG(const string, const string, const string);
	string getCodigo();
	string getNome();
	vector<string> getInstituicoes();
	void novaInstituicao(string nome);
	void novaProducao(Producao*);
	void imprimeInstituicoes();
	bool rede();
	vector<int> calculaEstatisticas();
	friend ostream& operator<<(ostream&, PPG const&);
	vector<Producao*> ordenaProducoes(string, vector<Producao*>);
	void imprimeProducoes(string tipo);
	virtual ~PPG();
};

#endif /* PPG_H_ */
