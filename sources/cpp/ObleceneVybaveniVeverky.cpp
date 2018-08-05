/**
@file
*/
#include "../hlavicky/ObleceneVybaveniVeverky.h"

/**
Metoda vracejici obsah leve ruky.
*/
IceAge::Predmet* IceAge::ObleceneVybaveniVeverky::getLevaRuka() {
    return this->m_levaRuka;
}

/**
Metoda nastavujici obsah leve ruky. Neni kladeno zadne omezeni.
*/
void IceAge::ObleceneVybaveniVeverky::setLevaRuka(IceAge::Predmet* novaLevaRuka) {
	this->m_levaRuka=novaLevaRuka;
}

/**
Metoda vracejici obsah prave ruky.
*/
IceAge::Predmet* IceAge::ObleceneVybaveniVeverky::getPravaRuka() {
    return this->m_pravaRuka;
}

/**
Metoda nastavujici obsah prave ruky. Neni kladeno zadne omezeni.
*/
void IceAge::ObleceneVybaveniVeverky::setPravaRuka(IceAge::Predmet* novaPravaRuka) {
	this->m_pravaRuka=novaPravaRuka;
}

/**
Konstruktor ve kterem se nastavuji nove predmety do rukou.
*/
IceAge::ObleceneVybaveniVeverky::ObleceneVybaveniVeverky(IceAge::Predmet* novaLevaRuka, IceAge::Predmet* novaPravaRuka) {
	this->setLevaRuka(novaLevaRuka);
	this->setPravaRuka(novaPravaRuka);
}

/**
Destruktor, ve kterem se mazou predmety z rukou.
*/
IceAge::ObleceneVybaveniVeverky::~ObleceneVybaveniVeverky(){
    if(this->m_levaRuka != nullptr) delete this->m_levaRuka;
    if(this->m_pravaRuka != nullptr) delete this->m_pravaRuka;
}

/**
Metoda zahazujici (mazani) predmet v leve ruce. Nasledne nastavi atribut na nullptr.
*/
void IceAge::ObleceneVybaveniVeverky::zahodLevaRuka(){
    if(this->m_levaRuka != nullptr) delete this->m_levaRuka;
    this->m_levaRuka=nullptr;
}

/**
Metoda zahazujici (mazani) predmet v prave ruce. Nasledne nastavi atribut na nullptr.
*/
void IceAge::ObleceneVybaveniVeverky::zahodPravaRuka(){
    if(this->m_pravaRuka != nullptr) delete this->m_pravaRuka;
    this->m_pravaRuka=nullptr;
}
