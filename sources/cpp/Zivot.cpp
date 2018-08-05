/**
@file
*/
#include "../hlavicky/Zivot.h"

/**
Metoda menici zivotAktualni. V pripade, ze zdravi bude mensi nebo rovno nule, hra se ukonci a uvolni se pamet.
Toto opatreni se tyka stylu Doby ledove, Scrat nezabiji a sam nesmi byt zabit.
*/
void IceAge::Zivot::changeZivotAktualni(short hodnotaZmeny) {
	this->m_zivotAktualni+=hodnotaZmeny;
	if(this->m_zivotAktualni>this->m_zivotMaximalni) this->m_zivotAktualni=this->m_zivotMaximalni;
/**
Zde se provadi kontrola, zda jeste zije.
*/
	if(this->m_zivotAktualni <= 0){
        std::cout << "Tohle ma byt mirumilovna hra! Nepovedlo se ti ziskat orisek! Game Over!" << std::endl;

        IceAge::MemoryArbiter::cycleDelete();
        exit(0);
	}
}

/**
Metoda vracejici hodnotu aktualnihoZivota.
*/
short IceAge::Zivot::getZivotAktualni() {
    return this->m_zivotAktualni;
}

/**
Metoda vracejici hodnotu maximalnihoZivota.
*/
short IceAge::Zivot::getZivotMaximalni() {
	return this->m_zivotMaximalni;
}

/**
Metoda nastavujici zivotAktualni. Tato hodnotu musi byt kladna. V opacnem pripade je zivot nastaven na 1;
Pokud nova hodnota presahne velikost maximalniho zivota, je nastavena maximalni povolena hodnota.
*/
void IceAge::Zivot::setZivotAktualni(short novyZivotAktualni) {
	if(novyZivotAktualni>=0)
	{
        if(novyZivotAktualni<this->m_zivotMaximalni) this->m_zivotAktualni=novyZivotAktualni;
        else this->m_zivotAktualni=this->m_zivotMaximalni;
	}
	else this->m_zivotAktualni=1;
}

/**
Metoda nastavujici zivotMaximalni. Pokud je nova hodnota mensi jak 0, je nastaven na 5.
*/
void IceAge::Zivot::setZivotMaximalni(short novyZivotMaximalni) {
    if(novyZivotMaximalni>0) this->m_zivotMaximalni=novyZivotMaximalni;
	else this->m_zivotMaximalni=5;
}

/**
Konstruktor, ve kterem se nastavuje zivot. Nejdrive musi byt metoda setZivotMazimalni(). V opacnem pripade se do aktualniZivot nastavi nahodna hodnota.
*/
IceAge::Zivot::Zivot(short novyZivot, short novyMaximalniZivot) {
//nejdriv udelat maximalku, potom aktualni
	this->setZivotMaximalni(novyMaximalniZivot);
    this->setZivotAktualni(novyZivot);
}

/**
Destruktor
*/
IceAge::Zivot::~Zivot(){
}
