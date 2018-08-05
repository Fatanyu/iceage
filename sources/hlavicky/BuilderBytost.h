/**
@file
*/
#ifndef BUILDERBYTOST_H
#define BUILDERBYTOST_H

#include "BuilderPredmet.h"
#include "Beast.h"
#include "Humanoid.h"

namespace IceAge {

/**
Trida, ktera bude stavet bytosti(Humanoidy s predmety/Beasty). Podle navrhoveho vzoru Builder.
*/
	class BuilderBytost {

	private:
		IceAge::Beast* m_beast;/**< @brief Atribut do ktereho se uklada odkaz vytvareneho beastu.*/
		IceAge::Humanoid* m_humanoid;/**< @brief Atribut do ktereho se uklada odkaz vytvareneho humanoida.*/
		IceAge::BuilderPredmet *m_builder; /**< @brief Atribut do ktereho se uklada odkaz na BuilderPredmet.*/

	public:
		BuilderBytost(IceAge::BuilderPredmet* novyBuilder); /**< @brief Konstruktor*/
		~BuilderBytost();/**< @brief Destruktor*/

		void setBuilder(IceAge::BuilderPredmet* novyBuilder); /**< @brief Metoda ktera nastavuje BuilderPredmet.*/

		IceAge::Predmet* createPredmet(std::string novyNazev, short novaHodnota); /**< @brief Metoda vytvarejici predmet.*/

		IceAge::Beast* getBeast(); /**< @brief Metoda vracejici Beast.*/
		IceAge::Humanoid* getHumanoid(); /**< @brief Metoda vracejici Humanoida.*/

		void createBeast(short novaZurivost, std::string novyNazev, short novaSila, std::string novyPopis, short novaOdolnost, short novyZivot);/**< @brief Metoda vytvarejici Beast*/

		void createHumanoid(short novyZivot, std::string novyPopis, short novaSila, short novaOdolnost, std::string novyNazevPredmetu1, std::string novyNazevPredmetu2,
                                             std::string novyNazevPredmetu3, short novaHodnotaPredmetu1, short novaHodnotaPredmetu2, short novaHodnotaPredmetu3);/**< @brief Metoda vytvarejici Humanoida*/
	};
}
#endif
