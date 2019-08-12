/*
 * Anal.cpp
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#include "Anal.h"

/**
* Construtor da classe Anal. Como atributo proprio, apenas evento, enquanto os demais sao extendidos por heranca
* da classe Producao.
* @param natureza - natureza da Producao
* @param titulo - titulo da Producao
* @param idioma - idioma em que foi escrita a Producao
* @param cidade - cidade em que foi produzida a Producao
* @param evento - evento onde ocorreu o Anal
*/
Anal::Anal(const string natureza, const string titulo, const string idioma, const string cidade, const string evento) : Producao(natureza, titulo, idioma, cidade, " ") {
	this->evento = evento;
}

/**
 * Retorna o nome do evento onde foi realizado o Anal.
 * @return string com o nome do evento.
 */
string Anal::getEvento(){
	return this->evento;
}

/**
 * Funcao sobrescrita para impressao mais simples de um Anal. Caso o numero de paginas seja menor que 0, imprime todos os atributos
 * da classe (herdados e proprios) com excecao do numero de paginas. No contrario, imprime todos os atributos ordenados
 * de acordo com o solicitado.
 */
void Anal::print(ostream& o) const{
	if(this->npags > 0)
		o << this->natureza << ";" << this->titulo << ";" << this->idioma << ";" << this->evento << ";" << this->cidade << ";" << this->npags;
	else
		o << this->natureza << ";" << this->titulo << ";" << this->idioma << ";" << this->evento << ";" << this->cidade << ";";
}

/**
 * Retorna todos os atributos da classe como string para comparacao com outros anais.
 * @return string como identificador de um Anal.
 */
string Anal::getIdentificador(){
	return (this->natureza + this->titulo + this->idioma + this->evento + this->cidade + to_string(this->npags));
}

/**
 * Imprime o cabecalho dos Anais pedido no comando csv do programa.
 */
void Anal::imprimeCabecalho(ostream& out) {
	out << "Natureza;Titulo;Idioma;Evento;Cidade;Paginas";
}

/**
 * Destrutor padrão.
 */
Anal::~Anal() {
	// TODO Auto-generated destructor stub
}

