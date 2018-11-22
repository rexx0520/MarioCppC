#ifndef _CONTROL_SYSTEM_
#define _CONTROL_SYSTEM_
#endif

#ifndef _UTILITY_
#define _UTILITY_
#include <utility>
#endif

#ifndef _NODES_
#define _NODES_
#include "nodes.hpp"
#endif

#ifndef _JSON_
#define _JSON_
#include "json.hpp"
using json = nlohmann::json;
#endif

using node = std::shared_ptr<class Node::Node>;
using stageline = std::vector<node>;
using stage = std::vector<stageline>;

using coord = std::pair<int, int>;

namespace Motive {
    using motive = const int;
    motive UP = 8;
    motive DOWN = 2;
    motive LEFT = 4;
    motive RIGHT = 6;
    motive DIVE = 0;
    motive LEFT_DOWN = 1;
    motive RIGHT_DOWN = 3;
    motive LEFT_UP = 7;
    motive RIGHT_UP = 9;
}

namespace Side {
    using side = const int;
    side UP = 8;
    side LEFT = 4;
    side DOWN = 2;
    side RIGHT = 6;
}

int collide(coord blockCoord, node block, Side::side collideSide, Character::Character *x, bool dive);

#ifndef _CONTROL_SYSTEM_CPP_
#define _CONTROL_SYSTEM_CPP_
#include "controlSystem.cpp"
#endif
