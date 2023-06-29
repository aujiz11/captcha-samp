/*  

    - captcha.inc <> Captcha system -

    * Author: Ausil (aujiz)
    * Date: 29/06/2023
    * Copyright: (C) 2023

*/

#if defined _captcha_included
    #endinput
#endif
#define _captcha_included

#if !defined _samp_included
	#error Please include <a_samp> first.
#endif

#if !defined isnull
	#define isnull(%1) \
		((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define Captcha_Show(%1,%2, \
	_show_captcha(%1, #%2,

#define Captcha:%1(%2)					forward ct_%1(%2); public ct_%1(%2)

#define MAX_CAPTCHA_LENGTH (10)

/*==== Variables ====*/
static  
        bool:captcha_open[MAX_PLAYERS],
        captcha_code[MAX_PLAYERS][MAX_CAPTCHA_LENGTH],
        captcha_id[MAX_PLAYERS][32 char];

/*==== Main Function ====*/
stock random_string(str_dest[], str_len = 10)
{
	while(str_len--) str_dest[str_len] = random(2) ? (random(26) + (random(2) ? 'a' : 'A')) : (random(10) + '0');
}

stock _show_captcha(playerid, c_id[], caption[], info[], bool:showcode = true)
{
    if(captcha_open[playerid])
        return 1;
    captcha_open[playerid] = true;

    new _code[12], string[226];
    random_string(_code);
    strcat(captcha_code[playerid], _code);
    
    if(showcode) format(string, sizeof string, "Captcha code: %s\n\n%s", captcha_code[playerid], info);

    ShowPlayerDialog(playerid, 1186, DIALOG_STYLE_INPUT, caption, string, "Xac nhan", "Dong");
    strpack(captcha_id[playerid], c_id, 32 char);

    // SendClientMessage(playerid, -1, "show");
    return 1;
}

stock c_Close(playerid) // Close Captcha Dialog
{
    captcha_open[playerid] = false;
    captcha_id[playerid]{0} = 0;
    captcha_code[playerid] = "";

    return ShowPlayerDialog(playerid, -1, DIALOG_STYLE_INPUT, " ", " ", " ", "");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == 1186 && captcha_open[playerid])
    {
        if(response)
        {
            new string[46], success;
            strcat(string, "ct_");
            strcat(string, captcha_id[playerid]);

            if(strcmp(captcha_code[playerid], inputtext, false) == 0 && !isnull(inputtext)) success = 1;
            else success = 0;
            
            CallLocalFunction(string, "dd", playerid, success);
            c_Close(playerid);
        }
        else
        {
            c_Close(playerid); // close
        }
    }
	#if defined C_OnDialogResponse
	    return C_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
	    return 0;
	#endif
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse C_OnDialogResponse

#if defined C_OnDialogResponse
	forward C_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
