//
// Created by priya on 31/03/2022.
//

#ifndef PROJECT2_TWITTER_CREATE_H
#define PROJECT2_TWITTER_CREATE_H

#endif //PROJECT2_TWITTER_CREATE_H

//Max length of a tweet
#define TWEET_LENGTH 270

//Max length of a username
#define USR_LENGHT 100

//Max num of a followers
#define MAX_FOLLOWERS 30

//Max num of following users
#define MAX_FOLLOWING 30

//Max num of tweets in the news feed
#define MAX_TWEETS 100

//Max num of users
#define MAX_USERS 100

typedef struct tweet{
    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGHT];

}tweet;

typedef struct user{
    char username[USR_LENGHT];

    char followers[MAX_FOLLOWERS];
    int num_followers;

    char following[MAX_FOLLOWING];
    int num_following;
}user;

typedef struct twitter{
    // to be completed
    int num_users;
    struct user users[MAX_USERS];
    struct tweet allTweets[MAX_TWEETS];

} twitter;


void create_twitter_system(twitter * twitter_system);
void postTweet(char user_nm[USR_LENGHT]);
