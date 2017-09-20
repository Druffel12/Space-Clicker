#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>

HANDLE hStdin;
DWORD fdwSaveOldMode;
int score = 0;
std::string Name;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
//VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

int main(VOID)
{
	std::cout << "                  eeeeeee   l       ccccccc  ooooooo                   eeeeeee " << std::endl;
	std::cout << " w              w e         l       c        o     o      m     m      e       " << std::endl;
	std::cout << "  w     ww     w  e         l       c        o     o     m m   m m     e       " << std::endl;
	std::cout << "   w   w  w   w   eeeee     l       c        o     o    m   m m   m    eeeee   " << std::endl;
	std::cout << "    w w    w w    e         l       c        o     o   m     m     m   e       " << std::endl;
	std::cout << "     w      w     eeeeeee   llllll  ccccccc  ooooooo  m             m  eeeeeee " << std::endl;
	std::cout << "===============================================================================" << std::endl;
	std::cout << "Enter Your Name " << std::endl;
	std::cin >> Name;
	std::cout << "hit e whenever you would like to quit" << std::endl;


	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 

	while (true)
	{
		// Wait for the events. 
		
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	


	return 0;
}

VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}
void ColorPicker(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void outputs()
{

	if (score == 10)
	{
		std::cout << "Welp ya gotta start somewhere" << std::endl;
	}
	else if (score == 12)
	{
		std::cout << "Hey my favorite number :D" << std::endl;
	}
	else if (score == 18)
	{
		std::cout << "Congrats your legal now" << std::endl;
	}
	else if (score == 21)
	{
		std::cout << "yay alchohol" << std::endl;
	}
	else if (score == 30)
	{
		std::cout << "there goes your hair" << std::endl;
	}
	else if (score == 42)
	{
		std::cout << "the answer to all" << std::endl;
	}
	else if (score == 69)
	{
		std::cout << "hehehehe" << std::endl;
	}
	else if (score == 88)
	{
		std::cout << "four circles" << std::endl;
	}
	else if (score == 99)
	{
		std::cout << "So close" << std::endl;
	}
	else if (score == 100)
	{
		std::cout << "there you go" << std::endl;
	}
	else if (score == 112)
	{
		std::cout << "its a bigger 12" << std::endl;
	}
	else if (score == 180)
	{
		std::cout << "Half way jk lol" << std::endl;
	}
	else if (score == 360)
	{
		std::cout << " fuckin no scoped bitch" << std::endl;
	}
	else if (score == 404)
	{
		std::cout << "ERROR 'System32' DELETED" << std::endl;
	}
	else if (score == 420)
	{
		std::cout << " what did u expect a weed joke you drugy" << std::endl;
	}
	else if (score == 500)
	{
		std::cout << "noice" << std::endl;
	}
	else if (score == 666)
	{
		std::cout << "SATAN!!!" << std::endl;
	}
	else if (score == 720)
	{
		std::cout << " double 360 no scope nerd!!" << std::endl;
	}
	else if (score == 314)
	{
		std::cout << "NERD!!!!" << std::endl;
	}
	else if (score == 999)
	{
		std::cout << "1 1/2 evil!!" << std::endl;
	}
	else if (score == 333)
	{
		std::cout << " 1/2 evil" << std::endl;
	}
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	//printf("Key event: ");


	if (ker.wVirtualKeyCode == VK_SPACE && ker.bKeyDown == false)
	{

		score++;
		printf("Mash that button!!\n");

	
		 
		if (score <= 1000000)
		{
			ColorPicker(28);
		}
		if (score <= 100000)
		{
			ColorPicker(12);
		}
		if (score <= 10000)
		{
			ColorPicker(13);
		}
		if (score <= 1000)
		{
			ColorPicker(14);
		}
		if (score <= 100)
		{
			ColorPicker(11);
		}
		if (score <= 10)
		{
			ColorPicker(10);
		}

		outputs();

		std::cout << score << std::endl;
	}


	else if (ker.uChar.AsciiChar == 'e' && ker.bKeyDown == false)
	{
		
		std::string Entry;

		std::fstream file;
		file.open("High Scores.txt");
		if (file.fail())
		{
			std::cerr << "Scores not found" << std::endl;
		}
	
		

		std::string buffer;
		while (std::getline(file, buffer))
		{

			std::cout << buffer << std::endl;
		}
			
		file.clear();
		file.seekp(0, std::ios_base::end);
	

		file << std::endl << Name<< ": " << score;

		file.flush();
			
		system("pause");
		file.close();
		exit(0);

	}
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	//printf("Mouse event: ");

	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			//printf("left button press \n");
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			//printf("right button press \n");
		}
		else
		{
			//printf("button press\n");
		}
		break;
	case DOUBLE_CLICK:
		//printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		//printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		//printf("mouse moved\n");
		break;
	case MOUSE_WHEELED:
		//printf("vertical mouse wheel\n");
		break;
	default:
		//printf("unknown\n");
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}