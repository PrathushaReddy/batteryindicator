#include <stdio.h>
#include <windows.h>

int batteryinfo()
{
    SYSTEM_POWER_STATUS status;
    if (GetSystemPowerStatus(&status))
    {
        unsigned char battery = status.BatteryLifePercent;
        /* battery := 0..100 or 255 if unknown */
        return battery;
        if (battery == 255) 
        {
            printf("Battery level unknown !");
        }
        else
        {
            printf("Battery level : %u%%.", battery);
        }
    }
    else
    {
        printf("Cannot get the power status, error %lu", GetLastError());
    }
}


int popup()
{
    MessageBoxA(NULL, "the batttery is less that 40 please connect the charger !!!", "Connect the charger ",MB_OKCANCEL);
}

void main()
{
    int batteryp = batteryinfo();
    int n;
    system("cls");
     if (batteryp < 40)
        {
            popup();
            Sleep(300000);
            if (batteryp = batteryinfo())
            {
                system("C:\\WINDOWS\\System32\\shutdown /h ");
            }
        }
        else
        {
            printf("The battery is : %d%% !!", batteryinfo());
        }
}