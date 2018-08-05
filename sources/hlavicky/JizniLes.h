/**
@file
*/
#ifndef JIZNILES_H
#define JIZNILES_H

#include "Command.h"

namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace JizniLes.
*/
	class JizniLes : public IceAge::Command {


	public:
		JizniLes(std::string novyNazev);/**< @brief Konstruktor*/

		~JizniLes();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace JizniLes.*/
	};
}
#endif
