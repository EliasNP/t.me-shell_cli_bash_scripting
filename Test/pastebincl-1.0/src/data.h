
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

#ifndef DEF_DATA
#define DEF_DATA

#include "data_devcode.h" // TODO before compile, check this file
#include "data_paramlist.h"

// TODO REDEFINE YOUR OS HERE!
#define UNIX
// #define WINDOWS

#define DEFAULT_PRIVATE "0"
#define DEFAULT_NAME ""
#define DEFAULT_EXPIRE "N"
#define DEFAULT_FORMAT ""
#define DEFAULT_USERKEY ""
#define DEFAULT_OPTION "paste"

#define PASTEBIN_SUBMIT_URL "http://pastebin.com/api/api_post.php"
#define PASTEBIN_USERCODE_URL "http://pastebin.com/api/api_login.php"

#define DEFAULT_CONFIGPATH ".pastebinclrc"

enum FlagParameter {
	P_NAME=1, P_SYNTAX=2, P_PRIVATE=4, P_EXPIRE=8, P_GUEST=16, P_HELP=32, P_VERSION=64, P_LICENCE=128, P_USERGEN=256, P_SYNTAXLIST=512
};

#define SOFT_VERSION "0.1 INDEV"

#define MANPAGE_SHORT "\n"\
	"Pastebincl is a software designed to submit pastes on http://pastebin.com/ using the command-line. To see the full manpage, type \"man pastebincl\" (UNIX-like OS).\n"\
	"\n"\
	"Arguments:\n"\
	" -v, --version \n"\
	"     => displays the current version and basic informations.\n"\
	" -h, -?, --help\n"\
	"     => displays this text (but, logically, you already knew it).\n"\
	" --licence \n"\
	"     => displays the program licence.\n"\
	" --usergen\n"\
	"     => generates an encrypted user file to allow you to post as a registered pastebin user.\n"\
	" -n [name], --name=[name]\n"\
	"     => sets [name] as the paste name.\n"\
	" -s [syntax], --syntax=[syntax]\n"\
	"     => sets [syntax] as the paste syntax.\n"\
	" --syntaxlist\n"\
	"     => Displays the full list of -s possible arguments.\n"\
	" -e [expire_time], --expire=[expire_time]\n"\
	"     => sets [expire_time] as the paste expiration time.\n"\
	" -p, --private\n"\
	"     => posts the paste as a \"private\" one.\n"\
	" -g, --guest\n"\
	"     => posts the paste without using the account set with --usergen.\n"

#endif//DEF_DATA

