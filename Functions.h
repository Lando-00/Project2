//
// Created by lovan on 11/04/2022.
//

#ifndef ENGPROJECT2_FUNCTIONS_H
#define ENGPROJECT2_FUNCTIONS_H




void follow(twitter *ts, user *ptr); //function to follow other users

void unfollow(twitter *ts, user *ptr); //function to unfollow other users

void delete_user(twitter *ts, user *curruser); //function to delete users

void sub_delete(twitter *ts, user *curruser);
//removes deleted user's presence from other user's list of following/followers
//deletes any previous tweets made by the user who is to be deleted
#endif //ENGPROJECT2_FUNCTIONS_H
