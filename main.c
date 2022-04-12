
#include <stdio.h>
#include <string.h>
#include "twitter_create.h"



int main() {

    twitter ts;
    create_twitter_system(&ts);

    // prints out all of the users
    for(int i = 0; i < ts.num_users; i++){
        printf("User%d: %s      \t\tfollowing:%d\t follwers:%d\n", i , ts.users[i].username, ts.users[i].num_following, ts.users[i].num_followers);
    }
    return 0;

}
