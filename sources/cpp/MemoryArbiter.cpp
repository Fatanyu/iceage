/**
@file
*/
#include "../hlavicky/MemoryArbiter.h"


std::vector<IceAge::Memory*> IceAge::MemoryArbiter::s_memoryVector;/**< @brief Oznamuje, ze se bude tento vector v programu vyskytovat. Musi byt v CPP souboru, v hlavickem to haze errory.*/

/**
Konstruktor, ktery se nikdy nebude volat.
*/
IceAge::MemoryArbiter::MemoryArbiter() {
}

/**
Staticka metoda pridavajici instanci nejake tridy do vectoru memoryVector. Nasledne zavola metodu setId() z prave pridane tridy a tim ji ulozi jeji ID v seznamu.
*/
/*static*/ void IceAge::MemoryArbiter::add(IceAge::Memory* target) {
    s_memoryVector.push_back(target);
    s_memoryVector.at(s_memoryVector.size()-1)->setId(s_memoryVector.size()-1);
}

/**
Staticka metoda odebirajici mazanou instanci tridy ze seznamu. Provadi to ve vlastnim destrutkoru => neni potreba tu uchovavat odkaz a zabirat misto.
*/
/*static*/ void IceAge::MemoryArbiter::remove(unsigned int targetId) {

    s_memoryVector.at(targetId)=nullptr; /**< @brief Nejprve se vynuluje odkaz mazane instance.*/
    s_memoryVector.erase(s_memoryVector.begin()+targetId, s_memoryVector.begin()+targetId);
}

/**
Staticka metoda, ktera smaze kompletni seznam uchovavane pameti v memoryVector.
*/
/*static*/ void IceAge::MemoryArbiter::cycleDelete() {
    for(unsigned int i=0; i<s_memoryVector.size();i++){
        if(s_memoryVector.at(i) != nullptr) delete s_memoryVector.at(i); /**< @brief Musi se kontrolovat, zda se tam nenechazi nullptr. Nektere instance mohou v destruktorech smazat jine instance. */
    }
}
