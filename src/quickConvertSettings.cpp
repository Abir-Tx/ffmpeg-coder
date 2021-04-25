#include "rang.hpp"
#include "ffmpeg_coder.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "quickConvertSettings.hpp"
#include "alib.hpp"
#include <iomanip>


void QC_Settings::set_setted_crf(){
    
  }

int QC_Settings::get_setted_crf(){
    return setted_crf;
}

void QC_Settings:: setDefault_encoding(){
  std::fstream qcsData;
  qcsData.open("appData/qcs_encoding.bin", std::ios::in);
  
  if (qcsData.is_open()){
  std::string def_encoding;
  while (getline(qcsData, def_encoding))
  {
    default_encoding = def_encoding;
  }
  }else{
    default_encoding = "h264";
  }
}

std::string QC_Settings:: getDefault_encoding(){
    setDefault_encoding();
    return default_encoding;
}


void QC_Settings::showOptions(){
  clear_screen();
  std::vector<std::string> options;
  options.push_back("Set Default Encoding");
  options.push_back("Set default CRF");


  // Showing the options
  for (int i =0; i < options.size(); i++){
    std::cout << (i+1) << ". " << options[i] << std::endl;
  }

  // Taking user input
  std::cout<< rang::style::bold << rang::fg::blue << "\nChoose your option: "
                            << rang::style::reset << rang::fg::reset;
  std::cin >> userChoice;
}


void QC_Settings:: settingsDataWriter(std::string filePath, std::string settings){
try
    {
      std::fstream qcsData;
      qcsData.open(filePath, std::ios::out);

      if (qcsData.is_open()){
        qcsData << settings;

        std::cout<<"\n|You preferred settings have been saved for future|";
      }
      else
        throw 501;
    }
    catch(...)
    {
      std::cerr << "Error occured while openning data file!";
    }
}

void QC_Settings::default_encoding_configurer(){
  clear_screen();
  std::string givenEncoding;
  int selectedOption;

  // Showing the current default encoding
  std::string currentDef = "The current default is: "+default_encoding;
  alib::decorateMe(currentDef,1," ",true);
  
  // Taking new encoding from user
  ffmpeg *fmpg = new ffmpeg();
  fmpg->load_encodes();
  fmpg->show_encodes();
  selectedOption = fmpg->select_encodes();

  if (selectedOption == 1){
    settingsDataWriter("appData/qcs_encoding.bin", fmpg->encodes[0]);
  }
  else if(selectedOption == 2){
    settingsDataWriter("appData/qcs_encoding.bin", fmpg->encodes[1]);
  }
  else
  std::cerr << "\nInvalid Option Selected ! Try again";
}