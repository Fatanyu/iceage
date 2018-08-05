/**
@file
*/
#include "../hlavicky/Zbran.h"

/**
Metoda vracejici hodnotu poskozeni.
*/
short IceAge::Zbran::getPoskozeni() {
	return this->m_poskozeni;
}

/**
Metoda nastavujici hodnotu poskozeni. Hodnota poskozeni muze byt jen nezaporna.
*/
void IceAge::Zbran::setPoskozeni(short novePoskozeni) {
	if(novePoskozeni>0) this->m_poskozeni=novePoskozeni;
	else this->m_poskozeni=0;
}

/**
Konstruktor ve kterem se nastavuje poskozeni a typ predmetu se nastavuje na 'w'.
*/
IceAge::Zbran::Zbran(std::string novyNazev, short novePoskozeni):Predmet(novyNazev) {
    this->setPoskozeni(novePoskozeni);
    this->setTyp('w');
}

/**
Destruktor
*/
IceAge::Zbran::~Zbran(){
}

/**
Podedena metoda vracejici hodnotu poskozeni.
*/
short IceAge::Zbran::getAtribut(){
     return this->getPoskozeni();
}
