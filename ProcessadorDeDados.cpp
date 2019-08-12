/*
 * ProcessadorDeDados.cpp
 *
 *  Created on: 29 de jun de 2019
 *      Author: marco
 */

#include "ProcessadorDeDados.h"

using namespace cpp_util;

/**
 * Construtor da classe ProcessadorDeDados. Nao recebe nenhum parametro, apenas atribui o valor de 0 ao numero de paginas e
 * ao denominador da media (utilizados na primeira parte do trabalho).
 */
ProcessadorDeDados::ProcessadorDeDados(){
	this->pags = 0;	this->denominadorMedia = 0;
}

/**
 * Transforma uma string em long (caso seja valida, ao contrario lanca excecao).
 * @return long representando o numero de paginas da string
 */
long parsePositiveLong(string s) {
	try {
		if (isNumber(s)) return stol(s);
		else return -1;
	}
	catch (exception& e) {
		return -1;
	}
}

/**
 * Funcao utilizada na funcao sort para organizar as instituicoes de acordo com seus respectivos nomes.
 */
bool ordenaInstituicoes(Instituicao* i1, Instituicao* i2){
	return (stringCompare(i1->getNome(), i2->getNome()));
}

/**
 * Adiciona uma instituicao no map de instituicoes (classe Instituicao).
 * A chave de busca consiste na concatenacao entre nome e sigla, para torna-la menos repetivel.
 * @param nome - nome completo da instituicao
 * @param sigla - sigla da instituicao
 */
void ProcessadorDeDados::adicionaInstituicao(const string nome, const string sigla){
	if(this->instituicoes.find(nome+sigla) != this->instituicoes.end()){
		this->instituicoes.insert(make_pair(nome+sigla, new Instituicao(nome, sigla)));
	}
}

/**
 * Adiciona uma producao (classe Producao) no seu respectivo ppg, encontrado pelo codigo fornecido pelo arquivo csv que tambem funciona como chave.
 * As repeticoes de producao sao tratadas para a parte 5 posteriomente.
 * @param codigoPPG - codigo de identificacao do ppg responsavel pela producao
 * @param prod - objeto da classe producao ja especificado com seus atributos
 */
void ProcessadorDeDados::adicionaProducao(const string codigo, Producao* prod){
	this->ppgs.find(codigo)->second->novaProducao(prod);
}

/**
 * Adiciona um novo ppg no map de ppgs (classe PPG). Alem disso, caso o ppg ja esteja inserido,
 * adiciona uma nova instituicao no vector de instituicoes do PPG (string).
 * Para preencher esse vector, envia-se uma string concatenando a sigla + " ;" + instituicao. A string central
 * foi escolhida de maneira estrategica para auxiliar na organizacao por ordem alfabetica dos dados.
 * Ja para a tabela do proprio processador, a chave de busca utilizada foi o codigo fornecido pelo arquivo csv de entrada.
 * @param codigo - codigo do ppg fornecido pelo arquivo csv
 * @param nome - nome do ppg a ser adicionado
 * @param instituicao - nome completo da instituicao responsavel pelo ppg
 * @param sigla - sigla da intituicao responsavel pelo ppg
 */
void ProcessadorDeDados::adicionaPPG(const string codigo, const string nome, const string instituicao, const string sigla){
	map<string, PPG*>::iterator it = this->ppgs.find(codigo);

	if(it != this->ppgs.end()){
		it->second->novaInstituicao(sigla+" ;"+instituicao);
		return;
	}
	this->ppgs.insert(make_pair(codigo, new PPG(sigla+" ;"+instituicao, codigo, nome)));
}

/**
 * Adiciona uma nova producao no vector de producoes (string) do processador de dados para realizar a contagem.
 * @param nome - nome da producao
 */
void ProcessadorDeDados::adicionaProducaoEstatistica(const string nome){
	this->producoes.push_back(nome);
}

void ProcessadorDeDados::calculaQuantidadePaginas(const string pagInicial, const string pagFinal){
	long inicial = parsePositiveLong(pagInicial);
	long final = parsePositiveLong(pagFinal);

			if (inicial != -1 && final != -1) {
				long tamanho = final - inicial + 1;
				if (tamanho > 0 && tamanho < 2000){ this->pags += tamanho; this->denominadorMedia++;};
			}
}

/**
 * Faz a contabilidade das paginas de uma certa producao. Para paginas com apenas um campo no cabecalho com numero de paginas, o parametro
 * pagInicial é " ". Caso os valores sejam possiveis de serem convertidos para numero de paginas e atendam as especificidades do trabalho
 * (verificacoes no parsePositiveLong), o valor eh atribuido a producao passada como parametro.
 * @param pagInicial string representando a pagina inicial
 * @param pagFinal string representando a pagina final
 * @param prod Producao responsavel pelo numero de paginas
 */
void ProcessadorDeDados::setPagsProducao(const string pagInicial, const string pagFinal, Producao* prod){
	long inicial = parsePositiveLong(pagInicial);

	if(pagFinal == " "){
		if(inicial > 0 && inicial < 2000)
			prod->setPags(inicial);
		else
			prod->setPags(0);
		return;
	}

	long final = parsePositiveLong(pagFinal);

	if (inicial != -1 && final != -1) {
		long tamanho = final - inicial + 1;
		if (tamanho > 0 && tamanho < 2000){ prod->setPags(tamanho); };
	}
}

/**
 * Percorre o map de ppgs (classe PPG), preenchendo cada instituicao do map de instituicoes (classe Instituicao) com suas
 * respectivas ppgs responsaveis.
 * A chave de busca da tabela de instituicoes corresponde a concatenacao nomeInstituicao + siglaInstituicao, enquanto as instituicoes sao
 * guardadas dentro de cada ppg como sigla + " ;" + nome. Assim, realiza-se o split do nome de cada instituicao da lista de strings do ppg
 * para separarmos o nome e a sigla, e a utilizarmos como chave para buscar a instituicao e adicionar o ppg no vector de ppgs contida
 * em cada Instituicao.
 */
void ProcessadorDeDados::preencheInstituicoes(){
	map<string, PPG*>::iterator iteradorPPG;

	for(iteradorPPG = this->ppgs.begin(); iteradorPPG != this->ppgs.end(); iteradorPPG++){
		vector<string> instituicoesPPG = iteradorPPG->second->getInstituicoes();
		vector<string>::iterator iteradorNomeInstituicoes;

		for(iteradorNomeInstituicoes = instituicoesPPG.begin(); iteradorNomeInstituicoes != instituicoesPPG.end(); iteradorNomeInstituicoes++){
			Tokenizer tok((*iteradorNomeInstituicoes), ';');
			vector<string> siglaNome = tok.remaining();
			if(this->instituicoes.find(siglaNome[1] + trim(siglaNome[0])) != this->instituicoes.end())
				this->instituicoes.find(siglaNome[1] + trim(siglaNome[0]))->second->adicionaPPG(iteradorPPG->second);
		}
	}
}

/**
 * Realiza a impressao dos dados estatisticos solicitados na primeira parte do trabalho.
 */
void ProcessadorDeDados::imprimeEstatisticas(){
	cout << "Instituicoes que publicaram em anais: " << this->instituicoes.size() << endl;
	cout << "PPGs que publicaram em anais: " << this->ppgs.size() << endl;
	cout << "Quantidade de producoes em anais: " << this->producoes.size() << endl;
	cout << "Quantidade de paginas publicadas em anais: " << this->pags << endl;
	cout << "Media de paginas por publicacao: " << formatDouble(this->pags/this->denominadorMedia, 1, LOCALE_PT_BR) << endl;
}

/**
 * Imprime todos os ppgs que sao administrados por mais de uma instituicao.
 * Percorre-se o map de ppgs por completo verificando a presenca ou nao de mais de uma instituicao em cada ppg. Depois do vector
 * ja completo, o vector eh ordenado de acordo com o codigo de cada ppg e logo depois sao impressos os ppgs em ordem, junto
 * com suas instituicoes (ordenadas por sigla e por nome).
 */
void ProcessadorDeDados::imprimeRede(){
	cout << "Programas em rede:" << endl;

	map<string, PPG*>::iterator it;

	for(it = this->ppgs.begin(); it != this->ppgs.end(); it++){
		if(it->second->rede()){
			cout << it->second->getCodigo() << ": " << it->second->getNome() << endl;
			it->second->imprimeInstituicoes();
		}
	}
}

/**
 * Imprime um ppg especificada pelo usuario, assim como suas estatisticas de producao (instituicoes responsaveis e
 * quantidade de producoes de cada tipo). Caso o codigo fornecido nao tenha sido registrado, o metodo imprime uma
 * mensagem de erro e retorna.
 * @param codigo - codigo do ppg a ser impresso
 */
void ProcessadorDeDados::imprimePpg(const string codigo){
	map<string, PPG*>::iterator it = this->ppgs.find(codigo);

	if(it == this->ppgs.end()){
		cout << "PPG nao encontrado.";
		return;
	}
	cout << "Programa: " << it->second->getNome() << endl;
	cout << "Instituicoes:" << endl;
	it->second->imprimeInstituicoes();
	cout << endl;
	cout << "Quantidade de producoes por tipo:" << endl;

	vector<int> estatisticas = it->second->calculaEstatisticas();

	cout << '\t' << "- Artigos em anais de eventos: " << estatisticas[0] << endl;
	cout << '\t' << "- Artigos em jornais e revistas: " << estatisticas[1] << endl;
	cout << '\t' << "- Artigos em periodicos cientificos: " << estatisticas[2] << endl;
	cout << '\t' << "- Livros: " << estatisticas[3] << endl;
	cout << '\t' << "- Partituras musicais: " << estatisticas[4] << endl;
	cout << '\t' << "- Traducoes: " << estatisticas[5] << endl;
	cout << '\t' << "- Outros: " << estatisticas[6] << endl << endl;
	cout << "Total de paginas produzidas pelo PPG: " << estatisticas[7];
}

/**
 * Imprime todos os ppgs de uma instituicao (com a mesma sigla), assim como o numero de producoes de cada ppg. Caso a
 * instituicao nao tenha sido registrada, imprime uma mensagem de erro e retorna.
 * Primeiramente as instituicoes contidas no map sao passadas para um vector, onde sao ordenadas por nome.
 * Apos isso, percorre-se o vector a procura de instituicoes com a sigla enviada. Quando encontrada,
 * imprime o nome da instituicao e suas ppgs com as estatisticas, alem de incrementar uma flag, utilizada para verificar
 * a presenca ou ausencia da instituicao.
 * @param sigla - sigla da instituicao procurada
 */
void ProcessadorDeDados::imprimeIes(const string sigla){
	int flag = 0;

	map<string, Instituicao*>::iterator iteradorMapa;
	vector<Instituicao*> ies;

	for(iteradorMapa = this->instituicoes.begin(); iteradorMapa != this->instituicoes.end(); iteradorMapa++){
		if(iteradorMapa->second->getSigla() == sigla){
			ies.push_back(iteradorMapa->second);
			flag++;
		}
	}

	sort(ies.begin(), ies.end(), ordenaInstituicoes);

	vector<Instituicao*>::iterator iteradorVetorOrdenado;

	for(iteradorVetorOrdenado = ies.begin(); iteradorVetorOrdenado != ies.end(); iteradorVetorOrdenado++){
		cout << **iteradorVetorOrdenado;
		(**iteradorVetorOrdenado).imprimePPGS();
	}

	if(flag==0){
		cout << "IES nao encontrada.";
	}

}

/**
 * Imprime todas as producoes de um certo tipo de um ppg. Caso o ppg nao esteja cadastrado ou o tipo seja invalido,
 * o metodo retorna.
 * Depois de encontrado o ppg, verifica-se o tipo de producao pedido pelo usuario e as imprime de maneira ordenada
 * pre estabelecida.
 * @param codigo - codigo do ppg a ser pesquisado
 * @param tipo - tipo de producao a ser impressa de um ppg
 */
void ProcessadorDeDados::imprimeCsv(const string codigo, const string tipo){
	if(this->ppgs.find(codigo) == this->ppgs.end()){
		cout << "PPG nao encontrado.";
		return;
	}

	map<string, PPG*>::iterator iteradorPPG = this->ppgs.find(codigo);

	if(tipo == "anais")
		iteradorPPG->second->imprimeProducoes("4Anal");
	else if(tipo == "artjr")
		iteradorPPG->second->imprimeProducoes("19ArtigoJornalRevista");
	else if(tipo == "artpe")
		iteradorPPG->second->imprimeProducoes("15ArtigoPeriodico");
	else if(tipo == "livro")
		iteradorPPG->second->imprimeProducoes("5Livro");
	else if(tipo == "partmu")
		iteradorPPG->second->imprimeProducoes("16PartituraMusical");
	else if(tipo == "tradu")
		iteradorPPG->second->imprimeProducoes("8Traducao");
	else if(tipo == "outro")
		iteradorPPG->second->imprimeProducoes("13OutraProducao");
	else
		cout << "Tipo invalido.";
}

/**
 * Todas as instituicoes sao liberadas do mapa, e logo depois os ppgs tambem.
 */
ProcessadorDeDados::~ProcessadorDeDados(){
	for(pair<string, Instituicao*> it : this->instituicoes){
		delete it.second;
		it.second = nullptr;
	}

	for(pair<string, PPG*> it2 : this->ppgs){
		delete it2.second;
		it2.second = nullptr;
	}

}
