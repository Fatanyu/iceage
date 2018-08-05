/**
@file
*/
#include "../hlavicky/SeverniLes.h"

/**
Konstruktor
*/
IceAge::SeverniLes::SeverniLes(std::string novyNazev):Command(novyNazev) {
}

/**
Destruktor
*/
IceAge::SeverniLes::~SeverniLes() {
}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace SeverniLes.
*/
void IceAge::SeverniLes::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {
    std::cout << std::endl;
    std::cout << "Oproti lesu na druhe strane, tento prales je plny svinciku a to i na zvireci pomery." << std::endl;
    std::cout << "Ocividne teto oblasti vevodi tlupa velkych dvounozcu a jejich rivalove savlozubi tygri." <<std::endl;

    bool cyklus2=true;/**< @brief Lokalni promenna pouzivana pro udrzovani cyklu v chodu. Konkretne u ziskavani odpovedi od uzivatele.*/
    unsigned int index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/

	while(cyklus2)/**< @brief Cyklus hlavni moznosti prozkoumani.*/
    {
        std::cout << std::endl;
        std::cout << "[" << index << "] Nenapadne se vytratit" <<std::endl; index++;
        std::cout << "[" << index << "] Napit se " <<std::endl; index=0;

        std::cout << "Vyber akci:";
        std::cin >> volba;std::cin.ignore();

        switch(volba){
            case '0':/**< @brief Moznost nenapadne se vytratit*/
                    std::cout << "Nepovedlo se, vsiml si te " << vektorHumanoid.at(0)->getNazev() << std::endl;
                    IceAge::boj(vektorHumanoid.at(0), scrat);
                    std::cout << "Povedlo se ti dostat do bezpeci, ale ztratil si svou lodku" << std::endl;
                    scrat->zahodPravaRuka();
                    cyklus2=false;
                break;
            case '1':/**< @brief Moznost napit/uzdravit se*/
                scrat->changeZivotAktualni(reka->getHodnotaZivota());
                std::cout << "Aktualne mas " << scrat->getZivotAktualni() << "/" << scrat->getZivotMaximalni() << std::endl;
                continue;
                break;
        }
    }
}
