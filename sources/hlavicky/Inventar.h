/**
@file
*/
#ifndef INVENTAR_H
#define INVENTAR_H

#include"IInventar.h"
const short MAX_INVENTAR=5;/**< @brief Konstanta udavajici maximalni velikost inventare.*/

namespace IceAge {
/**
Abstraktni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se Inventare a jeho obsluhy.
*/
	class Inventar : public IceAge::IInventar {

	protected:
		std::vector<IceAge::Predmet*> m_vektorPredmetu;/**< @brief Vektor predmetu fungujici jako inventar.*/
		unsigned short m_maximalniVelikost;/**< @brief Atribut udavajici maximalni velikost inventare.*/

		unsigned short getMaximalniVelikost();/**< @brief Metoda vracejici hodnotu maximalni povolene velikosti inventare.*/
		void setMaximalniVelikost(unsigned short novaMaximalniVelikost);/**< @brief Metoda nastavujici maximalni velikost inventare.*/
		unsigned int volba();/**< @brief Pomocna metoda k rozhodovani.*/

	public:
		IceAge::Predmet* odeberPredmet();/**< @brief Metoda vyndavajici nejaky predmet z inventare.*/
		void pridejPredmet(IceAge::Predmet* novyPredmet);/**< @brief Metoda pridavajici novy predmet do inventare.*/
		void znicPredmet();/**< @brief Metoda nicici predmet v inventari.*/
		void vypisObsah();/**< @brief Metoda vypisujici predmety v inventari.*/

		Inventar(unsigned short novaVelikost);
		~Inventar();
	};
}
#endif
