
#include "rang.hpp"
#include "ffmpeg_coder.hpp"
#include "s_lock.hpp"
#include "utils.hpp"
#include "quickConvertSettings.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include "frontend_funcs.hpp"


// Functions
void title() {
    decorateMe("FFMPEG Coder");
}

void about() {
    clear_screen();
    std::string about_ffmpeg_coder;
    std::ifstream read_about("res/about.bin");

    while (getline(read_about, about_ffmpeg_coder)) {
        std::cout << about_ffmpeg_coder;
    }
}

void settings() {
    int choice;
    clear_screen();
    std::vector<std::string> available_settings;
    available_settings.push_back("Startup-Lock");
    available_settings.push_back("Quick Convert Settings");
    available_settings.push_back("Go Back");

    std::cout << rang::fg::blue << rang::style::bold
              << "NB: " << rang::style::reset
              << "This feature only works in windows now !\n\n"
              << rang::fg::reset << std::endl;
    for (int i = 0; i < available_settings.size(); i++) {
        std::cout << (i + 1) << ". " << available_settings[i] << std::endl;
    }

    std::cout << "\n\nGive your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        S_Lock slock;
        slock.showOptions();
        break;
    }

    case 2: {
        QC_Settings *qc = new QC_Settings();
        
        qc->showOptions();
        qc->optionsRouter();
        delete qc;
    }

    case 3: {
        break;
    }

    default: std::cout << "Invalid choice !!"; break;
    }
}

// Home page of the tool
void homepage() {
    using namespace std;

    
    int choice;

    /* The char goBack variable is used for navigating to the main screen using
     * the while loop */
    char goBack;
    do {
        clear_screen();
        title();
        cout << rang::style::dim << "Choose your option: " << rang::style::reset
             << endl;

        // Adding the options to the homepage menu (Main menu)
        vector<string> options;
        options.push_back("Make Codes");
        options.push_back("Quick Convert (mp4)");
        options.push_back("About");
        options.push_back("Settings");
        options.push_back("Exit");

        // showing the options
        for (int i = 0; i < options.size(); i++) {
            cout << (i + 1) << ". " << options[i] << endl;
        }

        // taking choice input
        cout << rang::bg::green << rang::fg::black
             << "\nYour choice: " << rang::fg::reset << rang::bg::reset;
        cin >> choice;

        // Entering into selected option funcs
        if (choice == 1) {
            ffmpeg *fmpg = new ffmpeg(); // Creating ffmpeg object
            clear_screen();
            fmpg->load_encodes();
            fmpg->show_encodes();
            fmpg->select_encodes();
            fmpg->selected_action();
            delete fmpg;
        } else if (choice == 2) {
            ffmpeg *fmpg = new ffmpeg(); // Creating ffmpeg object
            fmpg->quickConvert();
            delete fmpg;
        } else if (choice == 3) {
            about();
        } else if (choice == 4) {
            settings();
        } else if (choice == 5) {
            clear_screen();
            std::cout << "Exiting the program..............." << std::endl;
            exit(0);
        } else {
            cout << "Invalid choice | Exiting...........";
            exit(0);
        }

        std::cout << "\n\nDo you want to go to Home screen[Y/N]: ";
        std::cin >> goBack;
    } while (goBack == 'Y');
}