#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <vector>
//blockchain class(obviously)
class Blockchain {
private:
    std::vector<Block> chain;

public:
    //constructor to initialize the blockchain with the genesis block
    Blockchain();

    void addBlock(const std::string& data);
    bool validateBlock(const Block& block) const;
    bool validateChain() const;
    void displayDigest() const;
    void hackBlock(int index, const std::string& newData);
};

#endif
