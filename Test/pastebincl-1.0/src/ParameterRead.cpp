
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

#include "ParameterRead.h"

ParameterRead::ParameterRead(int i_argc, char** i_argv) : argc(i_argc), argv(i_argv) {}

void ParameterRead::addValueParam(std::string i_valueparam)
{
	/// adds a parameter name that requires a following value.
	valueparam.push_back(i_valueparam);
}


void ParameterRead::execute()
{
	/// Processes the parameters

	rawcount=0;
	for(int i=1;i<argc;++i)
	{
		bool incrementI=false;
		std::string argstr=argv[i];
		std::string rawarg="", value="";
		switch(getParamType(argstr))
		{
			case LONG_PARAM:
				value=getParamValue(argstr);
				if(hasValue(rawparam(argstr)))
				{
					if(value.empty())
						value=PARAMETER_MISSING;
					paramMap[rawparam(argstr)]=value;
				}
				else
				{
					paramMap[rawparam(argstr)]=(value.empty()) ? PARAMETER_NOVALUE : value;
				}
				break;
			case SHORT_PARAM:
				rawarg=rawparam(argstr);
				for(unsigned j=0;j<rawarg.size();j++)
				{
					if(hasValue(charToString(rawarg[j])))
					{
						value=PARAMETER_MISSING;
						if((unsigned)j==rawarg.size()-1)
						{
							if(i+1<argc && getParamType(std::string(argv[i+1]))==OTHER_PARAM)
							{
								value=argv[i+1];
								incrementI=true;
							}
						}
						paramMap[charToString(rawarg[j])]=value;
					}
					else
						paramMap[charToString(rawarg[j])]=PARAMETER_NOVALUE;
				}
				break;
			case OTHER_PARAM:
				paramMap[rawdatastr()]=std::string(argv[i]);
				rawcount++;
				break;
			default:
				// How the hell did we reach there?!
				break;
		}

		if(incrementI)
			i++;
	}
}

bool ParameterRead::isSet(std::string name)
{
	/// checks if a given parameter is set
	if(paramMap.find(name) != paramMap.end())
		return true;
	return false;
}

std::string ParameterRead::getValue(std::string name)
{
	/// returns the value of a parameter, if any is associated.
	ParameterMap::iterator it=paramMap.find(name);
	if(it==paramMap.end())
		throw -1;
	return (*it).second;
}

bool ParameterRead::isValueSet(std::string name, bool die)
{
	ParameterMap::iterator it=paramMap.find(name);
	if(it==paramMap.end() || (*it).second==PARAMETER_MISSING || (*it).second==PARAMETER_NOVALUE)
	{
		if(die)
			throw -1;
		return false;
	}
	return true;
}

bool ParameterRead::hasValue(std::string name)
{
	/// checks if a parameter requires a value (like -i inputfile, or --input=inputfile)
	for(unsigned i=0;i<valueparam.size();i++)
		if(valueparam[i]==name)
			return true;
	return false;
}

std::string ParameterRead::getRawParam(int count)
{
	/// returns the value of the "count" raw data parameter
	if(count>=rawcount)
		throw -1;
	std::ostringstream oss;
	oss << count;
	std::string label=PARAMETER_RAWBEGIN;
	label+=oss.str();
	label+=PARAMETER_RAWEND;
	return paramMap[label];
}

std::string ParameterRead::rawparam(std::string in)
{
	/// returns the "raw" parameter, eg. "input" instead of "--input=file/path.txt" or "la" instead of "-la"
	size_t found=0;
	switch(getParamType(in))
	{
		case SHORT_PARAM:
			in.erase(0,1); // erases the -
			break;
		case LONG_PARAM:
			in.erase(0,2); // erases the --
			found=in.find('=');
			if(found!=std::string::npos)
				in.erase(in.begin()+found, in.end());
			break;
		default:
			break;
	}
	return in;
}

ParameterRead::ParameterType ParameterRead::getParamType(std::string in)
{
	/// Checks the parameter type (long parameter, eg "--param", short, eg. "-i", or other)
	if(in.size()>0 && in[0]=='-')
	{
		if(in.size()>1 && in[1]=='-')
			return LONG_PARAM;
		return SHORT_PARAM;
	}
	return OTHER_PARAM;
}

std::string ParameterRead::getParamValue(std::string in)
{
	/// returns the value for a parameter of type LONG_PARAM, eg. "value" for "--parameter=value".
	if(getParamType(in)==LONG_PARAM)
	{
		size_t found=in.find("=");
		if(found!=std::string::npos)
		{
			in.erase(in.begin(), in.begin()+found+1);
			return in;
		}
	}
	return "";
}

std::string ParameterRead::rawdatastr()
{
	/// returns the "raw data string", which means the string line __RAWDATAx__ where x stands for "rawcount"
	std::ostringstream oss;
	oss << rawcount;
	return std::string(PARAMETER_RAWBEGIN)+oss.str()+PARAMETER_RAWEND;
}

std::string ParameterRead::charToString(char c)
{
	/// string::string() does not accept "char". So, let's convert a char to a std::string !
	std::string o="";
	o+=c;
	return o;
}

