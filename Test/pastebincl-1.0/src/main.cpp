
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

#include "CurlPost.h"
#include "data.h"
#include "func.h"
#include "ParameterRead.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{

	try {
		ParameterRead pr(argc,argv);
		unsigned parameterFlags=0;

		if(!initParameterRead(pr, parameterFlags))
		{
			std::cerr << "FATAL ERROR: Bad parameters. See pastebincl -h for more help." << std::endl;
			throw 42;
		}

		if(parameterFlags & P_LICENCE)
			showLicence();
		else if(parameterFlags & P_HELP)
			showHelp();
		else if(parameterFlags & P_VERSION)
			showVersion();
		else if(parameterFlags & P_SYNTAXLIST)
			showSyntaxList();
		else if(parameterFlags & P_USERGEN)
		{
			if(userGen())
				std::cout << "Configuration file generated!" << std::endl;
			else
				std::cerr << "An error occured while writing configuration file. FAIL." << std::endl;
		}
		else
		{
			// Here we start real stuff!
			CurlPost::init();
			
			CurlPost* request=preparePostRequest(parameterFlags, pr, getPasteContent());

			std::cout << "Submitting paste..." << std::endl;

			std::string result=request->execute();
			delete request;

			if(result.find("http://pastebin.com/") == 0) // SUCCESS !
			{
				std::cout << "Paste submitted successfully!" << std::endl
						<< "URL: " << result << std::endl;
			}
			else
			{
				std::cerr << "ERROR: Pastebin.com returned an error to your request." << std::endl
						<< "Message: " << result << std::endl;
			}
			
			CurlPost::clean();
	
		}
	}
	catch(...) {
		std::cerr << "Exception catched. Program is terminating." << std::endl;
	}
	
	return 0;
}

