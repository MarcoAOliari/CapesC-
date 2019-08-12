/*
 * OutraProducao.cpp
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#include "OutraProducao.h"

/**
* Construtor da classe OutraProducao. Todos os atributos sao extendidos de Publicacao e Producao.
* @param id - codigo identificador da Producao
* @param natureza - natureza de cada Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param editora - editora responsavel pela Publicacao
*/
OutraProducao::OutraProducao(const string natureza, const string titulo, const string idioma, const string cidade, const string editora) : Producao(natureza, titulo, idioma, cidade, editora){
}

/**
 * Metodo sobrescrito para impressao mais simples da classe OutraProducao. Verifica-se o numero de paginas,
 * que so eh impresso caso seja maior que 0.
 */
void OutraProducao::print(ostream& o) const{
	if(this->npags > 0)
		o << this->natureza << ";" << this->idioma  << ";" << this->editora  << ";" << this->cidade  << ";" << this->npags;
	else
		o << this->natureza << ";" << this->idioma  << ";" << this->editora  << ";" << this->cidade  << ";";
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outros Livros.
 * @return string como identificador de um Livro.
 */
string OutraProducao::getIdentificador(){
	return this->natureza + this->idioma  + this->editora  + this->cidade + to_string(this->npags);
}

/**
 * Imprime cabecalho da classe OutraProducao especificado no comando csv.
 */
void OutraProducao::imprimeCabecalho(ostream& out){
	out << "Natureza;Idioma;Editora;Cidade;Paginas";
}

/*
 * Destrutor padrao.
 */
OutraProducao::~OutraProducao() {
}

