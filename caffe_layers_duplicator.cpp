#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  string input_file_path, output_file_path, current_line;
  fstream input_file, output_file;
  map<string, int> layer_types;
  vector<pair<int, int>> change_values;
  vector<string> input_contents;
  cout << "Enter the input file path : " << endl;
  cin >> input_file_path;
  cout << "Enter the output file path : " << endl;
  cin >> output_file_path;
  input_file.open(input_file_path.c_str(), ios::in);
  output_file.open(output_file_path.c_str(), ios::out);
  if (!input_file || !output_file) {
    cout << "Error in opening input and/or output files" << endl;
    return 1;
  }
  int i = 0;
  while (getline(input_file, current_line)) {
    input_contents.push_back(current_line);
    cout << "Read : " << current_line << endl;
    int index_name = current_line.find("name: ");
    int index_top = current_line.find("top: ");
    int index_bottom = current_line.find("bottom: ");
    int end_index;
    if (index_name != string::npos) {
      index_name += 7;
      end_index = index_name;
    } else if (index_top != string::npos) {
      index_top += 6;
      end_index = index_top;
    } else if (index_bottom != string::npos) {
      index_bottom += 9;
      end_index = index_bottom;
    } else {
      i++;
      continue;
    }
    while (end_index < current_line.size() && current_line[end_index] != '\"') {
      end_index++;
    }
    change_values.push_back(make_pair(i, end_index));
    i++;
  }
  int number_of_times;
  cout << "Enter the amount by which to duplicate : " << endl;
  cin >> number_of_times;
  int current_marker = 0;
  for (int i = 1; i <= number_of_times; i++) {
    current_marker = 0;
    for (int j = 0; j < input_contents.size(); j++) {
      if (current_marker < change_values.size() &&
          change_values[current_marker].first == j) {
        int index_in_line = change_values[current_marker].second;
        output_file << input_contents[j].substr(0, index_in_line);
        output_file << i;
        output_file << "\"" << endl;
        current_marker++;
      } else {
        output_file << input_contents[j] << endl;
      }
    }
  }
  cout << "Completed writing to output file" << endl;
  input_file.close();
  output_file.close();
  return 0;
}
