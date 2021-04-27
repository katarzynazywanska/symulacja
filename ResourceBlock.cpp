

#include "ResourceBlock.h"


#include "ResourceBlock.h"
#include <time.h>
#include <stdlib.h>

ResourceBlock::ResourceBlock(bool if_error, int what_user) {
    if_transmission_error_= if_error;
    what_user_id_ = what_user;
}

bool ResourceBlock::fun_if_error() {
    srand(time(NULL));
    int temp = rand()%10;
    if (temp > 0) { return true; }
    else return false;
}