//
// Created by lovan on 06/04/2022.
//

#include "twitter_create.h"
#include <stdio.h>


int menu(user *sptr){
    //printf("\n\n");
    int choice = -1;
    puts("Choose an action: (by entering the corresponding number)");
    printf("Post tweet: 1\n");
    printf("get News Feed: 2\n");
    printf("follow others: 3\n");
    printf("unfollow users: 4\n");
    printf("Delete your account: 5\n");
    printf("End current user's turn: 6\n");
    printf("End twitter system: 7\n");
    while(choice != 0){
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                break;
            case 5:
                break;
            case 6:
                return 6;
            case 7:
                return 0;
        }
    }
}
