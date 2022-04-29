//
// Created by priya on 18 Apr 2022.
//

#include "twitter_create.h"

#ifndef PROJECT2_TWEETS_H
#define PROJECT2_TWEETS_H

#endif //PROJECT2_TWEETS_H

// function that allows user to post tweets
void postTweet(twitter *ts, user *ptr);

//function that allows user to see the 10 most recent tweets either made by them or by the users they follow
void getNewsFeed(twitter *ts, user *currUser);