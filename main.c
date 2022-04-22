
#include <stdio.h>
#include <stdlib.h>
#include "twitter_create.h"



int main() {

    twitter ts;
    create_twitter_system(&ts);

    // prints out all of the users // linked list style
    Userptr currptr = ts.headptr;
    printf("Last Active Users on the System:\n");
    puts("--------------------------------------------------------------------------");
    if(ts.headptr == NULL){
        puts("No User Left on system. Sad Times!");
        puts("Anyhoo. Bye Human! Come again!");
        exit(EXIT_SUCCESS);
    }
    while(currptr != NULL){
        printf("User:%s\t\t  Following:%d\t    Followers:%d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr;
    }
    return 0;

}
