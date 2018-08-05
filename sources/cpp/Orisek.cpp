/**
@file
*/
#include "../hlavicky/Orisek.h"

/**
Konstruktor
*/
IceAge::Orisek::Orisek(std::string novyNazev):Predmet(novyNazev) {
    this->setTyp('n');
}

/**
Destruktor
*/
IceAge::Orisek::~Orisek(){
}

/**
Podedena metoda vracejici hodnotu 0.
*/
 short IceAge::Orisek::getAtribut(){
    return 0;
 }
