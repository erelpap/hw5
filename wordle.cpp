// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here

void wordleHelper(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict, 
    std::set<std::string>& result);

std::string ifIncludesRemoves(std::string word, char c);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    std::set<std::string> result;
    wordleHelper(in, floating, dict, result);
    return result;
    // Add your code here

}

// Define any helper functions here

void wordleHelper(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict, 
    std::set<std::string>& result){
        
	// finding no of dahses in 'in'
	unsigned int noOfDash = 0;
	int index;
	for(unsigned int i = 0; i < in.length(); i++){
			if(in[i] == '-' && noOfDash < 1){
					index = i;
			}
			if(in[i] == '-'){
				noOfDash = noOfDash + 1;
			}
	}

	if(noOfDash == 0){
			if(dict.find(in) != dict.end()){
					result.insert(in);
					return;
			}
			else{
					return;
			}
	}

	std::string floatingTemp = floating;
	std::string temp;

	if(floating.size() == noOfDash){	
		for(unsigned int i = 0; i < floating.length(); i++){
			temp = in;
			temp[index] = floating[i];
			if(noOfDash > 1){
					floatingTemp = ifIncludesRemoves(floating, floating[i]);
					wordleHelper(temp, floatingTemp, dict, result);
			}
			else{
				if(dict.find(temp) != dict.end()){
					result.insert(temp);
				}
			}				
		}
	}

	else{
		std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
		for(unsigned int i = 0; i < alphabet.length(); i++){
			floatingTemp = floating;
			temp = in;
			temp[index] = alphabet[i];
				

			if(noOfDash > 1){
					floatingTemp = ifIncludesRemoves(floating, alphabet[i]);
					wordleHelper(temp, floatingTemp, dict, result);
			}
			else{
				if(dict.find(temp) != dict.end()){
					result.insert(temp);
				}
			}
		}
	}
	
}

std::string ifIncludesRemoves(std::string word, char c){
		std::string result = "";
    for(unsigned int i = 0; i < word.length(); i++){
			if(word[i] != c){
				result = result + word[i];
			}
			else if(word[i] == c){
				c = '0';
			}	

    }
  	return result;

}



// std::string ifIncludesRemoves(std::string word, char c){
// 	std::string result;
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] == c){
//             word[i] = '0';
//             break;
//         }
//     }
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] != '0'){
//             result = result + word[i];
//         }
//     }
//     return result;

// }





// VERSION 1

// bool includes(std::string word, char c);

// std::string removeIncludedLetter(std::string word, char c);




// void wordleHelper(
//     const std::string& in,
//     const std::string& floating,
//     const std::set<std::string>& dict, 
//     std::set<std::string>& result){

        
// 	unsigned int noOfDash = 0;
       
        
// 	// finding no of dahses in 'in'
// 	int index;
// 	for(unsigned int i = 0; i < in.length(); i++){
// 			if(in[i] == '-' && noOfDash < 1){
// 					index = i;
// 			}
// 			if(in[i] == '-'){
// 				noOfDash = noOfDash + 1;
// 			}
// 	}

// 	if(noOfDash == 0){
// 			if(dict.find(in) != dict.end()){
// 					result.insert(in);
// 					return;
// 			}
// 			else{
// 					return;
// 			}
// 	}

// 	std::string floatingTemp = floating;
// 	std::string temp;

        
// 	// std::cout <<  floating << temp << std::endl;
// 	if(floating.size() == noOfDash){
			
// 			for(unsigned int i = 0; i < floating.length(); i++){
// 							temp = in;
// 							temp[index] = floating[i];
// 							if(noOfDash > 1){
// 									floatingTemp = removeIncludedLetter(floating, floating[i]); 
// 									wordleHelper(temp, floatingTemp, dict, result);
// 							}

// 							else{
// 									if(dict.find(temp) != dict.end()){
// 											result.insert(temp);
// 									}
// 							}
							
// 					}
// 			}

// 	else{
// 			std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
// 			for(unsigned int i = 0; i < alphabet.length(); i++){
// 					floatingTemp = floating;
// 					temp = in;
// 					temp[index] = alphabet[i];
						
			
// 					if(noOfDash > 1){
							
// 							if(includes(floating, alphabet[i])){
// 									floatingTemp = removeIncludedLetter(floating, alphabet[i]); 
// 							}
// 							wordleHelper(temp, floatingTemp, dict, result);
// 					}
// 					else{
// 							if(dict.find(temp) != dict.end()){
// 									result.insert(temp);
// 							}
// 					}
// 			}
// 	}

// }

// bool includes(std::string word, char c){
//     bool include = false;
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] == c){
//             include = true;
//             break;
//         }
//     }
//     return include;
// }

// std::string removeIncludedLetter(std::string word, char c){
//     std::string result;
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] == c){
//             word[i] = '0';
//             break;
//         }
//     }
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] != '0'){
//             result = result + word[i];
//         }
//     }
//     return result;
// }


// bool includes(std::string word, char c){
//     bool include = false;
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] == c){
//             include = true;
//             break;
//         }
//     }
//     return include;
// }



// std::string removeIncludedLetter(std::string word, char c){
//     std::string result;
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] == c){
//             word[i] = '0';
//             break;
//         }
//     }
//     for(unsigned int i = 0; i < word.length(); i++){
//         if(word[i] != '0'){
//             result = result + word[i];
//         }
//     }
//     return result;
// }

