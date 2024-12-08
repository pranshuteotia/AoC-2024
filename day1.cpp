// Advent of Code (2024) Day 1

#include <iostream>
#include <vector>

size_t part_1(std::vector<size_t> list1, std::vector<size_t> list2) {

  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  size_t distance_sum = 0;
  for(size_t i=0; i<list1.size(); ++i) {
    distance_sum += std::abs(int(list1[i]) - int(list2[i]));
  }

  return distance_sum;
}

size_t part_2(std::vector<size_t> list1, std::vector<size_t> list2) {
  size_t bucket[99999] = {0};

  for(size_t num : list2)
    bucket[num]++;

  size_t similarity = 0;

  for(size_t num : list1)
    similarity += num * bucket[num];
  
  return similarity;
}

int main() {
  std::vector<size_t> list1, list2;
  size_t num1, num2;

  while(std::cin >> num1 >> num2) {
    list1.push_back(num1);
    list2.push_back(num2);
  }

  std::cout << "Part 1: " << part_1(list1, list2) << std::endl;
  std::cout << "Part 2: " << part_2(list1, list2) << std::endl;
}
