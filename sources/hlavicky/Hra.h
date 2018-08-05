/**
@file
*/
#ifndef HRA_H
#define HRA_H

#include "Lokace.h"
#include "Veverka.h"
#include "VolneFunkce.h"

namespace IceAge {
/**
Trida zajistujici samotny prubeh hry.
*/
	class Hra : public IceAge::Memory {

	private:
		IceAge::Lokace* m_aktualniLokace; /**< @brief Atribut udrzujici odkaz na aktualni lokaci.*/
		short m_obrazek; /**< @brief Atribut ktery je pocitadlo aktualniho obrazku.*/

		void zmenLokaci(IceAge::Veverka* scrat); /**< @brief Metoda ktera zmeni aktualni lokaci.*/
		void zmenLokaci(unsigned int index, IceAge::Veverka* scrat);/**< @brief Metoda ktera zmeni aktualni lokaci.*/

		void setAktualniLokace(IceAge::Lokace* novaAktualniLokace);/**< @brief Metoda ktera nastavi aktualni lokaci.*/
        void vypisAktualniLokaci();/**< @brief Metoda ktera vypise aktualni lokaci.*/
		void vypisAsciObrazek(); /**< @brief Metoda ktera vypise aktualni obrazek.*/
		void intro(IceAge::Veverka *scrat);/**< @brief Metoda ktera je uvodnim algoritmem(dejem) ve hre.*/

    public:
		Hra(IceAge::Lokace* novaAktualniLokace); /**< @brief Konstruktor.*/
		void zacniHrat(IceAge::Veverka *scrat); /**< @brief Metoda ktera spusti pribeh.*/

	};
}
#endif
