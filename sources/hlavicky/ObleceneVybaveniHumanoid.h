/**
@file
*/
#ifndef OBLECENEVYBAVENIHUMANOID_H
#define OBLECENEVYBAVENIHUMANOID_H

#include"IObleceneVybaveni.h"


namespace IceAge {
/**
Abstratkni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se obleceneho vybaveni (hlavne zbrani). Konkretne pro dve ruce a zada.
*/
	class ObleceneVybaveniHumanoid : public IceAge::IObleceneVybaveni {

	protected:
		IceAge::Predmet* m_levaRuka;/**< @brief Atribut udrzujici odkaz na predmet v leve ruce.*/
		IceAge::Predmet* m_pravaRuka;/**< @brief Atribut udrzujici odkaz na predmet v prave ruce.*/
		IceAge::Predmet* m_zada;/**< @brief Atribut udrzujici odkaz na predmet na zadech.*/

		IceAge::Predmet* getLevaRuka();/**< @brief Metoda vracejici obsah leve ruky.*/
		IceAge::Predmet* getPravaRuka();/**< @brief Metoda vracejici obsah prave ruky.*/
		IceAge::Predmet* getZada();/**< @brief Metoda vracejici obsah zad.*/

	public:
		void setZada(IceAge::Predmet* novaZada);/**< @brief Metoda nastavujici obsah zad.*/
		void setPravaRuka(IceAge::Predmet* novaPravaRuka);/**< @brief Metoda nastavujici obsah prave ruky.*/
		void setLevaRuka(IceAge::Predmet* novaLevaRuka);/**< @brief Metoda nastavujici obsah leve ruky.*/
		ObleceneVybaveniHumanoid(IceAge::Predmet* levaRuka, IceAge::Predmet* pravaRuka, IceAge::Predmet* zada);/**< @brief Konstruktor*/
		~ObleceneVybaveniHumanoid();/**< @brief Destruktor*/
	};
}
#endif
