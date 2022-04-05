//
// Created by lovan on 31/03/2022.
//

#include "twitter_create.h"
#include <stdio.h>
#include <string.h>


void create_twitter_system(twitter * twitter_system){

    //creates users first
    for(int i = 0; i < MAX_USERS; i++){
        printf("Enter username of the next user or press 'tab' to exit:");
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


}
