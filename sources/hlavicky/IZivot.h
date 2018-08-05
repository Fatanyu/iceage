/**
@file
*/
#ifndef IZIVOT_H
#define IZIVOT_H

#include<iostream>


namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se zivota.
*/
	class IZivot {


	protected:
		virtual short getZivotAktualni() = 0;/**< @brief Virtualni metoda vracejici hodnotu aktualnihoZivota.*/

		virtual void setZivotAktualni(short novyZivotAktualni) = 0;/**< @brief Virtualni metoda nastavujici hodnotu aktualnihoZivota.*/

		virtual short getZivotMaximalni() = 0;/**< @brief Virtualni metoda vracejici hodnotu maximalnihoZivota.*/

		virtual void setZivotMaximalni(short novyZivotMaximalni) = 0;/**< @brief Virtualni metoda nastavujici hodnotu maximalnihoZivota.*/

	public:
		virtual void changeZivotAktualni(short hodnotaZmeny) = 0;/**< @brief Virtualni metoda menici hodnotu aktualnihoZivota.*/

	};
}
#endif
