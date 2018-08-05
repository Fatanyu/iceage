/**
@file
*/
#ifndef BEAST_H
#define BEAST_H

#include "Memory.h"
#include "Zivot.h"
#include "Nazev.h"
#include "Popis.h"
#include "Staty.h"

namespace IceAge {
/**
Jedna se o tridu, ktera znazornuje zvirata, ktera nemohou nest zadne veci. Ridi se spise instinkty.
*/
	class Beast : public IceAge::Memory, public IceAge::Zivot, public IceAge::Nazev, public IceAge::Popis, public IceAge::Staty {

	private:
        short m_zurivost;/**< @brief Atribut znazornujici jak agresivni muze dane zvire byt. Muze byt i zaporna.*/
		void setZurivost(short novaZurivost);/**< @brief Metoda nastavujici zurivost.*/

    public:
		short utok();/**< @brief Konkretni implementace dedene metody vracejici hodnotu celkoveho utoku.*/
        short getZurivost();/**< @brief Metoda vracejici hodnotu zurivosti.*/
		short obrana();/**< @brief Konkretni implementace dedene metody vracejici hodnotu celkove obrany.*/
		Beast(short novaZurivost, std::string novyNazev, short novaSila, std::string novyPopis, short novaOdolnost, short novyZivot);/**< @brief Konstruktor*/
		~Beast();/**< @brief Destruktor*/
	};
}
#endif
