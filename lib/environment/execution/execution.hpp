#pragma once

#include "../../globals.hpp"
#include "../../update/update.hpp"

#include "luacode.h"
#include "lapi.h"
#include "lobject.h"
#include "lstate.h"
#include "lbytecode.h"

#include "Luau/Compiler.h"
#include "Luau/BytecodeBuilder.h"
#include "Luau/BytecodeUtils.h"

namespace roblox::execution 
{
    void execute(lua_State* L, std::string script);
    std::string compile(std::string source);
}