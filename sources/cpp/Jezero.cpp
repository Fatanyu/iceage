/**
@file
*/
#include "../hlavicky/Jezero.h"

/**
Konstruktor
*/
IceAge::Jezero::Jezero(std::string novyNazev):Command(novyNazev) {

}

/**
Destruktor
*/
IceAge::Jezero::~Jezero() {
}

/**
Podedena metoda pridavajici algoritmus pro prozkoumani lokace Jezero.
*/
void IceAge::Jezero::prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) {
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/
    unsigned int index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/
    std::cout << std::endl;
    std::cout << "Jsi na pokraji mensiho jezera. V prumeru je mensi jak reka, mistami vidis mokriny, ktere jdou prebrodit." << std::endl << std::endl;
    std::cout << "Na vrcholku veze vidis hnizdko." << std::endl;
    std::cin.ignore();
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

    std::cout << "[0] Cmuchej" <<std::endl;
    std::cout << "Vyber akci:";
    std::cin >> volba; std::cin.ignore();


    bool cyklus2=true;/**< @brief Lokalni promenna pouzivana pro udrzovani cyklu v chodu. Konkretne u ziskavani odpovedi od uzivatele.*/
    while(cyklus2)/**< @brief Cyklus pro pasaz cmuchani.*/
    {
        switch(volba)
        {
            case '0':
                cyklus2=false;
                break;
            default:
                std::cout << "Vyber akci:";
                std::cin >> volba;std::cin.ignore();
                break;
        }
    }
    cyklus2=true; volba='a';/**< @brief Reset lokalnich promennych na puvodni hodnoty.*/

    std::cout << "Orisek je urcite nekde pobliz. Citis ho." << std::endl << std::endl;

    std::cout << "[0] Hledej dal" <<std::endl;
    std::cout << "Vyber akci:";
    std::cin >> volba;std::cin.ignore();

    while(cyklus2)/**< @brief Cyklus pro hledani dal.*/
    {
        switch(volba)
        {
            case '0':
                cyklus2=false;
                break;
            default:
                std::cout << "Vyber akci:";
                std::cin >> volba;std::cin.ignore();
                break;
        }
    }
    cyklus2=true; volba='a';/**< @brief Reset lokalnich promennych na puvodni hodnoty.*/

    std::cout << std::endl << "Citis zde " << vektorBeast.at(0)->getNazev() << std::endl;
    std::cout << "Pach je slaby, daleko silneji ho prekryva pach orisku" << std::endl;
    std::cout << std::endl;
    std::cin.ignore();
    std::cout << "Rychle skaces po melcine ke skalce."<< std::endl;

/** @brief Pokud ma hrac stale lodicku, tak mu ji sebereme.*/
    if(scrat->getPravaRuka() != nullptr){
        std::cout << "Kdyz zjistis, ze se nahoru neda jen tak dostat, vztekem roztriskas svoji lodicku" << std::endl;
        scrat->zahodPravaRuka();
    }
    else std::cout << "Nahoru se dostat neda, aspon ne s tim co mas po ruce." << std::endl;

    std::cin.ignore();
    std::cout << std::endl;
    std::cout << "Rozhlizis se po okoli, hledaje neco, co by ti pomohlo dostat se do hnizda." << std::endl;
    std::cout << "V okoli se nachazi nekolik velkych vrb. Svou vyskou mohou konkurovat stromum v pralese." << std::endl;

    bool cyklus=true;/**< @brief Lokalni promenna pouzivana pro udrzovani cyklu v chodu. Konkretne u opakovani vypisu nejake cinnosti a ziskavani odpovedi (cyklus2)*/
    while(cyklus)/**< @brief Cyklus pro trhani proutku. Pokud neutrhnu vic kusu, budu tu cyklit.*/
    {
        std::cout << std::endl;
        std::cout << "[" << index << "] Utrhnout si proutek" << std::endl; index++;
        std::cout << "[" << index << "] Utrhnout si hodne proutku a uplest z nich jedno silne lano." << std::endl; index=0;
        std::cout << "Vyber akci:";

        while(cyklus2)/**< @brief Ziskavani odpovedi od uzivatele.*/
        {
            std::cin >> volba;std::cin.ignore();
            std::cout << std::endl;

            switch(volba)
            {
                case '0':
                    cyklus2=false;
                    std::cout << "Utrhnes si jeden proutek. Kdyz zkousis jeho pevnost, tak ti praskne." << std::endl << std::endl;
                    break;
                case '1':
                    std::cout << "Po hodine mas dostatecne silne a dlouhe lano." << std::endl;
                    scrat->setPravaRuka(new IceAge::Orisek("Proutkove lano"));
                    cyklus2=false; cyklus=false;
                    break;
                default:
                    break;
            }
        }
        cyklus2=true; volba='a';/**< @brief Reset lokalnich promennych na puvodni hodnoty.*/
    }
    cyklus2=true;/**< @brief Reset lokalnich promennych na puvodni hodnoty.*/

    std::cout << "Hazes lano na vrsek skalky a lezes nahoru." << std::endl;
    std::cin.ignore();

    IceAge::Orisek *scratuvOrisek=new IceAge::Orisek("Orisek");
/** @brief Pasaz se Supomutim mladetem*/
    std::cout << std::endl;
    std::cout << "Vylezl si nahoru. Vidis tu jen " << vektorBeast.at(1)->getNazev() << " a " << scratuvOrisek->getNazev() << std::endl;
    std::cin.ignore();
    std::cout << scratuvOrisek->getNazev() << "!!!" << std::endl;
    std::cin.ignore();
    scrat->zahodPravaRuka();
    std::cout << "Poustis lano a pripravujes se k boji!" << std::endl;
    std::cin.ignore();

    IceAge::boj(scrat,vektorBeast.at(1));

    scrat->setPravaRuka(scratuvOrisek);

/** @brief Hrac ziskal orisek a utika pryc.*/
    std::cout << "Prastil si " << vektorBeast.at(1)->getNazev() << " po hlave a utikas s ukoristenym oriskem." << std::endl;

    std::cout << std::endl;
    std::cout << "[" << index << "] Skocit pres okraj" << std::endl; index++;
    std::cout << "[" << index << "] Pouzit lano k ceste dolu" << std::endl; index=0;


    while(cyklus2)/**< @brief Cyklus pro ziskani odpovedi "kudy zdrhnout"*/
    {
        std::cout << "Vyber akci:";
        std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':
                    cyklus2=false;
                    std::cout << "Padas do vody. V ruce uz mas jen Orisek." << std::endl << std::endl;
                    break;
                case '1':
                    std::cout << "Aby si se mohl drzet lana a neztratit Orisek, hazes klacek po " << vektorBeast.at(1)->getNazev() << std::endl;
                    std::cout << "Kdyz jsi v puli cesty, tak ti " << vektorBeast.at(1)->getNazev() << " precvakne lano." << std::endl;
                    cyklus2=false;
                    break;
                default:
                    break;
            }
    }
    cyklus2=true;/**< @brief Reset lokalnich promennych na puvodni hodnoty.*/
    scrat->zahodLevaRuka(); /**< @brief Zahozeni klacku.*/
    std::cin.ignore();
    std::cout << std::endl;
/** @brief Pasaz s rybickama a kung-fu Scratem*/
    std::cout << "Stoji proti tobe strasne moc ryb. Ocividne chteji tvuj orisek!" << std::endl;

    std::cout << std::endl;
    std::cout << "[" << index << "] Utect" << std::endl; index++;
    std::cout << "[" << index << "] Nikdy nedostanete muj Orisek!" << std::endl; index=0;


    while(cyklus2)/**< @brief Cyklus pro ziskani odpovedi a pripadne pro boj s rybami*/
    {
        std::cout << "Vyber akci:";
        std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':
                    cyklus2=false;
                    std::cout << "Podarilo se ti uprchnout." << std::endl << std::endl;
                    break;
                case '1':
                /** @brief Zde je popsan boj s rybami. Boj je zcela automaticky a casovany. Pred bojem se hracovi zvednou staty*/
                    scrat->enrageZapnout();
                    for(unsigned int i=2; i<vektorBeast.size(); i++){
                        IceAge::boj(scrat,vektorBeast.at(i));
                        std::cout << i-1 << ". " << vektorBeast.at(i)->getNazev() << " je omracen." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    scrat->enrageVypnout();
                    cyklus2=false;
                    break;
                default:
                    break;
            }
    }
    std::cin.ignore();


    std::cin.ignore();
/** @brief Zaverecny obrazek a vypis*/
    std::cout << "Konecne jsi sam. Na ledovci s oriskem. Nasel sis svoje mistecko." << std::endl;

    std::cin.ignore();

std::cout << "     .-----.            .'`-." << std::endl;
std::cout << "    /      ,--          | .- `-." << std::endl;
std::cout << "  ,'    ,-'   `.     _.-'  ,-.`.)" << std::endl;
std::cout << " ;     /   ,=---`--+'     .- -. `." << std::endl;
std::cout << "(   \\    ,'   =,- ,'     ( o ) | /\\" << std::endl;
std::cout << " :   :  /  =,-'  /        \\-'  ;(o :" << std::endl;
std::cout << "  \\  |     '    ;  (       `--'  \\ ;" << std::endl;
std::cout << "   \\ |        = |  \\`--+   --.    `(" << std::endl;
std::cout << "    `+       =/ :   :   `.    `.    \\" << std::endl;
std::cout << "     '      =/   \\   `--. '-.   `.   `." << std::endl;
std::cout << "      \\    =;     `._    : ( `-.  `.   `." << std::endl;
std::cout << "       \\  = ;        `._.'  `-.-`-._\\    `-." << std::endl;
std::cout << "        \\= '                   _.-'_)  (::::)" << std::endl;
std::cout << "         `+      -.           `--7'  `--`..'" << std::endl;
std::cout << "          (        :    .'       ;" << std::endl;
std::cout << "           \\       |    |       /" << std::endl;
std::cout << "            \\      | _.-|  +---'" << std::endl;
std::cout << "             `--+   `.  \\   \\" << std::endl;
std::cout << "                /`.  '-.-\\   `--." << std::endl;
std::cout << "               /    /#### `----.'" << std::endl;
std::cout << "              (  ,-'############\\" << std::endl;
std::cout << "              \\\\/###############;" << std::endl;
std::cout << "               \\###############/" << std::endl;
std::cout << "                |--------------|     _.---------" << std::endl;
std::cout << "                :::::::::::::::|_.-''" << std::endl;
std::cout << "                 ::::::::::_.-''" << std::endl;
std::cout << "       .-''..'---'-------''" << std::endl;

    std::cin.ignore();

    IceAge::MemoryArbiter::cycleDelete();/**< @brief Uvolneni pameti.*/
	exit(0);/**< @brief Uspesne ukonceni.*/
}
