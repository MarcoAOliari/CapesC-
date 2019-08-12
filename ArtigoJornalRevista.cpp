/*
 * ArtigoJornalRevista.cpp
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#include "ArtigoJornalRevista.h"

/**
* Construtor da classe ArtigoJornalRevista. Como atributo proprio, possui uma data (DateUtils) e o issn. Para atribuir a data ao objeto,
* realiza-se uma verificacao de erro. Caso a string data lida do arquivo csv de entrada nao possua a formatacao ideal, o atributo data recebe 0.
* No contrario, a string eh transformada para a classe Data e armazenada no objeto.
* @param natureza - natureza da Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param editora - editora responsavel pela Producao
* @param issn - codigo representando o issn (International Standard Serial Number) do Artigo
* @param data - data de quando foi publicado o Artigo especificado
*/
ArtigoJornalRevista::ArtigoJornalRevista(const string natureza, const string titulo, const string idioma, const string cidade, const string editora, const string issn, const string data) : Producao(natureza, titulo, idioma, cidade, editora){
	this->issn = issn;
	try{
		this->data = parseDate(data, DATE_FORMAT_PT_BR_SHORT);
	}
	catch(exception& e){
		this->data = 0;
	}
}

/**
 * Retorna a data de publicacao do Artigo.
 * @return data time_t representando o dia em que foi publicado o Artigo
 */
time_t ArtigoJornalRevista::getData(){
	return this->data;
}

/**
 * Retorna o codigo issn do Artigo.
 * @return string representando o codigo issn do Artigo.
 */
string ArtigoJornalRevista::getIssn(){
	return this->issn;
}

/**
 * Metodo sobrescrito para impressao mais simples da classe ArtigoJornalRevista. Antes de retornar a String completa, verifica-se se a data
 * eh nula ou nao, e tambem se o numero de paginas eh maior que 0 ou nao.
 */
void ArtigoJornalRevista::print(ostream& o) const{
	o << this->titulo << ";" << this->idioma << ";" << this->cidade << ";";

	if(this->data != 0)
		o << formatDate(this->data, DATE_FORMAT_PT_BR_SHORT) << ";";

	o << this->issn << ";";

	if(this->npags > 0)
		o << this->npags;
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outros ArtigoJornalRevista.
 * @return string como identificador de um ArtigoJornalRevista.
 */
string ArtigoJornalRevista::getIdentificador(){
	return this->titulo + this->idioma + this->cidade + formatDate(this->data, DATE_FORMAT_PT_BR_SHORT) + this->issn + to_string(this->npags);
}

/**
 * Imprime cabecalho da classe ArtigoJornalRevista especificado no comando csv.
 */
void ArtigoJornalRevista::imprimeCabecalho(ostream& out){
	out << "Titulo;Idioma;Cidade;Data;ISSN;Paginas";
}

/**
 * Destrutor padrao.
 */
ArtigoJornalRevista::~ArtigoJornalRevista() {
	// TODO Auto-generated destructor stub
}

