//
// Created by priya on 18 Apr 2022.
//
//including the necessary libraries
#include "tweets.h"
#include "twitter_create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

void postTweet(twitter *ts, user* ptr) //function that allows users to post tweets
{
    static int idDigit = 1;
    Tweetptr currptr = malloc(sizeof(struct tweet));//creating new node for new tweet
    printf("What's on your mind?\n");
    fgets(currptr->msg, TWEET_LENGTH, stdin);//getting input from user
    fflush(stdin); //used to flush output buffer of the stream
    //adding a tweet into a node(struct) from the beginning of the list
    if (currptr->msg[strlen(currptr->msg) - 1] == '\n') { //getting rid of the new line char
        currptr->msg[strlen(currptr->msg) - 1] = '\0'; //putting a null char instead
    }
    strcpy(currptr->user, ptr->username);
    currptr->id = idDigit++;
    if (ts->tweetheadptr == NULL) //if the head pointer points to NULL
    {
        // ts->newsfeed, is the head pointer for tweets in the twitter system!
        ts->tweetheadptr = currptr;
        currptr->nextpointer = NULL; //instead of the head pointer pointing to NULL, the current pointer now points to NULL
    } else {
        currptr->nextpointer = ts->tweetheadptr;//adding a new node to the beginning of the list
        ts->tweetheadptr = currptr;
    }

}
void getNewsFeed(twitter *ts, user *currUser)
{
    Tweetptr currptr = ts->tweetheadptr; //temp ptr
    if(currptr == NULL){
        printf("There are no Tweets in your feed!\n");
    }
    int tweet_check = 0;//allows for the 10 recent tweets to be displayed
    while(currptr != NULL)//going through the tweets
    {
        if(currUser->num_following > 0) // for edge cases
        {
            for (int i = 0; i < currUser->num_following; i++) //going through the following list & comparing to tweeter
            {
                if (strcasecmp(currptr->user, currUser->following[i]) == 0 ||
                    strcasecmp(currptr->user, currUser->username) == 0) {
                    tweet_check++;//counting each tweet
                    printf("%s\n"
                           "By User:%s, Tweet Id: %d\n"
                           "-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n", currptr->msg,currptr->user, currptr->id);
                    break;
                }
            }
        }
        else // in case user follows no one
        {
            if(strcasecmp(currptr->user, currUser->username) == 0){
                tweet_check++;
                printf("%s\n"
                       "By User:%s, Tweet Id: %d\n"
                       "-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n", currptr->msg,currptr->user, currptr->id);
            }
        }
        if(tweet_check==10)
        {
            break;
        }
        currptr = currptr->nextpointer; // moves to Next tweet
    }
}
