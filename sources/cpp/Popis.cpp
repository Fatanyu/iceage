/**
@file
*/
#include "../hlavicky/Popis.h"

/**
Metoda vracejici popis.
*/
std::string IceAge::Popis::getPopis() {
	return this->m_popis;
}

/**
Metoda nastavujici popis. Neni zde zadne omezeni.
*/
void IceAge::Popis::setPopis(std::string novyPopis) {
	this->m_popis=novyPopis;
}

/**
Konstruktor ve kterem se nastavuje popis.
*/
IceAge::Popis::Popis(std::string novyPopis) {
	this->setPopis(novyPopis);
}

/**
Destruktor
*/
IceAge::Popis::~Popis(){
}
