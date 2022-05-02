//
// Created by lovan on 11/04/2022.
//

#include "twitter_create.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *ts, user *ptr) //takes in the whole twitter struct, and the current user
{
    char mUser[USR_LENGHT];
    printf("Enter user you want to Follow:\n");
    fflush(stdin); //used to flush output buffer of the stream
    fgets(mUser, USR_LENGHT, stdin); //gets user input
    if(mUser[strlen(mUser) -1] == '\n') //replacing the newline char with the null char
    {
        mUser[strlen(mUser) - 1] = '\0';
    }
    //edge case for if user tries to follow themselves
    if(strcasecmp(mUser,ptr->username)==0){
        printf("You can't follow yourself. Not very clever are you?\n anyhoo...\n\n");
        return;
    }
    // runs check to see if you already follow the entered user
    for(int d = 0; d < ptr->num_following; d++){
        if(strcasecmp(mUser,ptr->following[d])==0){
            printf("You already follow this User!\n No point in following them twice!\n\n");
            return;
        }
    }

    Userptr currptr; //temp pointer
    currptr = ts->headptr; //starting at the beginning of the list
    int user_check = 0;
    while(currptr != NULL) //while the end of the list is not reached
    {
        if(strcasecmp(currptr->username,mUser) == 0) //compares the current user to the user who is going to be followed
        {
            strcpy(ptr->following[ptr->num_following], currptr->username ); //copying the name of the user that's being followed and putting it into the string of names that the current user follows
            ptr->num_following++; // increases following count
            strcpy(currptr->followers[currptr->num_followers], ptr->username); //copying the name of current user and putting it into the string of names of the following list for the user that's being followed
            currptr->num_followers++; // increases follower count
            user_check = 1;
            break;
        }
        else{
            currptr = currptr->nextptr; //else point to the next node
        }
    }
    if(user_check == 0) //edge case to check whether the user to be followed entered by the current user is in the system
    {
        puts("Username you have entered is not in the System! You will be returned to the menu now!");
        return;
    }
}

void delete_user(twitter *ts, user *curruser) //function to delete a user
{
    Userptr tmp; //creating a temporary pointer which will change what it points to each time unlike the headptr which only points to the first node in the list
    tmp = ts->headptr; //temp starts by pointing to the first node in the list

    if(curruser == ts->headptr)
    {
        ts->headptr = curruser->nextptr;
        free(curruser);//removes the space previously taken up by that user struct
        sub_delete(ts, curruser); //calling the sub_delete function
        return;
    }


    while(strcasecmp(tmp->nextptr->username, curruser->username) != 0){//finds pointer to the user before current user
        tmp = tmp->nextptr;
    }
    tmp->nextptr = curruser->nextptr;// previous user is pointing to the user after current one // current user has now been removed from linked list
    sub_delete(ts, curruser); //calling the sub_delete function
    free(curruser);//removes the space previously taken up by that user struct
}

void sub_delete(twitter *ts, user *curruser)
{
    char tmpuser[USR_LENGHT];
    //trying to find users that follow the current user to be deleted and subtracting their num_following by 1
    for(int i = 0; i < curruser->num_followers; i++){
        strcpy(tmpuser,curruser->followers[i]); //copy current user's follower list into tmpuser
        Userptr tmpptr = ts->headptr; //starting at the beginning of the list of users
        while(strcasecmp(tmpptr->username,tmpuser)!=0)
        {
            tmpptr = tmpptr->nextptr;//move onto the next node
        }
        int k = 0;
        while(strcasecmp(tmpptr->following[k],curruser->username)!=0){
            k++;
        }
        for(int o = k+1; o < tmpptr->num_following; o++){
            strcpy(tmpptr->following[k],tmpptr->following[o]);
            k++;
        }
        tmpptr->num_following--;
    }
    //removing the current user from the follower list of other users.
    for(int i = 0; i < curruser->num_following; i++){ // same thing as above , but does it for followers list of other users.
        strcpy(tmpuser,curruser->following[i]);
        Userptr tmpptr = ts->headptr;//starting at the beginning
        while(strcasecmp(tmpptr->username,tmpuser)!=0){
            tmpptr = tmpptr->nextptr;
        }
        int k = 0;
        while(strcasecmp(tmpptr->followers[k],curruser->username)!=0){
            k++;
        }
        for(int o = k+1; o < tmpptr->num_followers; o++){
            strcpy(tmpptr->followers[k],tmpptr->followers[o]);
            k++;
        }
        tmpptr->num_followers--;
    }
    //need to delete any tweets made by the user before deleting their account
    if(ts->tweetheadptr == NULL){
        return;
    }
    Tweetptr currtweet = ts->tweetheadptr;
    Tweetptr prevtweet = ts->tweetheadptr->nextpointer;
    while(currtweet != NULL){ //while the end of the list is not reached
        if(strcasecmp(curruser->username,currtweet->user) == 0){ //if current tweeter is the same as the current user
            if(currtweet == ts->tweetheadptr){
                ts->tweetheadptr = currtweet->nextpointer;
                free(currtweet); //deleting tweet made by the user who is to be deleted
                currtweet = ts->tweetheadptr->nextpointer;
                continue;
            }
            prevtweet->nextpointer = currtweet->nextpointer;
            free(currtweet);
            currtweet = prevtweet->nextpointer;
            continue;
        }
        prevtweet = currtweet;
        currtweet = currtweet->nextpointer;
    }
}

void unfollow(twitter *ts, user *ptr)//function to unfollow a user
{
    char name[USR_LENGHT];
    char null[USR_LENGHT];
    Userptr currptr;
    currptr = ts->headptr; //first start at the beginning of the list
    for(int j = 0; j < USR_LENGHT; j++)
    {
        null[j] = '\0';
    }
    printf("\nEnter username of the user you would like to unfollow:\n");
    fflush(stdin); //used to flush output buffer of the stream
    fgets(name,USR_LENGHT,stdin); //getting input from the user
    if(name[strlen(name) - 1] == '\n') { //getting rid of the new line char
        name[strlen(name) - 1] = '\0'; //putting a null char instead
    }
    int i, check = 0;
    for(i = 0; i < ptr->num_following; i++){
        if(strcmp(ptr->following[i], name) == 0) //compare the following list of names to the name entered above
        {
            strcpy(ptr->following[i], null);
            ptr->num_following--; //decrease the current user following list by 1
            check = 1;
            break;
        }
    }
    if(check == 0) //edge case to check whether the user to be unfollowed entered by the current user is in the system
    {
        printf("Error, entered user not found.\n"
               "You do not follow this User.\n");
        return;
    }
    while(currptr->nextptr != NULL) //while the end of the list is not reached
    {
        if(strcasecmp(currptr->username, name) == 0){//compare username to the name entered above
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

void printUsers(twitter *ts){
    Userptr currptr = ts->headptr; //calling the head pointer inside the twitter system
    if(ts->headptr == NULL)
    {
        puts("No User Left on system.");
        exit(EXIT_SUCCESS);
    }
    // prints out all the users // linked list style
    while(currptr != NULL){
        printf("User:@%20s\tFollowing:%d\t    Followers:%d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr; //move onto the next user in the list
    }
    printf("\n\n");
}
