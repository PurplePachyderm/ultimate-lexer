#pragma once

#include <stdbool.h>

//Nondeterministic automaton

    // Structs

typedef struct {
    unsigned int to; //Don't need 'from' since going to be stored inside States
    char * characters;
    unsigned int nChars;
}Transition;


typedef struct {
    unsigned int id;

    bool terminal;
    //By convention, state will be considered start when id==0

    Transition * transitions;
    unsigned int nTransitions;

}State;


typedef struct {
    State * states;
    unsigned int nStates;
}NDAutomaton;



// Functions

//Returns an automaton accepting the empty language
void initEmptyLang(NDAutomaton * aut);
