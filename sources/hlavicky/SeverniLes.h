/**
@file
*/
#ifndef SEVERNILES_H
#define SEVERNILES_H

#include "Command.h"

namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace SeverniLes.
*/
	class SeverniLes : public IceAge::Command {


	public:
		SeverniLes(std::string novyNazev);/**< @brief Konstruktor*/

		~SeverniLes();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace SeverniLes.*/
	};
}
#endif
