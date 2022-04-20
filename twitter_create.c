//
// Created by lovan on 31/03/2022.
//

#include "twitter_create.h"
#include "Menu.h"
#include "Functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "tweets.h"


void create_twitter_system(twitter * ts){

    //creates users first
    // using linked lists

    Userptr currptr; //declaring a current pointer which is associated to the struct user
    ts->headptr = 0; //initially the list is empty so head points to nothing
    for(int i = 0;i < MAX_USERS;i++){
        //newptr is the pointer which holds the address and points to the next empty node
        Userptr newptr = malloc(sizeof(user)); //allocating memory - malloc is going to return the staring address of that memory block
        if(newptr != NULL){ //space is available, i.e while newptr does not point to the end
            printf("\nEnter username of the next user or press 'tab key' then 'Enter' to exit:\n");
            fgets(newptr->username, USR_LENGHT, stdin);
            if(newptr->username[0] == ' ') { //does not allow for empty usernames
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
            newptr->nextptr = NULL; //newptr points to the nextptr which points to nothing
        }
        if(ts->headptr == NULL)
        {
            ts->headptr = newptr; //newptr is now thw headptr and points to the first node in the list
        }
        else{
            currptr = ts->headptr; //currptr is like a temporary pointer which changes what it points to everytime, unlike headptr which only points to the first node
            while(currptr->nextptr != NULL){ //while cuuptr doesn't reach the end of the list
                currptr = currptr->nextptr; //currptr holds the address of the next node
            }
            currptr->nextptr = newptr; //currptr (last node) holds the address of the next node which is now the newptr
        }
    }
    // prints out all of the users
    currptr = ts->headptr; //starting at the beginning of the list
    while(currptr != NULL){ //while the end of the list is not reached
        printf("User: %s  \t\tfollowing: %d\tfollowers: %d\n", currptr->username, currptr->num_followers, currptr->num_followers);
        currptr = currptr->nextptr; //incrementing each time to read the next node
    }

    // create another loop for when i variable reaches max.
    // needs to re-iterate through the users and give each user the various options...
    currptr = ts->headptr; //staring at the beginning of the list
    int control;
    while(currptr != NULL){ //while the end of the list is not reached
        printf("\n\nCurrent User: %s\n", currptr->username);
        control = menu(ts, currptr);
        if(control == 6){
            currptr = currptr->nextptr; //go to the next user
            continue;
        }
        else if(control == 7){
            break; //exit out of the program
        }
    }

}
