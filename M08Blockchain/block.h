#ifndef BLOCK_H
#define BLOCK_H

#include <string>
// tis class represents the block in the chain
class Block {
public:
    int blockNumber;
    long nonce;
    std::string data;
    std::string previousHash;
    std::string hash;
    //constructor to initialize block
    Block(int blockNum, const std::string& data, const std::string& prevHash);
    //method to calculate hash of the block
    std::string calculateHash() const;
    //static method to generate a hash value for a block
    static std::string generateHash(int blockNum, long nonce, const std::string& data, const std::string& prevHash);
};

#endif
