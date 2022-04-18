//
// Created by lovan on 11/04/2022.
//

#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *ts, user *ptr){ //takes in the whole twitter struct, and the current user

    char mUser[USR_LENGHT];
    printf("Enter user you want to Follow:\n");
    fflush(stdin);

    fgets(mUser, USR_LENGHT, stdin);

    if(mUser[strlen(mUser) -1] == '\n') {
        mUser[strlen(mUser) - 1] = '\0';
    }

    Userptr currptr;
    currptr = ts->headptr;
    while(currptr != NULL){

        if(strcasecmp(currptr->username,mUser) == 0){
            // current user follows user b

            strcpy(ptr->following[ptr->num_following], currptr->username );
            ptr->num_following++; // increases following count
            // person b has a follower
            strcpy(currptr->followers[currptr->num_followers], ptr->username);
            currptr->num_followers++; // increases follwers count
            break;
        }
        else{
            currptr = currptr->nextptr;
        }
    }
}

void delete_user(twitter *ts, user *curruser){//deltes current user

    Userptr tmp;
    tmp = ts->headptr;

    while(strcasecmp(tmp->nextptr->username, curruser->username) != 0){
        tmp = tmp->nextptr;
    }
    tmp->nextptr = curruser->nextptr;
    free(curruser);
}

void unfollow(twitter *ts, user *ptr){//unfollows another user
    char name[USR_LENGHT];
    char null[USR_LENGHT];
    Userptr currptr;
    currptr = ts->headptr;
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
        if(strcmp(ptr->following[i], name) == 0){
            strcpy(ptr->following[i], null);
            ptr->num_following--;
            check = 1;
            break;
        }
    }
    if(check == 0){
        printf("Error, entered user not found.\n");
        return;
    }
    while(currptr->nextptr != NULL){
        if(strcasecmp(currptr->username, name) == 0){
            break;
        }
        currptr = currptr->nextptr;
    }
    for(int k = 0; k < currptr->num_followers; k++){
        if(strcmp(currptr->followers[i], ptr->username) == 0){
            strcpy(currptr->followers[i], null);
            currptr->num_followers--;
            break;
        }
    }

}
