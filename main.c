
#include <stdio.h>
#include <string.h>
#include "twitter_create.h"



int main() {

    twitter ts;
    create_twitter_system(&ts);

    // prints out all of the users // linked list style
    Userptr currptr = ts.headptr;
    while(currptr != NULL){
        printf("User: %s\t\tfollowing: %d\tfollowers: %d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr; //currptr holds the address of the next node
    }
    return 0;

}
