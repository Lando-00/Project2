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

    Tweetptr currptr = malloc(sizeof(struct tweet));//creating new node for new tweet
    printf("What's on your mind?\n");
    fgets(currptr->msg, TWEET_LENGTH,stdin);//getting input from user
    fflush(stdin); //used to flush output buffer of the stream
    //adding a tweet into a node(struct) from the beginning of the list
    if(currptr->msg[strlen(currptr->msg) - 1] == '\n') { //getting rid of the new line char
        currptr->msg[strlen(currptr->msg) - 1] = '\0'; //putting a null char instead
    }
    if(ts->tweetheadptr == NULL) //if the head pointer points to NULL
    {
        // ts->newsfeed, is the head pointer for tweets in the twitter system!
        ts->tweetheadptr=currptr; //the head pointer is the current pointer
        currptr->nextpointer=NULL; //instead of the head pointer pointing to NULL, the current pointer now points to NULL
    }
    else
    {
        currptr->nextpointer=ts->tweetheadptr;//make the current pointer which points to the next pointer be the head pointer (first node in the list)
        ts->tweetheadptr= currptr;
    }


    //for printing the tweet
    //we have to loop through each list to find the node we want to pront out
    /*Tweetptr currentptr;
      currentptr=headpointer; //starting at the beginning
      while(currentptr!=NULL)//while currentptr doesn't reach the end, keep printing the tweets
      {
          printf("%s\n", currentptr->msg);
          currentptr=currentptr->nextweet;
      }*/
}
