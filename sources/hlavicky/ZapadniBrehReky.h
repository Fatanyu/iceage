/**
@file
*/
#ifndef ZAPADNIBREHREKY_H
#define ZAPADNIBREHREKY_H

#include "Command.h"


namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace ZapadniBrehReky.
*/
	class ZapadniBrehReky : public IceAge::Command {


	public:
		ZapadniBrehReky(std::string novyNazev);/**< @brief Konstruktor*/

		~ZapadniBrehReky();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace ZapadniBrehReky.*/
	};
}

#endif
