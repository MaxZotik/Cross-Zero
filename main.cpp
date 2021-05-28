#include <iostream>

bool checkingInput(std::string str){
    if(str.length() != 3)
        return false;

    for(int i = 0; i < str.length(); i++){
        if(str[i] != 'X' && str[i] != 'O' && str[i] != '.'){
            return false;
        }
    }
    return true;
}

bool findWon(std::string strOne, std::string strTwo, std::string strThree, char ch){

    if(strOne[0] == ch && strOne[1] == ch && strOne[2] == ch){
        return true;
    }else if(strTwo[0] == ch && strTwo[1] == ch && strTwo[2] == ch){
        return true;
    }else if(strThree[0] == ch && strThree[1] == ch && strThree[2] == ch){
        return true;
    }else if(strOne[0] == ch && strTwo[0] == ch && strThree[0] == ch){
        return true;
    }else if(strOne[1] == ch && strTwo[1] == ch && strThree[1] == ch){
        return true;
    }else if(strOne[2] == ch && strTwo[2] == ch && strThree[2] == ch){
        return true;
    }else if(strOne[0] == ch && strTwo[1] == ch && strThree[2] == ch){
        return true;
    }else if(strOne[2] == ch && strTwo[1] == ch && strThree[0] == ch){
        return true;
    }

    return false;
}

//find number of characters
int countCharacter(std::string str, char ch){
    int temp = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == ch){
            temp ++;
        }
    }
    return temp;
}

std::string findWinner(std::string strOne, std::string strTwo, std::string strThree){
    std::string strSum = strOne + strTwo + strThree;

    if(findWon(strOne, strTwo, strThree, 'X') && findWon(strOne, strTwo, strThree, 'O')){
        return "There can't be two winners!";
    }

    if(findWon(strOne, strTwo, strThree, 'X') && countCharacter(strSum, 'X') > countCharacter(strSum, 'O')){
        return "Petya won!";
    }else if(findWon(strOne, strTwo, strThree, 'X') && countCharacter(strSum, 'X') <= countCharacter(strSum, 'O')){
        return "\"X\" should be more than \"O\"";
    }

    if(findWon(strOne, strTwo, strThree, 'O') && countCharacter(strSum, 'X') == countCharacter(strSum, 'O')){
        return "Vanya won!";
    }else if(findWon(strOne, strTwo, strThree, 'O') && countCharacter(strSum, 'X') > countCharacter(strSum, 'O')){
        return "\"X\" should not be more than \"O\"";
    }

    return "Nobody!";
}

int main() {
    std::string strOne, strTwo, strThree;

    std::cout << "-----Cross - Zero-----" << std::endl;

    std::cout << "Enter three lines using the characters \"X\", \"O\" and \".\"" << std::endl;
    std::cin >> strOne >> strTwo >> strThree;

    if(checkingInput(strOne) && checkingInput(strTwo) && checkingInput(strThree)){
        std::cout << findWinner(strOne, strTwo, strThree) << std::endl;
    }else{
        std::cout << "Input is incorrect!" << std::endl;
    }
}
