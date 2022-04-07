
#include <stdio.h>
#include <string.h>
#include "twitter_create.h"



int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);

    //implement here the code to print the users
    // for each user you need to print the username, the number of followers and the number of users that the current user is following

    for(int i = 0; i < twitter_system.num_users; i++){

        printf("Username%d: %s \t\t following:%d\t follwers:%d\n",i ,twitter_system.users[i].username, twitter_system.users[i].num_following,twitter_system.users[i].num_followers);
    }


}
