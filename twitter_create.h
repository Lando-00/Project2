//
// Created by lovan on 31/03/2022.
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
    struct tweet *nextweet;
}tweet;

typedef tweet *Tweetptr;

typedef struct user{
    char username[USR_LENGHT];

    char followers[MAX_FOLLOWERS][USR_LENGHT];
    int num_followers;

    char following[MAX_FOLLOWING][USR_LENGHT];
    int num_following;

    struct user *nextptr;
}user;

typedef user *Userptr;


typedef struct twitter{
    // to be completed
    int num_users;
    Userptr headptr;
    Tweetptr newsfeed;
} twitter;

void create_twitter_system(twitter * ts);
