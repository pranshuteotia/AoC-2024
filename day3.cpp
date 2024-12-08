#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>

size_t part_1(const std::string &input);
size_t part_2(const std::string &input);
size_t calculate_result(const std::string &s);
bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b);

int main() {
  std::string s;
  std::string input;

  while(std::getline(std::cin, s)) {
    input += s;
  }

  std::cout << "Part 1: " << part_1(input) << std::endl;
  std::cout << "Part 2: " << part_2(input) << std::endl;
}

size_t part_1(const std::string &input) {
  return calculate_result(input);
}

size_t calculate_result(const std::string &s) {
  size_t result = 0;
  std::regex mult("mul\\(([0-9]+),([0-9]+)\\)");

  auto begin = std::sregex_iterator(s.begin(), s.end(), mult);
  auto end = std::sregex_iterator();

  for(auto i=begin; i != end; ++i) {
    size_t num1 = std::stoi((*i).str(1));
    size_t num2 = std::stoi((*i).str(2));

    result += num1 * num2;
  }

  return result;
}

size_t part_2(const std::string &input) {
  size_t sum=0;
  std::vector<std::pair<int, int>> v = {{0, 1}};


  auto pos = input.find("don\'t()", 0);
  while(pos != std::string::npos) {
    v.push_back({pos, 0});
    pos = input.find("don\'t()", pos+1);
  }

  pos = input.find("do()", 0);
  while(pos != std::string::npos) {
    v.push_back({pos, 1});
    pos = input.find("do()", pos+1);
  }

  std::sort(v.begin(), v.end(), comp);

  if (v.back().second == 1)
    v.push_back({input.length(), 0});

  std::vector<std::pair<int, int>> vf = {v[0]};
  for(size_t i=1; i<v.size(); ++i) {
    auto prev = v[i-1];
    auto curr = v[i];

    if (prev.second != curr.second)
      vf.push_back(curr);
  }

  for(size_t i=0; i<vf.size()-1; i+=2) {
    size_t start = vf[i].first, end = vf[i+1].first - start;
    sum += calculate_result(input.substr(start, end));
  }
  
  return sum;
}

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;

  return a.first < b.first;
}
