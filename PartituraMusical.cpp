/*
 * PartituraMusical.cpp
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#include "PartituraMusical.h"

/**
* Construtor da classe PartituraMusical. Como atributo proprio, tem-se formacao (que representa a formacao musical),
* sendo todos os outros extendidos de Producao.
* @param natureza - natureza da Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param editora - editora responsavel pela Publicacao
* @param formacao - formacao musical do autor da PartituraMusical
*/
PartituraMusical::PartituraMusical(const string natureza, const string titulo, const string idioma, const string cidade, const string editora, const string formacao) : Producao(natureza, titulo, idioma, cidade, editora) {
	this->formacaoMusical = formacao;
}

/**
 * Retorna a formacao musical do autor da PartituraMusical.
 * @return String representando a formacao musical do autor da PartituraMusical
 */
string PartituraMusical::getFormacaoMusical(){
	return this->formacaoMusical;
}

/**
 * Metodo sobrescrito para impressao mais simples da classe PartituraMusical. Verifica-se o numero de paginas,
 * que so eh impresso caso seja maior que 0.
 */
void PartituraMusical::print(ostream& o) const{
	if(this->npags > 0)
		o << this->natureza << ";" << this->editora << ";" << this->cidade << ";" << this->formacaoMusical << ";" << this->npags;
	else
		o << this->natureza << ";" << this->editora << ";" << this->cidade << ";" << this->formacaoMusical << ";";
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outras PartituraMusical.
 * @return string como identificador de uma PartituraMusical.
 */
string PartituraMusical::getIdentificador(){
	return this->natureza + this->editora + this->cidade + this->formacaoMusical + to_string(this->npags);
}

/**
 * Imprime cabecalho da classe PartituraMusical especificado no comando csv.
 */
void PartituraMusical::imprimeCabecalho(ostream& out){
	out << "Natureza;Editora;Cidade;Formacao;Paginas";
}

/**
 * Destrutor padrao.
 */
PartituraMusical::~PartituraMusical() {
	// TODO Auto-generated destructor stub
}

