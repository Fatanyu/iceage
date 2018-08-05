/**
@file
*/
#ifndef STATY_H
#define STATY_H

#include"IStaty.h"
#include <iostream>

namespace IceAge {
/**
Abstratkni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se zakladnich statu.
*/
	class Staty : public IceAge::IStaty {

	protected:
		short m_sila;/**< @brief Atribut do ktereho se uklada sila.*/
		short m_odolnost;/**< @brief Atribut do ktereho se uklada odolnost.*/

		short getSila();/**< @brief Metoda vracejici hodnotu sily.*/
		void setSila(short novaSila);/**< @brief Metoda nastavujici hodnotu sily.*/

		short getOdolnost();/**< @brief Metoda vracejici hodnotu odolnosti.*/
		void setOdolnost(short novaOdolnost);/**< @brief Metoda nastavujici hodnotu odolnosti.*/

	public:
		Staty(short novaSila, short novaOdolnost);/**< @brief Konstruktor*/
		~Staty();/**< @brief Destruktor*/
	};
}
#endif
