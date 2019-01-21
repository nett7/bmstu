//============================================================================
// Name        : lab-05-filesystem-yokkidack
// Author      : yokki
// Version     :
// Copyright   : Igor Roshchin mosgreyday@gmail.com
// Description : lab-05-filesystem-yokkidack
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <boost/filesystem.hpp>
#include <boost/lambda/bind.hpp>

struct note{
    std::string brok;
    std::vector<std::string> files;
};
using namespace std;
using namespace boost::filesystem;
int main(int argc, char * argv[]) {
    std::string path_to_ftp;
    if (argc == 2)
    {
        path_to_ftp = argv[1];
    }else{
        path_to_ftp =
    "/home/yokkidack/labs/lab-05-filesystem-yokkidack/misc/ftp/";
    }
    std::vector<path> pathes;
    std::vector<std::string> brok;
    size_t pos_o_ftp = path_to_ftp.find("ftp") + 4;
    const path p{path_to_ftp};
    for (const directory_entry& x : directory_iterator{p})// dir bypass
    {
        pathes.push_back(x.path());
        std::string temp = x.path().string();
        temp = temp.substr(pos_o_ftp);
        brok.push_back(temp);
    }
    std::vector<note> data;
    // dirs in dir bypass (files)
    for (unsigned int i = 0; i < pathes.size(); i++) {
        int count = 0;
        std::vector<std::string> accs;
        std::vector<int> counts;
        std::vector<std::string> last_dates;
        std::vector<std::string> files;
        bool there_are_files = false;
        for (const directory_entry& x : directory_iterator{pathes[i]})
        {
            std::string temp = x.path().string();
            if (temp.find('_') == std::string::npos) there_are_files = true;
            if ((temp.find(".old") == std::string::npos)
                &&(temp.find("balance") != std::string::npos)) {
                std::string name = x.path().stem().string().substr(8);
                files.push_back(x.path().filename().string());
                int temp_flag = -1;
                std::string ac = name.substr(0, 8);
                std::string date = name.substr(9);
                for (size_t j = 0; j < accs.size(); j++) {
                    if (accs[j] == ac) {
                        temp_flag = j;
                        counts[j]++;
                        if (last_dates[j] < date) last_dates[j] = date;
                        break;
                    }
                }
                if (temp_flag == -1)
                {
                    accs.push_back(ac);
                    counts.push_back(1);
                    last_dates.push_back(date);
                }
                count++;
            }
        }
        if (there_are_files)
        {
            for (size_t j = 0; j < accs.size(); j++) {
                std::cout <<brok[i] << " acc: " << accs[j]
                << " files: " << counts[j] << " last: " 
                << last_dates[j] <<std::endl;
            }
            note a = {brok[i], files};
            data.push_back(a);
        }
    }
    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j< data[i].files.size(); j++) {
            std::cout << data[i].brok << " " << data[i].files[j] << endl;
        }
    }
}
