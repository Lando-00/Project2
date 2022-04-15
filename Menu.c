//
// Created by lovan on 06/04/2022.
//


#include "twitter_create.h"
#include "Functions.h"
#include "Menu.h"
#include <stdio.h>


int menu(twitter *ts, user *sptr){
    //printf("\n\n");
    int choice = -1;
    puts("Choose an action: (by entering the corresponding number)");
    printf("Post tweet: \t\t 1\n");
    printf("get News Feed:\t\t 2\n");
    printf("follow others:\t\t 3\n");
    printf("unfollow users:\t\t 4\n");
    printf("Delete your account:\t 5\n");
    printf("End currrent user's turn:6\n");
    printf("End twitter system:\t 7\n");
    while(choice != 0){
        printf("Enter (next) choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                follow(ts, sptr);
                return 3;
            case 4:
                unfollow(ts, sptr);
                return 4;
            case 5:
                delete_user(ts, sptr);
                return 6;
            case 6:
                return 6;
            case 7:
                return 7;
        }
    }
}
