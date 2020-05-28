
#include "sha-1.h"

/**
 *  SHA1 Circular Shift as suggested by SHA1 creater
 */
#define SHA1CircularShift(bits, word) \
            (((word) << (bits)) | ((word) >> (32 - (bits))))

/**
 * @brief
 *      Reset the SHA1Reset context for computing new
 *      message digest
 * @param context an object of SHA1Context which is
 *                currently being computed
 */
void SHA1Reset(SHA1Context *context){
    context->m_low  = 0;
    context->m_high = 0;
    context->index  = 0;
    context->corrupted = 0;
    context->computed = 0;
    context->message_digest[0]      = 0x67452301;
    context->message_digest[1]      = 0xEFCDAB89;
    context->message_digest[2]      = 0x98BADCFE;
    context->message_digest[3]      = 0x10325476;
    context->message_digest[4]      = 0xC3D2E1F0;
}

/**
 *
 * @param context an object of SHA1Context which is
 *                currently being computed
 * @return  True  when SHA1 computation is successful
 *          False Otherwise
 *
 */
static bool sha1Result(SHA1Context * context){
    /// when SHA1 computation not successful return false
    if(context->corrupted){
        return false;
    }
    /// computed the SHA1, set context->computed to 1, return true
    if(!context->computed){
        SHA1PadMessage(context);
        context->computed = 1;
    }
    return true;
}

/**
 *  Read message for computing SHA1 message digest
 * @param context struct object which will store message
 *          chunk and later store message digest
 * @param message input message whose SHA1 message
 *          digest is being calculated
 * @param length  Length of the message
 */
static void sha1Input(SHA1Context *context,
        const unsigned char *message,
        unsigned length){
    if(!length){
        return;
    }

    if(context->computed || context->corrupted ){
        context->corrupted = 1;
        return;
    }

    // computed till last bit or stop when corruption happen
    while(length-- && context->corrupted){

    }

}
/**
 * processes the message chunk
 * @param context an object of SHA1Context which is
 *                currently be computed
 */
static void sha1_process_block(SHA1Context * context){

}

void SHA1PadMessage(SHA1Context *context){

}