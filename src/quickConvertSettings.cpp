
#include "rang.hpp"
#include "quickConvertSettings.hpp"
#include "alib.hpp"
#include "ffmpeg_coder.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>


void QC_Settings::set_setted_crf() {
    std::fstream qcsData;
    qcsData.open("appData/qcs_crf.bin", std::ios::in);

    if (qcsData.is_open()) {
        std::string def_crf;
        while (getline(qcsData, def_crf)) { def_crf = def_crf; }

        if (def_crf == "20")
            setted_crf = 20;
        else if (def_crf == "24")
            setted_crf = 24;
        else if (def_crf == "26")
            setted_crf = 26;
        else if (def_crf == "28")
            setted_crf = 28;
        else
            setted_crf = 26;

    } else {
        setted_crf = 26;
    }
}

int QC_Settings::get_setted_crf() {
    set_setted_crf();
    return setted_crf;
}

void QC_Settings::setDefault_encoding() {
    std::fstream qcsData;
    qcsData.open("appData/qcs_encoding.bin", std::ios::in);

    if (qcsData.is_open()) {
        std::string def_encoding;
        while (getline(qcsData, def_encoding)) {
            default_encoding = def_encoding;
        }
    } else {
        default_encoding = "h264";
    }
}

std::string QC_Settings::getDefault_encoding() {
    setDefault_encoding();
    return default_encoding;
}

void QC_Settings::showOptions() {
    clear_screen();
    std::vector<std::string> options;
    options.push_back("Set Default Encoding");
    options.push_back("Set default CRF");

    // Showing the options
    for (int i = 0; i < options.size(); i++) {
        std::cout << (i + 1) << ". " << options[i] << std::endl;
    }

    // Taking user input
    std::cout << rang::style::bold << rang::fg::blue
              << "\nChoose your option: " << rang::style::reset
              << rang::fg::reset;
    std::cin >> userChoice;
}

void QC_Settings::settingsDataWriter(std::string filePath,
                                     std::string settings) {
    try {
        std::fstream qcsData;
        qcsData.open(filePath, std::ios::out);

        if (qcsData.is_open()) {
            qcsData << settings;

            std::cout
                << "\n|You preferred settings have been saved for future|";
        } else
            throw 501;
    } catch (...) { std::cerr << "Error occured while openning data file!"; }
}

void QC_Settings::default_encoding_configurer() {
    clear_screen();
    std::string givenEncoding;
    int selectedOption;

    // Showing the current default encoding
    std::string currentDef = "The current default is: " + default_encoding;
    alib::decorateMe(currentDef, 1, " ", true);

    // Taking new encoding from user
    ffmpeg *fmpg = new ffmpeg();
    fmpg->load_encodes();
    fmpg->show_encodes();
    selectedOption = fmpg->select_encodes();

    if (selectedOption == 1) {
        settingsDataWriter("appData/qcs_encoding.bin", fmpg->encodes[0]);
    } else if (selectedOption == 2) {
        settingsDataWriter("appData/qcs_encoding.bin", fmpg->encodes[1]);
    } else
        std::cerr << "\nInvalid Option Selected ! Try again";
}

void QC_Settings::default_crf_configurer() {
    clear_screen();
    std::string givenCrf;
    int selectedOption;

    // Showing the current default encoding
    // std::string currentDef = "The default is: 26";
    // alib::decorateMe(currentDef, 1, " ", true);

    // Taking new encoding from user
    ffmpeg *fmpg = new ffmpeg();
    fmpg->select_crf();
    selectedOption = fmpg->selected_crf;

    if (selectedOption == 20)
      settingsDataWriter("appData/qcs_crf.bin","20");
    else if (selectedOption == 24)
      settingsDataWriter("appData/qcs_crf.bin","24");
    else if (selectedOption == 26)
      settingsDataWriter("appData/qcs_crf.bin","26");
    else if (selectedOption == 28)
      settingsDataWriter("appData/qcs_crf.bin","28");
    else
      settingsDataWriter("appData/qcs_crf.bin","26");
}

void QC_Settings::optionsRouter() {
    if (userChoice == 1)
        default_encoding_configurer();
    else if (userChoice == 2)
        default_crf_configurer();
    else
        std::cout << "\nInvalid choice. Try again\n";
}
