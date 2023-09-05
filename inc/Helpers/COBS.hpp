#pragma once

#include <etl/string.h>
#include "cobs.h"

template<int MaxLength>
etl::string<MaxLength> COBSencode(const uint8_t* input, uint16_t length) {
    char output[MaxLength];

    auto cobsOutput = cobs_encode(output, MaxLength, input, length);

    return { output, cobsOutput.out_len };
}

template<int MaxLength>
etl::string<MaxLength> COBSencode(const etl::string<MaxLength>& input) {
    char output[MaxLength];

    auto cobsOutput = cobs_encode(output, MaxLength, input.data(), input.length());

    return { output, cobsOutput.out_len };
}

template<int MaxLength>
etl::string<MaxLength> COBSdecode(const uint8_t* input, uint16_t length) {
    char output[MaxLength];

    auto cobsOutput = cobs_decode(output, MaxLength, input, length);

    return { output, cobsOutput.out_len };
}

template<int MaxLength>
etl::string<MaxLength> COBSdecode(const etl::string<MaxLength>& input) {
    char output[MaxLength];

    auto cobsOutput = cobs_decode(output, MaxLength, input.data(), input.length());

    return { output, cobsOutput.out_len };
}
