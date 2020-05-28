
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

/*
	========
	= TODO =
	========

	To keep my Pastebin Developper Key for my own, I removed it from the shared source code.
	To compile the project, RENAME THIS FILE TO "data_devcode.h" :
	$ mv data_devcode_default.h data_devcode.h
	Then enter your Developper key on the #define DEVELOPPER_CODE line.
	To obtain one, just create an account on http://pastebin.com/ and then go to http://pastebin.com/api.
*/

#ifndef DEF_DATADEVCODE
#define DEF_DATADEVCODE

#define DEVELOPPER_CODE "" // TODO: Enter your Pastebin Developper Key here

#endif//DEF_DATADEVCODE

