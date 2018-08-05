/**
@file
*/
#ifndef INAZEV_H
#define INAZEV_H

#include<iostream>

namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se nazvu.
*/
	class INazev {

	protected:
		virtual void setNazev(std::string novyNazev) = 0;/**< @brief Virtualni metoda nastavujici nazev.*/

	public:
		virtual std::string getNazev() = 0;/**< @brief Virtualni metoda vracejici nazev.*/
	};
}
#endif
