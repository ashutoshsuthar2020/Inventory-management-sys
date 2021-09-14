#include "Transaction.h"

Transaction::Transaction(){}

Transaction::Transaction(std::string cashierName, std::string customerName, std::string item, int no): cashierName(cashierName), customerName(customerName) {
	items.emplace_back(std::make_pair(item, no));
}
