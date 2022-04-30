//
// Created by lovan on 31/03/2022.
//

#ifndef PROJECT2_TWITTER_CREATE_H
#define PROJECT2_TWITTER_CREATE_H

//Max length of a tweet
#define TWEET_LENGTH 270

//Max length of a username
#define USR_LENGHT 20

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
    struct tweet *nextpointer; //will hold the address of the next tweet
}tweet;

typedef tweet *Tweetptr;//used to declare pointers to the struct tweet

typedef struct user{
    char username[USR_LENGHT];

    char followers[MAX_FOLLOWERS][USR_LENGHT];
    int num_followers;

    char following[MAX_FOLLOWING][USR_LENGHT];
    int num_following;

    struct user *nextptr; //will hold the address of the next user struct
}user;

typedef user *Userptr; //used to declare pointers to the struct user


typedef struct twitter
{
    Userptr headptr; //points to the first User in the user list
    Tweetptr tweetheadptr; //points to the first Tweet in the tweets list
} twitter;

void create_twitter_system(twitter * ts); //function prototype for the twitter system

#endif //PROJECT2_TWITTER_CREATE_H
