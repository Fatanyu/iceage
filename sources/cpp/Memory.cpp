/**
@file
*/
#include "../hlavicky/Memory.h"

/**
Vraci hodnotu ID.
*/
unsigned int IceAge::Memory::getId() {
	return this->m_id;
}

/**
Nastavuje hodnotu ID. Hodnota, ktera se sem vklada, bude vzdy kladna (jedna se o index vectoru).
*/
void IceAge::Memory::setId(unsigned int noveId) {
	this->m_id=noveId;
}

/**
Konstruktor, ve kterem se vola metoda MemoryArbitera, pridavajici sam sebe do jeho seznamu.
*/
IceAge::Memory::Memory() {
    IceAge::MemoryArbiter::add(this);
}

/**
Destruktor, ve kterem se vola metoda MemoryArbitera, odebirajici sam sebe z jeho seznamu.
*/
IceAge::Memory::~Memory() {
	IceAge::MemoryArbiter::remove(this->getId());
}
