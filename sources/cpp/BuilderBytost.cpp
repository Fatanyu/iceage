/**
@file
*/
#include "../hlavicky/BuilderBytost.h"

/**
Konstruktor ve kterem se nastavuje novy BuilderPredmet a do ostatnich atributu se uklada nullptr.
*/
IceAge::BuilderBytost::BuilderBytost(IceAge::BuilderPredmet* novyBuilder) {
	this->setBuilder(novyBuilder);
	this->m_beast=nullptr;
	this->m_humanoid=nullptr;
}


/**
Metoda ktera nastavuje BuilderPredmet.
*/
void IceAge::BuilderBytost::setBuilder(IceAge::BuilderPredmet* novyBuilder) {
	this->m_builder=novyBuilder;
}

/**
Metoda vytvarejici predmet. Nejdrive zavola metodu pro vytvoreni buildera, nasledne zavola getter.
*/
IceAge::Predmet* IceAge::BuilderBytost::createPredmet(std::string novyNazev, short novaHodnota) {
	this->m_builder->createPredmet(novyNazev, novaHodnota);
	return this->m_builder->getPredmet();
}

/**
Metoda vracejici Beast. Nastavuje atribut beast na nullptr.
*/
IceAge::Beast* IceAge::BuilderBytost::getBeast() {
	IceAge::Beast*third=this->m_beast;
	this->m_beast=nullptr;
	return third;
}

/**
Metoda vracejici Humanoida. Nastavuje atribut humanoid na nullptr.
*/
IceAge::Humanoid* IceAge::BuilderBytost::getHumanoid() {
	IceAge::Humanoid*third=this->m_humanoid;
	this->m_humanoid=nullptr;
	return third;
}

/**
Metoda vytvarejici Beast.
*/
void IceAge::BuilderBytost::createBeast(short novaZurivost, std::string novyNazev, short novaSila, std::string novyPopis, short novaOdolnost, short novyZivot) {
    this->m_beast=new IceAge::Beast(novaZurivost, novyNazev, novaSila, novyPopis, novaOdolnost, novyZivot);
}

void IceAge::BuilderBytost::createHumanoid(short novyZivot, std::string novyPopis, short novaSila, short novaOdolnost,
                                            std::string novyNazevPredmetu1, std::string novyNazevPredmetu2, std::string novyNazevPredmetu3,
                                            short novaHodnotaPredmetu1, short novaHodnotaPredmetu2, short novaHodnotaPredmetu3) {

	this->m_humanoid=new IceAge::Humanoid(novyZivot, "Ruzovy dvounozec", novyPopis, novaSila, novaOdolnost,
                                        this->createPredmet(novyNazevPredmetu1, novaHodnotaPredmetu1),
                                        this->createPredmet(novyNazevPredmetu2, novaHodnotaPredmetu2),
                                        this->createPredmet(novyNazevPredmetu3, novaHodnotaPredmetu3));
}

/**
Metoda vytvarejici Humanoida.
*/
IceAge::BuilderBytost::~BuilderBytost(){
    if(this->m_beast != nullptr) delete this->m_beast;
    if(this->m_humanoid != nullptr) delete this->m_humanoid;
    if(this->m_builder != nullptr) delete this->m_builder;
}
