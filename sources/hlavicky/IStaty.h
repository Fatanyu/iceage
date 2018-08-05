/**
@file
*/
#ifndef ISTATY_H
#define ISTATY_H

namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se zakladnich statu.
*/
	class IStaty {

	protected:
		virtual short getSila() = 0;/**< @brief Virtualni metoda vracejici hodnotu sily.*/

		virtual void setSila(short novaSila) = 0;/**< @brief Virtualni metoda nastavujici hodnotu sily.*/

		virtual short getOdolnost() = 0;/**< @brief Virtualni metoda vracejici hodnotu odolnosti.*/

		virtual void setOdolnost(short novaOdolnost) = 0;/**< @brief Virtualni metoda nastavujici hodnotu odolnosti.*/
	};
}
#endif
