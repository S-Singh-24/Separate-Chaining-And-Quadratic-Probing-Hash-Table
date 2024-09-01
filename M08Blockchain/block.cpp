#include "block.h"
#include <ctime>
#include <sstream>
#include <iostream>

//constructor to initialize a block with its number, data, and last hash
Block::Block(int blockNum, const std::string& data, const std::string& prevHash)
    : blockNumber(blockNum), data(data), previousHash(prevHash) {
    nonce = std::time(0);
    hash = calculateHash();
}
//hash calculation of block
std::string Block::calculateHash() const {
    return generateHash(blockNumber, nonce, data, previousHash);
}
//generate hash value of blockk
std::string Block::generateHash(int blockNum, long nonce, const std::string& data, const std::string& prevHash) {
    std::stringstream ss;
    ss << blockNum << nonce << data << prevHash;
    std::string input = ss.str();

    unsigned long hashValue = 0;
    for (char c : input) {
        hashValue = (hashValue * 31 + c) % 1000000007;
    }
    //convert hash value to string
    return std::to_string(hashValue);
}
