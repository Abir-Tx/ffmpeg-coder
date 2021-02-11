#if !defined(FRONTEND_FUNC_H)
#define FRONTEND_FUNC_H

#include <iostream>
#include <vector>
#include "utils.hpp"
#include "ffmpeg_coder.hpp"
//Functions
void title()
{
    decorateMe("FFMPEG Coder");
}


void about()
{
    clear_screen();
    std::string about_ffmpeg_coder;

    about_ffmpeg_coder = "FFMPEG Coder is a CLI tool created by Mushfiqur Rahman Abir AKA Abir-Tx.The tool is now in beta for testing purpose only and not much ready for use. Updates will be added soon";

    std::cout << about_ffmpeg_coder;
}

//Home page of the tool
void homepage()
{
    using namespace std;

    ffmpeg ffmpeg; //Creating ffmpeg object
    int choice;

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
        std::cout << "Exiting the program..............." << std::endl;
        exit(0);
    }
    else
    {
        exit(0);
    }
}

#endif // FRONTEND_FUNC_H
