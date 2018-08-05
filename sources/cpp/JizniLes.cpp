/**
@file
*/
#include "../hlavicky/JizniLes.h"

/**
Konstruktor
*/
IceAge::JizniLes::JizniLes(std::string novyNazev):Command(novyNazev) {
}

/**
Destruktor
*/
IceAge::JizniLes::~JizniLes() {

}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace JizniLes.
*/
void IceAge::JizniLes::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {

	std::cout << "Mas silne nutkani zde zustat, ale vune ti pripomina tvuj orisek a jeho ztratu." << std::endl;
	std::cout << "Reka tu proteka jako na planine a je stale prilis siroka na preplavani. Mozna se tu najde nejaka lodka." << std::endl;
/** @brief Vykresleni obrazku*/


std::cout << "                         .-."                     << std::endl;
std::cout << "                        |/`\\\\.._"               << std::endl;
std::cout << "     _..._,,--.         `\\ /.--.\\ _.-."         << std::endl;
std::cout << "  ,/'  ..:::.. \\     .._.-'/    \\` .\\/"        << std::endl;
std::cout << " /       ...:::.`\\ ,/:..| |(o)  / /o)|"          << std::endl;
std::cout << "|:..   |  ..:::::'|:..  ;\\ `---'. `--'"          << std::endl;
std::cout << ";::... |   .::::,/:..    .`--.   .:.`\\_"         << std::endl;
std::cout << " |::.. ;  ..::'/:..   .--'    ;\\   :::.`\\"      << std::endl;
std::cout << " ;::../   ..::|::.  /'          ;.  ':'.---."     << std::endl;
std::cout << "  `--|    ..::;\\:.  `\\,,,____,,,/';\\. (_)  |)" << std::endl;
std::cout << "     ;     ..::/:\\:.`\\|         ,__,/`;----'"   << std::endl;
std::cout << "     `\\       ;:.. \\: `-..      `-._,/,_,/"     << std::endl;
std::cout << "       \\      ;:.   ). `\\ `>     _:\\"          << std::endl;
std::cout << "        `\\,  ;:..    \\ \\ _>     </,/`\\"       << std::endl;
std::cout << "           `\\|:.      `-'      <_/:.  |"         << std::endl;
std::cout << "             ;:     |:.  `----':.    /"           << std::endl;
std::cout << "              \\,__,/'-::....;      ,/"           << std::endl;
std::cout << "               |:|          `----'"               << std::endl;
std::cout << "               / < \\          /:/"               << std::endl;
std::cout << "              `-'-'-'        <:.`-._"             << std::endl;
std::cout << "                               `\\,>>'"           << std::endl;

std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;


    bool cyklus2=true;/**< @brief Lokalni promenna pouzivana pro udrzovani cyklu v chodu. Konkretne u ziskavani odpovedi od uzivatele.*/
    unsigned int index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/
    unsigned int volbaCislo=0; /**< @brief Lokalni promenna pouzivana pro vybrani odpovedi, musi byt schopna dosahnout nejvyssich hodnot indexu vectoru.*/
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/

	while(cyklus2) /**< @brief Cyklus pro hlavni nabidku prozkoumani.*/
    {
            std::cout << std::endl;
            std::cout << "[" << index << "] Odejit" <<std::endl; index++;
            std::cout << "[" << index << "] Napit se " <<std::endl; index++;
            std::cout << "[" << index << "] Pokusit se preplavat na druhou stranu svepomoci" <<std::endl;index++;
            std::cout << "[" << index << "] Zautocit na nekoho" <<std::endl; index++;
            std::cout << "[" << index << "] Sebrat klacek" <<std::endl; index++;
            std::cout << "[" << index << "] Vyrobit lodku" <<std::endl;

            index=0;
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':/**< @brief Moznost odejit*/
                    return;
                    break;
                case '1':/**< @brief Moznost napit/uzdravit se*/
                    scrat->changeZivotAktualni(reka->getHodnotaZivota());
                    std::cout << "Aktualne mas " << scrat->getZivotAktualni() << "/" << scrat->getZivotMaximalni() << std::endl;
                    continue;
                    break;
                case '2':/**< @brief Moznost preplavani bez lodky*/
                    std::cout << "Proud je moc silny, utopil ses. Nedokazal si ziskat zpatky orisek!" << std::endl;
                    IceAge::MemoryArbiter::cycleDelete();
                    exit(0);
                    break;
                case '3':/**< @brief Moznost zautocit na nekoho*/
                    for(unsigned int i=0; i<vektorBeast.size(); index++,i++)
                        std::cout << "[" << index << "] " << vektorBeast.at(i)->getNazev() << std::endl;


                    for(unsigned int j=0; j<vektorHumanoid.size(); index++, j++)
                        std::cout << "[" << index << "] " << vektorHumanoid.at(j)->getNazev() << std::endl;

                    std::cout << "Vyber si cil: ";

                    while(true){/**< @brief Vybrani na koho se utoci*/

                        std::cin >> volbaCislo;std::cin.ignore();

                        if(volbaCislo < index){
                            if(volbaCislo<vektorBeast.size()) boj(scrat,vektorBeast.at(volbaCislo));
                            else boj(scrat, vektorHumanoid.at(volbaCislo-vektorBeast.size()));
                            break;
                        }
                    }
                    index=0;
                    break;
                case '4':/**< @brief Moznost sebrani klacku*/
                        if(scrat->getLevaRuka() == nullptr) scrat->setLevaRuka(new IceAge::Zbran("Maly klacik",3));
                        else std::cout << "Uz mas Maly klacik. Vic neuneses." << std::endl;
                    break;
                case '5':/**< @brief Moznost sebrani lodicky*/
                        if(scrat->getPravaRuka() == nullptr) scrat->setPravaRuka(new IceAge::Orisek("Lodka"));
                        else std::cout << "Uz mas Lodku. Vic neuneses." << std::endl;
                    break;
                default:
                    break;
            }
        }
}
