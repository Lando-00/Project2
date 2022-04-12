//
// Created by lovan on 31/03/2022.
//

#include "twitter_create.h"
#include "Menu.h"
#include "Functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void create_twitter_system(twitter * ts){

    //creates users first
    for(int i = 0;i < MAX_USERS;i++){
        printf("\nEnter username of the next user or press 'tab key' then 'Enter' to exit:\n");
        //scanf("%s", &twitter_system->users[i].username); // scanf does not account for 'spaces' therefore use fgets
        //fflush(stdin);
        fgets(ts->users[i].username, USR_LENGHT, stdin);
        if(ts->users[i].username[strlen(ts->users[i].username) - 1] == '\n') { //getting rid of the new line char
            ts->users[i].username[strlen(ts->users[i].username) - 1] = '\0'; //putting a null char instead
        }
        if(ts->users[i].username[i] == ' ') { //does not allow for empty usernames
            printf("(Do not start username with a 'Space'!!!)");
            i--;
            continue;
        }
        if(ts->users[i].username[strlen(ts->users[i].username) - 1] == '\t') {
            break;
        }
        ts->users[i].num_following = 0;
        ts->users[i].num_followers = 0;
        ts->num_users++;

    }
    // prints out all of the users
    for(int i = 0; i < ts->num_users; i++){
        printf("User%d: %s      \t\tfollowing:%d\t follwers:%d\n", i , ts->users[i].username, ts->users[i].num_following, ts->users[i].num_followers);
    }

    // create another loop for when i variable reaches max.
    // needs to reiterate through the users and give each user the various options...
    int control;
    for(int j = 0; j < ts->num_users; j++){
        printf("\n\nCurrent user%d: %s\n", j , ts->users[j].username);
        control = menu(ts, &ts->users[j]);
        if(control == 7){
            break;
        }

    }

}
