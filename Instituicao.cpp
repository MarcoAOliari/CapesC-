/*
 * Instituicao.cpp
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#include "Instituicao.h"

/**
* Construtor da classe Instituicao, atribuindo um nome e uma sigla.
* @param nome - nome da instituicao
* @param sigla - sigla da instituicao
*/
Instituicao::Instituicao(const string nome, const string sigla) {
	this->nome = nome; this->sigla = sigla;
}

/**
 * Funcao utilizada para ordenar os ppgs pelos nomes.
 */
bool ordenaPPG(PPG* p1, PPG* p2){
	return (stringCompare(p1->getNome(), p2->getNome()));
}

/**
 * Retorna a sigla de um objeto Instituicao.
 * @return String representando a sigla da Instituicao
 */
string Instituicao::getSigla(){
	return this->sigla;
}

/**
 * Retorna o nome de um objeto Instituicao.
 * @return String representando o nome da Instituicao
 */
string Instituicao::getNome(){
	return this->nome;
}

/**
 * Sobrescrita do operador << para impressao mais simples da instituicao com o cout.
 */
ostream& operator<<(ostream& o, Instituicao const& inst){
	return o << inst.nome << " (" << inst.sigla << "):" << endl;
}

/**
 * Adiciona um PPG na lista de ppgs da Instituicao.
 * @param ppg - objeto do tipo PPG com seus atributos ja armazenados
 */
void Instituicao::adicionaPPG(PPG* ppg){
	this->ppgs.push_back(ppg);
}

/**
 * Imprime o vector de ppgs contida em uma Instituicao, ja ordenada da maneira especificada.
 */
void Instituicao::imprimePPGS(){
	sort(this->ppgs.begin(), this->ppgs.end(), ordenaPPG);

	vector<PPG*>::iterator iteradorPPG;

	for(iteradorPPG = this->ppgs.begin(); iteradorPPG != this->ppgs.end(); iteradorPPG++){
		cout << **iteradorPPG;
	}
}

/**
 * Destrutor padrao
 */
Instituicao::~Instituicao() {

}

