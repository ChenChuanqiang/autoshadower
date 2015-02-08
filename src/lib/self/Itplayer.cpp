// last modified 

#include "Itplayer.h"
#include <iostream>
#include <algorithm>
#include "../helper/Misc.h"
#include "../helper/RichTxt.h"

using namespace std;


const string Itplayer::itplayer_url("http://it-player.com/");

Itplayer::Itplayer (Certificate::Mode mode, const string& url_test, const string& savas_path)
    : Webpage(itplayer_url)
{
    if (!isLoaded()) {
        cerr << "ERROR! " << itplayer_url << " loaded failure. " << endl;
        return;
    }

    while (true) {
        static size_t start_pos = 0;
        
        
        // 提取证书中可字段
        const pair<string, size_t> pair_server = fetchStringBetweenKeywords( getTxt(),
                                                                             "服务器&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ",
                                                                             "<br>",
                                                                             start_pos );
        if (pair_server.first.empty()) {
            break;
        }
        start_pos = pair_server.second;
        const pair<string, size_t> pair_serverport = fetchStringBetweenKeywords( getTxt(),
                                                                                 "服务器端口&nbsp;&nbsp;&nbsp;",
                                                                                 "<br>",
                                                                                 start_pos );
        if (pair_serverport.first.empty()) {
            break;
        }
        start_pos = pair_serverport.second;
        const pair<string, size_t> pair_password = fetchStringBetweenKeywords( getTxt(),
                                                                               "href=\"http://daodaovps.taobao.com\">",
                                                                               "</a><br>",
                                                                               start_pos );
        if (pair_password.first.empty()) {
            break;
        }
        start_pos = pair_password.second;
        const pair<string, size_t> pair_method = fetchStringBetweenKeywords( getTxt(),
                                                                             "加密方式&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",
                                                                             "<br>",
                                                                             start_pos );
        if (pair_method.first.empty()) {
            break;
        }
        start_pos = pair_method.second;
        
        // 验证证书并保存至文件
        cout << "check certificate " << pair_server.first << endl;
        cout << ">>>>>>>>" << endl;
        Certificate cert_file( mode,
                               url_test,
                               pair_server.first,
                               pair_serverport.first, 
                               pair_password.first,
                               pair_method.first );
        if (cert_file.isAvailable()) {
            cert_file.saveas(savas_path);
            cout << RichTxt::foreground_green;
            cout << RichTxt::bold_on << "\\(^o^)/" << RichTxt::bold_off
                 << ". this SS certificate available. now you can issue SS proxy as follow: " << endl
                 << "\tsslocal -s \"" << pair_server.first << "\" -p " << pair_serverport.first
                 << " -k \"" << pair_password.first << "\" -b \"127.0.0.1\" -l 1080 -m \""
                 << pair_method.first << "\" -t 512" << endl;
            cout << RichTxt::reset_all;
        } else {
            cout << RichTxt::foreground_red;
            cout << RichTxt::bold_on << " ╮(╯▽╰)╭" << RichTxt::bold_off
                 << ". this SS certificate unavailable. " << endl;
            cout << RichTxt::reset_all;
        }
        cout << "<<<<<<<<" << endl << endl;
    }
}

Itplayer::~Itplayer ()
{
    ;
}

