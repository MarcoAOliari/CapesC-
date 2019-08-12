/*
 * Producao.cpp
 *
 *  Created on: 30 de jun de 2019
 *      Author: marco
 */

#include "Producao.h"

/**
* Construtor da classe abstrata Producao.
* @param natureza - natureza da Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param editora - editora que publicou a Producao
*/
Producao::Producao(const string natureza, const string titulo, const string idioma, const string cidade, const string editora) {
	this->natureza = natureza; this->titulo = titulo; this->idioma = idioma; this->cidade = cidade; this->editora = editora;
	this->npags = 0;
}

/**
 * Retorna a natureza da Producao.
 * @return String representando a natureza da Producao
 */
string Producao::getNatureza(){
	return this->natureza;
}

/**
 * Retorna o titulo da Producao.
 * @return String representando o titulo da Producao
 */
string Producao::getTitulo(){
	return this->titulo;
}

/**
 * Retorna o idioma da Producao.
 * @return String representando o idioma da Producao
 */
string Producao::getIdioma(){
	return this->idioma;
}

/**
 * Retorna a cidade da Producao.
 * @return String representando a cidade da Producao
 */
string Producao::getCidade(){
	return this->cidade;
}

/**
 * Retorna a editora da Publicacao.
 * @return String representando a editora da Publicacao
 */
string Producao::getEditora(){
	return this->editora;
}

/**
 * Retorna o numero de paginas da Producao.
 * @return Inteiro representando o numero de paginas da Producao
 */
int Producao::getPags(){
	return this->npags;
}

/**
 * Atribui a quantidade de paginas para uma Producao, com o valor ja verificado.
 */
void Producao::setPags(int pags){
	this->npags = pags;
}

/**
 * Sobrescrita do operador << para impressao simplificada das producoes diretamente pelo cout.
 */
ostream& operator <<(ostream& os, const Producao& producao){
	producao.print(os);
	return os;
}

/**
 * Funcao utilizada para evitar a impressao de producoes iguais no comando csv.
 * @return boolean true caso as producoes sejam iguais, false caso contrario
 */
bool Producao::iguais(Producao* p2){
	if(this->getIdentificador() == p2->getIdentificador())
		return true;
	return false;
}

/**
 * Destrutor padrão.
 */
Producao::~Producao() {
	// TODO Auto-generated destructor stub
}

