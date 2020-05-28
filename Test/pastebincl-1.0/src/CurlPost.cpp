
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

CurlPost::CurlPost() {}
CurlPost::CurlPost(PostMap i_postmap) : postmap(i_postmap) {}
CurlPost::CurlPost(std::string i_url, PostMap i_postmap) : url(i_url), postmap(i_postmap) {}

std::string CurlPost::execute()
{
	// defining data structures
	CURL *curl;
	CURLcode res;
	std::string output;

	struct curl_httppost *formpost=NULL, *formlast=NULL;
	struct curl_slist *headers=NULL;

	// defining the POST forms list
	for(std::map<std::string,std::string>::iterator it=postmap.begin();it!=postmap.end();++it)
	{
		curl_formadd(&formpost, &formlast,
				CURLFORM_COPYNAME, (*it).first.c_str(),
				CURLFORM_COPYCONTENTS, (*it).second.c_str(),
				CURLFORM_END);
	}

	// CURL init
	curl=curl_easy_init();
	headers=curl_slist_append(headers, "Expect:");

	if(curl)
	{
		// options setting
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, postRequest_callbackReadout);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

		// begin request
		res=curl_easy_perform(curl);
		
		// cleaning up
		curl_easy_cleanup(curl);
		curl_formfree(formpost);
		curl_slist_free_all(headers);

		// error handling
		if(res!=0)
			throw (int)res;
	}

	return output;
}

void CurlPost::init()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

void CurlPost::clean()
{
	curl_global_cleanup();
}

size_t postRequest_callbackReadout(char* ptr, size_t size, size_t nmemb, void* i_userdata)
{
	// Here, we'll assume that ptr is a char string
	if(size*nmemb!=0)
	{
		std::string *userdata=(std::string*)i_userdata;
		for(unsigned i=0;i<size*nmemb;i++)
			(*userdata)+=ptr[i];
	}
	return size*nmemb;
}

