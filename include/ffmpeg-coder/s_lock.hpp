#if !defined(S_LOCK_HPP)
#define S_LOCK_HPP

#include "rang.hpp"
#include <iostream>
#include <fstream>
#include <bitset>
#include "utils.hpp"

class S_Lock
{
private:
    bool isLock = false;
    std::string passphrase;

    std::string getPassphrase()
    {
        return passphrase;
    }
    void setIsLock(bool value)
    {
        isLock = value;
        std::ofstream writer("appData/s_lockValue.bin");
        writer << isLock;
        writer.close();
    }

public:
    // setter and getter
    void setPassphrase(std::string passphrase)
    {
        this->passphrase = passphrase;
    };

    bool getIsLock()
    {
        std::ifstream reader("appData/s_lockValue.bin");
        int storer;
        reader >> storer;

        if (storer==0)
        {
            return false;
        }
        else if ( storer == 1)
        {
            return true;
        }
        else return false;
    }


    //Methods
    int encrypt(std::string text)
    {
        int textToInt;
        for (int i = 0; i < text.size(); i++)
        {
            textToInt += int(text[i]);
        }
        textToInt = (textToInt)*text.size();
        return textToInt;
    }

    void setupLock()
    {
        
        std::string pass1, pass2;
        std::cout << "Enter your passphrase: ";
        std::cin >> pass1;
        std::cout << "Enter passphrase again: ";
        std::cin >> pass2;
        passphrase = (pass1 == pass2) ? pass1 : "Not Set";
        if (passphrase == "Not Set")
        {
            std::cout << "Passphrase does not match ! ";
            std::cout << std::endl;
        }
        else
        {
            std::ofstream passKeeper("usrData/passphrase.bin");
            int encryptedPassphrase = encrypt(passphrase);
            if (passKeeper.is_open())
            {
                passKeeper << encryptedPassphrase;
                passKeeper.close();
                // Turn on the flag to let other funcs know that locking is turned on
                setIsLock(true);
            }
            else
            {
                std::cout << "Unable to set passphrase. Error occured !";
            }
            std::cout << "Passphrase set :-)";
            std::cout << std::endl;
        }
    }

    void deleteLock()
    {
        int isRemoved = remove("usrData/passphrase.bin");
        if (isRemoved == 0)
        {
            setIsLock(false);
            std::cout<<"Passphrase removed successfully";
            std::cout<<std::endl;
            
        }
        else
        {
            std::cout<<"Errors occured";
            std::cout<<std::endl;
            
        }
    }

    void showOptions()
    {
        clear_screen();
        int chosenOption;
        std::string availableOptions[2] = {"Setup Lock", "Delete Lock"};

        std::cout << "1. " << availableOptions[0] << std::endl;
        std::cout << "2. " << availableOptions[1] << std::endl;
        std::cout<<rang::bg::cyan<<"\nYour choice: "<<rang::bg::reset;
        std::cin>>chosenOption;

        if (chosenOption == 1)
        {
            clear_screen();
            setupLock();
        }
        else if (chosenOption == 2)
        {
            clear_screen();
            deleteLock();
        }
        else
        {
            clear_screen();
            std::cout<<"Invalid Option";
            std::cout<<std::endl;
        }
    }

    bool unlocker()
    {
        std::string givenPassphrase;
        int storedPassphrase;
        std::cout<<"Enter your passphrase: ";
        std::cin>>givenPassphrase;

        std::ifstream passReader ("usrData/passphrase.bin");

        passReader >> storedPassphrase;

        if (encrypt(givenPassphrase)==storedPassphrase)
        {
             return true;
        }
        else
        {
            clear_screen();
            std::cout<<"Wrong passphrase !!";
            return false;
        }
    }
};

#endif // S_LOCK_H