#if !defined(FRONTEND_FUNC_H)
#define FRONTEND_FUNC_H

#include "rang.hpp"
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "ffmpeg_coder.hpp"
#include <fstream>
#include "s_lock.hpp"

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

void settings()
{
    int choice;
    clear_screen();
    std::vector<std::string> available_settings;
    available_settings.push_back("Startup-Lock");
    available_settings.push_back("Go Back");

    std::cout<<rang::fg::blue<<rang::style::bold<<"NB: "<<rang::style::reset<<"This feature only works in windows now !\n\n"<<rang::fg::reset<<std::endl;
    for (int i = 0; i < available_settings.size(); i++)
    {
        std::cout << (i + 1) << ". " << available_settings[i] << std::endl;
    }

    std::cout << "\n\nGive your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        S_Lock slock;
        slock.showOptions();
        break;
    }

    case 2:
    {
        break;
    }

    default:
        std::cout << "Invalid choice !!";
        break;
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
        clear_screen();
        title();
        cout <<rang::style::dim <<  "Choose your option: "<< rang::style::reset << endl;

        //Adding the options to the homepage menu (Main menu)
        vector<string> options;
        options.push_back("Make Codes");
        options.push_back("Quick Convert");
        options.push_back("About");
        options.push_back("Settings");
        options.push_back("Exit");

        //showing the options
        for (int i = 0; i < options.size(); i++)
        {
            cout << (i + 1) << ". " << options[i] << endl;
        }

        //taking choice input
        cout <<rang::bg::green<<rang::fg::black<<"\nYour choice: "<<rang::fg::reset<<rang::bg::reset;
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
        else if (choice == 2){
            cout << "Work in progress !!" << endl;
        }
        else if (choice == 3)
        {
            about();
        }
        else if (choice == 4)
        {
            settings();
        }
        else if (choice == 5)
        {
            clear_screen();
            std::cout << "Exiting the program..............." << std::endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice | Exiting...........";
            exit(0);
        }

        std::cout << "\n\nDo you want to go to Home screen[Y/N]: ";
        std::cin >> goBack;
    } while (goBack == 'Y');
}

#endif // FRONTEND_FUNC_H
