//
// Created by lovan on 11/04/2022.
//

#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include "tweets.h"
void follow(twitter *ts, user *ptr){ //takes in the whole twitter struct, and the current user

    char mUser[USR_LENGHT]; //the user who is going to get followed by the current user
    printf("Enter user you want to Follow:\n");
    fflush(stdin); //used to flush output buffer of the stream

    fgets(mUser, USR_LENGHT, stdin); //reads in the characters from the stream

    if(mUser[strlen(mUser) -1] == '\n')  //replacing the newline char with the null char
    {
        mUser[strlen(mUser) - 1] = '\0'; //when the user presses enter, move on
    }

    Userptr currptr;
    currptr = ts->headptr; //starting at the beginning of the list
    while(currptr != NULL){ //while the end of the list is not reached

        if(strcasecmp(currptr->username,mUser) == 0){ //compares the current user to the user who is going to be followed
            // current user follows user b
            strcpy(ptr->following[ptr->num_following], currptr->username ); //copying the name of the user that's being followed and putting it into the string of names that the current user follows
            ptr->num_following++; // increases following count
            // person b has a follower
            strcpy(currptr->followers[currptr->num_followers], ptr->username); //copying the name of current user and putting it into the string of names of the following list for the user that's being followed
            currptr->num_followers++; // increases followers count
            break;
        }
        else{
            currptr = currptr->nextptr; //else point to the next node
        }
    }
}

void delete_user(twitter *ts, user *curruser){//deletes current user

    Userptr tmp; //creating a temporary pointer which will change what it points to each time unlike the headptr which only points to the first node in the list
    tmp = ts->headptr; //temp starts by pointing to the first node in the list

    while(strcasecmp(tmp->nextptr->username, curruser->username) != 0){ //while loops starts from the first user, and scans through until you find the current user
        tmp = tmp->nextptr; //pointing to the next node
    }
    tmp->nextptr = curruser->nextptr; //the temporary node is now the current node
    free(curruser); //delete the node
}

void unfollow(twitter *ts, user *ptr){//unfollows another user
    char name[USR_LENGHT];
    char null[USR_LENGHT];
    Userptr currptr;
    currptr = ts->headptr; //first start at the beginning of the list
    for(int j = 0; j < USR_LENGHT; j++){
        null[j] = '\0';
    }
    printf("\nEnter username of the user you would like to unfollow:\n");
    fflush(stdin);
    fgets(name,USR_LENGHT,stdin);
    if(name[strlen(name) - 1] == '\n') { //getting rid of the new line char
        name[strlen(name) - 1] = '\0'; //putting a null char instead
    }
    int i, check = 0;
    for(i = 0; ptr->num_following; i++){
        if(strcmp(ptr->following[i], name) == 0){ //comapre the following list of names to the name entered above
            strcpy(ptr->following[i], null);
            ptr->num_following--; //decrease the current user following list by 1
            check = 1;
            break;
        }
    }
    if(check == 0){ //edge case
        printf("Error, entered user not found.\n");
        return;
    }
    while(currptr->nextptr != NULL){ //while the end of the list is not reached
        if(strcasecmp(currptr->username, name) == 0){ //compare username to the name entered above
            break;
        }
        currptr = currptr->nextptr; //point to the next user
    }
    for(int k = 0; k < currptr->num_followers; k++){
        if(strcmp(currptr->followers[i], ptr->username) == 0){ //compare the unfollowed user's follower list to the current user's username
            strcpy(currptr->followers[i], null);
            currptr->num_followers--; //decrease the unfollowed user's follower list by 1
            break;
        }
    }
}
