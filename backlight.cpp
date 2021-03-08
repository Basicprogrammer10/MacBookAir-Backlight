#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void setFile(string path, int value){
    fstream file;
    file.open(path, ios::out);
    file << value;
    file.close();
}

bool cmdOption(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char **argv)
{
    cout << "\033[1;35mBacklight Control V1.1 for MacBookAir | By: Connor Slade\n";

    if (argv[1] == NULL || argv[2] == NULL){
        cout << "\033[1;31mNot enough args given :/\n";
		cout << "\033[34mUseage: ./backlight( d / k ) 0-100\n";
        cout << "\033[34m   d - Display\n   k - Keybord\n";
        return 1;
    }

    float brightness = stoi(argv[2]);

    if (brightness > 100 || brightness < 0){
        cout << "\033[1;31mGive Birghtness value from 0 - 100\n";
        return 1;
    }

    if(cmdOption(argv, argv+argc, "d"))
    {
        cout <<"\033[36mSetting Backlight to " << brightness << "%\n";
        setFile("/sys/class/backlight/intel_backlight/brightness", (int)(2777 * (brightness / 100)));
        cout <<"\033[32mSucess!" << "\n";
        return 0;
    }

    if(cmdOption(argv, argv+argc, "k"))
    {
        cout <<"\033[36mSetting Keybord to " << brightness << "%\n";
        setFile("/sys/devices/platform/applesmc.768/leds/smc::kbd_backlight/brightness", (int)(255 * (brightness / 100)));
        cout <<"\033[32mSucess!" << "\n";
        return 0;
    }
}