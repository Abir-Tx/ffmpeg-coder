#ifndef QUICKCONVERTSETTINGS_HPP
#define QUICKCONVERTSETTINGS_HPP

#include <iostream>

class QC_Settings{
  private:
  int setted_crf = 26;
  int userChoice;
  std::string default_encoding = "h264";

  // Private methods
  void settingsDataWriter(std::string filePath, std::string settings);
  public:


  // Getter & setter
  void set_setted_crf();
  int get_setted_crf();
  void setDefault_encoding();
  std::string getDefault_encoding();
  // Methods
  void showOptions();
  void default_encoding_configurer();
  void default_crf_configurer();
  void optionsRouter();
};

#endif