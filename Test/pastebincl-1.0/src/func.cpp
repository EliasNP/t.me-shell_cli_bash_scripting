
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

#include "func.h"

bool initParameterRead(ParameterRead& pr, unsigned& flags)
{
	pr.addValueParam("n");
	pr.addValueParam("name");
	pr.addValueParam("s");
	pr.addValueParam("syntax");
	pr.addValueParam("e");
	pr.addValueParam("expire");

	pr.execute();

	if(!checkParameterRead(pr, flags))
		return false;
	return true;
}

bool checkParameterRead(ParameterRead& pr, unsigned& flags)
{
	try {
		if(pr.isSet("licence"))
		{
			flags=P_LICENCE;
			return true;
		}
		if(pr.isSet("h") || pr.isSet("?") || pr.isSet("help"))
		{
			flags=P_HELP;
			return true;
		}
		if(pr.isSet("usergen"))
		{
			flags=P_USERGEN;
			return true;
		}
		if(pr.isSet("v") || pr.isSet("version"))
		{
			flags=P_VERSION;
			return true;
		}
		if(pr.isSet("syntaxlist"))
		{
			flags=P_SYNTAXLIST;
			return true;
		}
		if((pr.isSet("n") && pr.isValueSet("n", true)) || (pr.isSet("name") && pr.isValueSet("name", true)))
			flags+=P_NAME;
		if((pr.isSet("s") && pr.isValueSet("s", true)) || (pr.isSet("syntax") && pr.isValueSet("syntax", true)))
			flags+=P_SYNTAX;
		if((pr.isSet("e") && pr.isValueSet("e", true)) || (pr.isSet("expire") && pr.isValueSet("expire", true)))
			flags+=P_EXPIRE;
		if(pr.isSet("p") || pr.isSet("private"))
			flags+=P_PRIVATE;
		if(pr.isSet("g") || pr.isSet("guest"))
			flags+=P_GUEST;
	}
	catch(const int& e) {
		return false;
	}

	return true;
}

void showLicence()
{
	std::cout << std::endl <<
		"Copyright (C) 2011 Théophile BASTIAN (aka. Tobast) " << std::endl <<
		"This program is free software: you can redistribute it and/or modify " << std::endl <<
		"it under the terms of the GNU General Public License as published by " << std::endl <<
		"the Free Software Foundation, either version 3 of the License, or " << std::endl <<
		"(at your option) any later version. " << std::endl <<
		std::endl <<
		"This program is distributed in the hope that it will be useful, " << std::endl <<
		"but WITHOUT ANY WARRANTY; without even the implied warranty of " << std::endl <<
		"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the " << std::endl <<
		"GNU General Public License for more details. " << std::endl <<
		std::endl <<
		"You should have received a copy of the GNU General Public License " << std::endl <<
		"along with this program.  If not, see http://www.gnu.org/licenses/gpl.txt." << std::endl << std::endl;
}
void showHelp()
{
	std::cout << MANPAGE_SHORT << std::endl;
}
void showVersion()
{
	std::cout << std::endl
		<< "pastebincl by BASTIAN Théophile (aka Tobast) v" << SOFT_VERSION << std::endl
		<< "Contact: <contact@tobast.fr> or contact feature at http://tobast.fr/" << std::endl
		<< "Error report: <error-report@tobast.fr>" << std::endl << std::endl;
}
void showSyntaxList()
{
	std::cout << SYNTAX_LIST << std::endl;
}

bool userGen()
{
	std::string user="", pass="";
	std::cout << "Enter your nickname: \t";
	std::cin >> user;
	std::cin.ignore();

	std::cout << "Enter your password (willn't be displayed, type it blindly ; 128 char max): \t";
	echoInput(false);
	char passc[128];
	std::cin.getline(passc, 128);
	pass=passc;
	echoInput(true);

	std::cout << std::endl;

	return ConfigRead::writeConf(user, pass, getConfigPath());
}

CurlPost* preparePostRequest(const unsigned& flags, ParameterRead& pr, std::string pasteContent)
{
	CurlPost* request=new CurlPost(PASTEBIN_SUBMIT_URL);

	if(flags & P_NAME)
	{
		if(pr.isSet("n"))
			request->setPostData("api_paste_name", pr.getValue("n"));
		else if(pr.isSet("name"))
			request->setPostData("api_paste_name", pr.getValue("name"));
	}
	else
		request->setPostData("name", DEFAULT_NAME);

	if(flags & P_SYNTAX)
	{
		if(pr.isSet("s"))
			request->setPostData("api_paste_format", pr.getValue("s"));
		else if(pr.isSet("syntax"))
			request->setPostData("api_paste_format", pr.getValue("syntax"));
	}

	if(flags & P_PRIVATE)
		request->setPostData("api_paste_private", "1");
	else
		request->setPostData("api_paste_private", DEFAULT_PRIVATE);

	if(flags & P_EXPIRE)
	{
		if(pr.isSet("e"))
			request->setPostData("api_paste_expire_date", pr.getValue("e"));
		else if(pr.isSet("expire"))
			request->setPostData("api_paste_expire_date", pr.getValue("expire"));
	}
	else
		request->setPostData("api_paste_expire_date", DEFAULT_EXPIRE);

	if(!(flags & P_GUEST))
	{
		std::string usercode=getUserCode();
		if(!usercode.empty())
			request->setPostData("api_user_key", usercode);
	}

	request->setPostData("api_paste_code", pasteContent);
	request->setPostData("api_dev_key", DEVELOPPER_CODE);
	request->setPostData("api_option", "paste");

	return request;
}

std::string getUserCode()
{
	try {
		ConfigRead cr(getConfigPath());

		CurlPost* request=new CurlPost(PASTEBIN_USERCODE_URL);

		request->setPostData("api_dev_key", DEVELOPPER_CODE);
		request->setPostData("api_user_name", cr.getUser());
		request->setPostData("api_user_password", cr.getPass());

		std::string result=request->execute();

		delete request;

		if(result.find("Bad API request") != std::string::npos) // FAIL!
		{
			std::cerr << result << std::endl;
			throw -1;
		}

		return result;
	}
	catch(const int& e) {
		if(e==-42) // Couldn't open file, let's assume no password was set
			std::cerr << "Warning: couldn't open file " << getConfigPath() << ". Run 'pastebincl --usergen' to be able to post as a registered user." << std::endl;
	}
	return "";
}

std::string getPasteContent()
{
	std::string outstr;

	if(!std::cin.eof())
	{
		while(1)
		{
			char c=std::cin.get();
			if(std::cin.eof())
				break;
			outstr+=c;
		}
	}
	else
	{
		while(1)
		{
			std::string tmp;
			std::cin >> tmp;
			outstr+=tmp;
			if(tmp.find(-1) != std::string::npos) // found a ^D
				break;
		}
	}

	return outstr;
}

inline std::string getConfigPath()
{
	std::string outpath;

#if defined(UNIX)
	outpath=getpwuid(getuid())->pw_dir;
	outpath+="/";
#elif defined(WINDOwS)
	outpath="C:/Documents and Settings/";

	char username[100];
	DWORD nUsername=sizeof(username);
	if(!GetUserName(username, &nUsername))
		outpath+="All Users";	
	else
		outpath+=username;
	outpath+="/Application Data/";
#endif

	outpath+=DEFAULT_CONFIGPATH;

	return outpath;
}

void echoInput(bool echo)
{
#ifdef UNIX
	struct termios settings;
	tcgetattr( STDIN_FILENO, &settings );
	settings.c_lflag = echo
		? (settings.c_lflag |   ECHO )
		: (settings.c_lflag & ~(ECHO));
	tcsetattr( STDIN_FILENO, TCSANOW, &settings );
#elif defined(WINDOWS)
	DWORD  mode;
	HANDLE hConIn = GetStdHandle( STD_INPUT_HANDLE );
	GetConsoleMode( hConIn, &mode );
	mode = echo
		? (mode |   ENABLE_ECHO_INPUT )
		: (mode & ~(ENABLE_ECHO_INPUT));
	SetConsoleMode( hConIn, mode );
#endif
}

