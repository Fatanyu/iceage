/**
@file
*/
#ifndef JEZERO_H
#define JEZERO_H

#include "Command.h"

#include <thread>
#include <chrono>

namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace Jezero.
*/
	class Jezero : public IceAge::Command {


	public:
		Jezero(std::string novyNazev);/**< @brief Konstruktor*/

		~Jezero();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace Jezero.*/
	};
}
#endif
