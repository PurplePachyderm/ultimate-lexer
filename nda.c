#include <stdlib.h>
#include <stdio.h>
#include "headers/nda.h"



void initEmptyLang(NDAutomaton * aut) {
        aut->states = NULL;
        aut->nStates = 0;
}

void initEmptyWord(NDAutomaton * aut){
        State state1;
        state1.id = 0;
        state1.terminal = 1;
        state1.transitions = NULL;
        state1.nTransitions = 0;

        aut->states = &state1;
        aut->nStates = 1;
}

void initCharLang(NDAutomaton * aut,char chara){
        Transition tr;
        tr.to = 1;
        tr.characters = chara;
        tr.nChars = 1;

        State * tab =(State *)malloc(sizeof(State)*2);
        tab[1].id = 1;
        tab[1].terminal = 1;
        tab[1].transitions = NULL;
        tab[1].nTransitions = 0;

        tab[0].id = 0;
        tab[0].terminal = 0;
        tab[0].transitions = &tr;
        tab[0].nTransitions = 1;

        aut->states = tab;
        aut->nStates = 2;
}
