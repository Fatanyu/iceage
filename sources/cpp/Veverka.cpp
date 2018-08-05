/**
@file
*/
#include "../hlavicky/Veverka.h"

IceAge::Veverka* IceAge::Veverka::s_vlastniInstance = nullptr; /**< @brief Inicializace statickeho atributu*/

/**
Konstruktor, ve kterem se nastavuje novy predmet Orisek. Je privatni, coz zarucuje, ze pujde vytvaret instance pouze ze staticke metody.
*/
IceAge::Veverka::Veverka(short novyZivot, short novaSila, short novaOdolnost):ObleceneVybaveniVeverky(nullptr, nullptr),
                                                Staty(novaSila,novaOdolnost),
                                                Zivot(novyZivot, novyZivot) {
    this->setPravaRuka(new IceAge::Orisek("Orisek"));
}
/**
Staticka metoda, ktera povoli vytvorit pouze jedinou instanci teto tridy. Pokud jiz instance existuje, vrati odkaz na ni misto vytvareni nove.
*/
/*static*/ IceAge::Veverka* IceAge::Veverka::getInstance() {
    if(s_vlastniInstance == nullptr) s_vlastniInstance = new IceAge::Veverka(SCRAT_HP,SCRAT_SILA,SCRAT_ODOLNOST);
    return s_vlastniInstance;
}

/**
Konkretni implementace dedene metody vracejici hodnotu celkoveho utoku, coz je sila. Pokud nese veverka i zbrane, pripocita se i jejich poskozeni.
*/
short IceAge::Veverka::utok(){
    short utokCelkem=0;
    if(this->m_levaRuka != nullptr)     if(this->m_levaRuka->getTyp() == 'w') utokCelkem+=this->m_levaRuka->getAtribut();
    if(this->m_pravaRuka != nullptr)    if(this->m_pravaRuka->getTyp() == 'w') utokCelkem+=this->m_pravaRuka->getAtribut();
//    std::cout << this->getSila() << " " << utokCelkem << std::endl;
    return this->getSila() + utokCelkem;
}

/**
Konkretni implementace dedene metody vracejici hodnotu celkove obrany, coz je odolnost.
*/
short IceAge::Veverka::obrana(){
//    short obranaCelkem=0;
/*
    if(this->m_levaRuka != nullptr)     if(this->m_levaRuka->getTyp() == 'c') obranaCelkem+=this->m_levaRuka->getAtribut();
    if(this->m_pravaRuka != nullptr)    if(this->m_pravaRuka->getTyp() == 'c') obranaCelkem+=this->m_pravaRuka->getAtribut();
*/
    return this->getOdolnost()/* + obranaCelkem*/;
}

/**
Destruktor
*/
IceAge::Veverka::~Veverka(){
}

/**
Okamzite zvysuje atributy na mnohem vyssi hodnoty. Jedna se o silu a odolnost.
*/
void IceAge::Veverka::enrageZapnout(){
    this->setSila(40);
    this->setOdolnost(40);
    std::cout << "***ENRAGE***" << std::endl;
}

/**
Vraci atributy do normalnich hodnot. Jedna se o silu a odolnost.
*/
void IceAge::Veverka::enrageVypnout(){
    this->setSila(SCRAT_SILA);
    this->setOdolnost(SCRAT_ODOLNOST);
    std::cout << "Uz si to rozdychal." << std::endl;
}
