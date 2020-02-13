#include "headers/nda.h"
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    NDAutomaton aut,aut2,aut3;
    initEmptyLang(&aut);
    initEmptyWord(&aut2);
    initCharLang(&aut3,'a');
    printf("[Test] Transition character : %c\n",aut3.states[0].transitions->characters);
    free(aut3.states);
    return 0;
}
