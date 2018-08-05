/**
@file
*/
#ifndef HUMANOID_H
#define HUMANOID_H

#include "Inventar.h"
#include "ObleceneVybaveniHumanoid.h"
#include "Memory.h"
#include "Zivot.h"
#include "Nazev.h"
#include "Popis.h"
#include "Staty.h"

namespace IceAge {
/**
Jedna se o tridu, ktera znazornuje Lidi, kteri mohou nest veci i na zadech.
*/
	class Humanoid : public IceAge::Inventar, public IceAge::ObleceneVybaveniHumanoid, public IceAge::Memory,
                     public IceAge::Zivot, public IceAge::Nazev, public IceAge::Popis, public IceAge::Staty {

	public:
		Humanoid(short novyZivot, std::string novyNazev, std::string novyPopis, short novaSila, short novaOdolnost, IceAge::Predmet* zbran1, IceAge::Predmet* zbran2, IceAge::Predmet* zbran3);/**< @brief Konstruktor*/
        ~Humanoid();/**< @brief Destruktor*/

		short utok();/**< @brief Podedena metoda vracejici hodnotu celkoveho utoku.*/

		short obrana();/**< @brief Podedena metoda vracejici hodnotu celkove obrany.*/
	};
}

#endif
