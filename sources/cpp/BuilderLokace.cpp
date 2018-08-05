/**
@file
*/
#include "../hlavicky/BuilderLokace.h"

/**
Konstruktor ve kterem se nastavuje BuilderBytost a do lokace se uklada nullptr.
*/
IceAge::BuilderLokace::BuilderLokace(IceAge::BuilderBytost* novyBuilder) {
	this->setBuilder(novyBuilder);
	this->m_lokace=nullptr;
}

/**
Metoda ktera nastavuje BuilderBytost.
*/
void IceAge::BuilderLokace::setBuilder(IceAge::BuilderBytost* novyBuilder) {
	this->m_builderBytost=novyBuilder;
}

/**
Metoda vracejici Lokaci.
*/
IceAge::Lokace* IceAge::BuilderLokace::getLokace() {
	return this->m_lokace;
}

/**
Metoda vytvarejici humanoida. Provola metody ostatnich builderu a vrati vytvoreneho Humanoida.
*/
IceAge::Humanoid* IceAge::BuilderLokace::createHumanoid(short novyZivot, std::string novyPopis, short novaSila, short novaOdolnost,
                                                     std::string novyNazevPredmetu1, std::string novyNazevPredmetu2, std::string novyNazevPredmetu3,
                                                     short novaHodnotaPredmetu1, short novaHodnotaPredmetu2, short novaHodnotaPredmetu3) {
	this->m_builderBytost->createHumanoid(novyZivot, novyPopis, novaSila, novaOdolnost, novyNazevPredmetu1, novyNazevPredmetu2, novyNazevPredmetu3,
                                             novaHodnotaPredmetu1, novaHodnotaPredmetu2, novaHodnotaPredmetu3);
    return this->m_builderBytost->getHumanoid();
}

/**
Metoda vytvarejici beasta. Provola metody ostatnich builderu a vrati vytvoreneho beasta.
*/
IceAge::Beast* IceAge::BuilderLokace::createBeast(short novaZurivost, std::string novyNazev, short novaSila, std::string novyPopis, short novaOdolnost, short novyZivot) {
	this->m_builderBytost->createBeast( novaZurivost, novyNazev, novaSila, novyPopis, novaOdolnost, novyZivot);
	return this->m_builderBytost->getBeast();
}

/**
Metoda vytvarejici Lokaci.
*/
void IceAge::BuilderLokace::createLokace() {

	std::ifstream seznam, popisLokace;
	seznam.open("Lokace/.seznam");/**< @brief Otevreni seznamu lokaci.*/
	if(!seznam.is_open())
    {
        std::cerr << "Chyby seznam lokaci. Program ukoncen.";
        IceAge::MemoryArbiter::cycleDelete();/**< @brief V pripade chyby uvolni pamet a skonci.*/
        exit(-1);
    }
//    std::cout << "Soubor s lokacemi otevren" << std::endl;

    std::string radek, nazevL, popisL, popisLCast, rekaL; /**< @brief Lokalni promenne, do kterych se bude nacitat ze souboru.*/

//    IceAge::Lokace *pridavanaLokace;

    while(getline(seznam, radek)) /**< @brief Nacitani nazvu souboru ze souboru ".seznam"*/
    {
//        std::cout << "Otevira se " << radek << std::endl;
        popisLokace.open(radek); /**< @brief Otevirani souboru s popisem aktualne vytvarene lokace.*/
        if(!popisLokace.is_open())
        {
            std::cerr << "Chybi soubor: " << radek << std::endl;
            IceAge::MemoryArbiter::cycleDelete(); /**< @brief V pripade chyby uvolni pamet a skonci.*/
            exit(-1);
        }
    /** Nastavovani zakladnich atributu lokace. */
        getline(popisLokace, nazevL);           //************************
        getline(popisLokace, rekaL);            //                      **
        popisL=""; popisLCast="";               //nacitani popisu       **
        do                                      //                      **
        {                                       //                      **
            popisL+= popisLCast;                //                      **
            getline(popisLokace, popisLCast);   //                      **
        }while(popisLCast != "***");            //************************


        this->m_lokace=new IceAge::Lokace(nazevL, popisL);/**< @brief Vytvoreni hole kostry lokace.*/

        if(rekaL == "1") this->m_lokace->pridejReku(); /**< @brief Rozhodnuti, zda se vytvari reka*/

//nacteni poctu Humanoidu
        this->nactiHumanoidy(popisLokace); /**< @brief Nacteni humanoidu ze souboru.*/
        this->nactiBeasty(popisLokace); /**< @brief Nacterni beastu ze souboru.*/

        while(!popisLokace.fail()) /**< @brief Cyklus ve kterem se usporadaji odkazy mezi jednotlivymi lokacemi.*/
        {
            //std::cout << "jsem tu" << std::endl;
            getline(popisLokace, radek);
                                //std::cout << "Nacetl jsem " << radek << std::endl;
            for(unsigned int i=0; i<this->m_vektorLokaci.size(); i++)
            {
                //std::cout << radek;
                if(radek == (this->m_vektorLokaci.at(i)->getNazevLokace()))
                {
                                //std::cout << radek + " " + this->m_vektorLokaci.at(i)->getNazevLokace() << std::endl;
                    this->m_lokace->pridejLokaci(this->m_vektorLokaci.at(i));
                                // std::cout << this->m_lokace->getNazevLokace() << " dostava " << this->m_vektorLokaci.at(i)->getNazevLokace() << std::endl;
                    this->m_vektorLokaci.at(i)->pridejLokaci(this->m_lokace);
                                //std::cout << this->m_vektorLokaci.at(i)->getNazevLokace() << " dostava " << this->m_lokace->getNazevLokace() << std::endl;
                }
            }
        }

//        this->m_vektorLokaci.push_back(pridavanaLokace);
        this->m_lokace->setPrikaz();    /**< @brief Do lokace se vlozi odpovidajici trida s metodou pruzkumu.*/
        this->m_vektorLokaci.push_back(this->m_lokace); /**< @brief Ulozeni lokace do vectoru.*/
        this->m_lokace=nullptr;
        popisLokace.close(); /**< @brief Uzavreni souboru s popisem aktualni lokace.*/
    }


    seznam.close(); /**< @brief Uzavreni souboru se seznamem souboru vsech lokaci.*/

    this->m_lokace=this->m_vektorLokaci.at(0); /**< @brief Nastaveni prvni lokace jako hlavni (aktualni).*/

    this->m_vektorLokaci.clear();
}

/**
Metoda vytvarejici Humanoidy na zaklade popisu v souboru. Pokud jsou spatne popsane lokace v souborech, nactou se spatne a muze dojit ke spatnemu pristupu do pameti.
*/
void IceAge::BuilderLokace::nactiHumanoidy(std::ifstream &popisLokace){
    short pocet=0; /**< @brief Lokalni promena znacici pocet Humanoidu v lokaci.*/
    std::string radek="";
    popisLokace >> pocet;           popisLokace.ignore(); /**< @brief Nacteni poctu Humanoidu + ignorace konce radku.*/

//    std::cout << pocet << std::endl;
    if(pocet <=0) /**< @brief Pokud humanoidi v lokaci nejsou, nacte znacku a ukonci metodu.*/
    {
//        std::cout << "Nejsou tu lidi" << std::endl;
        getline(popisLokace,radek);
        return;
    }
    std::string popis, nazevPredmetu1, nazevPredmetu2, nazevPredmetu3; /**< @brief Lokalni promenne potrebne k vytvoreni humanoida.*/
    short zivot, sila, odolnost, hodnotaPredmetu1, hodnotaPredmetu2, hodnotaPredmetu3;

    for(short i=0; i<pocet; i++) /**< @brief Cyklus ve kterem se nactou hodnoty potrebne pro vytvoreni humanoida a nasledne jeho vytvoreni a pridani do vectoru.*/
    {
        getline(popisLokace,popis);
        popisLokace >> sila;                        popisLokace.ignore();
        popisLokace >> odolnost;                    popisLokace.ignore();
        popisLokace >> zivot;                       popisLokace.ignore();
        getline(popisLokace,nazevPredmetu1);
        popisLokace >> hodnotaPredmetu1;            popisLokace.ignore();
        getline(popisLokace,nazevPredmetu2);
        popisLokace >> hodnotaPredmetu2;            popisLokace.ignore();
        getline(popisLokace,nazevPredmetu3);
        popisLokace >> hodnotaPredmetu3;            popisLokace.ignore();

        this->m_lokace->pridejHumanoid(this->createHumanoid(zivot,popis,sila,odolnost,
                                                    nazevPredmetu1,nazevPredmetu2,nazevPredmetu3,
                                                    hodnotaPredmetu1, hodnotaPredmetu2, hodnotaPredmetu3));

    }

    getline(popisLokace,radek); /**< @brief Odebrani znacky.*/

}

/**
Metoda vytvarejici Beasty na zaklade popisu v souboru. Pokud jsou spatne popsane lokace v souborech, nactou se spatne a muze dojit ke spatnemu pristupu do pameti.
*/
void IceAge::BuilderLokace::nactiBeasty(std::ifstream &popisLokace){
    short pocet=0;/**< @brief Lokalni promena znacici pocet Beastu v lokaci.*/
    std::string radek="";
    popisLokace >> pocet; popisLokace.ignore();/**< @brief Nacteni poctu Beastu + ignorace konce radku.*/

    if(pocet <=0)/**< @brief Pokud beasty v lokaci nejsou, nacte znacku a ukonci metodu.*/
    {
        getline(popisLokace,radek);
        return;
    }
//    std::cout << "jsem tady" << std::endl;
    std::string popis, nazev;/**< @brief Lokalni promenne potrebne k vytvoreni beasta.*/
    short zurivost, zivot, sila, odolnost;

    for(short i=0; i<pocet; i++)/**< @brief Cyklus ve kterem se nactou hodnoty potrebne pro vytvoreni beasta a nasledne jeho vytvoreni a pridani do vectoru.*/
    {
        getline(popisLokace,nazev);
        getline(popisLokace,popis);
        popisLokace >> zurivost;            popisLokace.ignore();
        popisLokace >> sila;                popisLokace.ignore();
        popisLokace >> odolnost;            popisLokace.ignore();
        popisLokace >> zivot;               popisLokace.ignore();

        this->m_lokace->pridejBeast(this->createBeast(zurivost,nazev,sila,popis,odolnost,zivot));

    }

    getline(popisLokace,radek);/**< @brief Odebrani znacky.*/
//    std::cout << radek;
}

/**
Destruktor ve kterem se maze builder a pripadne vytvarena lokace.
*/
IceAge::BuilderLokace::~BuilderLokace(){
    if(this->m_builderBytost != nullptr) delete this->m_builderBytost;
    if(this->m_lokace != nullptr) delete this->m_lokace;

    for(unsigned int i=0; i<m_vektorLokaci.size(); i++)
        if(this->m_vektorLokaci.at(i) != nullptr) delete this->m_vektorLokaci.at(i);
}
