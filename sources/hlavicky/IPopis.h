/**
@file
*/
#ifndef IPOPIS_H
#define IPOPIS_H

#include<iostream>

namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se jakehokoli popisu.
*/
	class IPopis {

	protected:
		virtual std::string getPopis() = 0;/**< @brief Virtualni metoda vracejici popis.*/

		virtual void setPopis(std::string novyPopis) = 0;/**< @brief Virtualni metoda nastavujici popis.*/
	};
}
#endif
