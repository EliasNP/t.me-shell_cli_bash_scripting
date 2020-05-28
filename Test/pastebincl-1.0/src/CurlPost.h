
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

#ifndef DEF_CURLPOST
#define DEF_CURLPOST

#include <string>
#include <map>
#include <curl/curl.h>

typedef std::map<std::string,std::string> PostMap;

class CurlPost {
	public:
		CurlPost();
		CurlPost(PostMap i_postmap);
		CurlPost(std::string i_url, PostMap i_postmap=PostMap());

		std::string getUrl() const { return url; }
		void setUrl(const std::string& i) { url=i; }
		
		PostMap getPostmap() const { return postmap; }
		void setPostmap(PostMap i) { postmap=i; }
		void setPostData(const std::string &a, const std::string &b) { postmap[a]=b; }

		std::string execute();

		static void init();
		static void clean();

	protected:
		std::string url;
		PostMap postmap;
};

size_t postRequest_callbackReadout(char* ptr, size_t size, size_t nmemb, void* i_userdata);

#endif//DEF_CURLPOST

