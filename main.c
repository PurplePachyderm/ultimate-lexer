#include "headers/nda.h"
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    NDAutomaton aut,aut2,aut3,aut4,aut5,aut6;
    initEmptyLang(&aut);
    initEmptyWord(&aut2);
    initCharLang(&aut3,'a');
    initCharLang(&aut4,'b');
    unionLang(&aut5,&aut3,&aut4);
    concatenationLang(&aut6,&aut3,&aut4);
    free(aut3.states->transitions);
    free(aut3.states);
    free(aut4.states->transitions);
    free(aut4.states);
    free(aut5.states->transitions);
    free(aut5.states);
    free(aut6.states->transitions);
    free(aut6.states);
    return 0;
}
