#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

struct Transaction{
    std::string cashierName;
    std::string customerName;
    std::vector<std::pair<std::string, int>> items;
    Transaction();
    Transaction(std::string cashierName, std::string customerName, std::string item, int no);
};

#endif
