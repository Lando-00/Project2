//
// Created by lovan on 11/04/2022.
//

#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *ts, user *ptr){ //takes in the whole twitter struct, and the current user

    char mUser[USR_LENGHT];
    printf("Which user do you want to Follow:\n");
    fflush(stdin);

    fgets(mUser, USR_LENGHT, stdin);

  ''  if(mUser[strlen(mUser) -1] == '\n') {
        mUser[strlen(mUser) - 1] = '\0';
    }

    for (int f = 0; f < ts->num_users; f++) {
        if (strcasecmp(ts->users[f].username, mUser) == 0)
        {
            //strcpy(&twitter_system->users->following[twitter_system->users->num_following],&mUser);
            /*strcpy(ts->users[f].username[ts->users[f].num_followers],mUser);
            ts->users[f].num_followers++;
            strcpy(ptr->following[ptr->num_following],ptr->username);
            ptr->num_following++;*/ //priyanshi's code. I think you're copying the wrong names.

            // current user follows user b
            strcpy(&ptr->following[ptr->num_following], &ts->users[f].username );
            // Second person's name is in following list of current user
            ptr->num_following++; // increases following count
            // person b has a follower
            strcpy(&ts->users[f].followers[ts->users[f].num_followers], &ptr->username);
            // current user's name is in follwers list of person b
            ts->users[f].num_followers++; // increases follwers count
        }
    }

}
