#pragma once

#include <inttypes.h>
#include <thread>

#include "../globals.hpp"
#include "../update/update.hpp"
#include "../environment/exploit.hpp"

#include "lua.h"
#include "dobby.h"

namespace roblox::hooks 
{
    auto setup_hooks( ) -> void;
}