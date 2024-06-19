#include <iostream>
#include <vector>
#include <thread>



class MergeSort {
public:    void Sort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;        std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
        std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());
        Sort(left);
        Sort(right);
        Merge(arr, left, right);
    }
private:
    void Merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
        size_t leftIndex = 0, rightIndex = 0, mergeIndex = 0;

        while (leftIndex < left.size() && rightIndex < right.size()) {
            if (left[leftIndex] < right[rightIndex]) {
                arr[mergeIndex++] = left[leftIndex++];
            } else {
                arr[mergeIndex++] = right[rightIndex++];
            }
        }

        while (leftIndex < left.size()) {
            arr[mergeIndex++] = left[leftIndex++];
        }

        while (rightIndex < right.size()) {
            arr[mergeIndex++] = right[rightIndex++];
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr(10);
    std::cout << "Введи 10 чисел бла бла бла: ";
    for (int i = 0; i < 10; ++i) {
        while (!(std::cin >> arr[i])) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "НЕПРАВИЛЬНО введи норм чёт: ";
        }
    }

    MergeSort sorter;

    auto sortFunction = [&sorter](std::vector<int>& array) {
        sorter.Sort(array);
    };

    std::thread mergeSortThread(sortFunction, std::ref(arr));
    mergeSortThread.join();

    std::cout << "Вывод: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
