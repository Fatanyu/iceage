/**
@file
*/
#ifndef IOBLECENEVYBAVENI_H
#define IOBLECENEVYBAVENI_H

#include"Zbran.h"

namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se obleceneho vybaveni (hlavne zbrani).
*/
	class IObleceneVybaveni {

	protected:
		virtual IceAge::Predmet* getLevaRuka() = 0;/**< @brief Virtualni metoda vracejici obsah leve ruky.*/
		virtual IceAge::Predmet* getPravaRuka() = 0;/**< @brief Virtualni metoda vracejici obsah prave ruky.*/

	public:
		virtual void setLevaRuka(IceAge::Predmet* novaLevaRuka) = 0;/**< @brief Virtualni metoda nastavujici obsah leve ruky.*/
		virtual void setPravaRuka(IceAge::Predmet* novaPravaRuka) = 0;/**< @brief Virtualni metoda nastavujici obsah prave ruky.*/
	};
}
#endif
