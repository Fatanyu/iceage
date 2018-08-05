/**
@file
*/
#ifndef ZAPADNIPLANINA_H
#define ZAPADNIPLANINA_H

#include"Command.h"

namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace ZapadniPlanina.
*/
	class ZapadniPlanina : public IceAge::Command {


	public:
		ZapadniPlanina(std::string novyNazev);/**< @brief Konstruktor*/

		~ZapadniPlanina();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace ZapadniPlanina.*/
	};
}

#endif
