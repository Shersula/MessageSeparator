#define HAVE_STDINT_H

#include "Source/Separator.h"
#include "SDK/plugin.h"
#include "SDK/sampgdk/sampgdk.h"

void** ppPluginData;
extern void* pAMXFunctions;
PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];

    sampgdk::logprintf("Plugin loaded");
    return sampgdk::Load(ppData);
}
PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    sampgdk::logprintf("Plugin unloaded");
    sampgdk::Unload();
}

cell AMX_NATIVE_CALL SendClientMessageSeparate(AMX* amx, cell* params)
{
    if (params[0] / sizeof(cell) != 4)
    {
        sampgdk::logprintf("SendClientMessageSeparate incorrect number of parameter(s). Expected: 4 Received: %d", params[0]/sizeof(cell));
        return 1;
    }

    int len;
    cell* address;
    amx_GetAddr(amx, params[3], &address);
    amx_StrLen(address, &len);
    char* Message = nullptr;
    if (len)
    {
        len++;
        Message = new char[len];
        amx_GetString(Message, address, 0, len);

        Separator PrepareMSG(Message, params[4]);

        for (std::string i : PrepareMSG.getMessageQueue()) SendClientMessage(params[1], params[2], i.c_str());

        delete[] Message;
    }
    return 1;
}

cell AMX_NATIVE_CALL SendClientMessageSeparateEx(AMX* amx, cell* params)
{
    if (params[0] / sizeof(cell) != 5)
    {
        sampgdk::logprintf("SendClientMessageSeparateEx incorrect number of parameters. Expected: 5 Received: %d", params[0]/sizeof(cell));
        return 1;
    }

    int len;
    cell* address;
    amx_GetAddr(amx, params[3], &address);
    amx_StrLen(address, &len);
    char* Message = nullptr;
    if (len)
    {
        len++;
        Message = new char[len];
        amx_GetString(Message, address, 0, len);

        Separator PrepareMSG(Message, params[4], params[5]);

        for (std::string i : PrepareMSG.getMessageQueue()) SendClientMessage(params[1], params[2], i.c_str());

        delete[] Message;
    }
    return 1;
}

AMX_NATIVE_INFO NATIVES_LIST[] =
{
    {"SendClientMessageSeparate", SendClientMessageSeparate},
    {"SendClientMessageSeparateEx", SendClientMessageSeparateEx},
    { 0, 0 }
};
PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return sampgdk::Supports() | SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}
PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    return amx_Register(amx, NATIVES_LIST, -1);
}
PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
    return AMX_ERR_NONE;
}
