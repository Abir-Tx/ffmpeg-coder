/* A C++ program code by Mushfiqur Rahman Abir  */

#include "rang.hpp"
#include "ffmpeg_coder.hpp"
#include "frontend_funcs.hpp"
#include "s_lock.hpp"
int main()
{
    S_Lock slock;
    if (slock.getIsLock() == true)
    {
        if (slock.unlocker() == true)
        {
            clear_screen();
            homepage();
        }
        else if (slock.unlocker() == false)
        {
            std::cout<<"Exiting the app";
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        clear_screen();
        homepage();
    }

}
