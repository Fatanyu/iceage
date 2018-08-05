/**
@file
*/
#include "../hlavicky/LocationDirector.h"

/**
Konstruktor nastavujici BuilderLokace.
*/
IceAge::LocationDirector::LocationDirector(IceAge::BuilderLokace* novyBuilder) {
	this->setBuilder(novyBuilder);
}

/**
Metoda ktera vytvori Lokace a vrati aktualni.
*/
IceAge::Lokace* IceAge::LocationDirector::createLokace() {
	this->m_builder->createLokace();
    return this->m_builder->getLokace();
}

/**
Metoda ktera nastavuje BuilderLokace
*/
void IceAge::LocationDirector::setBuilder(IceAge::BuilderLokace* novyBuilder) {
	this->m_builder=novyBuilder;
}

/**
Destruktor ve kterem se maze builder.
*/
IceAge::LocationDirector::~LocationDirector(){
    if(this->m_builder != nullptr) delete this->m_builder;
}
