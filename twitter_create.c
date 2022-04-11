//
// Created by priya on 31/03/2022.
//

#include "twitter_create.h"
#include "Menu.h"
#include <stdio.h>
#include <string.h>

tweet mytweet[100];
int feed = 0;

void create_twitter_system(twitter * twitter_system){
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
    for(i = 0; i < twitter_system->num_users; i++){
        printf("User%d: %s      \tfollowing:%d\t follwers:%d\n",i ,twitter_system->users[i].username, twitter_system->users[i].num_following,twitter_system->users[i].num_followers);
    }
    // create another loop for when i variable reaches max and needs to restart.
    // needs to reiterate through the users and give each user the various options
    int control = 0;
    for(int j = 0; j < twitter_system->num_users; ){
        printf("\n\nCurrent user%d: %s\n",j ,twitter_system->users[j].username);
        control = menu(&twitter_system->users[j]);
        if(control == 0){
            break;
        }
        if(control == 1){
            ++feed;
            postTweet(twitter_system->users[j].username);
        }
        /*if(control == 2){
            int c = 0;
            printf("The user is: %s\n",twitter_system->users[j].username);
            printf("All my tweets are:\n");
            while(c<=MAX_TWEETS)
            {
                if(strcmp(twitter_system->users[j].username,mytweet[c].user)==0)
                {
                    printf("%s",mytweet[c].msg); //FIX THIS PROBLEM...IT PRINTS ALL MY TWEETS THE AMOUNT OF TIMES I TWEETED...MAKE IT NOT DO THAT
                }
                c++;
            }
        }*/

        if (control == 3)
        {
            char mUser[USR_LENGHT];
            printf("Which user do you want to Follow:\n");
            //scanf("%s", &twitter_system->users[i].username);
            fflush(stdin);
            //fgets(twitter_system->users[i].username, USR_LENGHT, stdin);
            fgets(mUser, USR_LENGHT, stdin);
            if(mUser[strlen(mUser) -1] == '\n') {
                mUser[strlen(mUser) - 1] = '\0';
            }

            for (int f = 0; f < twitter_system->num_users; f++) {
                if (strcmp(twitter_system->users[f].username, mUser) == 0)
                {
                    //strcpy(&twitter_system->users->following[twitter_system->users->num_following],&mUser);
                    strcpy(&twitter_system->users[f].username[twitter_system->users[f].num_followers],mUser);
                    twitter_system->users[f].num_followers++;
                    strcpy(&twitter_system->users[j].following[twitter_system->users[j].num_following],twitter_system->users[j].username);
                    twitter_system->users[j].num_following++;

                }
            }
        }
        if(control == 6){
            printf("\nCurrent user turn finished, moving to next user\n");
            j++;
        }
    }
}

void postTweet(char user_nm[USR_LENGHT]){
    printf("\nWhats on your mind:\n");
    //scanf("%s", &twitter_system->users[i].username);
    fflush(stdin);
    //fgets(twitter_system->users[i].username, USR_LENGHT, stdin);
    fgets(mytweet[feed].msg, TWEET_LENGTH, stdin);
    mytweet[feed].id=feed;
    strcpy(mytweet[feed].user,user_nm);
}
