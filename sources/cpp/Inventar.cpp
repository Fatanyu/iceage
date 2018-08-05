/**
@file
*/
#include "../hlavicky/Inventar.h"


/**
Metoda vracejici hodnotu maximalni povolene velikosti inventare.
*/
unsigned short IceAge::Inventar::getMaximalniVelikost() {
	return this->m_maximalniVelikost;
}

/**
Metoda vyndavajici nejaky predmet z inventare. Predmet se vybira na zaklade vypisu a volani pomocne metody volba().
*/
IceAge::Predmet* IceAge::Inventar::odeberPredmet() {
    std::cout << "Vyber predmet:" << std::endl;
    this->vypisObsah();

    unsigned int x=this->volba();
/**
V ramci usetreni rychlost se zde meni odebirany prvek s poslednim. Jinak by se shiftovalo.
*/
    IceAge::Predmet *odeber=this->m_vektorPredmetu.at(x);
    this->m_vektorPredmetu.at(x)=nullptr;
    this->m_vektorPredmetu.pop_back();
    return odeber;
}

/**
Metoda pridavajici novy predmet do inventare. Kontroluje se zde maximalni velikost Inventare a pripadne se to zahlasi uzivateli.
*/
void IceAge::Inventar::pridejPredmet(IceAge::Predmet* novyPredmet) {
	if(this->m_vektorPredmetu.size() >= this->getMaximalniVelikost()) std::cout << "Inventar je plny!" << std::endl;
	else this->m_vektorPredmetu.push_back(novyPredmet);
}

/**
Metoda nastavujici maximalni velikost inventare. Dane cislo musi byt kladne. Pokud neni, je nastaven inventar na 1.
*/
void IceAge::Inventar::setMaximalniVelikost(unsigned short novaMaximalniVelikost) {
	if(novaMaximalniVelikost > 0)this->m_maximalniVelikost=novaMaximalniVelikost;
	else this->m_maximalniVelikost=1;
}

/**
Metoda nicici predmet v inventari. Probiha to na zaklade vypisu a volby.
V ramci rychlosti se mazany predmet uklada na konec. Zamezi se tim shiftovani.
*/
void IceAge::Inventar::znicPredmet() {
    std::cout << "Vyber predmet k zahozeni:" << std::endl;

    this->vypisObsah();
    unsigned int x = this->volba();

    IceAge::Predmet *odeber=this->m_vektorPredmetu.at(x);
    this->m_vektorPredmetu.at(x)=this->m_vektorPredmetu.at(this->m_vektorPredmetu.size()-1);
    this->m_vektorPredmetu.at(this->m_vektorPredmetu.size()-1)=odeber;
    this->m_vektorPredmetu.pop_back();
}

/**
Konstruktor, ve kterem se nastavuje maximalni velikost inventare.
*/
IceAge::Inventar::Inventar(unsigned short novaVelikost) {
	this->setMaximalniVelikost(novaVelikost);
}

/**
Destruktor, ve kterem se mazou vsechny predmety v inventari. Probiha kontrola, zda tam neni nullptr.
*/
IceAge::Inventar::~Inventar() {
    for(unsigned int i=0; i<m_vektorPredmetu.size(); i++)
        if(this->m_vektorPredmetu.at(i) != nullptr) delete this->m_vektorPredmetu.at(i);
}

/**
Metoda vypisujici predmety v inventari.
*/
void IceAge::Inventar::vypisObsah() {
    for(unsigned int i=0; i<this->m_vektorPredmetu.size();i++)
    {
        std::cout << i << ": " << this->m_vektorPredmetu.at(i)->getNazev() << std::endl;
    }
}

/**
Pomocna metoda k rozhodovani. Nacita od uzivatele a bude cyklit, dokud to nenacte cislo a zaroven nebude mensi, jak aktualni velikost inventare.
*/
unsigned int IceAge::Inventar::volba() {
    unsigned int x;
    while(true)
    {
        std::cin >> x;
        if(x<m_vektorPredmetu.size()) break;
    }
    return x;
}
