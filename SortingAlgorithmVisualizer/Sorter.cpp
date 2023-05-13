#include "Sorter.h"

void Sorter::IncrementOperations() {
    _operationsDone++;
}

vector<int>& Sorter::GetData() {
    return _data;
}

size_t Sorter::Count() {
    return _count;
}

void Sorter::SetDone(bool isDone) {
    _doneness = isDone;
}

void Sorter::SetFound(bool isFound) {
    _found = isFound;
}

Sorter::Sorter(vector<int> data) : _data(data), _count(data.size()) {
}

Sorter::~Sorter() {
}

bool Sorter::Found() const {
    return _found;
}

bool Sorter::Sorted() {
    return _doneness;
}

pair<int, int> Sorter::Positions() const {
    return pair<int, int> { i, j };
}

long long Sorter::OperationsPerformed() const {
    return _operationsDone;
}
