#if !defined MSGSeparator_INC_
    #define MSGSeparator_INC_
#endif

native SendClientMessageSeparate(playerid, color, const message[], mode = 0);
native SendClientMessageSeparateEx(playerid, color, const message[], mode = 0, separator = ' ');

#if !defined MSGSeparator_Separate_DISABLE

    #if !defined MSGSeparator_Separate_AS_IS

        #if !defined MSGSeparator_Separate_GAP

            #if !defined MSGSeparator_Separate_CHAR_MOD0

                #if !defined MSGSeparator_Separate_CHAR_MOD1

                    #define MSGSeparator_Separate_CHAR_MOD1

                #endif
            #endif
        #endif
    #endif
#endif

#if defined MSGSeparator_Separate_AS_IS
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparate(playerid, color, message, 0);
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif

#if defined MSGSeparator_Separate_GAP
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

#if defined MSGSeparator_Separate_CHAR_MOD0
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparateEx(playerid, color, message, 0, ' ');
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif

#if defined MSGSeparator_Separate_CHAR_MOD1
    stock MSGSeparator_SendClientMessage(playerid, color, const message[])
    {
        return SendClientMessageSeparateEx(playerid, color, message, 1, ' ');
    }
    #if defined _ALS_SendClientMessage
	    #undef SendClientMessage
    #else
        #define _ALS_SendClientMessage
    #endif
    #define SendClientMessage MSGSeparator_SendClientMessage
#endif