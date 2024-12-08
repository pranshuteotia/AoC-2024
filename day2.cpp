// Advent of Code (2024) Day 2

#include <iostream>
#include <vector>
#include <sstream>

bool is_increasing(const std::vector<int> &list);
bool is_decreasing(const std::vector<int> &list);
std::vector<int> modify_list(const std::vector<int> &list, const size_t &index);

size_t part_1(const std::vector<std::vector<int>> &lists);
size_t part_2(const std::vector<std::vector<int>> &lists);

int main() {
  std::vector<std::vector<int>> lists;
  std::string s;
  while(std::getline(std::cin, s)) {
    std::vector<int> list;
    std::istringstream is(s);
    int n;
    while (is >> n)
      list.push_back(n);
    
    lists.push_back(list);
  }
    
  std::cout << "Part 1: " << part_1(lists) << std::endl;
  std::cout << "Part 2: " << part_2(lists) << std::endl;
}

size_t part_1(const std::vector<std::vector<int>> &lists) {
  size_t safe_reports = 0;
  for(const auto &list : lists)
    if (is_increasing(list) || is_decreasing(list))
      ++safe_reports;

  return safe_reports;
}

size_t part_2(const std::vector<std::vector<int>> &lists) {
  size_t safe_reports = 0;
  for(const auto &list : lists) {
    if (is_increasing(list) || is_decreasing(list))
      ++safe_reports;

    else {
      for(size_t i=0; i<list.size(); ++i) {
	auto modified_list = modify_list(list, i);

	if (is_increasing(modified_list) || is_decreasing(modified_list)) {
	  ++safe_reports;
	  break;
	}
      }
    }
  }
  
  return safe_reports;
}

std::vector<int> modify_list(const std::vector<int> &list, const size_t &index) {
  std::vector<int> modified;

  for(size_t i=0; i<list.size(); ++i)
    if (i != index)
      modified.push_back(list[i]);

  return modified;
}

bool is_increasing(const std::vector<int> &list) {
  for(size_t i=1; i<list.size(); ++i) {
    int difference = list[i] - list[i-1];

    if (difference < 1 || difference > 3)
      return false;
  }
  return true;
}

bool is_decreasing(const std::vector<int> &list) {
  for(size_t i=1; i<list.size(); ++i) {
    int difference = list[i-1] - list[i];

    if (difference < 1 || difference > 3)
      return false;
  }
  return true;
}
