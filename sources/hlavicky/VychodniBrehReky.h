/**
@file
*/
#ifndef VYCHODNIBREHREKY_H
#define VYCHODNIBREHREKY_H

#include"Command.h"

namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace VychodniBrehReky.
*/
	class VychodniBrehReky : public IceAge::Command {


	public:
		VychodniBrehReky(std::string novyNazev);/**< @brief Konstruktor*/

		~VychodniBrehReky();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace VychodniBrehReky.*/
	};
}

#endif
