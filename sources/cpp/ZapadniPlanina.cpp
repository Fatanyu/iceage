/**
@file
*/
#include "../hlavicky/ZapadniPlanina.h"

/**
Konstruktor
*/
IceAge::ZapadniPlanina::ZapadniPlanina(std::string novyNazev):Command(novyNazev) {
}

/**
Destruktor
*/
IceAge::ZapadniPlanina::~ZapadniPlanina() {
}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace ZapadniPlanina. Zde se provadi jen vypis toho co se tam odehrava.
*/
void IceAge::ZapadniPlanina::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {

	std::cout << "Vidis mensi melu. Je tu vymena nazoru mezi [";
    for(unsigned int i=0;i<(vektorBeast.size()-1);i++) std::cout << vektorBeast.at(i)->getNazev() << " ";
    std::cout << "] a [";
    for(unsigned int i=0;i<vektorHumanoid.size();i++) std::cout << vektorHumanoid.at(i)->getNazev() << " ";
    std::cout << " ]";
    std::cout << std::endl;
    std::cout << "Radeji se drzis stranou." <<std::endl;
    std::cout << std::endl;

}
