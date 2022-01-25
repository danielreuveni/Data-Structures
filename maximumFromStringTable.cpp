#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;
 
int main()
{
    std::string str = "A,B,C,D\n1,2,3\n4,5,6\n7,8,9";
    std::vector<std::pair<std::string, std::vector<float>>> info;
    std::string row, col;
    float val;
    std::stringstream string_stream(str);


    while (std::getline(string_stream, row, '\n')){
        info.push_back({row, std::vector<float>{}});
    }

    for (int i = 1; i < info.size(); i++) {
        stringstream string_stream2 (info[i].first);
            while (string_stream2 >> val) {
                info.at(i).second.push_back(val);
                    if(string_stream2.peek() == ',') {
                        string_stream2.ignore();
            }
        }  
    

    }
    std::string str2 = info[0].first;
    std::stringstream string_stream3(str2);
    int j = 0;
    while (string_stream3.good()) {
        string substr;
        getline(string_stream3, substr, ',');
        info[j].first = substr;
        cout << info[j].first << endl;
        j++;
    }
    float max_array[info.size()];
    for (int i = 1; i < info.size(); i++) {
        float max = 0;
        for (int j = 0; j < info[i].second.size(); j++) {
            if (info[i].second[j] >= max) {
                max = info[i].second[j];
            }
        }
        max_array[i] = max;
        //cout << info[2].first << endl;
        cout << max_array[i] << " ";
        
    }

    return 0;
}