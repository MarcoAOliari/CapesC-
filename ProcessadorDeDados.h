/*
 * ProcessadorDeDados.h
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#ifndef PROCESSADORDEDADOS_H_
#define PROCESSADORDEDADOS_H_
#include "Instituicao.h"
#include <map>
#include <string>
#include "Tokenizer.h"
#include <iostream>
#include <iterator>
#include <iomanip>
#include "NumberUtils.h"

using namespace std;

class ProcessadorDeDados {
	map<string, Instituicao*> instituicoes;
	map<string, PPG*> ppgs;
	vector<string> producoes;
	long pags;
	double denominadorMedia;

public:
	ProcessadorDeDados();
	void adicionaInstituicao(const string, const string);
	void adicionaProducao(const string, Producao* prod);
	void adicionaPPG(const string, const string, const string, const string);
	void adicionaProducaoEstatistica(const string);
	void calculaQuantidadePaginas(const string, const string);
	void setPagsProducao(const string, const string, Producao*);
	void preencheInstituicoes();
	void imprimeEstatisticas();
	void imprimeRede();
	void imprimePpg(const string);
	void imprimeIes(const string);
	void imprimeCsv(const string, const string);
	virtual ~ProcessadorDeDados();
};

#endif /* PROCESSADORDEDADOS_H_ */
