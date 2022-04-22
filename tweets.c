//
// Created by priya on 18 Apr 2022.
//

#include "tweets.h"
#include "twitter_create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "functions.h"

void posttweet(twitter *ts, user* ptr)
{
    char newTweet[TWEET_LENGTH];
    Tweetptr headpointer;
    for(int i=0;i<TWEET_LENGTH;i++)
    {
        Tweetptr currptr = malloc(sizeof(struct tweet));
        printf("What's on your mind?\n");
        fgets(currptr->msg, TWEET_LENGTH,stdin);
        fflush(stdin);
        //adding a tweet into a node(struct)
        if(currptr->msg[0] == '\t') {
            break;
        }
        if(currptr->msg[strlen(currptr->msg) - 1] == '\n') { //getting rid of the new line char
            currptr->msg[strlen(currptr->msg) - 1] = '\0'; //putting a null char instead
        }
        if(headpointer==NULL)
        {
            headpointer=currptr;
            currptr->nextpointer=headpointer;
        }
        else
        {
            currptr->nextpointer=NULL;
            headpointer= currptr;
        }

    }
  //for printing the tweet
  //we have to loop through each list to find the node we want to pront out
  /*Tweetptr currentptr;
    currentptr=headpointer; //starting at the beginning
    while(currentptr!=NULL)//while currentptr doesn't reach the end, keep printing the tweets
    {
        printf("%s\n", currentptr->msg);
        currentptr=currentptr->nextpointer;
    }*/
}

