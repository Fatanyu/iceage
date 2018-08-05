/**
@file
*/
#ifndef REKA_H
#define REKA_H

namespace IceAge {
/**
Trida, implementujici rozhrani pro praci s rekou.
*/
	class Reka {

	private:
		short m_hodnotaZivota;/**< @brief Atribut udavajici o kolik se uzdravis.*/

		void setHodnotaZivota(short novaHodnotaZivota);/**< @brief Metoda nastavujici hodnotaZivota.*/

	public:
		short getHodnotaZivota();/**< @brief Metoda vracejici hodnotaZivota*/

		Reka(short novaHodnota);/**< @brief Konstruktor*/
		~Reka();/**< @brief Destruktor*/
	};
}
#endif
