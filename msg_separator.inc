#if !defined MSGSeparator_INC_
    #define MSGSeparator_INC_
#endif

native SendClientMessageSeparate(playerid, color, const message[], mode = 0, MaxLen = 144);
native SendClientMessageSeparateEx(playerid, color, const message[], mode = 0, MaxLen = 144, separator = ' ');

#if !defined SEPARATE_METHOD_DISABLE

    #if !defined SEPARATE_METHOD_AS_IS

        #if !defined SEPARATE_METHOD_GAP

            #if !defined SEPARATE_METHOD_CHAR_MOD_0

                #if !defined SEPARATE_METHOD_CHAR_MOD_1

                    #define SEPARATE_METHOD_CHAR_MOD_1

                #endif
            #endif
        #endif
    #endif
#endif

#if defined SEPARATE_METHOD_AS_IS
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparate(playerid, color, message);
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif

#if defined SEPARATE_METHOD_GAP
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparate(playerid, color, message, 1);
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif

#if defined SEPARATE_METHOD_CHAR_MOD_0
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparateEx(playerid, color, message);
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif

#if defined SEPARATE_METHOD_CHAR_MOD_1
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparateEx(playerid, color, message, 1);
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif