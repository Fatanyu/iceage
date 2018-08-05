/**
@file
*/
#ifndef ZBRAN_H
#define ZBRAN_H

#include"Predmet.h"


namespace IceAge {
/**
Trida, ktera znazorunuje predmet typu Zbran a implementuje pro nej rozhrani.
*/
	class Zbran : public IceAge::Predmet {

    private:
		short m_poskozeni;/**< @brief Atribut obsahujici hodnotu poskozeni, ktere muze tato zbran zpusobit.*/

        void setPoskozeni(short novePoskozeni);/**< @brief Metoda nastavujici hodnotu poskozeni.*/


    public:
		short getPoskozeni();/**< @brief Metoda vracejici hodnotu poskozeni.*/
        short getAtribut();/**< @brief Podedena metoda vracejici hodnotu poskozeni.*/
		Zbran(std::string novyNazev, short novePoskozeni); /**< @brief Konstruktor*/
		~Zbran();/**< @brief Destruktor*/
	};
}
#endif
