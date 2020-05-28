
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

#ifndef DEF_PARAMETERREAD
#define DEF_PARAMETERREAD

#include <map>
#include <vector>
#include <string>
#include <sstream>

#define PARAMETER_MISSING "__MISSING__"
#define PARAMETER_NOVALUE "__NOVALUE__"

#define PARAMETER_RAWBEGIN "__RAWDATA"
#define PARAMETER_RAWEND "__"

typedef std::map<std::string, std::string> ParameterMap;

class ParameterRead
{
	public:
		enum ParameterType {
			SHORT_PARAM, LONG_PARAM, OTHER_PARAM
		};

		ParameterRead(int i_argc, char** i_argv);
		void setValueParam(std::vector<std::string> i_valueparam) { valueparam=i_valueparam; };
		void addValueParam(std::string i_valueparam);

		void execute();

		ParameterMap getMap() const { return paramMap; }
		bool isSet(std::string name);
		std::string getValue(std::string name);
		bool isValueSet(std::string name, bool die=false);
		bool hasValue(std::string name);

		int rawParamCount() const { return rawcount; };
		std::string getRawParam(int count);

	protected: //meth
		std::string rawparam(std::string in);
		ParameterType getParamType(std::string in);
		std::string getParamValue(std::string in);
		std::string rawdatastr();

		std::string charToString(char c);
		
	protected:
		ParameterMap paramMap;
		std::vector<std::string> valueparam;
		int argc;
		char** argv;
		int rawcount;
};

#endif//DEF_PARAMETERREAD

