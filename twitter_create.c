//
// Created by lovan on 31/03/2022.
//

#include "twitter_create.h"
#include "Menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void create_twitter_system(twitter * twitter_system){

    //creates users first
    int i;
    for(i = 0;i < MAX_USERS;i++){
        printf("\nEnter username of the next user or press 'tab key' to exit:\n");
        //scanf("%s", &twitter_system->users[i].username);
        //fflush(stdin);
        fgets(twitter_system->users[i].username, USR_LENGHT, stdin);
        if(twitter_system->users[i].username[strlen(twitter_system->users[i].username) -1] == '\n') {
            twitter_system->users[i].username[strlen(twitter_system->users[i].username) - 1] = '\0';
        }
        if(twitter_system->users[i].username[strlen(twitter_system->users[i].username) -1] == '\t') {
            break;
        }
        twitter_system->users[i].num_following = 0;
        twitter_system->users[i].num_followers = 0;
        twitter_system->num_users++;


    }
    // create another loop for when i variable reaches max and needs to restart.
    // needs to reiterate through the users and give each user the various options

    /*for(i = 0; i < twitter_system->num_users; i++){


    }*/

}
