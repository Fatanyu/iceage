/**
@file
*/
#include "../hlavicky/ZapadniBrehReky.h"

/**
Konstruktor
*/
IceAge::ZapadniBrehReky::ZapadniBrehReky(std::string novyNazev):Command(novyNazev) {
}

/**
Destruktor
*/
IceAge::ZapadniBrehReky::~ZapadniBrehReky() {
}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace ZapadniBrehReky.
*/
void IceAge::ZapadniBrehReky::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {

	std::cout << "Pomalu si prisel k rece. Na druhou stranu to je nejmene 100 metru." << std::endl;


    bool cyklus2=true;/**< @brief Lokalni promenna pouzivana pro udrzovani cyklu v chodu. Konkretne u ziskavani odpovedi od uzivatele.*/
    unsigned int index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/
    unsigned int volbaCislo=0;/**< @brief Lokalni promenna pouzivana pro urcovani koho pujde hrac zmlatit.*/
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/

	while(cyklus2)/**< @brief Cyklus hlavnich moznosti prozkoumavani.*/
        {
            std::cout << std::endl;
            std::cout << "[" << index << "] Odejit" <<std::endl; index++;
            std::cout << "[" << index << "] Napit se " <<std::endl; index++;
            std::cout << "[" << index << "] Pokusit se preplavat na druhou stranu" <<std::endl; index++;
            std::cout << "[" << index << "] Zautocit na nekoho" <<std::endl; index=0;
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':/**< @brief Moznost odejit.*/
                    return;
                    break;
                case '1':/**< @brief Moznost napit/uzdravit se.*/
                    scrat->changeZivotAktualni(reka->getHodnotaZivota());
                    std::cout << "Aktualne mas " << scrat->getZivotAktualni() << "/" << scrat->getZivotMaximalni() << std::endl;
                    continue;
                    break;
                case '2':/**< @brief Moznost preplavat reku bez lodky.*/
                    std::cout << "Proud je moc silny, utopil ses. Nedokazal si ziskat zpatky orisek!" << std::endl;
                    IceAge::MemoryArbiter::cycleDelete();
                    exit(0);
                    break;
                case '3':/**< @brief Moznost zautocit na nekoho.*/
                    for(unsigned int i=0; i<vektorBeast.size(); index++,i++)
                         std::cout << "[" << index << "] " << vektorBeast.at(i)->getNazev() << " - "<< vektorBeast.at(i)->getPopis() << std::endl;


                    for(unsigned int j=0; j<vektorHumanoid.size(); index++, j++)
                        std::cout << "[" << index << "] " << vektorHumanoid.at(j)->getNazev() << " - "<< vektorHumanoid.at(j)->getPopis() << std::endl;

                    std::cout << "Vyber si cil: ";

                    while(true){/**< @brief Vybrani si koho pujde zmlatit.*/

                        std::cin >> volbaCislo;std::cin.ignore();

                        if(volbaCislo < index){
                            if(volbaCislo<vektorBeast.size()) boj(scrat,vektorBeast.at(volbaCislo));
                            else boj(scrat, vektorHumanoid.at(volbaCislo-vektorBeast.size()));
                            break;
                        }
                    }
                    index=0;/**< @brief Nulovani lokalni promenne.*/
                    break;
                default:
                    break;
            }
        }
}
