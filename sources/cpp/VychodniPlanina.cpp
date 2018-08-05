/**
@file
*/
#include "../hlavicky/VychodniPlanina.h"

/**
Konstruktor
*/
IceAge::VychodniPlanina::VychodniPlanina(std::string novyNazev):Command(novyNazev) {
}

/**
Destruktor
*/
IceAge::VychodniPlanina::~VychodniPlanina() {
}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace VychodniPlanina.
*/
void IceAge::VychodniPlanina::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {
	std::cout << std::endl;
	std::cout << "Jen slysis \"Hele maso!\" a uz vis, ze je zle" << std::endl;

    bool cyklus2=true;/**< @brief Lokalni promenna pouzivana pro udrzovani cyklu v chodu. Konkretne u ziskavani odpovedi od uzivatele.*/
    unsigned int index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/

	while(cyklus2)/**< @brief Cyklus hlavnich moznosti prozkoumavani.*/
    {
            std::cout << std::endl;
            std::cout << "[" << index << "] Zdrhej" <<std::endl; index=0;

            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':/**< @brief Moznost odejit.*/
                    if(scrat->getPravaRuka() != nullptr){
                        std::cout << "Zahazujes lodku a utikas" << std::endl;
                        scrat->zahodPravaRuka();
                    }
                    std::cout << "Uspesne si utekl " << vektorHumanoid.at(0)->getPopis() << std::endl;
                    std::cout << std::endl;
                    return;
                    break;
                default:
                    break;

            }
        }
}
