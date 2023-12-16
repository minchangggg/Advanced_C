#include <stdio.h>
#include <stdarg.h>
#include "controller.h"

int main() {
    controlDevice(LIGHT, ON); 
    controlDevice(AIR_CONDITIONER, ON, SET_TEMPERATURE, 18);
    controlDevice(FINGERPRINT_LOCK, UNLOCK); 
    controlDevice(MUSIC_PLAYER, ON, CHANGE_TRACK,"Price tag");
    return 0;
}
