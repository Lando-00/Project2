//
// Created by lovan on 31/03/2022.
//

#include "twitter_create.h"
#include "Menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create_twitter_system(twitter * ts){

    //creates users first
    // using linked lists
    Userptr currptr; //a temporary pointer which will point to the current user
    ts->headptr = NULL; //initially the list is empty so head points to nothing
    ts->tweetheadptr = NULL; //initially the list of tweets is also empty so head points to nothing
    for(int i = 0;i < MAX_USERS;i++){
        Userptr newptr = malloc(sizeof(user)); //allocating memory - malloc is going to return the staring address of that memory block
        if(newptr != NULL){ //checking if space is available, i.e while newptr does not point to the end
            printf("\nEnter username of the next user or press 'tab key' then 'Enter' to exit:\n");
            fgets(newptr->username, USR_LENGHT, stdin);
            fflush(stdin);//used to flush output buffer of the stream
            if(newptr->username[0] == ' ') { //edge case
                printf("(Do not start username with a 'Space'!!!)");
                i--;
                continue;
            }
            if(newptr->username[0] == '\t') {
                break;
            }
            if(newptr->username[strlen(newptr->username) - 1] == '\n') { //getting rid of the new line char
                newptr->username[strlen(newptr->username) - 1] = '\0'; //putting a null char instead
            }
            newptr->num_followers = 0;
            newptr->num_following = 0;
            newptr->nextptr = NULL;
        }
        if(ts->headptr == NULL)
        {
            ts->headptr = newptr; //newptr is now the headptr and points to NULL
        }
        else{
            currptr = ts->headptr; //currptr is like a temporary pointer which changes what it points to everytime, unlike headptr which only points to the first node
            while(currptr->nextptr != NULL){ //while cuuptr doesn't reach the end of the list
                currptr = currptr->nextptr; //currptr holds the address of the next node
            }
            currptr->nextptr = newptr;
        }
    }
    // prints out all of the users
    currptr = ts->headptr; //starting at the beginning of the list
    while(currptr != NULL){ //while the end of the list is not reached
        printf("User: @%s  \t\tfollowing: %d\tfollowers: %d\n", currptr->username, currptr->num_followers, currptr->num_followers);
        currptr = currptr->nextptr; //incrementing each time to read the next node (moving onto the next user in the list)
    }

    currptr = ts->headptr; //staring at the beginning of the list
    int control;
    while(1){ //while true
        printf("\n\nCurrent User: %s\n", currptr->username);
        control = menu(ts, currptr);
        if(control == 6){//give turn to next user
            if(currptr->nextptr == NULL)
            {
                currptr = ts->headptr;
                if(ts->headptr == NULL){
                    return;
                }
            }
            else {
                currptr = currptr->nextptr;
            }
            continue;
        }
        else if(control == 7){
            break; //exit out of the program
        }
    }
}
