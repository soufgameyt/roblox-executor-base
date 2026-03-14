#include "./hooks.hpp"

namespace roblox::hooks {
    static std::uintptr_t rcapabilitieserror_og = 0x0;
    static void capabilitieserrorhk(int64_t a1, int64_t a2, int64_t a3, uint8_t a4) {
        return;
    }

    static std::uintptr_t startscript_og = 0x0;
    static int startscripthk(void* script_context, std::uintptr_t script_start, __int128_t* a3)
    {
        const auto original = *reinterpret_cast<decltype(startscripthk)*>(startscript_og);

        if (globals::rSC == roblox::functions::rgetcontext(script_context)) {
            return original(script_context, script_start, a3);
        }

        int identity[3] = {8, 0, 0};
        int script[] = {0, 0};

        globals::rSC = roblox::functions::rgetcontext(script_context);
        globals::rL  = roblox::functions::rgetglobalstate(globals::rSC, (uintptr_t)identity, (uintptr_t)script);

        std::thread([]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            roblox::exploit::start();
        }).detach();

        return original(script_context, script_start, a3);
    }

    auto setup_hooks( ) -> void
    {        
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        DobbyHook((void*)roblox::addresses::rscriptstart, (void*)&startscripthk, (void**)&startscript_og);
        DobbyHook((void*)roblox::addresses::rcapabilitieserror, (void*)&capabilitieserrorhk, (void**)&rcapabilitieserror_og);
    }
}