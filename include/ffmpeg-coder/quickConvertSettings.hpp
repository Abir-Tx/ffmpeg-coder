#ifdef QUICKCONVERTSETTINGS_HPP
#define QUICKCONVERTSETTINGS_HPP

#include <iostream>

class QC_Settings() {
  private:
    int crf;

  public:
    int getCrf();
    void setCrf(int crf);
}
