/**
@file
*/
#ifndef IINVENTAR_H
#define IINVENTAR_H

#include"Predmet.h"

namespace IceAge {
/**
Abstraktni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se Inventare a jeho obsluhy.
*/
	class IInventar {

	protected:
		virtual unsigned short getMaximalniVelikost() = 0;/**< @brief Virtualni metoda vracejici hodnotu maximalni povolene velikosti inventare.*/
		virtual void setMaximalniVelikost(unsigned short novaMaximalniVelikost) = 0;/**< @brief Virtualni metoda nastavujici maximalni velikost inventare.*/

	public:
		virtual void pridejPredmet(IceAge::Predmet* novyPredmet) = 0;/**< @brief Virtualni metoda pridavajici novy predmet do inventare.*/
		virtual IceAge::Predmet* odeberPredmet() = 0;/**< @brief Virtualni metoda vyndavajici nejaky predmet z inventare.*/
		virtual void znicPredmet() = 0;/**< @brief Virtualni metoda nicici predmet v inventari.*/
	};
}
#endif
