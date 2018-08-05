/**
@file
*/
#ifndef OBLECENEVYBAVENIVEVERKY_H
#define OBLECENEVYBAVENIVEVERKY_H

#include"IObleceneVybaveni.h"
#include"Predmet.h"
#include "Zbran.h"
#include "Orisek.h"

namespace IceAge {
/**
Abstratkni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se obleceneho vybaveni (hlavne zbrani). Konkretne pro dve ruce.
*/
	class ObleceneVybaveniVeverky : public IceAge::IObleceneVybaveni {

	protected:
		IceAge::Predmet* m_levaRuka;/**< @brief Atribut udrzujici odkaz na predmet v leve ruce.*/
		IceAge::Predmet* m_pravaRuka;/**< @brief Atribut udrzujici odkaz na predmet v prave ruce.*/

	public:
		void setPravaRuka(IceAge::Predmet* novaPravaRuka);/**< @brief Metoda nastavujici obsah prave ruky.*/
        void setLevaRuka(IceAge::Predmet* novaLevaRuka);/**< @brief Metoda nastavujici obsah leve ruky.*/
		ObleceneVybaveniVeverky(IceAge::Predmet* novaLevaRuka, IceAge::Predmet* novaPravaRuka); /**< @brief Konstruktor*/
		~ObleceneVybaveniVeverky();/**< @brief Destruktor*/
		IceAge::Predmet* getLevaRuka();/**< @brief Metoda vracejici obsah leve ruky.*/
		IceAge::Predmet* getPravaRuka();/**< @brief Metoda vracejici obsah prave ruky.*/

        void zahodLevaRuka(); /**< @brief Metoda zahazujici (mazani) predmet v leve ruce.*/
        void zahodPravaRuka(); /**< @brief Metoda zahazujici (mazani) predmet v prave ruce.*/
	};
}
#endif
