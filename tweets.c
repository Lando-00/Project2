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

void posttweet(twitter *ts, user* ptr) //function definition for function that allows users to post tweets
{
    static int iddigit = 1;
    Tweetptr currptr = malloc(sizeof(struct tweet));//creating new node for new tweet
    printf("What's on your mind?\n");
    fgets(currptr->msg, TWEET_LENGTH, stdin);//getting input from user
    fflush(stdin); //used to flush output buffer of the stream
    //adding a tweet into a node(struct) from the beginning of the list
    if (currptr->msg[strlen(currptr->msg) - 1] == '\n') { //getting rid of the new line char
        currptr->msg[strlen(currptr->msg) - 1] = '\0'; //putting a null char instead
    }
    strcpy(currptr->user, ptr->username);
    currptr->id = iddigit++;
    if (ts->tweetheadptr == NULL) //if the head pointer points to NULL
    {
        // ts->newsfeed, is the head pointer for tweets in the twitter system!
        ts->tweetheadptr = currptr; //the head pointer is the current pointer
        currptr->nextpointer = NULL; //instead of the head pointer pointing to NULL, the current pointer now points to NULL
    } else {
        currptr->nextpointer = ts->tweetheadptr;//make the current pointer which points to the next pointer be the head pointer (first node in the list)
        ts->tweetheadptr = currptr;
    }

}
void getNewsFeed(twitter *ts, user *currUser)
{
    Tweetptr currptr = ts->tweetheadptr; //temp ptr
    if(currptr == NULL){
        printf("There are no Tweets in your feed!\n");
    }
    int tweet_check = 0;
    while(currptr != NULL)//going through the tweets
    {
        if(currUser->num_following > 0) // for edge cases
        {
            for (int i = 0; i < currUser->num_following; i++) //going through the following list & comparing to tweeter
            {
                if (strcasecmp(currptr->user, currUser->following[i]) == 0 ||
                    strcasecmp(currptr->user, currUser->username) == 0) {
                    tweet_check++;
                    printf("%s\n"
                           "By User:%s, Tweet Id: %d\n", currptr->msg,currptr->user, currptr->id);
                    break;
                }
            }
        }
        else // incase user follows nooone
        {
            if(strcasecmp(currptr->user, currUser->username) == 0){
                tweet_check++;
                printf("%s\n"
                       "By User:%s, Tweet Id: %d\n", currptr->msg,currptr->user, currptr->id);
            }
        }
        if(tweet_check==10)
        {
            break;
        }
        currptr = currptr->nextpointer;
    }
}
