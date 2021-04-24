#ifndef QUICKCONVERTSETTINGS_HPP
#define QUICKCONVERTSETTINGS_HPP

#include <iostream>
class QC_Settings{
  private:
  int setted_crf = 26;
  std::string default_encoding = "h264";
  public:


  // Getter & setter
  void set_setted_crf();
  int get_setted_crf();
  void setDefault_encoding();
  std::string getDefault_encoding();
  // Methods
  int showOptions();
  
};

#endif