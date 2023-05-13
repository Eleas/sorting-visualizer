#pragma once
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::swap; 
using std::vector;

class Sorter {
    vector<int> _data = {};

    bool _found = false;
    bool _doneness = false;
    int _count;
    long long _operationsDone = 0;

public:
    int i = 0;
    int j = 0;

public:
    Sorter(vector<int> data);
    virtual ~Sorter();

public:
    void IncrementOperations();

public:
    vector<int>& GetData();

public:
    size_t Count();

public:
    void SetDone(bool isDone);

public:
    void SetFound(bool isFound);

public:
    bool Found() const;

public:
    bool Sorted();

public:
    pair<int, int> Positions() const;

public:
    long long OperationsPerformed() const;

public:
    virtual void SingleComparison() = 0;

public:
    virtual string Name() = 0;
};