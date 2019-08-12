/*
 * ArtigoPeriodico.cpp
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#include "ArtigoPeriodico.h"

/**
* Construtor da classe ArtigoPeriodico. Como atributos proprios, possui tres inteiros, representando o volume, o numero do fasciculo e a serie do ArtigoPeriodico,
* alem do codigo issn. Em todos os tres inteiros, tem-se uma verificacao de erro, para caso a String lida do arquivo csv de entrada nao esteja formatada da
* maneira ideal. Se o erro for detectado, os valores sao atribuidos como 0.
* @param natureza - natureza da Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param editora - editora responsavel pela Producao
* @param issn - codigo representando o issn (International Standard Serial Number) do Artigo
* @param volume - String representando o volume em que foi publicado o ArtigoPeriodico
* @param fasciculo - String representando o numero do fasciculo em que foi publicado o ArtigoPeriodico
* @param serie - String representando o numero da serie em que foi publicado o ArtigoPeriodico
*/
ArtigoPeriodico::ArtigoPeriodico(const string natureza, const string titulo, const string idioma, const string cidade, const string editora, const string issn, const string volume, const string fasciculo, const string serie) : Producao(natureza, titulo, idioma, cidade, editora) {
	this->issn = issn;

	try{ this->volume = stoi(volume); }
	catch(exception& e){ this->volume = 0; }

	try{ this->fasciculo = stoi(fasciculo); }
	catch(exception& e){ this->fasciculo = 0; }

	try{ this->serie = stoi(serie); }
	catch(exception& e){ this->serie = -1; }
}

/**
 * Retorna o codigo issn do Artigo.
 * @return string representando o codigo issn do Artigo.
 */
string ArtigoPeriodico::getIssn(){
	return this->issn;
}

/**
 * Retorna o volume do ArtigoPeriodico.
 * @return Inteiro representando o volume do ArtigoPeriodico
 */
int ArtigoPeriodico::getVolume(){
	return this->volume;
}

/**
 * Retorna o fasciculo do ArtigoPeriodico.
 * @return Inteiro representando o fasciculo do ArtigoPeriodico
 */
int ArtigoPeriodico::getFasciculo(){
	return this->fasciculo;
}

/**
 * Retorna a serie do ArtigoPeriodico.
 * @return Inteiro representando a serie do ArtigoPeriodico
 */
int ArtigoPeriodico::getSerie(){
	return this->serie;
}

/**
 * Metodo sobrescrito para impressao mais simples da classe ArtigoPeriodico. Realizam-se verificacoes para todos os inteiros
 * (volume, fasciculo, serie e npags), caso sejam maiores que 0 sao inclusos na impressao, ao contrario sao excluidos.
 */
void ArtigoPeriodico::print(ostream& o) const{
	o << this->natureza << ";" << this->idioma << ";" << this->editora << ";" << this->cidade << ";";

	if(this->volume > 0) o << this->volume << ";";
	else	o << "" << ";";

	if(this->fasciculo > 0) o << this->fasciculo << ";";
	else	o << "" << ";";

	if(this->serie > 0) o << this->serie << ";";
	else	o << "" << ";";

	o << this->issn << ";";

	if(npags > 0) o << this->npags;
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outros ArtigoPeriodico.
 * @return string como identificador de um ArtigoPeriodico.
 */
string ArtigoPeriodico::getIdentificador(){
	return this->natureza + this->idioma + this->editora + this->cidade + to_string(this->volume) +
			to_string(this->fasciculo) + to_string(this->serie) + this->issn + to_string(this->npags);
}

/**
 * Imprime cabecalho da classe ArtigoPeriodico especificado no comando csv.
 */
void ArtigoPeriodico::imprimeCabecalho(ostream& out){
	out << "Natureza;Idioma;Editora;Cidade;Volume;Fasciculo;Serie;ISSN;Paginas";
}

/**
 * Destrutor padrao.
 */
ArtigoPeriodico::~ArtigoPeriodico() {
	// TODO Auto-generated destructor stub
}

