/*
 * LeitorCsv.h
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#ifndef LEITORCSV_H_
#define LEITORCSV_H_
#include <string>
#include <vector>
#include <iostream>
#include "ProcessadorDeDados.h"

using namespace std;

class LeitorCsv {
	vector<string> info;

public:
	LeitorCsv(const string);
	int leitorCabecalho(const vector<string>, const string);
	void leCsv(ProcessadorDeDados&);
	virtual ~LeitorCsv();
};

#endif /* LEITORCSV_H_ */
