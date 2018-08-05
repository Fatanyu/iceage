/**
@file
*/
#ifndef POPIS_H
#define POPIS_H

#include"IPopis.h"

namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se jakehokoli popisu.
*/
	class Popis : public IceAge::IPopis {

	protected:
		std::string m_popis;/**< @brief Atribut do ktereho se uklada popis.*/

		void setPopis(std::string novyPopis);/**< @brief Metoda nastavujici popis.*/

	public:
		Popis(std::string novyPopis);/**< @brief Konstruktor*/
		~Popis();/**< @brief Destruktor*/
		std::string getPopis();/**< @brief Metoda vracejici popis.*/
	};
}
#endif
