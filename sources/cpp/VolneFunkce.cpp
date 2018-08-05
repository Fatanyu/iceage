/**
@file
*/
#include "../hlavicky/VolneFunkce.h"

/**
Funkce, ktera zprostredkovava boj mezi dvema potomky tridy Zivot.
Boj probiha jednokolove. Nejprve utoci utocnik, nasledne utoci obrance.
Pokud nekdo z nich zemre, hra se ukonci.
O boji se vypisuje informace.
*/
void IceAge::boj(IceAge::Zivot* utocnik, IceAge::Zivot* obrance) {
	std::cout << std::endl;
	if(utocnik->utok() > obrance->obrana()){
        std::cout << "Obrance ztraci "<< utocnik->utok() - obrance->obrana() << " zivotu" << std::endl;
        obrance->changeZivotAktualni(obrance->obrana() - utocnik->utok());
	}
	if(obrance->utok() > utocnik->obrana()){
        std::cout << "Utocnik ztraci "<< obrance->utok() - utocnik->obrana() << " zivotu" << std::endl;
        utocnik->changeZivotAktualni(utocnik->obrana() - obrance->utok());
	}
	std::cout << "Stav zivotu:" << std::endl;
	std::cout << "************" << std::endl;
	std::cout << "Utocnik: " << utocnik->getZivotAktualni() << "/" << utocnik->getZivotMaximalni() << std::endl;
	std::cout << "Obrance: " << obrance->getZivotAktualni() << "/" << obrance->getZivotMaximalni() << std::endl;
}
