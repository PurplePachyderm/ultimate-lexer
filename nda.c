#include <stdlib.h>

#include "headers/nda.h"



void initEmptyLang(NDAutomaton * aut) {
        aut->states = NULL;
        aut->nStates = 0;
}
