#pragma once

#include <string>
#include <thread>

namespace utils {
    namespace memory {
        inline bool is_lib_loaded(const std::string lib_name) {
            char line[512] = {0};
            FILE* fp = std::fopen("/proc/self/maps", "rt");
            if (fp != nullptr) {
                while (std::fgets(line, sizeof(line), fp)) {
                    if (std::strstr(line, lib_name.c_str())) {
                        fclose(fp);
                        return true;
                    }
                }
                fclose(fp);
            }
            return false;
        }

        inline std::uintptr_t find_lib(const std::string library) {
            char buffer[1024] = {0};
            FILE* fp = fopen("/proc/self/maps", "rt");
            std::uintptr_t address = 0;

            if (fp == nullptr) return 0;

            while (fgets(buffer, sizeof(buffer), fp)) {
                if (strstr(buffer, library.c_str())) {
                    address = static_cast<std::uintptr_t>(strtoul(buffer, nullptr, 16));
                    break;
                }
            }
            fclose(fp);
            return address;
        }

        inline void wait_for_lib(const std::string lib_name) {
            while (!utils::memory::is_lib_loaded(lib_name)) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        };

        inline int64_t rebase(const std::string lib_name, int64_t address) {
            std::uintptr_t lib_base = utils::memory::find_lib(lib_name);
            if (lib_base == 0) return 0;
            return (lib_base + address);
        }
    };
}