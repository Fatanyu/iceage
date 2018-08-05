/**
@file
*/
#ifndef ORISEK_H
#define ORISEK_H

#include"Predmet.h"
namespace IceAge {
/**
Trida, ktera znazornuje predmet typu Orisek a implementuje pro nej rozhrani.
Tato trida je urcena pro jakykoli predmet, ktery potrebuje pouze nazev a nic jineho.
*/
	class Orisek : public IceAge::Predmet {

	public:
		Orisek(std::string novyPopis);/**< @brief Konstruktor*/
		~Orisek();/**< @brief Destruktor*/
		 short getAtribut();/**< @brief Podedena metoda vracejici hodnotu 0.*/
	};
}
#endif
