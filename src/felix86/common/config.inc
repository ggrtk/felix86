// GROUP --- TYPE --- NAME --- DEFAULT VALUE --- ENVIRONMENT VARIABLE NAME --- DESCRIPTION -- REQUIRED
X(General, std::filesystem::path, rootfs_path, "", FELIX86_ROOTFS, "Set the rootfs path, required for the emulator to work", true)
X(General, std::filesystem::path, thunks_path, "", FELIX86_THUNKS, "Set the thunk libraries path", false)
X(General, std::string, enabled_thunks, "none", FELIX86_ENABLED_THUNKS, "Set the enabled thunks, possible choices: \"vk, glx, wayland, egl\" or \"all\"", false)

X(Logging, bool, verbose, false, FELIX86_VERBOSE, "Enable verbose logging", false)
X(Logging, bool, quiet, false, FELIX86_QUIET, "Disable all logging", false)
X(Logging, bool, strace, false, FELIX86_STRACE, "Enable logging of syscalls", false)
X(Logging, bool, print_signals, false, FELIX86_PRINT_SIGNALS, "Print on every guest signal handler", false);

X(Debugging, bool, dump_regs, false, FELIX86_DUMP_REGS, "Dump register values on exit", false)
X(Debugging, bool, calltrace, false, FELIX86_CALLTRACE, "Capture a calltrace (push on every call, pop on every ret)", false)
X(Debugging, bool, single_step, false, FELIX86_SINGLE_STEP, "Enable single stepping mode (each block is one instruction)", false)
X(Debugging, bool, no_sse2, false, FELIX86_NO_SSE2, "Stop the emulator on SSE2 instructions", false)
X(Debugging, bool, no_sse3, false, FELIX86_NO_SSE3, "Stop the emulator on SSE3 instructions", false)
X(Debugging, bool, no_ssse3, false, FELIX86_NO_SSSE3, "Stop the emulator on SSSE3 instructions", false)
X(Debugging, bool, no_sse4_1, false, FELIX86_NO_SSE4_1, "Stop the emulator on SSE4.1 instructions", false)
X(Debugging, bool, no_sse4_2, false, FELIX86_NO_SSE4_2, "Stop the emulator on SSE4.2 instructions", false)
X(Debugging, bool, perf_blocks, false, FELIX86_PERF_BLOCKS, "Name blocks for perf", false)
X(Debugging, bool, perf_symbols, false, FELIX86_PERF_SYMBOLS, "Use symbols for perf block naming, may cause some slowdown", false)
X(Debugging, bool, perf_global, false, FELIX86_PERF_GLOBAL, "Name entire code cache for perf", false)
X(Debugging, bool, perf_libs, false, FELIX86_PERF_LIBS, "Name entire code cache for perf", false)
X(Debugging, bool, gdb, false, FELIX86_GDB, "Emit symbols for gdb in /tmp -- Currently doesn't work due to gdb bug: https://sourceware.org/bugzilla/show_bug.cgi?id=32248", false)
X(Debugging, u64, interpreter_base, 0, FELIX86_INTERPRETER_BASE, "Make the interpreter (ld-linux.so) be loaded at this address -- 0 to let the emulator choose", false)
X(Debugging, u64, executable_base, 0, FELIX86_EXECUTABLE_BASE, "Make the executable be loaded at this address -- 0 to let the emulator choose", false)
X(Debugging, u64, brk_base, 0, FELIX86_BRK_BASE, "Make the BRK be loaded at this address -- 0 to let the emulator choose", false)
X(Debugging, u64, max_brk_size, 0, FELIX86_MAX_BRK_SIZE, "Set the maximum BRK (ram for the application) size -- 0 to let the emulator choose", false)
X(Debugging, bool, sleep_on_error, false, FELIX86_SLEEP_ERROR, "Sleep for 40 seconds on error to give enough time to attach gdb", false)
X(Debugging, bool, capture_sigsegv, false, FELIX86_CAPTURE_SIGSEGV, "Sleep for 40 seconds on any SIGSEGV that is unrelated to self-modifying code", false)
X(Debugging, bool, hacky_envs, true, FELIX86_HACKY_ENVS, "Enable some hacky environment variable solutions to allow some apps to work under felix86", false)
X(Debugging, bool, always_flags, false, FELIX86_ALWAYS_FLAGS, "Emit flag calculations for every instruction even if they are unused", false)
X(Debugging, bool, paranoid, false, FELIX86_PARANOID, "Disables multiple optimizations in hopes to catch bugs", false)

X(Performance, bool, link, true, FELIX86_LINK, "Enable basic block linking, important for performance", false)
X(Performance, bool, address_cache, true, FELIX86_ADDRESS_CACHE, "Use lower address bits to speed up block lookup", false)
X(Performance, bool, unsafe_flags, false, FELIX86_UNSAFE_FLAGS, "Assume flags are thrashed on every call/ret to avoid some calculations", false)
X(Performance, bool, inline_syscalls, true, FELIX86_INLINE_SYSCALLS, "Use ECALL directly instead of a function for some syscalls", false)
X(Performance, bool, inaccurate_minmax, true, FELIX86_INACCURATE_MINMAX, "Don't accurately calculate minps/minpd/maxps/maxpd instructions when it comes to NaNs", false)
X(Performance, bool, always_tso, false, FELIX86_ALWAYS_TSO, "Use fences to emulate TSO on every memory read/write -- Will cause slowdown but may fix some games", false)
X(Performance, bool, protect_pages, true, FELIX86_PROTECT_PAGES, "Protect pages to catch self-modifying code, disabling may perform better in some games but break others", false)
X(Performance, bool, noflag_opts, true, FELIX86_NOFLAG_OPTS, "Optimize some instructions when the flag calculations aren't necessary", false)
