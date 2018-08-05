/**
@file
*/
#include "../hlavicky/EngineIceAge.h"

IceAge::EngineIceAge* IceAge::EngineIceAge::s_vlastniInstance=nullptr; /**< @brief Inicializace statickeho atributu*/

/**
Metoda vracejici instanci teto tridy. Pokud jiz existuje, vrati odkaz na ni.
*/
/*static*/ IceAge::EngineIceAge* IceAge::EngineIceAge::getInstance() {
	if(s_vlastniInstance == nullptr) s_vlastniInstance=new IceAge::EngineIceAge(new IceAge::LocationDirector
                                                                                (new IceAge::BuilderLokace
                                                                                (new IceAge::BuilderBytost
                                                                                (new IceAge::BuilderPredmet()))));
	return s_vlastniInstance;
}

/**
Konstruktor ve kterem se nastavuje LocationDirector a zbytek atributu se nastavuje na nullptr.
*/
IceAge::EngineIceAge::EngineIceAge(IceAge::LocationDirector* novyDirector) {
    this->setDirector(novyDirector);
    this->m_lokace=nullptr;
    this->m_veverka=nullptr;
}

/**
Metoda vracejici Veverku.
*/
IceAge::Veverka* IceAge::EngineIceAge::getVeverka() {
	return this->m_veverka;
}

/**
Metoda vytvarejici Veverku.
*/
void IceAge::EngineIceAge::createVeverka() {
	this->m_veverka=IceAge::Veverka::getInstance();
}

/**
Metoda spoustejici hru. Pokud se provede spravne inicializace lokaci a vytvori se veverka, vytvori tridu IceAge::Hra a spusti hru.
*/
void IceAge::EngineIceAge::startHry() {
    if(!this->inicializaceLokaci())
	{
        return;
	}
	this->createVeverka();

    IceAge::Hra *PJ = new IceAge::Hra(this->m_lokace);

    PJ->zacniHrat(this->m_veverka);

    delete PJ;
}

/**
Metoda inicializujici Lokace. Provola se LocationDirector a v pripade uspechu se vrati true.
*/
bool IceAge::EngineIceAge::inicializaceLokaci() {
	this->m_lokace=this->m_directorLokaci->createLokace();
//    std::cout<<"lokace ok"<<std::endl;
	if(this->m_lokace != nullptr) return true;
	else return false;
}
/**
Metoda nastavujici noveho LocationDirector.
*/
void IceAge::EngineIceAge::setDirector(IceAge::LocationDirector* novyDirector){
    this->m_directorLokaci=novyDirector;
}

/**
Destruktor ve kterem se mazou odkazy z atributu.
*/
IceAge::EngineIceAge::~EngineIceAge(){
    if(this->m_directorLokaci != nullptr) delete this->m_directorLokaci;
    if(this->m_veverka != nullptr) delete this->m_veverka;
    if(this->m_lokace != nullptr) delete this->m_lokace;
}
