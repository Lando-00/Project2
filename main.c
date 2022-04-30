
#include <stdio.h>
#include <stdlib.h>
#include "twitter_create.h"

int main() {
    twitter ts;
    create_twitter_system(&ts); //initialises the twitter System

    Userptr currptr = ts.headptr; //calling the head pointer inside the twitter system
    printf("Last Active Users on the System:\n");
    puts("--------------------------------------------------------------------------");
    if(ts.headptr == NULL)
    {
        puts("No User Left on system.");
        exit(EXIT_SUCCESS);
    }
    // prints out all the users // linked list style
    while(currptr != NULL){
        printf("User:@%20s\tFollowing:%d\t    Followers:%d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr; //move onto the next user in the list
    }
    return 0;

}
