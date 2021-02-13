#if !defined(S_LOCK_H)
#define S_LOCK_H

#include <iostream>
#include <fstream>
#include <bitset>

class S_Lock
{
private:
    bool isLock;
    std::string passphrase;

    // setter and getter
    void setPassphrase(std::string passphrase)
    {
        this->passphrase = passphrase;
    };
    std::string getPassphrase()
    {
        return passphrase;
    }

    bool getIsLock()
    {
        return isLock;
    }

public:
    //Methods
    int encrypt(std::string text)
    {
        int textToInt;
        for (int i = 0; i<text.size(); i++)
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
            }
            else
            {
                std::cout << "Unable to set passphrase. Error occured !";
            }
            std::cout << "Passphrase set :-)";
            std::cout << std::endl;
        }
    }

    /* void showOptions()
    {
        std::string availableOptions[2]={"Setup Lock", "Delete Lock"};

        // SHowing the setup lock option
        std::cout<<"1. "<<availableOptions[0]<<std::endl;
        if (isLockSetup() == true)
        {
            std::cout<<"2. "<<availableOptions[1]<<std::endl;
        }   
    } */
};

#endif // S_LOCK_H
