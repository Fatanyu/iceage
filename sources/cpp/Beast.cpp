/**
@file
*/
#include "../hlavicky/Beast.h"

/**
Metoda vracejici hodnotu zurivosti.
*/
short IceAge::Beast::getZurivost() {
	return this->m_zurivost;
}

/**
Metoda nastavujici hodnotu zurivosti.
*/
void IceAge::Beast::setZurivost(short novaZurivost) {
	this->m_zurivost=novaZurivost;
}

/**
Konkretni implementace dedene metody vracejici hodnotu celkoveho utoku.
*/
short IceAge::Beast::utok() {
	return this->getSila() + this->getZurivost();
}

/**
Konkretni implementace dedene metody vracejici hodnotu celkove obrany.
*/
short IceAge::Beast::obrana() {
    return this->getOdolnost();
}

/**
Konstruktor, ve kterem se nastavuje zurivost
*/
IceAge::Beast::Beast(short novaZurivost, std::string novyNazev, short novaSila, std::string novyPopis, short novaOdolnost, short novyZivot)
                                    :Memory(), Zivot(novyZivot,novyZivot), Nazev(novyNazev), Popis(novyPopis), Staty(novaSila,novaOdolnost){
    this->setZurivost(novaZurivost);
}

/**
Destruktor
*/
IceAge::Beast::~Beast(){
}
