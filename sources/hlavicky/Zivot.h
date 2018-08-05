/**
@file
*/
#ifndef ZIVOT_H
#define ZIVOT_H

#include "IZivot.h"
#include "MemoryArbiter.h"

namespace IceAge {
/**
Abstratkni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se zivota.
*/
	class Zivot : public IceAge::IZivot {

	protected:
		short m_zivotAktualni;  /**< @brief Aktualni hodnota zivota*/
		short m_zivotMaximalni; /**< @brief Maximalni hodnota zivota*/

		void setZivotAktualni(short novyZivotAktualni); /**< @brief Metoda nastavujici zivotAktualni.*/
		void setZivotMaximalni(short novyZivotMaximalni); /**< @brief Metoda nastavujici zivotMaximalni.*/

	public:
		void changeZivotAktualni(short hodnotaZmeny); /**< @brief Metoda menici hodnotu aktualnihoZivota.*/

		short getZivotAktualni(); /**< @brief Metoda vracejici hodnotu aktualnihoZivota.*/

		short getZivotMaximalni(); /**< @brief Metoda vracejici hodnotu maximalnihoZivota.*/

		Zivot(short novyZivot, short novyMaximalniZivot); /**< @brief Konstruktor*/
		virtual ~Zivot(); /**< @brief Virtualni Destruktor*/

		virtual short utok() = 0; /**< @brief Virtualni metoda vracejici hodnotu celkoveho Utoku.*/

		virtual short obrana() = 0; /**< @brief Virtualni metoda vracejici hodnotu celkove Obrany.*/
	};
}
#endif
