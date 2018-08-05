/**
@file
*/
#ifndef VEVERKA_H
#define VEVERKA_H

#include "ObleceneVybaveniVeverky.h"
#include "Staty.h"
#include "Memory.h"
#include "Zivot.h"
#include <cstdio>

const short SCRAT_HP=20; /**< @brief Konstanta urcujici hracovo zdravi.*/
const short SCRAT_SILA=5; /**< @brief Konstanta urcujici hracovu silu*/
const short SCRAT_ODOLNOST=5; /**< @brief Konstanta urcujici hracovu odolnost*/

namespace IceAge {
/**
Trida hlavniho hrdiny. Je implementovana jako Singleton.
*/
	class Veverka : public IceAge::ObleceneVybaveniVeverky, public IceAge::Staty, public IceAge::Memory, public IceAge::Zivot {

	private:
		static IceAge::Veverka* s_vlastniInstance; /**< @brief Staticky atribut odkaz sam na sebe. Dulezite pro Singleton.*/

		Veverka(short novyZivot, short novaSila, short novaOdolnost); /**< @brief Konstruktor*/

	public:
		static IceAge::Veverka* getInstance(); /**< @brief Staticka metoda, ktera povoli vytvorit pouze jedinou instanci teto tridy.*/
		short utok();/**< @brief Konkretni implementace dedene metody vracejici hodnotu celkoveho utoku.*/
		short obrana();/**< @brief Konkretni implementace dedene metody vracejici hodnotu celkove obrany.*/
		~Veverka();/**< @brief Destruktor*/
		void enrageZapnout();/**< @brief Okamzite zvysuje atributy na mnohem vyssi hodnoty.*/
		void enrageVypnout();/**< @brief Vraci atributy do normalnich hodnot.*/
	};
}

#endif
