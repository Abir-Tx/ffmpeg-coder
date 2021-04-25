
#include <iostream>
#include <fstream>
#include <vector>
#include "quickConvertSettings.hpp"


void QC_Settings::set_setted_crf(){
    
  }

int QC_Settings::get_setted_crf(){
    return setted_crf;
}

void QC_Settings:: setDefault_encoding(){
  std::fstream qcsData;
  qcsData.open("appData/qc_settingsData.bin", std::ios::in);
  
  if (qcsData.is_open()){
  std::string def_encoding;
  while (getline(qcsData, def_encoding))
  {
    default_encoding = def_encoding;
  }
  }else{
    default_encoding = "h264";
  }
  std::cout<<default_encoding;
}

std::string QC_Settings:: getDefault_encoding(){
    return default_encoding;
}

void QC_Settings::showOptions(){

  std::vector<std::string> options;
  options.push_back("Set Default Encoding");
  options.push_back("Set default CRF");


  // Showing the options
  for (int i =0; i < options.size(); i++){
    std::cout << (i+1) << ". " << options[i] << std::endl;
  }

  // Taking user input
  std::cout<< "Choose your option:";
  std::cin >> userChoice;
}

void QC_Settings::default_encoding_configurer(){

}