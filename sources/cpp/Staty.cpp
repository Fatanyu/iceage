/**
@file
*/
#include "../hlavicky/Staty.h"

/**
Metoda vracejici hodnotu sily.
*/
short IceAge::Staty::getSila() {
	return this->m_sila;
}

/**
Metoda nastavujici hodnotu sily. Muze obsahovat i zaporne hodnoty.
*/
void IceAge::Staty::setSila(short novaSila) {
	this->m_sila=novaSila;
}

/**
Metoda vracejici hodnotu odolnosti.
*/
short IceAge::Staty::getOdolnost() {
	return this->m_odolnost;
}

/**
Metoda nastavujici hodnotu odolnosti. Muze obsahovat i zaporne hodnoty.
*/
void IceAge::Staty::setOdolnost(short novaOdolnost) {
	this->m_odolnost=novaOdolnost;
}

/**
Konstruktor, ve kterem se nastavuje sila i odolnost.
*/
IceAge::Staty::Staty(short novaSila, short novaOdolnost) {
	this->setSila(novaSila);
	this->setOdolnost(novaOdolnost);
}

/**
Destruktor
*/
IceAge::Staty::~Staty(){
}
