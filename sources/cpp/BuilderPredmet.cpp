/**
@file
*/
#include "../hlavicky/BuilderPredmet.h"

/**
Metoda, ktera vytvori predmet podle zadanych parametru.
*/
void IceAge::BuilderPredmet::createPredmet(std::string novyNazev, short novaHodnota) {
    this->m_pripravovany=new IceAge::Zbran(novyNazev,novaHodnota);
}

/**
Metoda ktera vraci odkaz na predmet, ktery je vytvaren. Nasledne do atributu pripravovany ulozi nullptr.
*/
IceAge::Predmet* IceAge::BuilderPredmet::getPredmet() {
    IceAge::Predmet*third=this->m_pripravovany;
    this->m_pripravovany=nullptr;
	return third;
}

/**
Konstruktor ve kterem se jen do atributu pripravovany ulozi nullptr;
*/
IceAge::BuilderPredmet::BuilderPredmet() {
    this->m_pripravovany=nullptr;
}

/**
Destruktor ve kterem se pripadne maze vytvareny predmet.
*/
IceAge::BuilderPredmet::~BuilderPredmet(){
    if(this->m_pripravovany != nullptr) delete this->m_pripravovany;
}
