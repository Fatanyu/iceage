/**
@file
*/
#ifndef MEMORY_H
#define MEMORY_H

namespace IceAge{
    class MemoryArbiter;
}

#include "IMemory.h"
#include "MemoryArbiter.h"



namespace IceAge {
/**
Abstratkni trida, ktera implementuje rozhrani vsech dedenych trid, tykajicich se spravy pameti. Musi se z ni dedit, pokud ma byt jina trida ulozena v MemoryArbiter.
*/
	class Memory : public IceAge::IMemory {

	protected:
		unsigned int m_id;/**< @brief ID (index), na kterem se v MemoryArbiter nachazi dedena trida. */

		unsigned int getId();/**< @brief Vraci hodnotu ID.*/

	public:
		void setId(unsigned int noveId);/**< @brief Nastavuje hodnotu ID.*/

		Memory();/**< @brief Konstruktor*/
		virtual ~Memory();/**< @brief Destruktor*/
	};
}
#endif
