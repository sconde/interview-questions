/*
Question: Write a function that takes a string as input and returns a vector of integers found in the string.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

std::vector<int> findIntegersInSentence_sstream(const std::string& sentence) {
    std::vector<int> integers;
    std::stringstream ss(sentence);
    std::string temp;
    int found;

    while (!ss.eof()) {
        // Extracting word by word from stream
        ss >> temp;

        // Checking the given word is integer or not
        /*
        The >> operator returns a reference to the std::stringstream object, which can be implicitly converted to a boolean value. 
        If the extraction was successful (i.e., if the data in temp could be converted to the type of found), the if statement evaluates to true.

        Note this would cast floats to ints, so if you want to keep floats, you should use a float vector instead.
        */
        if (std::stringstream(temp) >> found) {
            integers.push_back(found);
        }

        // To save from space at the end of string
        // temp = "";
    }
    return integers;
}

std::vector<int> findAndPrintIntegers_regex(const std::string& sentence) {
    std::vector<int> integers;
    // Regular expression to match both explicitly positive and negative integer numbers
    /*
    This regex is not working as expected. It is not able to match the negative numbers. returning only the absolute value of the negative numbers.
    */
    // std::regex integerPattern(R"(\b[+-]?\d+\b)");

    /*
    This regex is working as expected. It is able to match the negative numbers as well.
    */
    std::regex integerPattern(R"((?:^|\s)[+-]?\d+\b)");

    // Using std::sregex_iterator to search the sentence for numbers matching the pattern
    auto numbersBegin = std::sregex_iterator(sentence.begin(), sentence.end(), integerPattern);
    auto numbersEnd = std::sregex_iterator();

    for (std::sregex_iterator i = numbersBegin; i != numbersEnd; ++i) {
        integers.push_back(std::stoi(i->str()));
    }
    return integers;
}

int main() {
    std::string sentence = "I have 2 apples and 5 oranges in 3 baskets. My phone number is 1234567890. and -17.5 is my temperature.";
    const std::string sentence2 = "I have -2 apples, +3 bananas, and 5 oranges in -3 baskets.";

    auto findAndPrintIntegersLambda = [](const std::string& sentence) {
        std::vector<int> integers = findIntegersInSentence_sstream(sentence);
        // std::vector<int> integers = findAndPrintIntegers_regex(sentence);

        std::cout << "Integers found in the sentence: ";
        for (int num : integers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    };

    findAndPrintIntegersLambda(sentence);
    findAndPrintIntegersLambda(sentence2);


    return 0;
}
