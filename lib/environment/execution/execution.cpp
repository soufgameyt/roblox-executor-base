#include "./execution.hpp"

namespace roblox::execution {
    class bytecode_encoder_t : public Luau::BytecodeEncoder 
    {
        virtual void encode(uint32_t* data, size_t count) override 
        {
            for (auto i = 0; i < count;)
            {
                uint8_t Opcode = LUAU_INSN_OP(data[i]);
                uint8_t FinalOpcode = (Opcode * 227) & 0xFF;

                data[i] = (FinalOpcode) | (data[i] & ~0xFF);
                i += Luau::getOpLength(static_cast<LuauOpcode>(Opcode));
            }
        }
    };

    std::string compile(std::string source) 
    {
        static const char* mutableGlobals[] = {"Game", "Workspace", "game", "plugin", "script", "shared", "workspace", "_G"};

        roblox::execution::bytecode_encoder_t encoder;
        Luau::CompileOptions options;

        options.optimizationLevel = 1;
        options.debugLevel = 2;
        options.coverageLevel = 0;
        options.vectorLib = "Vector3";
        options.vectorCtor = "new";
        options.vectorType = "Vector3";
        options.mutableGlobals = mutableGlobals;

        const auto compiled_res = Luau::compile(source, {}, {}, &encoder);
        return compiled_res;
    }   

    void execute(lua_State* L, std::string script) 
    {
        // you need to pop the thread from the stack and sandbox the thread
        auto new_thread = roblox::functions::rlua_newthread(L);

        const auto bytecode = roblox::execution::compile(script);
        if (roblox::functions::rluau_load(new_thread, globals::chunkname.c_str(), bytecode.c_str(), bytecode.size(), 0) != LUA_OK)
	    {
            // normally we would print the error but yk we are limited in functions
		    return;
	    }

        if (roblox::functions::rlua_pcall(new_thread, 1, 0, 0) != LUA_OK)
	    {
		    // same as luau load
		    return;
	    }
    }
}