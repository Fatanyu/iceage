/**
@file
*/
#ifndef ENGINEICEAGE_H
#define ENGINEICEAGE_H

#include "LocationDirector.h"
#include "Veverka.h"
#include "Hra.h"


namespace IceAge {
/**
Trida ktera zastituje celou hru. Inicializuje vsechny soubory a vetsinu trid. Spousti hru.
Trida je implementovana jako Singleton.
*/
	class EngineIceAge : public IceAge::Memory {

	private:
		IceAge::Veverka* m_veverka;/**< @brief Atribut udrzujici odkaz na Veverku.*/
		static IceAge::EngineIceAge* s_vlastniInstance;/**< @brief Staticky atribut udrzujici odkaz sam na sebe.*/
		IceAge::LocationDirector* m_directorLokaci;/**< @brief Atribut udrzujici odkaz na LocationDirector.*/
		IceAge::Lokace* m_lokace;/**< @brief Atribut udrzujici odkaz na aktualni lokaci.*/

		EngineIceAge(IceAge::LocationDirector *novyDirector); /**< @brief Konstruktor*/

		IceAge::Veverka* getVeverka(); /**< @brief Metoda vracejici Veverku.*/

		void createVeverka(); /**< @brief Metoda vytvarejici Veverku.*/
		bool inicializaceLokaci(); /**< @brief Metoda inicializujici Lokace.*/

		void setDirector(IceAge::LocationDirector* novyDirector); /**< @brief Metoda nastavujici noveho LocationDirector.*/

    public:
		static IceAge::EngineIceAge* getInstance(); /**< @brief Metoda vracejici instanci teto tridy.*/
		void startHry();/**< @brief Metoda spoustejici hru.*/

		~EngineIceAge();/**< @brief Destruktor*/
	};
}
#endif
