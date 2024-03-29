//
// Created by lovan on 06/04/2022.
//

#include "twitter_create.h"
#include "Functions.h"
#include "Menu.h"
#include "tweets.h"
#include <stdio.h>
#include <stdlib.h>

int menu(twitter *ts, user *CurrentUser){
    int choice = -1;
    puts("Choose an action: (by entering the corresponding number)");
    printf("Post tweet: \t\t 1\n");
    printf("get News Feed:\t\t 2\n");
    printf("follow others:\t\t 3\n");
    printf("unfollow users:\t\t 4\n");
    printf("Delete your account:\t 5\n");
    printf("End current user's turn: 6\n");
    printf("End twitter system:\t 7\n");
    //calling functions according to user choice
    while(choice != 0){
        printf("Enter (next) choice:\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                postTweet(ts, CurrentUser); //calling function that allows user to post tweets
                return 1;
            case 2:
                getNewsFeed(ts, CurrentUser);//calling function that allows user to view the 10 most recent tweets
                return 2;
            case 3:
                follow(ts, CurrentUser); //calling function that allows users to follow other users
                return 3;
            case 4:
                unfollow(ts, CurrentUser); //calling function that allows users to unfollow other users
                return 4;
            case 5:
                delete_user(ts, CurrentUser); //calling function that allows users to delete their account
                return 6;
            case 6:
                return 6; //gives turn to next user
            case 7:
                return 7;//ends the program
            default://edge case
                printf("Error! Not an option!\n");
                continue;
        }
    }
    if(choice == 0){
      printf("You have initiated termination procedure!\n");
      printf("The program will Self-Destruct Now!\nGoodBye!");
      exit(EXIT_FAILURE);
    }
}
