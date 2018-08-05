/**
@file
*/
#ifndef MEMORYARBITER_H
#define MEMORYARBITER_H

namespace IceAge{
    class Memory;
}
#include "Memory.h"
#include <vector>
#include <iostream>


namespace IceAge {
/**
Staticka Trida, obsluhujici pamet. Vsechny dulezite tridy (zabirajici vice mista nebo obsahujici vice jinych trid v ramci agregace/kompozice) zde na sebe ukladaji odkaz.
Pokud ma tato trida fungovat, musi si hlidana trida podedit abstraktni tridu Memory. V pripade, ze nedojde k smazani dane tridy v programu, MemoryArbiter muze sam uvolnit jeji pamet.
Problem muze nastat v pripade dosazeni maximalniho poctu prvku v memoryVector.
Trida je implementovana jako Monostate.
*/
	class MemoryArbiter {

	private:
		static std::vector<IceAge::Memory*> s_memoryVector;/**< @brief Staticky vektor udrzujici odkazy na jednotlive tridy.*/

		MemoryArbiter();/**< @brief Privatni Konstruktor, ktery se nikdy nezavola.*/

	public:
		static void add(IceAge::Memory* target);/**< @brief Staticka metoda pridavajici odkaz na tridu do memoryVector.*/

		static void remove(unsigned int targetId);/**< @brief Staticka metoda odebirajici odkaz na tridu z memoryVector.*/

		static void cycleDelete();/**< @brief Staticka metoda uvolnujici veskerou pamet, na kterou ma odkaz.*/
	};
}
#endif
