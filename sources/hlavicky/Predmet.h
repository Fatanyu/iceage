/**
@file
*/
#ifndef PREDMET_H
#define PREDMET_H

#include"Memory.h"
#include"Nazev.h"


namespace IceAge {
/**
Abstraktni trida, ktera znazornuje predmet a castecne pro nej implementuje rozhrani.
*/
	class Predmet : public IceAge::Memory, public IceAge::Nazev {

	protected:
		char m_typ;/**< @brief Atribut uchovavajici hodnotu, ktera znazornuje o ktery predmet se jedna. 'w' je zbran, 'n' je zbytek, 'u' je nezname.*/

        void setTyp(char novyTyp);/**< @brief Metoda nastavujici typ.*/


    public:
		char getTyp();/**< @brief Metoda vracejici typ(druh) predmetu.*/

        virtual short getAtribut() = 0;/**< @brief Virtualni metoda vracejici hodnotu atributu nejakeho potomka.*/
		Predmet(std::string novyNazev);/**< @brief Konstruktor*/
		~Predmet();/**< @brief Destruktor*/
	};
}
#endif
