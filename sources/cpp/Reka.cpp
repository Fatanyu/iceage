/**
@file
*/
#include "../hlavicky/Reka.h"

/**
Metoda vracejici hodnotaZivota.
*/
short IceAge::Reka::getHodnotaZivota() {
	return this->m_hodnotaZivota;
}

/**
Metoda nastavujici hodnotaZivota.
*/
void IceAge::Reka::setHodnotaZivota(short novaHodnotaZivota) {
    if(novaHodnotaZivota>0) this->m_hodnotaZivota=novaHodnotaZivota;
}

/**
Konstruktor
*/
IceAge::Reka::Reka(short novaHodnota) {
	this->setHodnotaZivota(novaHodnota);
}

/**
Destruktor
*/
IceAge::Reka::~Reka(){
}
