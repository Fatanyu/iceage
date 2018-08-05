/**
@file
*/
#ifndef NAZEV_H
#define NAZEV_H

#include"INazev.h"


namespace IceAge {
/**
Abstratkni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se nazvu.
*/
	class Nazev : public IceAge::INazev {

	protected:
		std::string m_nazev; /**< @brief Atribut do ktereho se uklada nazev dedene tridy (jeji instance).*/

		void setNazev(std::string novyNazev);/**< @brief Metoda nastavujici nazev.*/

	public:
		Nazev(std::string novyNazev);/**< @brief Konstruktor*/
		std::string getNazev();/**< @brief Metoda vracejici nazev.*/
	};
}
#endif
