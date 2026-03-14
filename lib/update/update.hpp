#pragma once

#include "lua.h"
#include "../utils/utils.hpp"

namespace roblox::addresses {
    auto init( ) -> void;

    inline uintptr_t rlua_newthread = 0x234B4F0;
    inline uintptr_t rlua_pcall = 0x234D800;
    inline uintptr_t rluau_load = 0x234D2B4;
    inline uintptr_t rscriptstart = 0x23491DC;
    inline uintptr_t rgetglobalstate = 0x234AFA0;
    inline uintptr_t rgetcontext = 0x2347084;
    inline uintptr_t rcapabilitieserror = 0x59093E4;
}

namespace roblox::functions {
    auto init( ) -> void;

    inline lua_State* (*rgetglobalstate)(void* scriptcontext, std::uint64_t identity, std::uint64_t script);
    inline lua_State* (*rgetcontext)(void* encryptedcontext);
    inline lua_State* (*rlua_newthread)(lua_State *L);
    inline int (*rlua_pcall)(lua_State *L, int nargs, int nresults, int errfunc);
    inline int (*rluau_load)(lua_State *L, const char *chunkname, const char *data, size_t size, int env);
}