#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "\033[1;35mBacklight Control V1.0 for MacBookAir | By: Connor Slade\n";

    if (argv[1] == NULL){
        cout << "\033[1;31mNot enough args given :/\n";
		cout << "\033[34mUseage: ./backlight 0-100\n";
        return 1;
    }

    float brightness = std::stoi(argv[1]);

    if (brightness > 100 || brightness < 0){
        cout << "\033[1;31mGive Birghtness value from 0 - 100\n";
        return 1;
    }

    cout <<"\033[36mSetting Backlight to " << brightness << "%\n";

    std::stringstream sstm;
    sstm << "sudo echo '" << (int)(2777 * (brightness / 100)) << "' | sudo tee /sys/class/backlight/intel_backlight/brightness &> /dev/null";
    string result = sstm.str();
    system(&result[0]);

    cout <<"\033[32mSucess!" << "\n";
}