#include <inttypes.h>
#include <thread>

#include "./utils/utils.hpp"
#include "./update/update.hpp"
#include "./hooks/hooks.hpp"

#include "lua.h"
#include "dobby.h"
#include "jni.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    std::thread([]() {
        utils::memory::wait_for_lib("libroblox.so");

        roblox::addresses::init();
        roblox::functions::init();

        roblox::hooks::setup_hooks();
    }).detach();

    return JNI_VERSION_1_6;
};