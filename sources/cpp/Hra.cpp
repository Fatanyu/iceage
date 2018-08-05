/**
@file
*/
#include "../hlavicky/Hra.h"

/**
Konstruktor ktery nastavi aktualni lokaci a aktualni obrazek na 0;
*/
IceAge::Hra::Hra(IceAge::Lokace* novaAktualniLokace) {
	this->setAktualniLokace(novaAktualniLokace);
	this->m_obrazek=0;
}

/**
Metoda ktera zmeni lokaci na zaklade hracova vyberu.
*/
void IceAge::Hra::zmenLokaci(IceAge::Veverka* scrat) {
    char volba= 'a';
    unsigned int volbaCislo=0;
    std::cout << std::endl;
    this->m_aktualniLokace->vypisLokace();
//    std::cout << std::endl;

    while(true){
        std::cout << "Vyber akci:";
        std::cin >> volba;std::cin.ignore(); volbaCislo=volba - '0';
        std::cout << std::endl;
        if(volbaCislo < (this->m_aktualniLokace->getVelikostVektoruLokaci())){
            this->zmenLokaci(volbaCislo, scrat);
            break;
        }
    }

//    std::cout << "[" << index << "] " <<std::endl; index++;
}

/**
Metoda ktera zmeni lokaci na zaklade hodnoty indexu a pripadnemu vybaveni hrace.
*/
void IceAge::Hra::zmenLokaci(unsigned int index, IceAge::Veverka* scrat) {
    if((this->m_aktualniLokace->getLokace(index)->getNazevLokace() == "Severni les") and (this->m_aktualniLokace->getNazevLokace() == "Jizni les")){ /**< @brief Pokud se cestuje z lesa do lesa.*/

        if(scrat->getPravaRuka() == nullptr || scrat->getLevaRuka()== nullptr){ /**< @brief Pokud nevlastnis lod a klacek*/
            std::cout << "Nemas se jak dostat pres reku." << std::endl;
        }
        else{
            std::cout << "Pouzivas svoji zbran jako padlo a plujes po lodce na druhou stranu" << std::endl;
            this->setAktualniLokace(this->m_aktualniLokace->getLokace(index));
        }
    }
    else if((this->m_aktualniLokace->getLokace(index)->getNazevLokace() == "Jizni les") and (this->m_aktualniLokace->getNazevLokace() == "Severni les")){ /**< @brief Pokud se cestuje z lesa do lesa.*/
        if(scrat->getPravaRuka() == nullptr || scrat->getLevaRuka()== nullptr){
            std::cout << "Nemas se jak dostat pres reku." << std::endl;
        }
        else{
            std::cout << "Pouzivas svoji zbran jako padlo a plujes po lodce na druhou stranu" << std::endl;
            this->setAktualniLokace(this->m_aktualniLokace->getLokace(index));
        }
    }
    else this->setAktualniLokace(this->m_aktualniLokace->getLokace(index));
}

/**
Metoda ktera nastavi aktualni lokaci.
*/
void IceAge::Hra::setAktualniLokace(IceAge::Lokace* novaAktualniLokace){
    this->m_aktualniLokace=novaAktualniLokace;
}

/**
Metoda ktera vypise aktualni lokaci, tj jeho nazev a popis.
*/
void IceAge::Hra::vypisAktualniLokaci(){
    std::cout << std::endl;
    std::cout << "Nazev mista: " << this->m_aktualniLokace->getNazevLokace() << std::endl;
    std::cout << "Popis: " << this->m_aktualniLokace->getPopisLokace() << std::endl;
    std::cout << std::endl;
}

/**
Metoda ktera vypise aktualni obrazek. Rozhoduje se na zaklade atributu obrazek.
*/
void IceAge::Hra::vypisAsciObrazek(){
        this->m_obrazek++;
        switch (this->m_obrazek){
        case 1:
std::cout<<"  _,                          _"                << std::endl;
std::cout<<".'  `.                  ___.>\"''-..-."         << std::endl;
std::cout<<"`-.   ;           .--\"\"\"        .-._@;"      << std::endl;
std::cout<<"   ;  !_.--..._ .'      /     .[_@'`'."         << std::endl;
std::cout<<"  ;            /       : .'  ; :_.._  `."       << std::endl;
std::cout<<"  :           ;        ;[   _T-\"  `.'-. `-."   << std::endl;
std::cout<<"   \\        .-:      ; `.`-=_,88p.   _.}.-\""  << std::endl;
std::cout<<"    `-.__.-'   \\    /L._ Y\",P$T888;  \"\""    << std::endl;
std::cout<<"             .-'_.-'  / ;$$$$$$]8P;"            << std::endl;
std::cout<<"             \\ /     / / \"Y$$P\" ^\""         << std::endl;
std::cout<<"              ;\\_    `.\\_._"                  << std::endl;
std::cout<<"              ]__\\     \\___;"                 << std::endl;

std::cin.ignore();
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;



            break;
        case 2:
std::cout<<"              ___"         << std::endl;
std::cout<<"        .-\"\"\"\"   \"."         << std::endl;
std::cout<<"       /         __'-."         << std::endl;
std::cout<<"      ;      ..sssSSSS;"         << std::endl;
std::cout<<"      ;   ;           ;"         << std::endl;
std::cout<<"       '.'  ..sssSSSSSS;"         << std::endl;
std::cout<<"       ;        \"\"\"\"\"\"\";"         << std::endl;
std::cout<<"      ;    ...ssssSSSSS;"         << std::endl;
std::cout<<"      ;          \"\"\"\"\"\";"         << std::endl;
std::cout<<"      ;               ;"         << std::endl;
std::cout<<"      ;     ....sssSS/"         << std::endl;
std::cout<<"      ;          \"\"\"/"         << std::endl;
std::cout<<"       ;          .'"         << std::endl;
std::cout<<"       ;    .-\"\"\"\"-."         << std::endl;
std::cout<<"        '-.'  _..ssS,"         << std::endl;
std::cout<<"        .'  \"\"  _..sSs"         << std::endl;
std::cout<<"       /__    \"\"  _.sSS."         << std::endl;
std::cout<<"     .-\"\" `-.   ___     ; _"         << std::endl;
std::cout<<"    /_..gg$$$pp'___`.   .' `>."         << std::endl;
std::cout<<"  ,s$$$$$$$$$B;\"   `;\"\";  .' ;"         << std::endl;
std::cout<<" :$$$$$$$$$$P\"`._():   `-`_O.'"         << std::endl;
std::cout<<":$$$$$$$$$P              '   `-."         << std::endl;
std::cout<<"$$$$$$$$$\"    _,,-.       :     ;"         << std::endl;
std::cout<<"$$$$$$$$!b.._g$$$$$$-.     ;    `."         << std::endl;
std::cout<<":$$$$$$$$$$$$$$$$$$P j\\    :_.._/"         << std::endl;
std::cout<<" T$$$$$$$$$$$$$$$$P  | :    ;"         << std::endl;
std::cout<<"  \"T$$$$$$$$$$$$P\";  ;_;    :"         << std::endl;
std::cout<<"    \"^T$$$$$$P^\"; : //:   __!"         << std::endl;
std::cout<<"        | |     : ; `.: .mMMM:"         << std::endl;
std::cout<<"        ) :_    ) '-.   'MMMP'"         << std::endl;
std::cout<<"       `.i_;I  '-._i.'"         << std::endl;

std::cin.ignore();
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
            break;
        case 3:
std::cout<<"                               ,"         << std::endl;
std::cout<<"         ,::.::::.            / `."         << std::endl;
std::cout<<"       ;::        `.         (  ,--."         << std::endl;
std::cout<<"       ,;           :   _,--'\"\\/\"\"-.\\_"         << std::endl;
std::cout<<"      ,:             `./ ,---./( O )) `;"         << std::endl;
std::cout<<"      ;  `.           _,'    (  `-' ) /_."         << std::endl;
std::cout<<"      ;   :         ,'        \\    , (o\\\\"         << std::endl;
std::cout<<"       ;  :         \\  \\-.  -.__--'   \\' )"         << std::endl;
std::cout<<"       ;  ;         /\\ (    `-._`-._   \\/"         << std::endl;
std::cout<<"        ';,        ; : |      -.`._'\\   `."         << std::endl;
std::cout<<"          ;       ;  : `-.,-..  )  \\'\\   ^."         << std::endl;
std::cout<<"           ;     ;   `.__   )))\\ ) (`.\\    \\"         << std::endl;
std::cout<<"            ;   ;        `-`///(, \\ \\ \\)  ,ooo."         << std::endl;
std::cout<<"             ;,;      ;     ``  ))))_;'(  88888p"         << std::endl;
std::cout<<"              ;      ;         ((-='--',-,Y8888'"         << std::endl;
std::cout<<"              ;     :         ;     ,:'-'  `\"'"         << std::endl;
std::cout<<"               ;     `        ;      |"         << std::endl;
std::cout<<"                ;      (_   __   _,-'"         << std::endl;
std::cout<<"                 `---.   ;\"(,-' /                              ____"         << std::endl;
std::cout<<"                      \\ (__/\\\\_`-.-.                     _____/"         << std::endl;
std::cout<<"                    ,(( '/\\/\\/\\`-;;))             ______//"         << std::endl;
std::cout<<"                   ((\\''/\\/\\/\\/\\/\\/`/\\      _____/  ____/"         << std::endl;
std::cout<<"                   /'/\\/\\/\\/\\/\\/\\/\\/\\/)  __/  _____/"         << std::endl;
std::cout<<"                  (\\/\\/\\/\\/\\/\\/\\/\\/\\_/ _/ ___/"         << std::endl;
std::cout<<"                   `-|\"\"--\"-.___,--'|-'__/"         << std::endl;
std::cout<<"                     |              | /"         << std::endl;
std::cout<<"                     |         __,--'"         << std::endl;
std::cout<<"                     _\\,----\"\"'"         << std::endl;

std::cin.ignore();
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
             break;
        case 4:
             break;
        case 5:
             break;
        case 6:
             break;
        case 7:
            break;
        default:
            break;
        }
}

void IceAge::Hra::intro(IceAge::Veverka *scrat){
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/
    bool cyklus=true,cyklus2=true; /**< @brief Lokalni promenne pouzivane pro cykleni.*/
    short index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/

    std::cout << "Bylo nebylo.." << std::endl;
    std::cout << "Za davnych casu zila jedna veverka." << std::endl;
    this->vypisAsciObrazek();/**< @brief Vypise obrazek na obrazovku.*/

    std::cout << "Hledala misto, kam by si schovala svuj orisek." << std::endl;
    this->vypisAsciObrazek();/**< @brief Vypise obrazek na obrazovku.*/

    std::cout << "[0] Hledej dal" <<std::endl;
    std::cout << "Vyber akci:";
    std::cin >> volba;std::cin.ignore();
    while(cyklus)/**< @brief Cykleni pri cekani na spravne hodnoty od hrace.*/
    {
        switch(volba)
        {
            case '0':
                cyklus=false;
                break;
            default:
                std::cout << "Vyber akci:";
                std::cin >> volba;std::cin.ignore();
                break;
        }
    }
    cyklus=true;/**< @brief Reset lokalni promenne.*/
    while(cyklus)/**< @brief Cykleni vypisu s moznostmi akci.*/
    {
        cyklus2=true;
        std::cout << std::endl << "Nasel si ho!" << std::endl; std::cin.ignore();
        while(cyklus2)/**< @brief Cykleni pri cekani na spravne hodnoty od hrace.*/
        {
            std::cout << "[" << index << "] Hledej dal" <<std::endl; index++;
            std::cout << "[" << index << "] Vloz orisek" <<std::endl; index++;
            std::cout << "[" << index << "] Kde ze jsem?" <<std::endl; index=0;
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            std::cout << std::endl;
            switch(volba)
            {
                case '0':/**< @brief Moznost Hledej dal*/
                    cyklus2=false;
                    continue;
                    break;
                case '1':/**< @brief Moznost Vloz orisek*/
                    cyklus=false; cyklus2=false;
                    break;
                case '2':/**< @brief Moznost Kde ze jsem?*/
                    this->vypisAktualniLokaci();
                    continue;
                    break;
                default:
                    break;
            }
        }
    }
    cyklus=true; cyklus2=true; /**< @brief Reset lokalnich promennych*/

    this->vypisAsciObrazek(); /**< @brief Vypis obrazek*/
    std::cout << "Povedlo se ti rozbit ledovec na kterem jsi byl!!" << std::endl;
    std::cout << "Ledovec se rozpada a sjizdis na lavine do udoli" << std::endl;
    std::cout << std::endl;

    this->zmenLokaci(0,scrat); /**< @brief Zmena lokace*/

    std::cout << "[" << index << "] Kde ze jsem?" <<std::endl; index=0;
    while(cyklus2)/**< @brief Cykleni pri cekani na spravne hodnoty od hrace. Spravna je pouze jedna hodnota.*/
    {
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':
                    this->vypisAktualniLokaci();
                    cyklus2=false;
                    break;
                default:
                    break;
            }
    }
    cyklus2=true;/**< @brief Reset lokalni promenne*/
    scrat->zahodPravaRuka();

    std::cout << "Opatrne se zvedas na nohy. Chybi ti orisek!!" << std::endl;
    std::cout << "Vidis velkeho Supomuta, jak ti s nim chce odletet!" << std::endl;

/** Interakce se Supomutem.*/
    std::cout << std::endl;
    std::cout << "[" << index << "] Zautocit" <<std::endl; index++;
    std::cout << "[" << index << "] Utect" <<std::endl; index++;
    std::cout << "[" << index << "] Schovat se" <<std::endl; index=0;
    while(cyklus2)/**< @brief Cykleni pri cekani na spravnou hodnotu od hrace*/
    {
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':/**< @brief Moznost Zautocit*/
                    boj(scrat, this->m_aktualniLokace->getBeast(3));
                    std::cout << "Dostal si ranu paratem. Supomut ti odlita pred nosem." << std::endl;
                    cyklus2=false;
                    break;
                case '1':/**< @brief Moznost Utect*/
                    std::cout << "Supomut odleta pryc i s tvym oriskem" << std::endl;
                    cyklus2=false;
                    break;
                case '2':/**< @brief Moznost Schovat se*/
                    std::cout << "Schovavas se za kousek ledu. Supomut si te nevsima a odleta s tvym oriskem" << std::endl;
                    cyklus2=false;
                    break;
                default:
                    break;
            }
    }
    cyklus2=true;/**< @brief Reset lokalni promenne*/

    std::cout << std::endl;
    std::cout << "[" << index << "] Pronasleduj Supomuta" <<std::endl; index=0;
    while(cyklus2) /**< @brief Cykleni pri cekani na spravnou jednu hodnotu*/
    {
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':
                    std::cout << "Bezis jak nejrychleji muzes, ale cestu ti prekrizila reka." << std::endl;
                    std::cout << "Vidis jak se ti Supomut vzdaluje na obzoru." << std::endl;
                    this->zmenLokaci(1, scrat); /**< @brief Zmena lokace na finalni v intru*/
                    cyklus2=false;
                    break;
                default:
                    break;
            }
    }
}

/**
Metoda ktera spusti pribeh.
*/
void IceAge::Hra::zacniHrat(IceAge::Veverka *scrat){
    char volba='a';/**< @brief Lokalni promenna pozivana pro nacitani odpovedi od uzivatele.*/
    bool cyklus=true,cyklus2=true; /**< @brief Lokalni promenne pouzite pro cykly.*/
    short index=0;/**< @brief Lokalni promenna pouzivana pro cislovani moznosti, ktere se zobrazi uzivateli.*/

    this->intro(scrat); /**< @brief Spust uvodni dej.*/

    while(cyklus)/**< @brief Cykleni v lokacich*/
    {
        cyklus2=true;

        this->vypisAktualniLokaci();

        while(cyklus2) /**< @brief Cykleni v ziskavani odpovedi od hrace*/
        {
            std::cout << "[" << index << "] Jit jinam " <<std::endl; index++;
            std::cout << "[" << index << "] Kde ze jsem?" <<std::endl;index++;
            std::cout << "[" << index << "] Prozkoumat to tu" <<std::endl; index=0;
            std::cout << "Vyber akci:";
            std::cin >> volba;std::cin.ignore();
            switch(volba)
            {
                case '0':/**< @brief Moznost Jit jinam*/
                    this->zmenLokaci(scrat);
                    cyklus2=false;
                    continue;
                    break;
                case '1':/**< @brief Moznost Kde ze jsem?*/
                    this->vypisAktualniLokaci();
                    continue;
                    break;
                case '2':/**< @brief Prozkoumat to tu*/
                    this->m_aktualniLokace->prozkoumatLokaci(scrat);
                    break;
                default:
                    break;
            }
        }
    }
}
