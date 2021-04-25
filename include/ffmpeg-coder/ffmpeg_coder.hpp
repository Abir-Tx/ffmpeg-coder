#if !defined(FFMPEG_CODER_HPP)
#define FFMPEG_CODER_HPP

#include "utils.hpp"
#include "quickConvertSettings.hpp"
#include <iostream>
#include <vector>

// The FFMPEG class which will hold all kinds of encode options as methods
class ffmpeg {
  private:
    std::vector<std::string> encodes;
    std::vector<int> crf;
    std::vector<int> audiobitrate;
    std::vector<int> videobitrate;

  public:
    // Vars
    int selected;
    std::string video_name;
    int selected_crf;
    int selected_audioBitrate;
    bool is_ab_selected = false;
    int selected_videoBitrate;
    bool is_vb_selected = false;

    // Methods
    ffmpeg();
    ~ffmpeg();

    void load_encodes();
    void show_encodes();
    int select_encodes();

    // ENCODERS ACTIONS
    void select_crf();

    void select_audioBitrate();
    void select_videoBitrate();

    /* take_videoName method takes video names as input and stores the name in
    the global video_name
    variable. So it can be easy to use this method on any video encoding format
  */
    void take_videoName();

    /* generateCodes method is for taking a specific video encoding method name
    and generate all the necessary commands for that encode respectively */
    void generateCodes(std::string videoEncoding);
    void h264();

    void libx265();
    // method to load all the needed modules
    void selected_action();

    //  Quick convert function
    void quickConvert();
};



#endif // FFMPEG_CODER_H
