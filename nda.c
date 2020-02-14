#include <stdlib.h>
#include <stdio.h>
#include "headers/nda.h"



void initEmptyLang(NDAutomaton * aut) {
        aut->states = NULL;
        aut->nStates = 0;
}

void initEmptyWord(NDAutomaton * aut){
        State * state1 =(State *)malloc(sizeof(State)*1);
        state1[0].id = 0;
        state1[0].terminal = 1;
        state1[0].transitions = NULL;
        state1[0].nTransitions = 0;

        aut->states = state1;
        aut->nStates = 1;
}

void initCharLang(NDAutomaton * aut,char chara){
        State * tab =(State *)malloc(sizeof(State)*3);
        Transition * tr =(Transition*)malloc(sizeof(Transition)*3);
        //Transitions :
        tr->to = 1;
        tr->characters = chara;
        tr->nChars = 1;
        //States :
        tab[0].id = 0;
        tab[0].terminal = 0;
        tab[0].transitions = tr;
        tab[0].nTransitions = 1;

        tab[1].id = 1;
        tab[1].terminal = 1;
        tab[1].transitions = NULL;
        tab[1].nTransitions = 0;

        aut->states = tab;
        aut->nStates = 2;
}

void unionLang(NDAutomaton * aut,NDAutomaton * aut1,NDAutomaton * aut2){
        State * tab = (State *)malloc(sizeof(State)*(aut1->nStates+aut2->nStates));
        Transition * tr = (Transition *)malloc(sizeof(Transition)*(aut1->states->nTransitions + aut2->states->nTransitions));
        //Transitions :
        tr[0].to = aut1->states[1].id;
        tr[0].characters = aut1->states->transitions->characters;
        tr[0].nChars = 1;

        tr[1].to = (aut2->states[1].id)+1;
        tr[1].characters = aut2->states->transitions->characters;
        tr[1].nChars = 1;

        //States :
        tab[0].id = 0 ;
        tab[0].terminal = 0;
        tab[0].transitions = tr;
        tab[0].nTransitions = (aut1->states->nTransitions + aut2->states->nTransitions);

        tab[1].id = aut1->states[1].id;
        tab[1].terminal = aut1->states[1].terminal;
        tab[1].transitions = aut1->states[1].transitions;
        tab[1].nTransitions = aut1->states[1].nTransitions;

        tab[2].id = (aut2->states[1].id)+1;
        tab[2].terminal = aut2->states[1].terminal;
        tab[2].transitions = aut2->states[1].transitions;
        tab[2].nTransitions = aut2->states[1].nTransitions;


        aut->states = tab;
        aut->nStates = (aut1->nStates+aut2->nStates)-1;

}

void concatenationLang(NDAutomaton * aut,NDAutomaton * aut1,NDAutomaton * aut2){
        State * tab = (State *)malloc(sizeof(State)*(aut1->nStates+aut2->nStates));
        Transition * tr = (Transition *)malloc(sizeof(Transition)*(aut1->states->nTransitions + aut2->states->nTransitions));
        //Transitions :
        tr[0].to = aut1->states[1].id;
        tr[0].characters = aut1->states->transitions->characters;
        tr[0].nChars = 1;

        tr[1].to = (aut2->states[1].id)+1;
        tr[1].characters = aut2->states->transitions->characters;
        tr[1].nChars = 1;

        //States :
        tab[0].id = 0 ;
        tab[0].terminal = 0;
        tab[0].transitions = tr;
        tab[0].nTransitions = 1;

        tab[1].id = aut1->states[1].id;
        tab[1].terminal = 0;
        tab[1].transitions = tr;
        tab[1].nTransitions = 1;

        tab[2].id = (aut2->states[1].id)+1;
        tab[2].terminal = aut2->states[1].terminal;
        tab[2].transitions = aut2->states[1].transitions;
        tab[2].nTransitions = aut2->states[1].nTransitions;


        aut->states = tab;
        aut->nStates = (aut1->nStates+aut2->nStates)-1;


}
