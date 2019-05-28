// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

#include <string>
#include <iostream>
#include <sstream>
#include "MyUtils.h"
#include "CipherMenus.h"
#include "CipherBase.h"
#include "CaesarCipher.h"
#include "Rot13Cipher.h"
#include "Rot47Cipher.h"

using namespace std;

void displaySplashScreen(void);    // Look how pretty it is!
int displayMenuA(void);                    // Choose a cipher module
void displaySubmenu1(void);            // Caesar Cipher routines
void displaySubmenu2(void);            // ROT-13 Cipher routines
void displaySubmenu3(void);            // ROT-47 Cipher routines

// ==========================================================================================================

void CipherMenus::showMainMenu() {

    int choiceA = 0;

    displaySplashScreen();

    while (choiceA != 4) {

        choiceA = displayMenuA();

        cout << "\033[5B"; // DOWN 5 LINES

        // cin.clear();
        // cin.ignore(1000,'\n');

        switch (choiceA) {

            case 1:
                cout << "Menu item 1 selected." << endl;
                clearScreen();
                displaySubmenu1(); /* call Caesar Cipher submenu */
                // cin.clear();
                // cin.ignore(1000,'\n');
                break;

            case 2:
                cout << "Menu item 2 selected." << endl;
                clearScreen();
                displaySubmenu2(); /* call ROT-13 Cipher submenu */
                // cin.clear();
                // cin.ignore(1000,'\n');
                break;

            case 3:
                cout << "Menu item 3 selected." << endl;
                clearScreen();
                displaySubmenu3(); /* call ROT-47 Cipher submenu */
                // cin.clear();
                // cin.ignore(1000,'\n');
                break;

            case 4:
                cout << "Menu item 4 selected." << endl;
                /* quit menus and program */
                break;

            default:
                cout << "Invalid menu item selected." << endl;
                break;

        } // end switch statement

    } // end while loop

    return;
}

// ==========================================================================================================

void displaySplashScreen(void) {

    clearScreen();

    cout << "                                                               " << endl;
    cout << "      ██████╗██╗███████╗       ██╗███████╗██████╗              " << endl;
    cout << "     ██╔════╝██║██╔════╝      ███║╚════██║╚════██╗             " << endl;
    cout << "     ██║     ██║███████╗█████╗╚██║    ██╔╝ █████╔╝             " << endl;
    cout << "     ██║     ██║╚════██║╚════╝ ██║   ██╔╝  ╚═══██╗             " << endl;
    cout << "     ╚██████╗██║███████║       ██║   ██║  ██████╔╝             " << endl;
    cout << "      ╚═════╝╚═╝╚══════╝       ╚═╝   ╚═╝  ╚═════╝              " << endl;
    cout << "                                                               " << endl;
    cout << "      ██████╗██╗██████╗ ██╗  ██╗███████╗██████╗                " << endl;
    cout << "     ██╔════╝██║██╔══██╗██║  ██║██╔════╝██╔══██╗               " << endl;
    cout << "     ██║     ██║██████╔╝███████║█████╗  ██████╔╝               " << endl;
    cout << "     ██║     ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗               " << endl;
    cout << "     ╚██████╗██║██║     ██║  ██║███████╗██║  ██║               " << endl;
    cout << "      ╚═════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝               " << endl;
    cout << "                                                               " << endl;
    cout << "     ██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗" << endl;
    cout << "     ██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝" << endl;
    cout << "     ██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║   " << endl;
    cout << "     ██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║   " << endl;
    cout << "     ██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║   " << endl;
    cout << "     ╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝   " << endl;
    cout << "                                                               " << endl;
    cout << "     ┌┐ ┬ ┬  ╔═╗┬─┐┬┌─┐┌─┐  ╔═╗┬─┐┬ ┬┌─┐                       " << endl;
    cout << "     ├┴┐└┬┘  ║╣ ├┬┘││  ├─┤  ║  ├┬┘│ │┌─┘                       " << endl;
    cout << "     └─┘ ┴   ╚═╝┴└─┴└─┘┴ ┴  ╚═╝┴└─└─┘└─┘                       " << endl;
    cout << "      ┬   ╔╦╗┌─┐┌┬┐┌┬┐  ╔═╗┌┬┐┌┐ ┬─┐┌─┐┌─┐┌─┐                  " << endl;
    cout << "     ┌┼─  ║║║├─┤ │  │   ╠═╣│││├┴┐├┬┘│ │└─┐├┤                   " << endl;
    cout << "     └┘   ╩ ╩┴ ┴ ┴  ┴   ╩ ╩┴ ┴└─┘┴└─└─┘└─┘└─┘                  " << endl;
    cout << "                                                               " << endl;
    cout << "                                  ASCII FONTS FROM PATORJK.COM " << endl;
    cout << "                                                               " << endl;

    pressEnterToContinue("~");

    return;
}

// ==========================================================================================================

int displayMenuA(void) {

    int choice = 0;

    clearScreen();

    cout << " ███████████████████████████████████████████████   " << endl;
    cout << "██╔════════════════════════════════════════════██╗ " << endl;
    cout << "██║  ┌──────────────────────────────────────┐  ██║ " << endl;
    cout << "██║  │ SELECT ONE OF THE FOLLOWING OPTIONS: │  ██║ " << endl;
    cout << "██║  ├──────────────────────────────────────┤  ██║ " << endl;
    cout << "██║  │  1. Caesar Cipher                    │  ██║ " << endl;
    cout << "██║  ├──────────────────────────────────────┤  ██║ " << endl;
    cout << "██║  │  2. ROT-13 Cipher                    │  ██║ " << endl;
    cout << "██║  ├──────────────────────────────────────┤  ██║ " << endl;
    cout << "██║  │  3. ROT-47 Cipher                    │  ██║ " << endl;
    cout << "██║  ├──────────────────────────────────────┤  ██║ " << endl;
    cout << "██║  │  4. Quit Program                     │  ██║ " << endl;
    cout << "██║  └──────────────────────────────────────┘  ██║ " << endl;
    cout << "██║                                            ██║ " << endl;
    cout << "██║                                            ██║ " << endl;
    cout << "██║                                            ██║ " << endl;
    cout << "╚███████████████████████████████████████████████╔╝ " << endl;
    cout << " ╚══════════════════════════════════════════════╝  " << endl;
    cout << "      \033[4A";    // Move cursor straight up 4 lines (in column 7).

    choice = inputIntegerChoice("? ", 1, 4);

    return choice;
};

// ==========================================================================================================

void displaySubmenu1(void) {

    // cerr << "Entering _dSM1" << endl;

    cout << "\n";
    CaesarCipher cc = CaesarCipher();
    cout << "\n";

    string userInput;
    string encrypted;
    string decrypted;
    int newShift;

    bool doit = true;

    while (doit) {

        userInput = inputString("\nEnter a message to encrypt using the Caesar Cipher: ");
        newShift = inputInteger("\nEnter a shift number: ");

        encrypted = cc.Encrypt(userInput, newShift);

        cout << "\nMessage encrypted with a shift of +" << newShift << " : " << encrypted << endl;

        newShift *= -1;
        decrypted = cc.Encrypt(encrypted, newShift);

        cout << "\nMessage decrypted with a shift of " << newShift << " : " << decrypted << endl;

        doit = inputYNchoice("\n\nEncrypt/Decrypt another message? (y/n) ");

    }

    return;
}

// ==========================================================================================================

void displaySubmenu2(void) {

    // cerr << "Entering _dSM2" << endl;

    clearScreen();

    cout << "\n";
    Rot13Cipher cc = Rot13Cipher();
    cout << "\n";

    string userInput;
    string encrypted;
    string decrypted;
    int newShift = 13;

    bool doit = true;

    while (doit) {

        userInput = inputString("\nEnter a message to encrypt using ROT-13 cipher: ");
        // newShift is locked at +13 for ROT-13
        // newShift = inputInteger("Enter a shift number: ");

        encrypted = cc.Encrypt(userInput, newShift);

        cout << "\nMessage encrypted with a shift of +" << newShift << " : " << encrypted << endl;

        // newShift is locked at +13 for ROT-13
        // newShift *= -1;
        decrypted = cc.Encrypt(encrypted, newShift);

        cout << "\nMessage decrypted with a shift of +" << newShift << " : " << decrypted << endl;

        doit = inputYNchoice("\n\nEncrypt/Decrypt another message? (y/n) ");

    }

    return;
}

// ==========================================================================================================

void displaySubmenu3(void) {

    // cerr << "Entering _dSM3" << endl;

    cout << "\n";
    Rot47Cipher cc = Rot47Cipher();
    cout << "\n";

    string userInput;
    string encrypted;
    string decrypted;
    int newShift = 47;

    bool doit = true;

    while (doit) {

        userInput = inputString("\nEnter a message to encrypt using ROT-47 cipher: ");
        // newShift is locked at +13 for ROT-13
        // newShift = inputInteger("Enter a shift number: ");

        encrypted = cc.Encrypt(userInput, newShift);

        cout << "\nMessage encrypted with a shift of +" << newShift << " : " << encrypted << endl;

        // newShift is locked at +47 for ROT-47
        // newShift *= -1;
        decrypted = cc.Encrypt(encrypted, newShift);

        cout << "\nMessage decrypted with a shift of +" << newShift << " : " << decrypted << endl;

        doit = inputYNchoice("\n\nEncrypt/Decrypt another message? (y/n) ");

    }

    return;
}

// ==========================================================================================================
