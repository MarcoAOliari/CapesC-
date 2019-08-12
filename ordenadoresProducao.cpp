/*
 * ordenadoresProducao.cpp
 *
 *  Created on: 8 de jul de 2019
 *      Author: marco
 */

#include "ordenadoresProducao.h"

/**
 * Funcoes utilizadas para comparacao no comando csv do trabalho. Recebem sempre duas Producoes e realizam o downcast,
 * para comparar os atributos da maneira solicitada pelo comando csv.
 */

bool ordenaAnal(Producao* p1, Producao* p2){
	Anal* o1 = (Anal*)p1; Anal* o2 = (Anal*)p2;

	if(o1->getNatureza() != o2->getNatureza())
		return stringCompare(o1->getNatureza(), o2->getNatureza());
	else if(o1->getTitulo() != o2->getTitulo())
		return stringCompare(o1->getTitulo(), o2->getTitulo());
	else if(o1->getIdioma() != o2->getIdioma())
		return stringCompare(o1->getIdioma(), o2->getIdioma());
	else if(o1->getEvento() != o2->getEvento())
		return stringCompare(o1->getEvento(), o2->getEvento());
	else if(o1->getCidade() != o2->getCidade())
		return stringCompare(o1->getCidade(), o2->getCidade());
	else return (o1->getPags() > o2->getPags());
}

bool ordenaArtigoJornalRevista(Producao* p1, Producao* p2){
	ArtigoJornalRevista* o1 = (ArtigoJornalRevista*)p1;
	ArtigoJornalRevista* o2 = (ArtigoJornalRevista*)p2;

	if(o1->getTitulo() != o2->getTitulo())
		return stringCompare(o1->getTitulo(), o2->getTitulo());
	else if(o1->getIdioma() != o2->getIdioma())
		return stringCompare(o1->getIdioma(), o2->getIdioma());
	else if(o1->getCidade() != o2->getCidade())
		return stringCompare(o1->getCidade(), o2->getCidade());
	else if(o1->getData() != o2->getData())
		return (o1->getData() < o2->getData());
	else if(o1->getIssn() != o2->getIssn())
		return stringCompare(o1->getIssn(), o2->getIssn());
	else return (o1->getPags() < o2->getPags());
}

bool ordenaArtigoPeriodico(Producao* p1, Producao* p2){
	ArtigoPeriodico* o1 = (ArtigoPeriodico*)p1;
	ArtigoPeriodico* o2 = (ArtigoPeriodico*)p2;

	if(o1->getNatureza() != o2->getNatureza())
	  return stringCompare(o1->getNatureza(), o2->getNatureza());
	else if(o1->getIdioma() != o2->getIdioma())
	  return stringCompare(o1->getIdioma(), o2->getIdioma());
	else if(o1->getEditora() != o2->getEditora())
	  return stringCompare(o1->getEditora(), o2->getEditora());
	else if(o1->getCidade() != o2->getCidade())
	  return stringCompare(o1->getCidade(), o2->getCidade());
	else if(o1->getVolume() != o2->getVolume())
	  return (o1->getVolume() < o2->getVolume());
	else if(o1->getFasciculo() != o2->getFasciculo())
	  return (o1->getFasciculo() < o2->getFasciculo());
	else if(o1->getSerie() != o2->getSerie())
	  return (o1->getSerie() < o2->getSerie());
	else if(o1->getIssn() != o2->getIssn())
	  return stringCompare(o1->getIssn(), o2->getIssn());
	else return (o1->getPags() < o2->getPags());
}

bool ordenaLivro(Producao* p1, Producao* p2){
	Livro* o1 = (Livro*)p1; Livro* o2 = (Livro*)p2;

	if(o1->getNatureza() != o2->getNatureza())
	  return stringCompare(o1->getNatureza(), o2->getNatureza());
	else if(o1->getTitulo() != o2->getTitulo())
		return stringCompare(o1->getTitulo(), o2->getTitulo());
	else if(o1->getIdioma() != o2->getIdioma())
	  return stringCompare(o1->getIdioma(), o2->getIdioma());
	else if(o1->getEditora() != o2->getEditora())
	  return stringCompare(o1->getEditora(), o2->getEditora());
	else if(o1->getCidade() != o2->getCidade())
	  return stringCompare(o1->getCidade(), o2->getCidade());
	else if(o1->getIsbn() != o2->getIsbn())
	  return stringCompare(o1->getIsbn(), o2->getIsbn());
	else return (o1->getPags() < o2->getPags());
}

bool ordenaOutraProducao(Producao* p1, Producao* p2){
	OutraProducao* o1 = (OutraProducao*)p1;
	OutraProducao* o2 = (OutraProducao*)p2;

	if(o1->getNatureza() != o2->getNatureza())
	  return stringCompare(o1->getNatureza(), o2->getNatureza());
	else if(o1->getIdioma() != o2->getIdioma())
	  return stringCompare(o1->getIdioma(), o2->getIdioma());
	else if(o1->getEditora() != o2->getEditora())
	  return stringCompare(o1->getEditora(), o2->getEditora());
	else if(o1->getCidade() != o2->getCidade())
	  return stringCompare(o1->getCidade(), o2->getCidade());
	else return (o1->getPags() < o2->getPags());
}

bool ordenaPartituraMusical(Producao* p1, Producao* p2){
	PartituraMusical* o1 = (PartituraMusical*)p1;
	PartituraMusical* o2 = (PartituraMusical*)p2;

	if(o1->getNatureza() != o2->getNatureza())
	  return stringCompare(o1->getNatureza(), o2->getNatureza());
	else if(o1->getEditora() != o2->getEditora())
	  return stringCompare(o1->getEditora(), o2->getEditora());
	else if(o1->getCidade() != o2->getCidade())
	  return stringCompare(o1->getCidade(), o2->getCidade());
	else if(o1->getFormacaoMusical() != o2->getFormacaoMusical())
		return stringCompare(o1->getFormacaoMusical(), o2->getFormacaoMusical());
	else return (o1->getPags() < o2->getPags());
}

bool ordenaTraducao(Producao* p1, Producao* p2){
	Traducao* o1 = (Traducao*)p1; Traducao* o2 = (Traducao*)p2;

	if(o1->getNatureza() != o2->getNatureza())
	  return stringCompare(o1->getNatureza(), o2->getNatureza());
	else if(o1->getTitulo() != o2->getTitulo())
		return stringCompare(o1->getTitulo(), o2->getTitulo());
	else if(o1->getIdioma() != o2->getIdioma())
	  return stringCompare(o1->getIdioma(), o2->getIdioma());
	else if(o1->getEditora() != o2->getEditora())
	  return stringCompare(o1->getEditora(), o2->getEditora());
	else if(o1->getCidade() != o2->getCidade())
	  return stringCompare(o1->getCidade(), o2->getCidade());
	else if(o1->getTraducao() != o2->getTraducao())
		return stringCompare(o1->getTraducao(), o2->getTraducao());
	else return (o1->getPags() < o2->getPags());
}
