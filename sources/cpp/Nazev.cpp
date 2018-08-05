/**
@file
*/
#include "../hlavicky/Nazev.h"


/**
Metoda vracejici nazev.
*/
std::string IceAge::Nazev::getNazev() {
	return this->m_nazev;
}

/**
Metoda nastavujici nazev. Nazev neni v tuto chvili nijak omezen.
*/
void IceAge::Nazev::setNazev(std::string novyNazev) {
	this->m_nazev=novyNazev;
}

/**
Konstruktor, ve kterem se nastavuje nazev.
*/
IceAge::Nazev::Nazev(std::string novyNazev) {
	this->setNazev(novyNazev);
}
