/**
@file
*/
#ifndef BUILDERLOKACE_H
#define BUILDERLOKACE_H

#include "BuilderBytost.h"
#include "Lokace.h"
#include <iostream>

#include <fstream>


namespace IceAge {
/**
Trida, ktera bude stavet Lokace (ktera obsahuje beasty/humanoidy). Podle navrhoveho vzoru Builder.
*/
	class BuilderLokace {

	private:
		IceAge::BuilderBytost* m_builderBytost;/**< @brief Atribut obsahujici odkaz na BuilderBytost.*/
		IceAge::Lokace* m_lokace;/**< @brief Atribut obsahujici odkaz na prave vytvarenou Lokaci.*/
        std::vector <IceAge::Lokace*> m_vektorLokaci;/**< @brief Vector jiz hotovych lokaci, ktere se nasledne spoji do jedne "mapy".*/
	public:
		BuilderLokace(IceAge::BuilderBytost* novyBuilder);/**< @brief Konstruktor*/
		~BuilderLokace();/**< @brief Destruktor*/

		void setBuilder(IceAge::BuilderBytost* novyBuilder);/**< @brief Metoda ktera nastavuje BuilderBytost.*/

		void createLokace();/**< @brief Metoda vytvarejici Lokaci.*/

		IceAge::Lokace* getLokace(); /**< @brief Metoda vracejici Lokaci.*/

		IceAge::Humanoid* createHumanoid(short novyZivot, std::string novyPopis, short novaSila, short novaOdolnost,
                                      std::string novyNazevPredmetu1, std::string novyNazevPredmetu2, std::string novyNazevPredmetu3,
                                      short novaHodnotaPredmetu1, short novaHodnotaPredmetu2, short novaHodnotaPredmetu3);/**< @brief Metoda vytvarejici humanoida.*/

		IceAge::Beast* createBeast(short novaZurivost, std::string novyNazev, short novaSila, std::string novyPopis, short novaOdolnost, short novyZivot);/**< @brief Metoda vytvarejici beast.*/

		void nactiBeasty(std::ifstream &popisLokace); /**< @brief Metoda ktera nacte beasty ze souboru a ulozi je do lokace.*/
		void nactiHumanoidy(std::ifstream &popisLokace);/**< @brief Metoda ktera nacte humanoidy ze souboru a ulozi je do lokace.*/
	};
}
#endif
