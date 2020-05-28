
/*
 * PROGRAM:
 *   Command-line pastebin
 *
 * AUTHOR:
 *   Théophile BASTIAN (a.k.a. Tobast)
 *
 * CONTACT & WEBSITE:
 *   http://tobast.fr/ (contact feature included)
 *   error-report@tobast.fr (error reporting only)
 *
 * SHORT DESCRIPTION:
 *   See first license line.
 *
 * LICENSE:
 *   "Command-line pastebin" is a software designed to submit a "paste" on http://pastebin.com/ using a command-line tool
 *   Copyright (C) 2011  Théophile BASTIAN
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see http://www.gnu.org/licenses/gpl.txt.
*/

#ifndef DEF_FUNCTION
#define DEF_FUNCTION

#include <iostream>
#include <string>
#include "ParameterRead.h"
#include "CurlPost.h"
#include "data.h"
#include "ConfigRead.h"

#ifdef UNIX
	#include <termios.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <pwd.h>
#elif defined(WINDOWS)
	#include <windows.h>
#endif

bool initParameterRead(ParameterRead& pr, unsigned& flags);
bool checkParameterRead(ParameterRead& pr, unsigned& flags);

void showLicence();
void showHelp();
void showVersion();
void showSyntaxList();

bool userGen();

CurlPost* preparePostRequest(const unsigned& flags, ParameterRead& pr, std::string pasteContent);

std::string getUserCode();
std::string getPasteContent();
inline std::string getConfigPath();

void echoInput(bool echo=true);

#endif//DEF_FUNCTION

