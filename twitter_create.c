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
    // prints out all of the users
    for(int i = 0; i < twitter_system->num_users; i++){
        printf("User%d: %s      \tfollowing:%d\t follwers:%d\n",i ,twitter_system->users[i].username, twitter_system->users[i].num_following,twitter_system->users[i].num_followers);
    }

    // create another loop for when i variable reaches max and needs to restart.
    // needs to reiterate through the users and give each user the various options
    int control = 0;
    for(int j = 0; j < twitter_system->num_users; j++){
        printf("\n\nCurrent user%d: %s\n",j ,twitter_system->users[j].username);
        control = menu(&twitter_system->users[j]);
        if(control == 0){
            break;
        }
    }

}
