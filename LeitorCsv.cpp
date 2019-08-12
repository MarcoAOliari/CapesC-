/*
 * LeitorCsv.cpp
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#include <fstream>
#include <stdexcept>
#include "Tokenizer.h"
#include "LeitorCsv.h"
#include "Producao.h"
#include "Anal.h"
#include "ArtigoJornalRevista.h"
#include "ArtigoPeriodico.h"
#include "Livro.h"
#include "OutraProducao.h"
#include "PartituraMusical.h"
#include "Traducao.h"
#include "ErroIO.h"

using namespace cpp_util;

/**
 * Construtor da classe LeitorCsv, recebendo o arquivo ja com seu caminho especificado e o armazenando como string.
 */
LeitorCsv::LeitorCsv(const string arquivo) {
	this->info.push_back(arquivo);
}

/**
 * Metodo utilizado para retornar a posicao do campo especificado pelo usuario, para o encapsulamento correto dos atributos
 * @param cabecalho - cabecalho do arquivo csv
 * @param campo - nome do campo correspondente a coluna desejada
 * @return Inteiro correspondente a posicao do vetor onde pode ser encontrado o campo desejado
 */
int LeitorCsv::leitorCabecalho(const vector<string> cabecalho, const string campo){
	for(unsigned int i=0; i<cabecalho.size(); i++){
		if(cabecalho[i] == campo)
			return i;
	}
	return 0;
}

/**
 * Metodo utilizado para realizar a leitura do arquivo csv fornecido pelo usuario, responsavel por encapsular os dados e levantar estatisticas.
 * Primeiramente o cabecalho eh lido e armazenado, para ser utilizado posteriormente na funcao leitorCabecalho, onde armazenara os atributos nas suas respectivas classes.
 * O campo de subtipo eh verificado para identificar o tipo de producao a ser criado. Depois de ja atribuido, a classe Producao eh criada e os dados sao tratados por
 * funcoes da classe ProcessadorDeDados, que serao explicitados no proprio arquivo.
 * @param processador - Processador de dados onde as informacoes serao direcionadas as suas respectivas classes e serao calculadas as estatisticas
 * @throws ErroIO, caso o arquivo fornecido pelo usuario nao seja encontrado
 */
void LeitorCsv::leCsv(ProcessadorDeDados& processador){
	ifstream in(this->info[0]);
	if(! in.good()){
		in.close();
		throw (ErroIO());
	}

	string linha, primeiraLinha;
	Producao* prod;

	getline(in, primeiraLinha);
	vector<string> cabecalho;
	Tokenizer tok(primeiraLinha, ';');
	cabecalho = tok.remaining();

	while(getline(in, linha)){
		Tokenizer tok(linha, ';');
		this->info = tok.remaining();
		processador.adicionaInstituicao(info[3], info[2]);

		if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("8")) {
			prod = new Anal(info[leitorCabecalho(cabecalho, "DS_NATUREZA")], info[leitorCabecalho(cabecalho, "NM_TITULO")], info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE")], info[leitorCabecalho(cabecalho, "DS_EVENTO")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINA_INICIAL")], info[leitorCabecalho(cabecalho, "NR_PAGINA_FINAL")], prod);
		}
		else if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("9")) {
			prod = new ArtigoJornalRevista(" ", info[leitorCabecalho(cabecalho, "NM_TITULO")], info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE")], " ", info[leitorCabecalho(cabecalho, "DS_ISSN")], info[leitorCabecalho(cabecalho, "DT_PUBLICACAO")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINA_INICIAL")], info[leitorCabecalho(cabecalho, "NR_PAGINA_FINAL")], prod);
		}
		else if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("10")) {
			prod = new OutraProducao(info[leitorCabecalho(cabecalho, "DS_NATUREZA")], " ", info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE")], info[leitorCabecalho(cabecalho, "NM_EDITORA")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINAS")], " ", prod);
		}
		else if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("21")) {
			prod = new Traducao(info[leitorCabecalho(cabecalho, "DS_NATUREZA")], info[leitorCabecalho(cabecalho, "NM_TITULO")], info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE")], info[leitorCabecalho(cabecalho, "NM_EDITORA_TRADUCAO")], info[leitorCabecalho(cabecalho, "DS_IDIOMA_TRADUCAO")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINAS")], " ", prod);
		}
		else if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("25")) {
			prod = new ArtigoPeriodico(info[leitorCabecalho(cabecalho, "DS_NATUREZA")], info[leitorCabecalho(cabecalho, "NM_PROGRAMA_IES")], info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE")], info[leitorCabecalho(cabecalho, "NM_EDITORA")], info[leitorCabecalho(cabecalho, "DS_ISSN")],
			info[leitorCabecalho(cabecalho, "NR_VOLUME")], info[leitorCabecalho(cabecalho, "DS_FASCICULO")], info[leitorCabecalho(cabecalho, "NR_SERIE")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINA_INICIAL")], info[leitorCabecalho(cabecalho, "NR_PAGINA_FINAL")], prod);
		}
		else if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("26")) {
			prod = new Livro(info[leitorCabecalho(cabecalho, "DS_NATUREZA")], info[leitorCabecalho(cabecalho, "NM_TITULO")], info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE_PAIS")], info[leitorCabecalho(cabecalho, "NM_EDITORA")], info[leitorCabecalho(cabecalho, "DS_ISBN")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINAS_CONTRIBUICAO")], " ", prod);
		}
		else if(info[leitorCabecalho(cabecalho, "ID_SUBTIPO_PRODUCAO")] == ("28")) {
			prod = new PartituraMusical(info[leitorCabecalho(cabecalho, "DS_NATUREZA")], " ", info[leitorCabecalho(cabecalho, "DS_IDIOMA")],
			info[leitorCabecalho(cabecalho, "NM_CIDADE")], info[leitorCabecalho(cabecalho, "NM_EDITORA")], info[leitorCabecalho(cabecalho, "DS_FORMACAO_INSTRUMENTAL")]);
			processador.setPagsProducao(info[leitorCabecalho(cabecalho, "NR_PAGINAS")], " ", prod);
		}

		processador.adicionaPPG(info[0], info[1], info[3], info[2]);
		processador.adicionaProducaoEstatistica(info[5]);
		processador.calculaQuantidadePaginas(info[14], info[13]);
		processador.adicionaProducao(info[0], prod);
	}

}

/**
 * Destrutor padrao
 */
LeitorCsv::~LeitorCsv() {

}

