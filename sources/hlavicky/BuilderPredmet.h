/**
@file
*/
#ifndef BUILDERPREDMET_H
#define BUILDERPREDMET_H

#include "Zbran.h"

namespace IceAge {

/**
Trida, ktera bude stavet predmety. Podle navrhoveho vzoru Builder.
*/
	class BuilderPredmet {

	private:
		IceAge::Predmet* m_pripravovany;/**< @brief Atribut do ktereho se uklada odkaz vytvareneho predmetu.*/

	public:
		void createPredmet(std::string novyNazev, short novaHodnota);/**< @brief Metoda, ktera vytvori predmet.*/

		IceAge::Predmet* getPredmet();/**< @brief Metoda vracejici odkaz na vytvareny predmet.*/

		BuilderPredmet();/**< @brief Konstruktor*/
		~BuilderPredmet();/**< @brief Destruktor*/
	};
}

#endif
