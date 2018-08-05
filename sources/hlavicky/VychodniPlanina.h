/**
@file
*/
#ifndef VYCHODNIPLANINA_H
#define VYCHODNIPLANINA_H

#include"Command.h"

namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace VychodniPlanina.
*/
	class VychodniPlanina : public IceAge::Command {


	public:
		VychodniPlanina(std::string novyNazev);/**< @brief Konstruktor*/

		~VychodniPlanina();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace VychodniPlanina.*/
	};
}

#endif
