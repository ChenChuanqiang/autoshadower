// last modified 

#pragma once

#include <string>
#include "../helper/Webpage.h"
#include "Certificate.h"

using std::string;


class Fyhqy: public Webpage
{
    public:
        Fyhqy (Certificate::Mode mode, const string& url_test, const string& savas_path);
        virtual ~Fyhqy ();

    private:
        static const string fyhqy_url;
};

