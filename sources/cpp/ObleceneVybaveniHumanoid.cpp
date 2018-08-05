/**
@file
*/
#include "../hlavicky/ObleceneVybaveniHumanoid.h"

/**
Metoda vracejici obsah leve ruky.
*/
IceAge::Predmet* IceAge::ObleceneVybaveniHumanoid::getLevaRuka() {
	return this->m_levaRuka;
}

/**
Metoda nastavujici obsah leve ruky. Neni kladeno zadne omezeni.
*/
void IceAge::ObleceneVybaveniHumanoid::setLevaRuka(IceAge::Predmet* novaLevaRuka) {
    this->m_levaRuka=novaLevaRuka;
}

/**
Metoda vracejici obsah prave ruky.
*/
IceAge::Predmet* IceAge::ObleceneVybaveniHumanoid::getPravaRuka() {
    return this->m_pravaRuka;
}

/**
Metoda nastavujici obsah prave ruky. Neni kladeno zadne omezeni.
*/
void IceAge::ObleceneVybaveniHumanoid::setPravaRuka(IceAge::Predmet* novaPravaRuka) {
    this->m_pravaRuka=novaPravaRuka;
}

/**
Metoda nastavujici obsah zad. Neni kladeno zadne omezeni.
*/
IceAge::Predmet* IceAge::ObleceneVybaveniHumanoid::getZada() {
	return this->m_zada;
}

/**
Metoda nastavujici obsah zad. Neni kladeno zadne omezeni.
*/
void IceAge::ObleceneVybaveniHumanoid::setZada(IceAge::Predmet* novaZada) {
    this->m_zada=novaZada;
}

/**
Konstruktor ve kterem se nastavuji nove predmety do rukou a zad.
*/
IceAge::ObleceneVybaveniHumanoid::ObleceneVybaveniHumanoid(IceAge::Predmet* levaRuka, IceAge::Predmet* pravaRuka, IceAge::Predmet* zada) {
    this->setLevaRuka(levaRuka);
    this->setPravaRuka(pravaRuka);
    this->setZada(zada);
}

/**
Destruktor, ve kterem se mazou predmety z rukou a zad.
*/
IceAge::ObleceneVybaveniHumanoid::~ObleceneVybaveniHumanoid(){
    if(this->m_levaRuka != nullptr) delete this->m_levaRuka;
    if(this->m_pravaRuka != nullptr) delete this->m_pravaRuka;
    if(this->m_zada != nullptr) delete this->m_zada;
}
