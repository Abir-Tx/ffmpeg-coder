#if !defined(FRONTEND_FUNC_H)
#define FRONTEND_FUNC_H

#include <iostream>
#include <vector>
#include "utils.hpp"
#include "ffmpeg_coder.hpp"
#include <fstream>
//Functions
void title()
{
    decorateMe("FFMPEG Coder");
}

void about()
{
    clear_screen();
    std::string about_ffmpeg_coder;
    std::ifstream read_about("res/about.bin");

    while (getline(read_about, about_ffmpeg_coder))
    {
        std::cout << about_ffmpeg_coder;
    }
}

//Home page of the tool
void homepage()
{
    using namespace std;

    ffmpeg ffmpeg; //Creating ffmpeg object
    int choice;
    
    /* The char goBack variable is used for navigating to the main screen using the while loop */
    char goBack;
    do
    {
        cout << "Choose your option: " << endl;

        //Adding the options to the homepage menu (Main menu)
        vector<string> options;
        options.push_back("Make Codes");
        options.push_back("About");
        options.push_back("Exit");

        //showing the options
        for (int i = 0; i < options.size(); i++)
        {
            cout << (i + 1) << ". " << options[i] << endl;
        }

        //taking choice input
        cout << "Your choice: ";
        cin >> choice;

        //Entering into selected option funcs
        if (choice == 1)
        {
            clear_screen();
            ffmpeg.load_encodes();
            ffmpeg.show_encodes();
            ffmpeg.select_encodes();
            ffmpeg.selected_action();
        }
        else if (choice == 2)
        {
            about();
        }
        else if (choice == 3)
        {
            clear_screen();
            std::cout << "Exiting the program..............." << std::endl;
            exit(0);
        }
        else
        {
            exit(0);
        }

        std::cout << "\n\nDo you want to go to Home screen[Y/N]: ";
        std::cin >> goBack;
    } while (goBack == 'Y');
}

#endif // FRONTEND_FUNC_H
