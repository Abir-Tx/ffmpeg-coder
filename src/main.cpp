/* A C++ program code by Mushfiqur Rahman Abir  */


#include "rang.hpp"
#include "s_lock.hpp"
#include "ffmpeg_coder.hpp"
#include "frontend_funcs.hpp"
int main() {
#ifdef __unix__
    clear_screen();
    homepage();
#else
    S_Lock *slock = new S_Lock();
    if (slock->getIsLock() == true) {
        if (slock->unlocker() == true) {
            clear_screen();
            homepage();
            delete slock;
        } else if (slock->unlocker() == false) {
            std::cout << "Exiting the app";
            delete slock;
        } else {
            delete slock;
            exit(0);
        }
    } else {
        clear_screen();
        homepage();
    }
    delete slock;
#endif
}
