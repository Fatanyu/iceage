/**
@file
*/
#include "../hlavicky/Humanoid.h"

/**
Konstruktor
*/
IceAge::Humanoid::Humanoid(short novyZivot, std::string novyNazev, std::string novyPopis, short novaSila, short novaOdolnost, IceAge::Predmet* zbran1,
        IceAge::Predmet* zbran2, IceAge::Predmet* zbran3):IceAge::Inventar::Inventar(MAX_INVENTAR), IceAge::ObleceneVybaveniHumanoid(zbran1,zbran2,zbran3),
                                                     IceAge::Zivot::Zivot(novyZivot,novyZivot), IceAge::Nazev::Nazev(novyNazev),
                                                     IceAge::Popis::Popis(novyPopis), IceAge::Staty::Staty(novaSila,novaOdolnost) {
}

/**
Podedena metoda vracejici hodnotu celkoveho utoku, coz je sila. Pokud ma v rukach nejake zbrane, prictou se hodnoty i techto zbrani.
*/
short IceAge::Humanoid::utok() {
    short utokCelkem=0;

    if(this->m_levaRuka != nullptr)    if(this->m_levaRuka->getTyp() == 'w') utokCelkem+=this->m_levaRuka->getAtribut();
    if(this->m_pravaRuka != nullptr)    if(this->m_pravaRuka->getTyp() == 'w') utokCelkem+=this->m_pravaRuka->getAtribut();

    return this->getSila() + utokCelkem;
}

/**
Podedena metoda vracejici hodnotu celkove obrany, coz je odolnost.
*/
short IceAge::Humanoid::obrana() {
//    short obranaCelkem=0;
/*
    if(this->m_levaRuka != nullptr)    if(this->m_levaRuka->getTyp() == 'c') obranaCelkem+=this->m_levaRuka->getAtribut();
    if(this->m_pravaRuka != nullptr)    if(this->m_pravaRuka->getTyp() == 'c') obranaCelkem+=this->m_pravaRuka->getAtribut();
*/
    return this->getOdolnost()/* + obranaCelkem*/;
}

/**
Destruktor
*/
IceAge::Humanoid::~Humanoid(){
}
