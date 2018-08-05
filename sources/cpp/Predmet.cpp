/**
@file
*/
#include "../hlavicky/Predmet.h"
/**
Metoda vracejici typ(druh) predmetu.
*/
char IceAge::Predmet::getTyp() {
    return this->m_typ;
}

/**
Metoda nastavujici typ. Ma omezeni na tri hodnoty.
*/
void IceAge::Predmet::setTyp(char novyTyp) {
    if(/*novyTyp == 'c' || */novyTyp == 'w' || novyTyp == 'n') this->m_typ=novyTyp;
    else this->m_typ='u'; //unknown
}

/**
Konstruktor
*/
IceAge::Predmet::Predmet(std::string novyNazev):Nazev(novyNazev) {
}

/**
Destruktor
*/
IceAge::Predmet::~Predmet(){
}
