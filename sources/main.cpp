/**
@file
Tato hra je o veverce Scrat a jeho Orisku. Byla napsana jako skolni projekt do predmetu ZOO na MENDELU
Hra je inspirovana filmem Doba Ledova.

Autor: Michal Srejber

Pocet radku zdrojovych souboru:3713
*/
#include <iostream>
#include "hlavicky/EngineIceAge.h"

int main()
{
    IceAge::EngineIceAge *dobaledova=IceAge::EngineIceAge::getInstance();

    dobaledova->startHry(); /**< @brief Spusteni samotneho hrani*/

    IceAge::MemoryArbiter::cycleDelete(); /**< @brief Vymazani veskere zbyvajici pameti*/
    return 0;
}
