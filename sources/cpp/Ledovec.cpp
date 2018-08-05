/**
@file
*/
#include "../hlavicky/Ledovec.h"

/**
Konstruktor
*/
IceAge::Ledovec::Ledovec(std::string novyNazev):Command(novyNazev) {
}

/**
Destruktor
*/
IceAge::Ledovec::~Ledovec() {
}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace Ledovec.
*/
void IceAge::Ledovec::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {
    std::cout << std::endl;
    std::cout << "Ledovec se zhroutil, krome laviny do udoli tu neni nikdo a nic." << std::endl;
    std::cout << "Spadl na tebe kus ledu! Ztracis 3 zivoty!" <<std::endl;
//    std::cout << vektorBeast.size() << std::endl;
    scrat->changeZivotAktualni(-3);/**< @brief Sebere se zivot*/
    std::cout << "Vidis " << vektorBeast.at(0)->getNazev() << ". Udelal si z tebe cvicny terc." << std::endl; /**< @brief Ukaze kdo trefil hrace*/
    std::cout << std::endl;
}
