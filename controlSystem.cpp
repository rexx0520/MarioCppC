#ifndef _CONTROL_SYSTEM_CPP_
#define _CONTROL_SYSTEM_CPP_
#endif

#ifndef _CONTROL_SYSTEM_
#define _CONTROL_SYSTEM_
#include "controlSystem.hpp"
#endif

int collide(coord blockCoord, node block, Side::side collideSide, Character::Character* x, bool dive = false) {
    /*
        @brief               Returns the result when a character runs into a block.
        @param blockCoord    The coordinate of the block.
        @param block         The pointer of a block.
        @param motive        The motive of the character.
        @param x             The pointer of the character.

        Returns 1 if the character runs over the block.
        Returns 0 if the character is blocked.
        Returns -1 if the chatacter dives into the block.
    */

    if (!block->isTriggerable()) {
        if (!block->isTouchable())
            return 1;
        else if (dive && collideSide == Side::DOWN && block->isDiviable())
            return -1;
        else
            return 0;
    } else {
        switch (collideSide){
            case Side::DOWN:
            case Side::LEFT:
            case Side::RIGHT:
                return !block->isTouchable();
                break;
            case Side::UP:
                block->trigger(x);
                return 0;
                break;
        }
    }
}
