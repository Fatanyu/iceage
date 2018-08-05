/**
@file
*/
#ifndef IMEMORY_H
#define IMEMORY_H



namespace IceAge {
/**
Abstratkni trida, ktera upresnuje rozhrani vsech dedenych trid, tykajicich se spravy pameti.
*/
	class IMemory {

	protected:
		virtual unsigned int getId() = 0; /**< @brief Virtualni metoda, ktera vraci ID (index), na kterem se v MemoryArbiter nachazi.*/

	public:
		virtual void setId(unsigned int novaId) = 0; /**< @brief Virtualni metoda nastavujici ID.*/
	};
}
#endif
