#include "md2.h"


static unsigned char PI_SUBSET[256] = {
        41, 46, 67, 201, 162, 216, 124, 1, 61, 54, 84, 161, 236, 240, 6,
        19, 98, 167, 5, 243, 192, 199, 115, 140, 152, 147, 43, 217, 188,
        76, 130, 202, 30, 155, 87, 60, 253, 212, 224, 22, 103, 66, 111, 24,
        138, 23, 229, 18, 190, 78, 196, 214, 218, 158, 222, 73, 160, 251,
        245, 142, 187, 47, 238, 122, 169, 104, 121, 145, 21, 178, 7, 63,
        148, 194, 16, 137, 11, 34, 95, 33, 128, 127, 93, 154, 90, 144, 50,
        39, 53, 62, 204, 231, 191, 247, 151, 3, 255, 25, 48, 179, 72, 165,
        181, 209, 215, 94, 146, 42, 172, 86, 170, 198, 79, 184, 56, 210,
        150, 164, 125, 182, 118, 252, 107, 226, 156, 116, 4, 241, 69, 157,
        112, 89, 100, 113, 135, 32, 134, 91, 207, 101, 230, 45, 168, 2, 27,
        96, 37, 173, 174, 176, 185, 246, 28, 70, 97, 105, 52, 64, 126, 15,
        85, 71, 163, 35, 221, 81, 175, 58, 195, 92, 249, 206, 186, 197,
        234, 38, 44, 83, 13, 110, 133, 40, 132, 9, 211, 223, 205, 244, 65,
        129, 77, 82, 106, 220, 55, 200, 108, 193, 171, 250, 36, 225, 123,
        8, 12, 189, 177, 74, 120, 136, 149, 139, 227, 99, 232, 109, 233,
        203, 213, 254, 59, 0, 29, 57, 242, 239, 183, 14, 102, 88, 208, 228,
        166, 119, 114, 248, 235, 117, 75, 10, 49, 68, 80, 180, 143, 237,
        31, 26, 219, 153, 141, 51, 159, 17, 131, 20
};
unsigned char *PADDING[17] = {
        (unsigned char *)"",
        (unsigned char *)"\001",
        (unsigned char *)"\002\002",
        (unsigned char *)"\003\003\003",
        (unsigned char *)"\004\004\004\004",
        (unsigned char *)"\005\005\005\005\005",
        (unsigned char *)"\006\006\006\006\006\006",
        (unsigned char *)"\007\007\007\007\007\007\007",
        (unsigned char *)"\010\010\010\010\010\010\010\010",
        (unsigned char *)"\011\011\011\011\011\011\011\011\011",
        (unsigned char *)"\012\012\012\012\012\012\012\012\012\012",
        (unsigned char *)"\013\013\013\013\013\013\013\013\013\013\013",
        (unsigned char *)"\014\014\014\014\014\014\014\014\014\014\014\014",
        (unsigned char *)"\015\015\015\015\015\015\015\015\015\015\015\015\015",
        (unsigned char *)"\016\016\016\016\016\016\016\016\016\016\016\016\016\016",
        (unsigned char *)"\017\017\017\017\017\017\017\017\017\017\017\017\017\017\017",
        (unsigned char *)"\020\020\020\020\020\020\020\020\020\020\020\020\020\020\020\020"};

void Init(MD2 *context)
{
    context->count = 0;
    for(int i = 0; i < 16; i++)
        context->state[i] = context->checksum[i] = (char) 0;

}

void Update(MD2 *context, unsigned char *input, int input_len){
    int index = context->count, i = 0;
    context->count = ( index + input_len) % 16;
    int part_len = 16 - index;

    if(input_len >= part_len){
        for(int j = 0; j < part_len; j++){
            context->buffer[index + j] = input[j];
        }
        Transform(context->state, context->checksum, context->buffer);
        for(i = part_len; i + 15< input_len; i += 16){
            Transform(context->state, context->checksum, &input[i]);
        }
        index = 0;
    }

    for(int j = 0; j < input_len - i; j++){
        context->buffer[j] = input[i + j];
    }
}

void Final(unsigned char digest[16], MD2 * context){
    int index, pad_len;
    index = context->count;
    pad_len = 16 - index;
    Update(context, PADDING[pad_len], pad_len);
    Update(context, context->checksum, 16);
    for(int i = 0; i < 16; i++){
        digest[i] = context->state[i];
    }
}

void Transform(unsigned char state[16], unsigned char checksum[16], unsigned char block[16]){
    unsigned char x[48];
    for(int i = 0; i < 16; i++){
        x[i] = state[i];
        x[i + 16] = block[i];
        x[i + 32] = state[i] ^ block[i];
    }
    unsigned int t = 0;
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 48; j++){
            t = x[j] ^= PI_SUBSET[t];
        }
        t = (t + i) & 0xff;
    }
    for(int i = 0; i < 16; i++){
        state[i] = x[i];
    }
    t = checksum[15];
    for(int i = 0; i < 16; i++){
        t = checksum[i] ^= PI_SUBSET[block[i] ^ t];
    }
    for(int i = 0; i < 48; i++){
        x[i] = 0;
    }
}