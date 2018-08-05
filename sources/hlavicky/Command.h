/**
@file
*/
#ifndef COMMAND_H
#define COMMAND_H


#include <iostream>
#include "Nazev.h"
#include "Veverka.h"
#include "Reka.h"
#include "Beast.h"
#include "Humanoid.h"
#include "VolneFunkce.h"

namespace IceAge {
/**
Abstraktni trida vyuzivana pro navrhovy vzor Command. Jednotlivi potomci jsou sparovani s jednotlivymi instancemi lokace v pomeru 1:1. Diky tomu pujde prozkoumavat tyto lokace.
*/
	class Command : public IceAge::Nazev {

	public:
		Command(std::string novyNazev);/**< @brief Konstruktor*/

		virtual ~Command();/**< @brief Virtualni Destruktor */

		virtual void prozkoumat(IceAge::Veverka* scrat, std::vector<IceAge::Beast*> vektorBeast,
                            std::vector<IceAge::Humanoid*> vektorHumanoid, IceAge::Reka* reka) = 0;/**< @brief Virtualni metoda, pomoci ktere se prida nova metoda(funkcionalita/algoritmus) do jiz existujici tridy.*/
	};
}

#endif
