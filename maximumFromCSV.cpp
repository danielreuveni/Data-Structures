#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;
 
int main()
{
    const char* file_name = "trainFile.csv";
    std::ifstream fin;
    fin.open(file_name);
    std::vector<std::pair<std::string, std::vector<float>>> info;
    std::string row, col;
    float val;
    std::getline(fin, row);
    std::stringstream string_stream(row);
    while(std::getline(string_stream, col, ',')){
    info.push_back({col, std::vector<float>{}});
    }
    while (std::getline(fin, row))
    {
        std::stringstream string_stream1(row);
        int index = 0;
        while(string_stream1 >> val)
        {
            info.at(index).second.push_back(val);
            if(string_stream1.peek() == ','){
                string_stream1.ignore();
            }
            index++;
        }
    }
    float max_array[info.size()];
    for (int i = 0; i < info.size(); i++) {
        float max = 0;
        for (int j = 0; j < info[i].second.size(); j++) {
            if (info[i].second[j] >= max) {
                max = info[i].second[j];
            }
        }
        max_array[i] = max;
        cout << max_array[i] << " ";
    }



    return 0;
}