/*
 * Livro.cpp
 *
 *  Created on: 5 de jul de 2019
 *      Author: marco
 */

#include "Livro.h"

	/**
	 * Construtor da classe Livro, que extende Producao. Como atributo proprio, apenas o isbn.
	 * @param natureza - natureza da Producao
	 * @param titulo - titulo da Producao
	 * @param idioma - idioma em que foi escrita a Producao
	 * @param cidade - cidade em que foi produzida a Producao
	 * @param editora - editora responsavel pela Publicacao
	 * @param isbn - codigo representando o isbn (International Standard Book Number) do Livro
	 */
Livro::Livro(const string natureza, const string titulo, const string idioma, const string cidade, const string editora, const string isbn) : Producao(natureza, titulo, idioma, cidade, editora){
	this->isbn = isbn;
}

/**
 * Retorna o isbn do objeto Livro.
 * @return String representando o isbn do objeto Livro
 */
string Livro::getIsbn(){
	return this->isbn;
}

/**
 * Metodo sobrescrito para impressao mais simples da classe Livro.
 */
void Livro::print(ostream& o) const{
	o << this->natureza << ";" << this->titulo << ";" << this->idioma << ";" << this->editora << ";" << this->cidade << ";" << this->isbn << ";" << this->npags;
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outros Livros.
 * @return string como identificador de um Livro.
 */
string Livro::getIdentificador(){
	return this->natureza + this->titulo + this->idioma + this->editora + this->cidade + this->isbn + to_string(this->npags);
}

/**
 * Imprime cabecalho da classe Livro especificado no comando csv.
 */
void Livro::imprimeCabecalho(ostream& out){
	out << "Natureza;Titulo;Idioma;Editora;Cidade;ISBN;Paginas";
}

/**
 * Destrutor padrao
 */
Livro::~Livro() {
	// TODO Auto-generated destructor stub
}

