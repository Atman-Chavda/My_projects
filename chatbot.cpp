#include <iostream>
#include<bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctime> // must include this header file to use time function

using namespace std;

// function to wish user according to time
void wishme()
{
    // current date  and time based on your system timezone
    time_t now = time(0);
    tm *time = localtime(&now);

    if (time->tm_hour < 12)
    {
        cout << "Good Morning Sir" << endl;
        string phrase = "Good Morning Sir";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }

    else if (time->tm_hour >= 12 && time->tm_hour <= 16)
    {
        cout << "Good Afternoon" << endl;
        string phrase = "Good Afternoon";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }

    else if (time->tm_hour > 16 && time->tm_hour < 24)
    {
        cout << "Good Evening Sir" << endl;
        string phrase = "Good Evening Sir";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }
}

void datetime()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The date and time is " << endl
         << dt << endl;
}

void speak(string phrase)
{
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
}

int main()
{
    system("cls");

    cout << "\t\t\t<======================================= W E L C O M E =====================================>" << endl;
    cout << "\t\t\t<====================================== IT'S A virtual quiz master=====================================>" << endl;
    cout << "\t\t\t<====================== I'M to ask you sime witty quiestion =======================>" << endl
         << endl;

    char password[20]; // to take password
    char ch[100];      // to take command from the user
    string s1;

    do
    {
        cout << "=======================" << endl;
        cout << "| ENTER YOUR PASSWORD |" << endl;
        cout << "=======================" << endl
             << endl;
        string phrase = "enter your password";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

        gets(password);

        STARTUPINFO startInfo = {0};
        PROCESS_INFORMATION processInfo = {0};

        if (strcmp(password, "1234") == 0)
        {
            cout << "\n<==================================================================================================>\n\n";
            wishme();
            do
            {
                cout << "\n<==================================================================================================>\n\n";
                cout << endl
                     << "How can I help you...." << endl
                     << endl;

                string phrase = "how can i help you ";
                string command = "espeak \"" + phrase + "\"";
                const char *charCommand = command.c_str();
                system(charCommand);

                cout << "Your query ===> ";
                gets(ch);
                cout << endl;
                cout << "Here is the result for your query ===> ";

                if (strcmp(ch, "hi") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0)
                {
                    cout << "Hello....." << endl;
                    s1 = "Hello";
                    speak(s1);
                }

                else if (strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0)
                {
                    cout << "Good Bye, have a nice day!!!!" << endl;
                    s1 = "Good Bye, have a nice day";
                    speak(s1);
                    exit(0);
                }

                else if (strcmp(ch, "who are you") == 0 || strcmp(ch, "tell me about yourself") == 0 || strcmp(ch, "about") == 0)
                {
                    cout << "I'm you quiz master!!!" << endl;
                    s1 = "I'm you quiz master";
                    speak(s1);
                }

                else if (strcmp(ch, "lets play") == 0)
                {
                    char a;
                    cout << "Get ready\n";
                    s1 = "get ready ";
                    speak(s1);
                    cout << "Queston 1: \n";
                    s1 = "question 1";
                    speak(s1);
                    cout << "What is 1+2: \n";
                    s1 = "what is 1+2";
                    speak(s1);
                    cout << "A. 3\n";
                    s1 = "option a 3";
                    speak(s1);
                    cout << "B. 4\n";
                    s1 = "option b 4";
                    speak(s1);
                    cout << "C. 5\n";
                    s1 = "option c 5";
                    speak(s1);
                    cout << "D. 6\n";
                    s1 = "option d 6";
                    speak(s1);
                    cin >> a;
                    if (a == 'a')
                    {
                        cout << "7 crore\n";
                        s1 = "saat crore";
                        speak(s1);
                    }
                    else
                    {
                        cout << "Galat javab:\n";
                        s1 = "galat javab";
                        speak(s1);
                    }

                    cout << "Queston 2: \n";
                    s1 = "question 2";
                    speak(s1);
                    cout << "How do plants make food: \n";
                    s1 = "how do plants make food";
                    speak(s1);
                    cout << "A. They don't\n";
                    s1 = "option a they don't";
                    speak(s1);
                    cout << "B. Photosynthesis\n";
                    s1 = "option b photosynthesis";
                    speak(s1);
                    cout << "C. They zomato it\n";
                    s1 = "option c they zomato it";
                    speak(s1);
                    cout << "D. They are so sad that thay dont feel like eating\n";
                    s1 = "option d they are so sad that thay dont feel like eating";
                    speak(s1);
                    cin >> a;
                    if (a == 'b')
                    {
                        cout << "7 crore";
                        s1 = "7 crore";
                        speak(s1);
                    }
                    else if (a == 'd')
                    {
                        cout << "bhai plants ka to pata nahi par mera to aisa hi hai\n";
                        s1 = "bhai plants ka to pata nahi par mera to aisa hi hai";
                        speak(s1);
                    }
                    else
                    {
                        cout << "Galat javab:\n";
                        s1 = "galat javab";
                        cout << "Aap gir gaye 5 lakh pe\n";
                        s1 = "aap gir gaye 5 lakh pe";
                        speak(s1);
                    }
                }

                else
                {
                    cout << "Sorry could not understand your query please ty again !!!" << endl;
                    s1 = "Sorry could not understand your query please ty again ";
                    speak(s1);
                }

            } while (1);
        }
        else
        {
            system("cls");

            cout << "\t\t\t<======================================= W E L C O M E =====================================>" << endl;
            cout << "\t\t\t<====================================== IT'S A CHATBOT =====================================>" << endl;
            cout << "\t\t\t<================================= MY NAME IS CHATGPT LITE =================================>" << endl;
            cout << "\t\t\t<====================== I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =======================>" << endl
                 << endl;

            cout << "======================" << endl;
            cout << "X Incorrect Password X" << endl;
            cout << "======================" << endl
                 << endl;
            string phrase = "Incorrect Password, Please enter correct password";
            string command = "espeak \"" + phrase + "\"";
            const char *charCommand = command.c_str();
            system(charCommand);
        }
    } while (1);

    return 0;
}