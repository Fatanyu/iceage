/**
@file
*/
#include "../hlavicky/Lokace.h"

IceAge::Lokace::Lokace(std::string novyNazev, std::string novyPopis):IceAge::Nazev(novyNazev), Popis(novyPopis) {
    this->m_odkazReka=nullptr;
    this->m_prikaz=nullptr;
}

void IceAge::Lokace::pridejBeast(IceAge::Beast* novyBeast) {
	this->m_vektorBeast.push_back(novyBeast);
}

void IceAge::Lokace::pridejHumanoid(IceAge::Humanoid* novyHumanoid) {
	this->m_vektorHumanoid.push_back(novyHumanoid);
}

void IceAge::Lokace::smazBeast(unsigned int index) {
	IceAge::Beast* third=this->m_vektorBeast.at(index);
    this->m_vektorBeast.at(index)=this->m_vektorBeast.at(this->m_vektorBeast.size()-1);
    this->m_vektorBeast.at(this->m_vektorBeast.size()-1)=third;
	this->m_vektorBeast.pop_back();
}

void IceAge::Lokace::smazHumanoid(unsigned int index) {
	IceAge::Humanoid* third=this->m_vektorHumanoid.at(index);
    this->m_vektorHumanoid.at(index)=this->m_vektorHumanoid.at(this->m_vektorHumanoid.size()-1);
    this->m_vektorHumanoid.at(this->m_vektorHumanoid.size()-1)=third;
	this->m_vektorHumanoid.pop_back();
}

void IceAge::Lokace::pridejReku() {
	this->m_odkazReka=new IceAge::Reka(LECIVOST_REKY);
}

void IceAge::Lokace::smazReku() {
	delete this->m_odkazReka;
}

void IceAge::Lokace::pridejLokaci(IceAge::Lokace* novaLokace) {
	this->m_vektorLokaci.push_back(novaLokace);
}

void IceAge::Lokace::smazLokaci(unsigned int index) {
	IceAge::Lokace* third=this->m_vektorLokaci.at(index);
    this->m_vektorLokaci.at(index)=this->m_vektorLokaci.at(this->m_vektorLokaci.size()-1);
    this->m_vektorLokaci.at(this->m_vektorLokaci.size()-1)=nullptr;
	this->m_vektorLokaci.pop_back();
	delete third;
}

void IceAge::Lokace::odeberLokaci(unsigned int index) {
	IceAge::Lokace* third=this->m_vektorLokaci.at(index);
    this->m_vektorLokaci.at(index)=this->m_vektorLokaci.at(this->m_vektorLokaci.size()-1);
    this->m_vektorLokaci.at(this->m_vektorLokaci.size()-1)=third;
	this->m_vektorLokaci.pop_back();
}

void IceAge::Lokace::vypisLokace() {
	for(unsigned int i=0; i<this->m_vektorLokaci.size(); i++)
	{
        std::cout << "[" << i << "] " << this->m_vektorLokaci.at(i)->getNazev() << std::endl;
	}
}

unsigned int IceAge::Lokace::getVelikostVektoruLokaci(){
    return this->m_vektorLokaci.size();
}

std::string IceAge::Lokace::getNazevLokace(){
    return this->getNazev();
}

std::string IceAge::Lokace::getPopisLokace(){
    return this->getPopis();
}

IceAge::Beast* IceAge::Lokace::getBeast(unsigned int index){
    if(index<this->m_vektorBeast.size()) return this->m_vektorBeast.at(index);
    else return this->m_vektorBeast.back();
}

IceAge::Humanoid* IceAge::Lokace::getHumanoid(unsigned int index){
    if(index<this->m_vektorHumanoid.size()) return this->m_vektorHumanoid.at(index);
    else return this->m_vektorHumanoid.back();
}

void IceAge::Lokace::setPrikaz(){
    if(this->getNazevLokace() == "Ledovec")                  this->m_prikaz=new IceAge::Ledovec("Ledovec");
    else if(this->getNazevLokace() == "Zapadni planina")     this->m_prikaz=new IceAge::ZapadniPlanina("Zapadni planina");
    else if(this->getNazevLokace() == "Zapadni breh reky")   this->m_prikaz=new IceAge::ZapadniBrehReky("Zapadni breh reky");
    else if(this->getNazevLokace() == "Jizni les")           this->m_prikaz=new IceAge::JizniLes("Jizni les");
    else if(this->getNazevLokace() == "Severni les")         this->m_prikaz=new IceAge::SeverniLes("Severni les");
    else if(this->getNazevLokace() == "Vychodni planina")    this->m_prikaz=new IceAge::VychodniPlanina("Vychodni planina");
    else if(this->getNazevLokace() == "Vychodni breh reky")  this->m_prikaz=new IceAge::VychodniBrehReky("Vychodni breh reky");
    else if(this->getNazevLokace() == "Jezero")              this->m_prikaz=new IceAge::Jezero("Jezero");

}

IceAge::Lokace::~Lokace(){
    if(this->m_odkazReka != nullptr) delete this->m_odkazReka;
    if(this->m_prikaz != nullptr) delete this->m_prikaz;

    for(unsigned int i=0; i<m_vektorBeast.size(); i++)
        if(this->m_vektorBeast.at(i) != nullptr) delete this->m_vektorBeast.at(i);

    for(unsigned int j=0; j<m_vektorHumanoid.size(); j++)
        if(this->m_vektorHumanoid.at(j) != nullptr) delete this->m_vektorHumanoid.at(j);

 /*   for(unsigned int i=0; i<m_vektorLokaci.size(); i++)
        if(this->m_vektorLokaci.at(i) != nullptr) delete this->m_vektorLokaci.at(i);*/
}

IceAge::Lokace* IceAge::Lokace::getLokace(unsigned int index){
    if(index < this->m_vektorLokaci.size()) return this->m_vektorLokaci.at(index);
    else return this;
}

void IceAge::Lokace::prozkoumatLokaci(IceAge::Veverka* scrat){
    this->m_prikaz->prozkoumat(scrat, this->getVektorBeast(), this->getVektorHumanoid(), this->getReka());
}

std::vector<IceAge::Beast*> IceAge::Lokace::getVektorBeast(){
    return this->m_vektorBeast;
}

std::vector<IceAge::Humanoid*> IceAge::Lokace::getVektorHumanoid(){
    return this->m_vektorHumanoid;
}

IceAge::Reka* IceAge::Lokace::getReka(){
    return this->m_odkazReka;
}

/*unsigned int IceAge::Lokace::volba() {

}*/
