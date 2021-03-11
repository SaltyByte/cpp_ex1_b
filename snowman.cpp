#include <string>
#include <iostream>
#include <array>
#include <stdexcept>

using namespace std;

// constants
const int MAX_INPUT = 44444444;
const int MIN_INPUT = 11111111;
const int base_ten = 10;
const int seq_size = 8;

//Left arm
const string NORMAL_LEFT_ARM = "<";
const string UPWARDS_LEFT_ARM = "\\";
const string DOWNWARDS_LEFT_ARM = "/";
const string NONE_ARM = " ";

//Right arm
const string NORMAL_RIGHT_ARM = ">";
const string UPWARDS_RIGHT_ARM = "/";
const string DOWNWARDS_RIGHT_ARM = "\\";


string getHat(int input) {
    const int num = 100000000; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_hat{"     \n_===_\n", " ___ \n.....\n", "  _  \n /_\\ \n", " ___ \n(_*_)\n"};
    int index = (input % num) / (num / base_ten); // get first number from left
    return arr_hat.at(index - 1);

}

string getNose(int input) {
    const int num = 10000000; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_nose{",", ".", "_", " "};
    int index = (input % num) / (num / base_ten); // get second number from left
    return arr_nose.at(index - 1);
}

string getLeftEye(int input) {
    const int num = 1000000; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_eyes{".", "o", "O", "-"};
    int index = (input % num) / (num / base_ten); // get third number from left
    return arr_eyes.at(index - 1);
}

string getRightEye(int input) {
    const int num = 100000; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_eyes{".", "o", "O", "-"};
    int index = (input % num) / (num / base_ten); // get fourth number from left
    return arr_eyes.at(index - 1);
}

string getLeftArm(int input) {
    const int num = 10000; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_left_arm{NORMAL_LEFT_ARM, UPWARDS_LEFT_ARM, DOWNWARDS_LEFT_ARM, NONE_ARM};
    int index = (input % num) / (num / base_ten); // get fifth number from left
    return arr_left_arm.at(index - 1);
}

string getRightArm(int input) {
    const int num = 1000; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_right_arm{NORMAL_RIGHT_ARM, UPWARDS_RIGHT_ARM, DOWNWARDS_RIGHT_ARM, NONE_ARM};
    int index = (input % num) / (num / base_ten); // get sixth number from left
    return arr_right_arm.at(index - 1);
}

string getTorso(int input) {
    const int num = 100; // use this number later to get the digit we are looking for
    std::array<string, 4> arr_torso{" : ", "] [", "> <", "   "};
    int index = (input % num) / base_ten; // get first seventh from left
    return arr_torso.at(index - 1);
}

string getBase(int input) {
    std::array<string, 4> arr_base{" : ", "\" \"", "___", "   "};
    int index = input % base_ten; // get first eighth from left
    return arr_base.at(index - 1);
}

string buildSnowman(array<string, seq_size> &arr) {
    const int hatIndex = 0;
    const int noseIndex = 1;
    const int leftEyeIndex = 2;
    const int rightEyeIndex = 3;
    const int leftArmIndex = 4;
    const int rightArmIndex = 5;
    const int torsoIndex = 6;
    const int baseIndex = 7;

    string hat = arr.at(hatIndex);
    string nose = arr.at(noseIndex);
    string leftEye = arr.at(leftEyeIndex);
    string rightEye = arr.at(rightEyeIndex);
    string leftArm = arr.at(leftArmIndex);
    string rightArm = arr.at(rightArmIndex);
    string torso = arr.at(torsoIndex);
    string base = arr.at(baseIndex);

    string ret;

    if ((leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM) &&
        (rightArm == UPWARDS_RIGHT_ARM || rightArm == NONE_ARM)) {
        ret =  hat += leftArm += "(" +
               leftEye += nose +=
               rightEye + ")" +=
               rightArm + "\n (" +=
               torso + ") \n" += "(" + base + ")";
    }
    else if ((leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM) &&
        (rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM)) {
        ret =  hat += leftArm += "(" +
               leftEye += nose +=
               rightEye + ") " +=
               "\n (" + torso +=
               ")" + rightArm += "\n(" + base + ")";
    }
    else if ((leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM) &&
        (rightArm == UPWARDS_RIGHT_ARM || rightArm == NONE_ARM)) {
        ret =  hat += " (" + leftEye += nose +=
               rightEye + ")" +=
               rightArm + "\n" +=
               leftArm + "(" +=
               torso + ") \n" + "(" += base + ")";
    }
    else if ((leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM) &&
        (rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM)) {
        ret =  hat += " (" + leftEye += nose +=
               rightEye + ") \n"
               + leftArm +=
               "(" + torso +=
               ")" + rightArm += "\n(" + base + ")";
    }
    return ret;
}

namespace ariel {
    string snowman(int i) {
        if (i > MAX_INPUT || i < MIN_INPUT) {
            throw std::out_of_range("Invalid range");
        }
        int temp = base_ten;
        for (int j = 0; j < seq_size; j++) {
            if ((i % temp) / (temp / base_ten) < 1 || (i % temp) / (temp / base_ten) > 4) {
                throw std::out_of_range("Invalid sequence");
            }
            temp = temp * base_ten;
        }
        std::array<string, seq_size> snowmanArr = {getHat(i), getNose(i), getLeftEye(i), getRightEye(i), getLeftArm(i),
                                                   getRightArm(i), getTorso(i), getBase(i)};
        return buildSnowman(snowmanArr);
    }
}