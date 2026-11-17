// Helpers of clearpods_native.cpp shared with mixer.cpp.
#ifndef CLEARPODS_INTERNAL_H
#define CLEARPODS_INTERNAL_H

#include <windows.h>
#include <stdint.h>

// CoIncrementMTAUsage once per process (never released), so threads without COM init run as implicit MTA.
HRESULT ensure_mta();
// BTHENUM\DEV_<address> devnode (present only) -> container ID shared by the device's audio endpoints. Throws on a
// CM failure.
bool find_container_id(uint64_t address, GUID& containerId);

#endif
