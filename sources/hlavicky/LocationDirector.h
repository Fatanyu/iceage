/**
@file
*/
#ifndef LOCATIONDIRECTOR_H
#define LOCATIONDIRECTOR_H

#include"BuilderLokace.h"

namespace IceAge {
/**
Troda ktera ridi vytvareni lokaci.
*/
	class LocationDirector {

	private:
		IceAge::BuilderLokace* m_builder;/**< @brief Atribut udrzujici odkaz na BuilderLokace.*/

	public:
		LocationDirector(IceAge::BuilderLokace* novyBuilder);/**< @brief Konstruktor*/
		~LocationDirector();/**< @brief Destruktor*/

		IceAge::Lokace* createLokace(); /**< @brief Metoda ktera vytvori Lokace*/

		void setBuilder(IceAge::BuilderLokace* novyBuilder); /**< @brief Metoda ktera nastavuje BuilderLokace*/
	};
}

#endif
