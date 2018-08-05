/**
@file
*/
#ifndef LEDOVEC_H
#define LEDOVEC_H
#include "Command.h"



namespace IceAge {
/**
Trida implementujici algoritmus pro prozkoumani lokace Ledovec.
*/
	class Ledovec : public IceAge::Command {


	public:
		Ledovec(std::string novyNazev);/**< @brief Konstruktor*/

		~Ledovec();/**< @brief Virtualni Destruktor */

		void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast, std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka);/**< @brief Podedena metoda pridavajici algoritmus pro prozkoumani lokace Ledovec.*/
	};
}
#endif
