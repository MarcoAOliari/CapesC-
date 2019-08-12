/*
 * ordenadoresProducao.h
 *
 *  Created on: 8 de jul de 2019
 *      Author: marco
 */

#ifndef ORDENADORESPRODUCAO_H_
#define ORDENADORESPRODUCAO_H_
#include <iostream>
#include <string>
#include "Producao.h"
#include "Anal.h"
#include "ArtigoJornalRevista.h"
#include "ArtigoPeriodico.h"
#include "Livro.h"
#include "OutraProducao.h"
#include "PartituraMusical.h"
#include "Traducao.h"
#include "StringUtils.h"

using namespace std;

bool ordenaAnal(Producao* p1, Producao* p2);
bool ordenaArtigoJornalRevista(Producao* p1, Producao* p2);
bool ordenaArtigoPeriodico(Producao* p1, Producao* p2);
bool ordenaLivro(Producao* p1, Producao* p2);
bool ordenaOutraProducao(Producao* p1, Producao* p2);
bool ordenaPartituraMusical(Producao* p1, Producao* p2);
bool ordenaTraducao(Producao* p1, Producao* p2);

#endif /* ORDENADORESPRODUCAO_H_ */
