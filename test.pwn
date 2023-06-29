/* Language: Vietnamese */

#include <a_samp>
#include <captcha>

main() {
    print("Captcha by Ausil (C) 2023");
}


public OnPlayerCommandText(playerid, cmdtext[])
{
    if(strcmp(cmdtext, "showcaptcha", false) == 0)
    {
        Captcha_Show(playerid, Test_Captcha, "[Captcha]", "Nhap ma captcha o ben duoi:");
    }
    return 1;
}

Captcha:Test_Captcha(playerid, success)
{
    if(!success) return SendClientMessage(playerid, 0xDC1818FF, "Captcha khong chinh xac!"); // Failed

    SendClientMessage(playerid, 0x18DC1FFF, "Captcha chinh xac!"); // Succeeded
    GivePlayerMoney(playerid, 1000); // give $100
    return 1;
}