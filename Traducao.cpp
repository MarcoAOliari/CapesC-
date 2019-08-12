/*
 * Traducao.cpp
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#include "Traducao.h"

/**
* Construtor da classe Traducao. Como atributo proprio, apenas traducao, sendo todos os outros extendidos de Producao.
* @param natureza - natureza da Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param editora - editora responsavel pela Publicacao
* @param traducao - idioma de traducao da Traducao
*/
Traducao::Traducao(const string natureza, const string titulo, const string idioma, const string cidade, const string editora, const string traducao) : Producao(natureza, titulo, idioma, cidade, editora) {
	this->traducao = traducao;
}

/**
 * Retorna o idioma de traducao da Traducao.
 * @return String que representa o idioma de traducao da Traducao.
 */
string Traducao::getTraducao(){
	return this->traducao;
}

/**
 * Metodo sobrescrito para impressao mais simples da classe Traducao. Verifica-se o numero de paginas, caso seja maior que 0
 * eh considerado na impressao, no contrario nao.
 */
void Traducao::print(ostream& o) const{
	if(this->npags > 0)
		o << this->natureza << ";" << this->titulo << ";" << this->idioma << ";" << this->editora << ";" << this->cidade << ";" << this->traducao << ";" << this->npags;
	else
		o << this->natureza << ";" << this->titulo << ";" << this->idioma << ";" << this->editora << ";" << this->cidade << ";" << this->traducao << ";";
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outras Traducao.
 * @return string como identificador de uma Traducao.
 */
string Traducao::getIdentificador(){
	return this->natureza + this->titulo + this->idioma + this->editora + this->cidade + this->traducao + to_string(this->npags);
}

/**
 * Imprime cabecalho da classe Traducao especificado no comando csv.
 */
void Traducao::imprimeCabecalho(ostream& out){
	out << "Natureza;Titulo;Idioma;Editora;Cidade;Traducao;Paginas";
}

/**
 * Destrutor padrao.
 */
Traducao::~Traducao() {
	// TODO Auto-generated destructor stub
}

