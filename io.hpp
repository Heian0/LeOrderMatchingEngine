#pragma once
#include <mutex>
#include <tuple>
#include <cstdint>
#include <iostream>
#include <string>

enum OrderType {
    buy = 'Buy',
    sell = 'Sell',
    cancel = 'Cancel'
};

struct ClientCommand {
    OrderType side;
    uint16_t id;
    uint32_t price;
    uint32_t quantity;
    string ticker;
};

enum class ReadResult
{
	Success,
	EndOfFile,
	Error
};