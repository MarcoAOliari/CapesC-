/*
 * PPG.cpp
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#include "PPG.h"

/**
* Construtor da classe PPG, que ja adiciona uma instituicao no seu vector de instituicoes (string).
* @param instituicao - nome da primeira instituicao lida com o PPG
* @param codigo - codigo do PPG
* @param nome - nome do PPG
*/
PPG::PPG(const string instituicao, const string codigo, const string nome) {
	this->instituicoes.push_back(instituicao);	this->codigo = codigo; this->nome = nome;
}

/**
 * Retorna o codigo do PPG.
 * @return String representando o codigo do PPG
 */
string PPG::getCodigo(){
	return this->codigo;
}

/**
 * Retorna o nome do PPG.
 * @return String representando o nome do PPG
 */
string PPG::getNome(){
	return this->nome;
}

/**
 * Retorna o vector com o nome das instituicoes responsaveis pelo PPG.
 * @return Vector de string com o nome das instituicoes responsaveis pelo PPG
 */
vector<string> PPG::getInstituicoes(){
	return this->instituicoes;
}

/**
 * Adiciona um novo nome de instituicao na lista de instituicoes (string) do PPG. Caso o nome ja esteja contido na lista,
 * o metodo retorna.
 * @param nome - nome da instituicao a ser adicionada
 */
void PPG::novaInstituicao(string nome){
	vector<string>::iterator it;
	for(it = this->instituicoes.begin(); it != this->instituicoes.end(); it++){
		if((*it) == nome)
			return;
	}
	this->instituicoes.push_back(nome);
}

/**
 * Adiciona uma nova Producao no PPG.
 * @param prod - objeto da classe Producao a ser adicionado.
 */
void PPG::novaProducao(Producao* prod){
	this->producoes.push_back(prod);
}

/**
 * Metodo auxiliar para a execucao do comando rede. Retorna verdadeiro caso o PPG tenha mais de uma instituicao responsavel
 * e falso caso contrario.
 * @return boolean true para vector com tamanho maior que 1, false caso contrario
 */
bool PPG::rede(){
	return (this->instituicoes.size() > 1);
}

/**
 * Imprime o nome e a sigla das instituicoes (ja ordenadas) responsaveis pelo PPG.
 */
void PPG::imprimeInstituicoes(){
	vector<string>::iterator it;
	vector<string> siglaNome;

	sort(this->instituicoes.begin(), this->instituicoes.end(), stringCompare);

	for(it = this->instituicoes.begin(); it != this->instituicoes.end(); it++){
		Tokenizer tok(*it, ';');
		siglaNome = tok.remaining();
		cout << '\t' << "- " << trim(siglaNome[0]) << " (" << siglaNome[1] << ")" << endl;
	}
}

/**
 * Calcula os dados estatisticos de um PPG especificados no comando PPG do trabalho e os retorna em um vetor. Os indices
 * correspondem aos seguintes dados:
 * - 0: quantidade de producoes da classe Anal
 * - 1: quantidade de producoes da classe ArtigoJornalRevista
 * - 2: quantidade de producoes da classe ArtigoPeriodico
 * - 3: quantidade de producoes da classe Livro
 * - 4: quantidade de producoes da classe PartituraMusical
 * - 5: quantidade de producoes da classe Traducao
 * - 6: quantidade de producoes da classe OutraProducao
 * - 7: numero de paginas produzidas por um PPG
 * @return - vector de inteiros representando os dados estatisticos de um PPG
 */
vector<int> PPG::calculaEstatisticas(){
	vector<int> estatisticas;

	for(int i=0; i<8; i++){
		estatisticas.push_back(0);
	}

	vector<Producao*>::iterator it;

	for(it = this->producoes.begin(); it != this->producoes.end(); it++){
		if(typeid(**it) == typeid(Anal)){
			estatisticas[0]++;
		}
		if(typeid(**it) == typeid(ArtigoJornalRevista)){
			estatisticas[1]++;
		}
		if(typeid(**it) == typeid(ArtigoPeriodico)){
			estatisticas[2]++;
		}
		if(typeid(**it) == typeid(Livro)){
			estatisticas[3]++;
		}
		if(typeid(**it) == typeid(PartituraMusical)){
			estatisticas[4]++;
		}
		if(typeid(**it) == typeid(Traducao)){
			estatisticas[5]++;
		}
		if(typeid(**it) == typeid(OutraProducao)){
			estatisticas[6]++;
		}
		estatisticas[7] += (**it).getPags();
	}

	return estatisticas;
}

/**
 * Sobrescrita do operador << para impressao mais simples de um PPG com o cout.
 */
ostream& operator<<(ostream& o, PPG const& ppg){
	return o << '\t' << "- " << ppg.nome << ": " << ppg.producoes.size() << " producoes" << endl;
}

/**
 * Funcao recebe uma string representando o tipo de Producao e um vector de Producoes (de apenas um tipo) a ser ordenado.
 * Apos ordenar o vector, o mesmo eh retornado.
 */
vector<Producao*> PPG::ordenaProducoes(string tipo, vector<Producao*> ordenar){
	if(tipo == "4Anal")
		sort(ordenar.begin(), ordenar.end(), ordenaAnal);
	else if(tipo == "19ArtigoJornalRevista")
		sort(ordenar.begin(), ordenar.end(), ordenaArtigoJornalRevista);
	else if(tipo == "15ArtigoPeriodico")
		sort(ordenar.begin(), ordenar.end(), ordenaArtigoPeriodico);
	else if(tipo == "5Livro")
		sort(ordenar.begin(), ordenar.end(), ordenaLivro);
	else if(tipo == "16PartituraMusical")
		sort(ordenar.begin(), ordenar.end(), ordenaPartituraMusical);
	else if(tipo == "8Traducao")
		sort(ordenar.begin(), ordenar.end(), ordenaTraducao);
	else if(tipo == "13OutraProducao")
		sort(ordenar.begin(), ordenar.end(), ordenaOutraProducao);

	return ordenar;

}

/**
 * Imprime producoes de um tipo especifico de um PPG. Primeiramente percorre-se o vector de producoes (Producao) do
 * PPG e armazena todas as producoes do tipo especificado em um outro vector. Depois disso, as producoes sao ordenadas
 * da maneira especificada pelo comando csv. Logo em seguida, as repeticoes de producao sao removidas e a lista eh
 * impressa.
 * @param tipo - nome da Classe que representa o tipo de producao a ser impressa
 */
void PPG::imprimeProducoes(string tipo){
	vector<Producao*>::iterator iteradorProducoes;
	vector<Producao*> producoesDoTipo;

	for(iteradorProducoes = this->producoes.begin(); iteradorProducoes != this->producoes.end(); iteradorProducoes++){
		string s = typeid(**iteradorProducoes).name();
		if(s == tipo){
			producoesDoTipo.push_back(*iteradorProducoes);
		}
	}

	producoesDoTipo = ordenaProducoes(tipo, producoesDoTipo);
	producoesDoTipo[0]->imprimeCabecalho(cout);
	cout << endl;

	for(iteradorProducoes = producoesDoTipo.begin(); iteradorProducoes != producoesDoTipo.end(); iteradorProducoes++){
		while((iteradorProducoes + 1) != producoesDoTipo.end() && (**iteradorProducoes).iguais((*(iteradorProducoes + 1)))){
			producoesDoTipo.erase(iteradorProducoes);
			continue;
		}
	}

	for(iteradorProducoes = producoesDoTipo.begin(); iteradorProducoes != producoesDoTipo.end(); iteradorProducoes++){
		cout << **iteradorProducoes << endl;
	}
}

/**
 * Todas as producoes contidas no vector de producoes do PPG sao deletadas, e logo apos este tambem eh.
 */
PPG::~PPG() {
	vector<Producao*>::iterator it;

	for(it = this->producoes.begin(); it != this->producoes.end(); it++){
		delete *it;
	}
}

