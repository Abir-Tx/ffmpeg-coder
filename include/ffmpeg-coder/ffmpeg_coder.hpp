#if !defined(FFMPEG_CODER_H)
#define FFMPEG_CODER_H

#include <iostream>
#include <vector>
#include "utils.hpp"

//The FFMPEG class which will hold all kinds of encode options as methods
class ffmpeg
{
private:
    std::vector<std::string> encodes;
    std::vector<int> crf;
    std::vector<int> audiobitrate;
    std::vector<int> videobitrate;

public:
    //Vars
    int selected;
    std::string video_name;
    int selected_crf;
    int selected_audioBitrate;
    bool is_ab_selected = false;
    int selected_videoBitrate;
    bool is_vb_selected = false;

    //Methods
    ffmpeg();
    ~ffmpeg();

    void load_encodes()
    {
        //Loading the encodes into the vector
        encodes.push_back("h264");
        encodes.push_back("libx265");
    };
    void show_encodes()
    {
        std::cout << "Which video encoding do you prefer: " << std::endl;
        for (int i = 0; i < encodes.size(); i++)
        {
            std::cout << (i + 1) << ". " << encodes[i] << std::endl;
        }
    };
    int select_encodes()
    {
        std::cout << "Enter your choice: ";
        std::cin >> selected;

        return selected;
    };

    //ENCODERS ACTIONS
    void select_crf()
    {
        clear_screen();
        int choice;
        crf.push_back(20);
        crf.push_back(24);
        crf.push_back(26);
        crf.push_back(28);

        //showing the crf
        std::cout << "Note: Higher the CRF value more the compression";
        std::cout << std::endl;
        std::cout << "Select CRF value: " << std::endl;
        for (int i = 0; i < crf.size(); i++)
        {
            std::cout << (i + 1) << ". " << crf[i] << std::endl;
        }

        //Taking the crf
        std::cout << "Input your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                selected_crf = 20;
                break;
            }
            case 2:
            {
                selected_crf = 24;
                break;
            }
            case 3:
            {
                selected_crf = 26;
                break;
            }
            case 4:
            {
                selected_crf = 28;
                break;
            }
            default:
            {
                std::cout << "No CRF selected going with default 24";
                std::cout << std::endl;
                selected_crf = 24;
            }
        }
    }

    void select_audioBitrate()
    {
        clear_screen();
        int choice;
        int ab1 = 96;
        int ab2 = 128;
        int ab3 = 192;
        int ab4 = 256;
        int ab5 = 320;
        audiobitrate.push_back(ab1);
        audiobitrate.push_back(ab2);
        audiobitrate.push_back(ab3);
        audiobitrate.push_back(ab4);
        audiobitrate.push_back(ab5);

        //Asking if the user need the option or not
        std::cout << "Do you want to specify the -ab option:";
        std::cout << std::endl;
        std::cout << "1. Yes";
        std::cout << std::endl;
        std::cout << "2. No";
        std::cout << std::endl;

        std::cout << "Your choice: ";
        std::cin >> choice;

        clear_screen();
        if (choice == 1)
        {
            is_ab_selected = true;
            //showing the audioBitrate
            std::cout<<"Select Audio Bitrate for your Video: "<<std::endl;
            for (int i = 0; i < audiobitrate.size(); i++)
            {
                std::cout << (i + 1) << ". " << audiobitrate[i] << std::endl;
            }

            //Taking the audioBitrate
            std::cout << "Input your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            {
                selected_audioBitrate = ab1;
                break;
            }
            case 2:
            {
                selected_audioBitrate = ab2;
                break;
            }
            case 3:
            {
                selected_audioBitrate = ab3;
                break;
            }
            case 4:
            {
                selected_audioBitrate = ab4;
                break;
            }
            case 5:
            {
                selected_audioBitrate = ab5;
                break;
            }
            default:
            {
                std::cout << "No audioBitrate selected going with default 128";
                std::cout << std::endl;
                selected_audioBitrate = 128;
            }
            }
        }
        else
        {
            is_ab_selected = false;
            std::cout << "Going without -ab option";
            std::cout << std::endl;
        }
    }
    void select_videoBitrate()
    {
        clear_screen();
        /* Type	Video Bitrate, Standard Frame Rate
        (24, 25, 30)
        Video Bitrate, High Frame Rate
        (48, 50, 60)
        2160p (4K)	35–45 Mbps	53–68 Mbps
        1440p (2K)	16 Mbps	24 Mbps
        1080p	8 Mbps	12 Mbps
        720p	5 Mbps	7.5 Mbps
        480p	2.5 Mbps	4 Mbps
        360p	1 Mbps	1.5 Mbps
        */

        using namespace std;

        int choice;
        int vb1, vb2, vb3, vb4, vb5, vb6;
        vb1 = 35; //4k
        vb2 = 18;
        vb3 = 8;
        vb4 = 5;
        vb5 = 3; //480p
        vb6 = 1; //360p

        //loading the video bitrates to the vector
        videobitrate.push_back(vb1);
        videobitrate.push_back(vb2);
        videobitrate.push_back(vb3);
        videobitrate.push_back(vb4);
        videobitrate.push_back(vb5);
        videobitrate.push_back(vb6);
        //Asking the user
        cout << "Do you want to specify video bitrates?" << endl;
        cout << "1. Yes" << endl
             << "2. No" << endl;
        cout << "Your choice: ";
        cin >> choice;

        clear_screen();
        std::cout << "Select the appropriate video bitrate (default is 8 MBPS): ";
        std::cout << std::endl;
        if (choice == 1)
        {
            is_vb_selected = true;
            for (int i = 0; i < videobitrate.size(); i++)
            {
                cout << (i + 1) << ". " << videobitrate[i] << endl;
            }
            cout << "Your choice:";
            cin >> choice;

            switch (choice)
            {
            case 1:
                selected_videoBitrate = vb1;
                break;
            case 2:
                selected_videoBitrate = vb2;
                break;
            case 3:
                selected_videoBitrate = vb3;
                break;
            case 4:
                selected_videoBitrate = vb4;
                break;
            case 5:
                selected_videoBitrate = vb5;
                break;
            case 6:
                selected_videoBitrate = vb6;
                break;

            default:
                cout << "No video bitrate selected. Going with the default 8 MBPS";
                std::cout << std::endl;
                selected_videoBitrate = vb3;
                break;
            }
        }
        else if (choice==2)
        {
            is_vb_selected = false;
            std::cout << "Going without -vb option";
        }
        else
        {
            is_vb_selected = false;
            std::cout << "Going without -vb option";
            std::cout << std::endl;
        }
        clear_screen();
    }

    /* take_videoName method takes video names as input and stores the name in the global video_name
    variable. So it can be easy to use this method on any video encoding format */
    void take_videoName(){
        //Taking the video name input
        std::cout << "Please input the video file name without file extension: ";

        // getline(std::cin, video_name);
        std::cin >> video_name;
        clear_screen();
        std::cout << rang::fg::blue<< "Note: Video file names with space does not work."<<rang::fg::reset;
        std::cout << std::endl;
        std::cout << "NB: Input -1 to Exit the input loop";
        std::cout << std::endl;

        std::cout << "Your inputted video file's name is: " << video_name;
        std::cout << std::endl;

        std::cout << "Generated code to run in your CLI in the specified video file Directory: ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    /* generateCodes method is for taking a specific video encoding method name and generate all the
    necessary commands for that encode respectively */
    void generateCodes(std::string videoEncoding)
    {
        if (is_ab_selected == true && is_vb_selected == true)
        {
            std::cout << "ffmpeg -i " << video_name << ".mp4 -vcodec "<<videoEncoding<<" -acodec aac -vb " << selected_videoBitrate << "M "<< "-ab " << selected_audioBitrate << "k "
            << "-crf " << selected_crf << " " << video_name << ".encoded.mp4";
        }
        else if (is_ab_selected == true)
        {
            std::cout << "ffmpeg -i " << video_name << ".mp4 -vcodec "<<videoEncoding<<" -acodec aac -ab " << selected_audioBitrate << "k "
                      << "-crf " << selected_crf << " " << video_name << ".encoded.mp4";
        }
        else if (is_vb_selected == true)
        {
            std::cout << "ffmpeg -i " << video_name << ".mp4 -vcodec "<<videoEncoding<<" -acodec aac -vb " << selected_videoBitrate << "M "
                      << "-crf " << selected_crf << " " << video_name << ".encoded.mp4";
        }
        else
        {
            std::cout << "ffmpeg -i " << video_name << ".mp4 -vcodec "<<videoEncoding<<" -acodec aac -crf " << selected_crf << " " << video_name << ".encoded.mp4";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void h264()
    {
        take_videoName();
        std::string videoEncoding = "h264";
        generateCodes(videoEncoding);
    }

    void libx265()
    {
        take_videoName();
        std::string videoEncoding = "libx265";
        generateCodes(videoEncoding);
    }

// method to load all the needed modules
    void selected_action()
    {
        using namespace std;
        switch (selected)
        {
            case 1: //h264
            {
                select_crf();
                select_audioBitrate();
                select_videoBitrate();
                do
                {
                    h264();
                } while (video_name != "-1");
                break;
            }
            case 2:
            {
                select_crf();
                select_audioBitrate();
                select_videoBitrate();
                do
                {
                    libx265();
                } while (video_name != "-1");
                break;
            }
        }
    }
};

ffmpeg::ffmpeg()
{
}

ffmpeg::~ffmpeg()
{
}

#endif // FFMPEG_CODER_H
