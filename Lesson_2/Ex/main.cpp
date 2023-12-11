#include "controller.h"

int main() {
    controlDevice(LIGHT, ON); 
    controlDevice(AIR_CONDITIONER, SET_TEMPERATURE, 18);
    controlDevice(FINGERPRINT_LOCK, UNLOCK); 
    controlDevice(MUSIC_PLAYER, CHANGE_TRACK, "Price tag");
    return 0;
}
