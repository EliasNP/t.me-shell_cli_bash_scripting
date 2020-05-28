
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

#include "ConfigRead.h"

using namespace std;

ConfigRead::ConfigRead(string filepath)
{
	ifstream infile(filepath.c_str(), ios_base::in);
	if(!infile)
		throw -42; // ANTI-ANSWER!!!1
	
	string filecontent=unxor(infile);

	unsigned findpos;

	user=filecontent;
	findpos=user.find("\n");
	if(findpos!=string::npos)
		user.erase(user.begin()+findpos, user.end());

	pass=filecontent;
	findpos=pass.find("\n");
	if(findpos!=string::npos)
		pass.erase(pass.begin(), pass.begin()+findpos+1);

	infile.close();
}

bool ConfigRead::writeConf(std::string user, std::string pass, std::string filepath)
{
	ofstream outfile(filepath.c_str(), ios_base::out | ios_base::trunc);
	if(!outfile)
		return false;
	
	string key=ENCODING_KEY, input=user+"\n"+pass;
	
	for(unsigned i=0, j=0; j<input.size(); i++, j++)
	{
		if(i>=key.size())
			i=0;
		char c=input[j]^key[i];
		outfile.put(c);
	}

	return true;
}

std::string ConfigRead::unxor(ifstream& infile)
{
	string key=ENCODING_KEY, output="";

	for(unsigned i=0; !infile.eof(); i++)
	{
		if(i>=key.size())
			i=0;
		char c=infile.get();
		if(infile.good())
			output+= c ^ key[i];
	}

	return output;
}

