//
// Created by the__martian on 5/26/20.
//

#ifndef ENDECRY_MD2_H
#define ENDECRY_MD2_H

#include <bits/stdc++.h>
using namespace std;

struct MD2{
    unsigned char state[16];
    unsigned char checksum[16];
    unsigned char buffer[16];
    int count;
};

void Final(unsigned char digest[16], MD2 * context);
void Transform(unsigned char state[16], unsigned char checksum[16], unsigned char block[16]);
void Init(MD2 *context);
void Update(MD2 *context, unsigned char *input, int input_len);
#endif //ENDECRY_MD2_H
