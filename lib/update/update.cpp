#include "./update.hpp"

namespace roblox::addresses {
    auto init( ) -> void
    {
        roblox::addresses::rlua_newthread = utils::memory::rebase("libroblox.so", roblox::addresses::rlua_newthread);
        roblox::addresses::rlua_pcall = utils::memory::rebase("libroblox.so", roblox::addresses::rlua_pcall);
        roblox::addresses::rluau_load = utils::memory::rebase("libroblox.so", roblox::addresses::rluau_load);
        roblox::addresses::rscriptstart = utils::memory::rebase("libroblox.so", roblox::addresses::rscriptstart);
        roblox::addresses::rgetglobalstate = utils::memory::rebase("libroblox.so", roblox::addresses::rgetglobalstate);
        roblox::addresses::rgetcontext = utils::memory::rebase("libroblox.so", roblox::addresses::rgetcontext);
        roblox::addresses::rcapabilitieserror = utils::memory::rebase("libroblox.so", roblox::addresses::rcapabilitieserror);
    }
}

namespace roblox::functions {
    auto init( ) -> void
    {
        roblox::functions::rluau_load = reinterpret_cast<decltype(roblox::functions::rluau_load)>(roblox::addresses::rluau_load);
        roblox::functions::rlua_pcall = reinterpret_cast<decltype(roblox::functions::rlua_pcall)>(roblox::addresses::rlua_pcall);
        roblox::functions::rlua_newthread = reinterpret_cast<decltype(roblox::functions::rlua_newthread)>(roblox::addresses::rlua_newthread);
        roblox::functions::rgetglobalstate = reinterpret_cast<decltype(roblox::functions::rgetglobalstate)>(roblox::addresses::rgetglobalstate);
        roblox::functions::rgetcontext = reinterpret_cast<decltype(roblox::functions::rgetcontext)>(roblox::addresses::rgetcontext);
    }
}