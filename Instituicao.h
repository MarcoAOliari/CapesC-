/*
 * Instituicao.h
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#ifndef INSTITUICAO_H_
#define INSTITUICAO_H_
#include <string>
#include <vector>
#include "Tokenizer.h"
#include "PPG.h"
#include "StringUtils.h"

using namespace std;
using namespace cpp_util;

class Instituicao {
	string nome;
	string sigla;
	vector<PPG*> ppgs;

public:
	Instituicao(const string, const string);
	string getSigla();
	string getNome();
	void adicionaPPG(PPG* ppg);
	friend ostream& operator<<(ostream&, Instituicao const&);
	void imprimePPGS();
	virtual ~Instituicao();
};

#endif /* INSTITUICAO_H_ */
