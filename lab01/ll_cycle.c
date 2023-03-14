#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    //test codespace's git
    node * fp, * sp = head;
    while(fp!=NULL&& fp->next!=NULL){
        fp=fp->next->next;
        sp=sp->next;
        if(fp==sp){
            return 1;
        }
    }
    return 0;
}