/*
 * main.cpp
 *
 *  Created on: Jun 25, 2019
 *      Author: vitor
 */

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Tokenizer.h"
#include "ProcessadorDeDados.h"
#include "LeitorCsv.h"
#include "ErroIO.h"

using namespace std;
using namespace cpp_util;

int main() {
	ProcessadorDeDados processador;

	string endereco; cin >> endereco;

	try{

		for(int i=0; i<7; i++){
			string arq; cin >> arq;
			LeitorCsv* leitor = new LeitorCsv(endereco+arq);
			leitor->leCsv(processador);
			delete leitor;
		}

		//processador.imprimeEstatisticas();

		string comando;	cin >> comando;

		if(comando == "rede"){
			processador.imprimeRede();
		}
		else if(comando == "ppg"){
			string codigo;	cin >> codigo;
			processador.imprimePpg(codigo);
		}
		else if(comando == "ies"){
			string sigla; cin >> sigla;
			processador.preencheInstituicoes();
			processador.imprimeIes(sigla);
		}
		else if(comando == "csv"){
			string codigo, tipo;	cin >> codigo;	cin >> tipo;
			processador.imprimeCsv(codigo, tipo);
		}
		else{
			cout << "Comando desconhecido.";
		}

	}catch(ErroIO& e){
		e.erro();
	}
}
