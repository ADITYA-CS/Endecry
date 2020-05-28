//
// Created by the__martian on 5/23/20.
//

#ifndef ENDECRY_SHA_1_H
#define ENDECRY_SHA_1_H


#include <bits/stdc++.h>
/**
 * @brief
 *      Hold information for hashing operation
 */
struct SHA1Context{
    /// contain final 160 bit message digest = 20 bytes = 5 x 4 bytes
    unsigned int message_digest[5];
    /// message length in bits
    unsigned int m_low;
    /// message length in bits
    unsigned int m_high;
    /// 512 bits message block = 64 x 8 bytes
    unsigned char block[64];
    /// index of block array
    int index;
    /// Is the digest computed?
    int computed;
    /// Is the message digest corrupted?
    int corrupted;
};


void SHA1PadMessage(SHA1Context * context);
void SHA1Reset(SHA1Context *context);
static bool sha1Result(SHA1Context *);
static void sha1Input(SHA1Context *, const unsigned char *, unsigned);

#endif //ENDECRY_SHA_1_H
