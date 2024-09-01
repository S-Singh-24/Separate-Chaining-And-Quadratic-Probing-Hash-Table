/* Program name: M08BlockChain.sln
* Author: Sahajpreet Singh
* Date last updated: 7/23/2024
*/
#include "blockchain.h"
#include <iostream>
#include <fstream>
#include <string>
//process input file and add blocks to the blockchain 
void processInputFile(Blockchain& blockchain, const std::string& filename) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        blockchain.addBlock(line);
    }
}

int main() {
    Blockchain blockchain;//new blockchain
    std::string inputFilename = "input1.txt";

    processInputFile(blockchain, inputFilename);

    std::cout << "Initial Blockchain:" << std::endl;
    blockchain.displayDigest();

    std::cout << "Validating chain... " << (blockchain.validateChain() ? "Valid" : "Invalid") << std::endl;

    //hack a block
    blockchain.hackBlock(1, "Hacked Data");

    std::cout << "Blockchain after hacking block 1:" << std::endl;
    blockchain.displayDigest();//display blockchain

    std::cout << "Validating chain... " << (blockchain.validateChain() ? "Valid" : "Invalid") << std::endl;

    return 0;
}
