#include "blockchain.h"
#include <iostream>
//initialize blockchain with genesis block
Blockchain::Blockchain() {
    chain.push_back(Block(0, "Genesis Block", "0"));
}
//add new block to block chain
void Blockchain::addBlock(const std::string& data) {
    int blockNumber = chain.size();
    std::string prevHash = chain.back().hash;
    chain.push_back(Block(blockNumber, data, prevHash));
}
//method to validate a single block by comparing its hash
bool Blockchain::validateBlock(const Block& block) const {
    return block.hash == block.calculateHash();
}
//method to validate whole blockchain
bool Blockchain::validateChain() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        if (!validateBlock(chain[i]) || chain[i].previousHash != chain[i - 1].hash) {
            return false;
        }
    }
    return true;
}
//show message digest of the blockchain
void Blockchain::displayDigest() const {
    for (const auto& block : chain) {
        std::cout << "Block Number: " << block.blockNumber << std::endl;
        std::cout << "Nonce: " << block.nonce << std::endl;
        std::cout << "Data: " << block.data << std::endl;
        std::cout << "Previous Hash: " << block.previousHash << std::endl;
        std::cout << "Hash: " << block.hash << std::endl;
        std::cout << std::endl;
    }
}
//hack a block by changing its data
void Blockchain::hackBlock(int index, const std::string& newData) {
    if (index < 0 || index >= chain.size()) {
        std::cerr << "Invalid block index." << std::endl;
        return;
    }
    chain[index].data = newData;
    chain[index].hash = chain[index].calculateHash();
}
