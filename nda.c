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
        tab[1].transitions = tr;
        tab[1].nTransitions = 1;

        aut->states = tab;
        aut->nStates = 2;
}
//A REVOIR NIVEAU TRANSITIONS :
void unionLang(NDAutomaton * aut,NDAutomaton * aut1,NDAutomaton * aut2){
        State * tab = (State *)malloc(sizeof(State)*(aut1->nStates+aut2->nStates));
        Transition * tr = (Transition *)malloc(sizeof(Transition)*(aut1->states->nTransitions + aut2->states->nTransitions));
        //Transitions :
        tr[0].to = tab[1].id;
        tr[0].characters = aut1->states->transitions->characters;
        tr[0].nChars = 1;
        for(int i = 1 ; i<(aut1->states->nTransitions + aut2->states->nTransitions)-1;i++){
          tr[i].to = tab[i+1].id;
          tr[i].characters = aut2->states->transitions[i].characters;
          tr[i].nChars = 1;
        }

        //States :
        tab[0].id = 0 ;
        tab[0].terminal = 0;
        tab[0].transitions = tr;
        tab[0].nTransitions = (aut1->states->nTransitions + aut2->states->nTransitions);
        int k = 1;
        for(int i = 1; i<(aut1->nStates+aut2->nStates)-1;i+=2){
          for(int j = i+1; j<(aut1->nStates+aut2->nStates)-1;j++){
            tab[i].id = (aut1->states[k].id);
            tab[i].terminal = aut1->states[k].terminal;
            tab[i].transitions = aut1->states[k].transitions;
            tab[i].nTransitions = aut1->states[k].nTransitions;
            if(tab[i].nTransitions != 0 ){
              tab[i].transitions->to = i + 2 ;
            }
            tab[j].id = (aut2->states[k].id)+1;
            tab[j].terminal = aut2->states[k].terminal;
            tab[j].transitions = aut2->states[k].transitions;
            tab[j].nTransitions = aut2->states[k].nTransitions;
            if(tab[j].nTransitions != 0){
              tab[j].transitions->to = j + 2 ;
            }
            k++;
          }
        }


        aut->states = tab;
        aut->nStates = (aut1->nStates+aut2->nStates)-1;

}
//A FAIRE
void concatenationLang(NDAutomaton * aut,NDAutomaton * aut1,NDAutomaton * aut2){
        State * tab = (State *)malloc(sizeof(State)*(aut1->nStates+aut2->nStates));
        Transition * tr = (Transition *)malloc(sizeof(Transition)*(aut1->states->nTransitions));
        Transition * tr2 = (Transition *)malloc(sizeof(Transition)*(aut2->states->nTransitions));
        //Transitions :
        tr[0].to = aut1->states[1].id;
        tr[0].characters = aut1->states->transitions->characters;
        tr[0].nChars = 1;

        tr2[0].to = (aut2->states[1].id)+1;
        tr2[0].characters = aut2->states->transitions->characters;
        tr2[0].nChars = 1;

        //States :
        tab[0].id = 0 ;
        tab[0].terminal = 0;
        tab[0].transitions = tr;
        tab[0].nTransitions = 1;

        tab[1].id = aut1->states[1].id;
        tab[1].terminal = 0;
        tab[1].transitions = tr2;
        tab[1].nTransitions = 1;

        tab[2].id = (aut2->states[1].id)+1;
        tab[2].terminal = aut2->states[1].terminal;
        tab[2].transitions = aut2->states[1].transitions;
        tab[2].nTransitions = aut2->states[1].nTransitions;



        aut->states = tab;
        aut->nStates = (aut1->nStates+aut2->nStates)-1;


}
//  A FAIRE
void closureKleeneLang(NDAutomaton * aut, NDAutomaton * aut1){
        State * tab = (State *)malloc(sizeof(State)*(aut1->nStates));
        Transition * tr = (Transition *)malloc(sizeof(Transition)*(aut1->states->nTransitions));

        //Transitions :
        tr[0].to = aut1->states[1].id;
        tr[0].characters = aut1->states->transitions->characters;
        tr[0].nChars = 1;
        //States :
        tab[0].id = aut1->states[0].id;
        tab[0].terminal = 1;
        tab[0].transitions = tr;
        tab[0].nTransitions = 1;

        tab[1].id = aut1->states[1].id;
        tab[1].terminal = aut1->states[1].terminal;
        tab[1].transitions = tr;
        tab[1].nTransitions = 1;


        aut->states = tab;
        aut->nStates = aut1->nStates;
}
