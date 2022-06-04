//
//  temps.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 03/06/2022.
//

#include "temps.h"
#include <sys/time.h>

unsigned long getTimeMicroSec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (100 * tv.tv_sec + tv.tv_usec);
}
