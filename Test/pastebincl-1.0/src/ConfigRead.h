
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

#ifndef DEF_CONFIGREAD
#define DEF_CONFIGREAD

#include <string>
#include <fstream>
#include "data.h"

class ConfigRead
{
	public:
		ConfigRead(std::string filepath=DEFAULT_CONFIGPATH);
		static bool writeConf(std::string user, std::string pass, std::string filepath=DEFAULT_CONFIGPATH);

		std::string getUser() const { return user; }
		std::string getPass() const { return pass; }

	protected: //meth
		std::string unxor(std::ifstream& infile);
	
	protected:
		std::string user;
		std::string pass;
};

#endif//DEF_CONFIGREAD

