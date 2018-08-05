/**
@file
*/
#ifndef LOKACE_H
#define LOKACE_H

namespace IceAge{
    class Command;
}
#include "Command.h"
#include "Reka.h"
#include "Popis.h"
#include "Nazev.h"
#include "Memory.h"
#include <vector>
#include "Zivot.h"
#include "Veverka.h"
#include "Beast.h"
#include "Humanoid.h"

#include "Ledovec.h"
#include "ZapadniPlanina.h"
#include "ZapadniBrehReky.h"
#include "JizniLes.h"
#include "SeverniLes.h"
#include "VychodniPlanina.h"
#include "VychodniBrehReky.h"
#include "Jezero.h"

const short LECIVOST_REKY=5;

namespace IceAge {

	class Lokace : public IceAge::Nazev, public IceAge::Popis, public IceAge::Memory {

	private:
		std::vector<IceAge::Beast*> m_vektorBeast;
		std::vector<IceAge::Humanoid*> m_vektorHumanoid;
		IceAge::Reka* m_odkazReka;
		std::vector<IceAge::Lokace*> m_vektorLokaci;
		IceAge::Command* m_prikaz;

	public:
		Lokace(std::string novyNazev, std::string novyPopis);
		~Lokace();

		void pridejBeast(IceAge::Beast* novyBeast);
		void pridejHumanoid(IceAge::Humanoid* novyHumanoid);

		void smazBeast(unsigned int index);
        void smazHumanoid(unsigned int index);

		void pridejReku();

		void smazReku();

		void pridejLokaci(IceAge::Lokace* novaLokace);

		void smazLokaci(unsigned int index);

		void odeberLokaci(unsigned int index);

		void vypisLokace();

		std::string getNazevLokace();
		std::string getPopisLokace();
		Lokace* getLokace(unsigned int index);
		IceAge::Beast* getBeast(unsigned int index);
		IceAge::Humanoid* getHumanoid(unsigned int index);

		unsigned int getVelikostVektoruLokaci();

		std::vector<IceAge::Beast*> getVektorBeast();
		std::vector<IceAge::Humanoid*> getVektorHumanoid();
		IceAge::Reka* getReka();

		void setPrikaz();

		void prozkoumatLokaci(IceAge::Veverka* scrat);

		//unsigned int volba();
	};
}
#endif
