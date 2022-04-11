
#include <stdio.h>
#include "twitter_create.h"



int main() {



    twitter ts; //ts = twitter system
    create_twitter_system(&ts);

    //implement here the code to print the users
    // for each user you need to print the username, the number of followers and the number of users that the current user is following
    printf("Back in Main\n");
    for (int i = 0; i < ts.num_users; i++) {
        printf("User%d: %s      \tfollowing:%d\t followers:%d\n", i, ts.users[i].username,
               ts.users[i].num_following, ts.users[i].num_followers);//, ts.newsfeed[i].msg);
            }
    }
