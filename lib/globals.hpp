#pragma once

#include <string>
#include <inttypes.h>
#include "lua.h"

namespace globals {
    inline lua_State* rL; // Roblox LState
    inline lua_State* eL; // Exploit LState

    inline void* rSC; // Roblox ScriptContext

    inline const std::string exploit_name = "roblox-executor";
    inline const std::string exploit_version = "1.0.0";
    inline const std::string exploit_build = "dev";

    inline const std::string roblox_version = "2.710.707";
    inline const std::string chunkname = "=LocalScript"; // script chunk used in execution (luau_load)

    inline const std::string roblox_lib = "libroblox.so";
    inline std::int64_t roblox_base; // roblox base address (unused)
    inline std::int64_t roblox_size; // roblox base size (unused)
};