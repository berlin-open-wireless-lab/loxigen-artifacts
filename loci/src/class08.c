/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ip_proto_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80001502); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ip_proto_masked of_oxm_ip_proto_masked
 */

/**
 * Create a new of_oxm_ip_proto_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ip_proto_masked
 */

of_object_t *
of_oxm_ip_proto_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IP_PROTO_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ip_proto_masked_init(obj, version, bytes, 0);
    of_oxm_ip_proto_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ip_proto_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ip_proto_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IP_PROTO_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IP_PROTO_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IP_PROTO_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ip_proto_masked.
 * @param obj Pointer to an object of type of_oxm_ip_proto_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_ip_proto_masked_value_get(
    of_oxm_ip_proto_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IP_PROTO_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ip_proto_masked.
 * @param obj Pointer to an object of type of_oxm_ip_proto_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ip_proto_masked_value_set(
    of_oxm_ip_proto_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IP_PROTO_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ip_proto_masked.
 * @param obj Pointer to an object of type of_oxm_ip_proto_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_ip_proto_masked_value_mask_get(
    of_oxm_ip_proto_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IP_PROTO_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ip_proto_masked.
 * @param obj Pointer to an object of type of_oxm_ip_proto_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ip_proto_masked_value_mask_set(
    of_oxm_ip_proto_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IP_PROTO_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv4_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80001804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv4_dst of_oxm_ipv4_dst
 */

/**
 * Create a new of_oxm_ipv4_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv4_dst
 */

of_object_t *
of_oxm_ipv4_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV4_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_dst_init(obj, version, bytes, 0);
    of_oxm_ipv4_dst_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv4_dst.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv4_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV4_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV4_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV4_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv4_dst.
 * @param obj Pointer to an object of type of_oxm_ipv4_dst.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_oxm_ipv4_dst_value_get(
    of_oxm_ipv4_dst_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv4_dst.
 * @param obj Pointer to an object of type of_oxm_ipv4_dst.
 * @param value The value to write into the object
 */
void
of_oxm_ipv4_dst_value_set(
    of_oxm_ipv4_dst_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv4_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80001908); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv4_dst_masked of_oxm_ipv4_dst_masked
 */

/**
 * Create a new of_oxm_ipv4_dst_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv4_dst_masked
 */

of_object_t *
of_oxm_ipv4_dst_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV4_DST_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_dst_masked_init(obj, version, bytes, 0);
    of_oxm_ipv4_dst_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv4_dst_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv4_dst_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV4_DST_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV4_DST_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV4_DST_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv4_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_dst_masked.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_oxm_ipv4_dst_masked_value_get(
    of_oxm_ipv4_dst_masked_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv4_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_dst_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv4_dst_masked_value_set(
    of_oxm_ipv4_dst_masked_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv4_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_dst_masked.
 * @param value_mask Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_oxm_ipv4_dst_masked_value_mask_get(
    of_oxm_ipv4_dst_masked_t *obj,
    of_ipv4_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv4_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_dst_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv4_dst_masked_value_mask_set(
    of_oxm_ipv4_dst_masked_t *obj,
    of_ipv4_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv4_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80001604); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv4_src of_oxm_ipv4_src
 */

/**
 * Create a new of_oxm_ipv4_src object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv4_src
 */

of_object_t *
of_oxm_ipv4_src_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV4_SRC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_src_init(obj, version, bytes, 0);
    of_oxm_ipv4_src_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv4_src.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv4_src_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV4_SRC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV4_SRC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV4_SRC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv4_src.
 * @param obj Pointer to an object of type of_oxm_ipv4_src.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_oxm_ipv4_src_value_get(
    of_oxm_ipv4_src_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv4_src.
 * @param obj Pointer to an object of type of_oxm_ipv4_src.
 * @param value The value to write into the object
 */
void
of_oxm_ipv4_src_value_set(
    of_oxm_ipv4_src_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv4_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80001708); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv4_src_masked of_oxm_ipv4_src_masked
 */

/**
 * Create a new of_oxm_ipv4_src_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv4_src_masked
 */

of_object_t *
of_oxm_ipv4_src_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV4_SRC_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv4_src_masked_init(obj, version, bytes, 0);
    of_oxm_ipv4_src_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv4_src_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv4_src_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV4_SRC_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV4_SRC_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV4_SRC_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv4_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_src_masked.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_oxm_ipv4_src_masked_value_get(
    of_oxm_ipv4_src_masked_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv4_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_src_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv4_src_masked_value_set(
    of_oxm_ipv4_src_masked_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv4_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_src_masked.
 * @param value_mask Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_oxm_ipv4_src_masked_value_mask_get(
    of_oxm_ipv4_src_masked_t *obj,
    of_ipv4_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv4_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv4_src_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv4_src_masked_value_mask_set(
    of_oxm_ipv4_src_masked_t *obj,
    of_ipv4_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV4_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003610); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_dst of_oxm_ipv6_dst
 */

/**
 * Create a new of_oxm_ipv6_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_dst
 */

of_object_t *
of_oxm_ipv6_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_dst_init(obj, version, bytes, 0);
    of_oxm_ipv6_dst_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_dst.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_dst.
 * @param obj Pointer to an object of type of_oxm_ipv6_dst.
 * @param value Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_dst_value_get(
    of_oxm_ipv6_dst_t *obj,
    of_ipv6_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_dst.
 * @param obj Pointer to an object of type of_oxm_ipv6_dst.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_dst_value_set(
    of_oxm_ipv6_dst_t *obj,
    of_ipv6_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_dst_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003720); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_dst_masked of_oxm_ipv6_dst_masked
 */

/**
 * Create a new of_oxm_ipv6_dst_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_dst_masked
 */

of_object_t *
of_oxm_ipv6_dst_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_DST_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_dst_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_dst_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_dst_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_dst_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_DST_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_DST_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_DST_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_dst_masked.
 * @param value Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_dst_masked_value_get(
    of_oxm_ipv6_dst_masked_t *obj,
    of_ipv6_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_dst_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_dst_masked_value_set(
    of_oxm_ipv6_dst_masked_t *obj,
    of_ipv6_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_dst_masked.
 * @param value_mask Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_dst_masked_value_mask_get(
    of_oxm_ipv6_dst_masked_t *obj,
    of_ipv6_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_dst_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_dst_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_dst_masked_value_mask_set(
    of_oxm_ipv6_dst_masked_t *obj,
    of_ipv6_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_DST_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_flabel_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_flabel of_oxm_ipv6_flabel
 */

/**
 * Create a new of_oxm_ipv6_flabel object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_flabel
 */

of_object_t *
of_oxm_ipv6_flabel_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_FLABEL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_flabel_init(obj, version, bytes, 0);
    of_oxm_ipv6_flabel_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_flabel.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_flabel_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_FLABEL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_FLABEL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_FLABEL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_flabel.
 * @param obj Pointer to an object of type of_oxm_ipv6_flabel.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ipv6_flabel_value_get(
    of_oxm_ipv6_flabel_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_flabel.
 * @param obj Pointer to an object of type of_oxm_ipv6_flabel.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_flabel_value_set(
    of_oxm_ipv6_flabel_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_flabel_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003908); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_flabel_masked of_oxm_ipv6_flabel_masked
 */

/**
 * Create a new of_oxm_ipv6_flabel_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_flabel_masked
 */

of_object_t *
of_oxm_ipv6_flabel_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_FLABEL_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_flabel_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_flabel_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_flabel_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_flabel_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_FLABEL_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_FLABEL_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_FLABEL_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_flabel_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_flabel_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ipv6_flabel_masked_value_get(
    of_oxm_ipv6_flabel_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_flabel_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_flabel_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_flabel_masked_value_set(
    of_oxm_ipv6_flabel_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_flabel_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_flabel_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ipv6_flabel_masked_value_mask_get(
    of_oxm_ipv6_flabel_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_flabel_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_flabel_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_flabel_masked_value_mask_set(
    of_oxm_ipv6_flabel_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_FLABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_nd_sll_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004006); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_nd_sll of_oxm_ipv6_nd_sll
 */

/**
 * Create a new of_oxm_ipv6_nd_sll object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_nd_sll
 */

of_object_t *
of_oxm_ipv6_nd_sll_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_SLL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_sll_init(obj, version, bytes, 0);
    of_oxm_ipv6_nd_sll_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_nd_sll.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_nd_sll_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_ND_SLL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_SLL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_ND_SLL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_nd_sll.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_sll.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_sll_value_get(
    of_oxm_ipv6_nd_sll_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_nd_sll.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_sll.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_nd_sll_value_set(
    of_oxm_ipv6_nd_sll_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_nd_sll_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x8000410c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_nd_sll_masked of_oxm_ipv6_nd_sll_masked
 */

/**
 * Create a new of_oxm_ipv6_nd_sll_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_nd_sll_masked
 */

of_object_t *
of_oxm_ipv6_nd_sll_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_SLL_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_sll_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_nd_sll_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_nd_sll_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_nd_sll_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_ND_SLL_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_SLL_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_ND_SLL_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_nd_sll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_sll_masked.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_sll_masked_value_get(
    of_oxm_ipv6_nd_sll_masked_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_nd_sll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_sll_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_nd_sll_masked_value_set(
    of_oxm_ipv6_nd_sll_masked_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_nd_sll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_sll_masked.
 * @param value_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_sll_masked_value_mask_get(
    of_oxm_ipv6_nd_sll_masked_t *obj,
    of_mac_addr_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_nd_sll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_sll_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_nd_sll_masked_value_mask_set(
    of_oxm_ipv6_nd_sll_masked_t *obj,
    of_mac_addr_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_SLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_nd_target_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003e10); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_nd_target of_oxm_ipv6_nd_target
 */

/**
 * Create a new of_oxm_ipv6_nd_target object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_nd_target
 */

of_object_t *
of_oxm_ipv6_nd_target_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TARGET];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_target_init(obj, version, bytes, 0);
    of_oxm_ipv6_nd_target_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_nd_target.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_nd_target_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_ND_TARGET] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TARGET];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_ND_TARGET;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_nd_target.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_target.
 * @param value Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_target_value_get(
    of_oxm_ipv6_nd_target_t *obj,
    of_ipv6_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_nd_target.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_target.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_nd_target_value_set(
    of_oxm_ipv6_nd_target_t *obj,
    of_ipv6_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_nd_target_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003f20); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_nd_target_masked of_oxm_ipv6_nd_target_masked
 */

/**
 * Create a new of_oxm_ipv6_nd_target_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_nd_target_masked
 */

of_object_t *
of_oxm_ipv6_nd_target_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TARGET_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_target_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_nd_target_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_nd_target_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_nd_target_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_ND_TARGET_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TARGET_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_ND_TARGET_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_nd_target_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_target_masked.
 * @param value Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_target_masked_value_get(
    of_oxm_ipv6_nd_target_masked_t *obj,
    of_ipv6_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_nd_target_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_target_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_nd_target_masked_value_set(
    of_oxm_ipv6_nd_target_masked_t *obj,
    of_ipv6_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_nd_target_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_target_masked.
 * @param value_mask Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_target_masked_value_mask_get(
    of_oxm_ipv6_nd_target_masked_t *obj,
    of_ipv6_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_nd_target_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_target_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_nd_target_masked_value_mask_set(
    of_oxm_ipv6_nd_target_masked_t *obj,
    of_ipv6_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TARGET_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_nd_tll_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004206); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_nd_tll of_oxm_ipv6_nd_tll
 */

/**
 * Create a new of_oxm_ipv6_nd_tll object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_nd_tll
 */

of_object_t *
of_oxm_ipv6_nd_tll_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TLL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_tll_init(obj, version, bytes, 0);
    of_oxm_ipv6_nd_tll_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_nd_tll.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_nd_tll_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_ND_TLL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TLL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_ND_TLL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_nd_tll.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_tll.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_tll_value_get(
    of_oxm_ipv6_nd_tll_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_nd_tll.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_tll.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_nd_tll_value_set(
    of_oxm_ipv6_nd_tll_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_nd_tll_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x8000430c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_nd_tll_masked of_oxm_ipv6_nd_tll_masked
 */

/**
 * Create a new of_oxm_ipv6_nd_tll_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_nd_tll_masked
 */

of_object_t *
of_oxm_ipv6_nd_tll_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TLL_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_nd_tll_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_nd_tll_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_nd_tll_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_nd_tll_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_ND_TLL_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_ND_TLL_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_ND_TLL_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_nd_tll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_tll_masked.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_tll_masked_value_get(
    of_oxm_ipv6_nd_tll_masked_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_nd_tll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_tll_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_nd_tll_masked_value_set(
    of_oxm_ipv6_nd_tll_masked_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_nd_tll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_tll_masked.
 * @param value_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_ipv6_nd_tll_masked_value_mask_get(
    of_oxm_ipv6_nd_tll_masked_t *obj,
    of_mac_addr_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_nd_tll_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_nd_tll_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_nd_tll_masked_value_mask_set(
    of_oxm_ipv6_nd_tll_masked_t *obj,
    of_mac_addr_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_ND_TLL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003410); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_src of_oxm_ipv6_src
 */

/**
 * Create a new of_oxm_ipv6_src object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_src
 */

of_object_t *
of_oxm_ipv6_src_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_SRC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_src_init(obj, version, bytes, 0);
    of_oxm_ipv6_src_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_src.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_src_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_SRC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_SRC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_SRC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_src.
 * @param obj Pointer to an object of type of_oxm_ipv6_src.
 * @param value Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_src_value_get(
    of_oxm_ipv6_src_t *obj,
    of_ipv6_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_src.
 * @param obj Pointer to an object of type of_oxm_ipv6_src.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_src_value_set(
    of_oxm_ipv6_src_t *obj,
    of_ipv6_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_ipv6_src_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003520); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_src_masked of_oxm_ipv6_src_masked
 */

/**
 * Create a new of_oxm_ipv6_src_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_src_masked
 */

of_object_t *
of_oxm_ipv6_src_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_SRC_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_src_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_src_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_src_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_ipv6_src_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_SRC_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_SRC_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_SRC_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_src_masked.
 * @param value Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_src_masked_value_get(
    of_oxm_ipv6_src_masked_t *obj,
    of_ipv6_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_src_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_src_masked_value_set(
    of_oxm_ipv6_src_masked_t *obj,
    of_ipv6_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_src_masked.
 * @param value_mask Pointer to the child object of type
 * of_ipv6_t to be filled out.
 *
 */
void
of_oxm_ipv6_src_masked_value_mask_get(
    of_oxm_ipv6_src_masked_t *obj,
    of_ipv6_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_src_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_src_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_src_masked_value_mask_set(
    of_oxm_ipv6_src_masked_t *obj,
    of_ipv6_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_SRC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv6_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80000408); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_metadata of_oxm_metadata
 */

/**
 * Create a new of_oxm_metadata object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_metadata
 */

of_object_t *
of_oxm_metadata_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_METADATA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_metadata_init(obj, version, bytes, 0);
    of_oxm_metadata_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_metadata.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_metadata_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_METADATA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_METADATA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_METADATA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_metadata.
 * @param obj Pointer to an object of type of_oxm_metadata.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_oxm_metadata_value_get(
    of_oxm_metadata_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_METADATA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_metadata.
 * @param obj Pointer to an object of type of_oxm_metadata.
 * @param value The value to write into the object
 */
void
of_oxm_metadata_value_set(
    of_oxm_metadata_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_METADATA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_metadata_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80000510); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_metadata_masked of_oxm_metadata_masked
 */

/**
 * Create a new of_oxm_metadata_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_metadata_masked
 */

of_object_t *
of_oxm_metadata_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_METADATA_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_metadata_masked_init(obj, version, bytes, 0);
    of_oxm_metadata_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_metadata_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_metadata_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_METADATA_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_METADATA_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_METADATA_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_metadata_masked.
 * @param obj Pointer to an object of type of_oxm_metadata_masked.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_oxm_metadata_masked_value_get(
    of_oxm_metadata_masked_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_METADATA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_metadata_masked.
 * @param obj Pointer to an object of type of_oxm_metadata_masked.
 * @param value The value to write into the object
 */
void
of_oxm_metadata_masked_value_set(
    of_oxm_metadata_masked_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_METADATA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_metadata_masked.
 * @param obj Pointer to an object of type of_oxm_metadata_masked.
 * @param value_mask Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_oxm_metadata_masked_value_mask_get(
    of_oxm_metadata_masked_t *obj,
    uint64_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_METADATA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_metadata_masked.
 * @param obj Pointer to an object of type of_oxm_metadata_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_metadata_masked_value_mask_set(
    of_oxm_metadata_masked_t *obj,
    uint64_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_METADATA_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_mpls_label_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004404); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_mpls_label of_oxm_mpls_label
 */

/**
 * Create a new of_oxm_mpls_label object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_mpls_label
 */

of_object_t *
of_oxm_mpls_label_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_MPLS_LABEL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_label_init(obj, version, bytes, 0);
    of_oxm_mpls_label_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_mpls_label.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_mpls_label_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_MPLS_LABEL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_MPLS_LABEL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_MPLS_LABEL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_mpls_label.
 * @param obj Pointer to an object of type of_oxm_mpls_label.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_mpls_label_value_get(
    of_oxm_mpls_label_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_mpls_label.
 * @param obj Pointer to an object of type of_oxm_mpls_label.
 * @param value The value to write into the object
 */
void
of_oxm_mpls_label_value_set(
    of_oxm_mpls_label_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_mpls_label_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004508); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_mpls_label_masked of_oxm_mpls_label_masked
 */

/**
 * Create a new of_oxm_mpls_label_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_mpls_label_masked
 */

of_object_t *
of_oxm_mpls_label_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_MPLS_LABEL_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_label_masked_init(obj, version, bytes, 0);
    of_oxm_mpls_label_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_mpls_label_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_mpls_label_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_MPLS_LABEL_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_MPLS_LABEL_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_MPLS_LABEL_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_mpls_label_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_label_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_mpls_label_masked_value_get(
    of_oxm_mpls_label_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_mpls_label_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_label_masked.
 * @param value The value to write into the object
 */
void
of_oxm_mpls_label_masked_value_set(
    of_oxm_mpls_label_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_mpls_label_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_label_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_mpls_label_masked_value_mask_get(
    of_oxm_mpls_label_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_mpls_label_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_label_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_mpls_label_masked_value_mask_set(
    of_oxm_mpls_label_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_LABEL_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_mpls_tc_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004601); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_mpls_tc of_oxm_mpls_tc
 */

/**
 * Create a new of_oxm_mpls_tc object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_mpls_tc
 */

of_object_t *
of_oxm_mpls_tc_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_MPLS_TC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_tc_init(obj, version, bytes, 0);
    of_oxm_mpls_tc_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_mpls_tc.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_mpls_tc_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_MPLS_TC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_MPLS_TC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_MPLS_TC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_mpls_tc.
 * @param obj Pointer to an object of type of_oxm_mpls_tc.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_mpls_tc_value_get(
    of_oxm_mpls_tc_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_TC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_mpls_tc.
 * @param obj Pointer to an object of type of_oxm_mpls_tc.
 * @param value The value to write into the object
 */
void
of_oxm_mpls_tc_value_set(
    of_oxm_mpls_tc_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_TC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_mpls_tc_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004702); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_mpls_tc_masked of_oxm_mpls_tc_masked
 */

/**
 * Create a new of_oxm_mpls_tc_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_mpls_tc_masked
 */

of_object_t *
of_oxm_mpls_tc_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_MPLS_TC_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_tc_masked_init(obj, version, bytes, 0);
    of_oxm_mpls_tc_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_mpls_tc_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_mpls_tc_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_MPLS_TC_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_MPLS_TC_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_MPLS_TC_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_mpls_tc_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_tc_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_mpls_tc_masked_value_get(
    of_oxm_mpls_tc_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_TC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_mpls_tc_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_tc_masked.
 * @param value The value to write into the object
 */
void
of_oxm_mpls_tc_masked_value_set(
    of_oxm_mpls_tc_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_TC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_mpls_tc_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_tc_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_mpls_tc_masked_value_mask_get(
    of_oxm_mpls_tc_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_TC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_mpls_tc_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_tc_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_mpls_tc_masked_value_mask_set(
    of_oxm_mpls_tc_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_TC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c1_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1e604); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c1 of_oxm_nsh_c1
 */

/**
 * Create a new of_oxm_nsh_c1 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c1
 */

of_object_t *
of_oxm_nsh_c1_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C1];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c1_init(obj, version, bytes, 0);
    of_oxm_nsh_c1_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c1.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c1_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C1] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C1];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C1;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c1.
 * @param obj Pointer to an object of type of_oxm_nsh_c1.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c1_value_get(
    of_oxm_nsh_c1_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C1);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c1.
 * @param obj Pointer to an object of type of_oxm_nsh_c1.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c1_value_set(
    of_oxm_nsh_c1_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C1);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c1_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1e708); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c1_masked of_oxm_nsh_c1_masked
 */

/**
 * Create a new of_oxm_nsh_c1_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c1_masked
 */

of_object_t *
of_oxm_nsh_c1_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C1_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c1_masked_init(obj, version, bytes, 0);
    of_oxm_nsh_c1_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c1_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c1_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C1_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C1_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C1_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c1_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c1_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c1_masked_value_get(
    of_oxm_nsh_c1_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C1_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c1_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c1_masked.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c1_masked_value_set(
    of_oxm_nsh_c1_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C1_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_nsh_c1_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c1_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c1_masked_value_mask_get(
    of_oxm_nsh_c1_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C1_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_nsh_c1_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c1_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_nsh_c1_masked_value_mask_set(
    of_oxm_nsh_c1_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C1_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c2_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1e804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c2 of_oxm_nsh_c2
 */

/**
 * Create a new of_oxm_nsh_c2 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c2
 */

of_object_t *
of_oxm_nsh_c2_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C2];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c2_init(obj, version, bytes, 0);
    of_oxm_nsh_c2_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c2.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c2_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C2] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C2];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C2;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c2.
 * @param obj Pointer to an object of type of_oxm_nsh_c2.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c2_value_get(
    of_oxm_nsh_c2_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c2.
 * @param obj Pointer to an object of type of_oxm_nsh_c2.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c2_value_set(
    of_oxm_nsh_c2_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c2_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1e908); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c2_masked of_oxm_nsh_c2_masked
 */

/**
 * Create a new of_oxm_nsh_c2_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c2_masked
 */

of_object_t *
of_oxm_nsh_c2_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C2_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c2_masked_init(obj, version, bytes, 0);
    of_oxm_nsh_c2_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c2_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c2_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C2_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C2_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C2_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c2_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c2_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c2_masked_value_get(
    of_oxm_nsh_c2_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C2_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c2_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c2_masked.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c2_masked_value_set(
    of_oxm_nsh_c2_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C2_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_nsh_c2_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c2_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c2_masked_value_mask_get(
    of_oxm_nsh_c2_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C2_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_nsh_c2_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c2_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_nsh_c2_masked_value_mask_set(
    of_oxm_nsh_c2_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C2_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c3_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1ea04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c3 of_oxm_nsh_c3
 */

/**
 * Create a new of_oxm_nsh_c3 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c3
 */

of_object_t *
of_oxm_nsh_c3_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C3];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c3_init(obj, version, bytes, 0);
    of_oxm_nsh_c3_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c3.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c3_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C3] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C3];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C3;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c3.
 * @param obj Pointer to an object of type of_oxm_nsh_c3.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c3_value_get(
    of_oxm_nsh_c3_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C3);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c3.
 * @param obj Pointer to an object of type of_oxm_nsh_c3.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c3_value_set(
    of_oxm_nsh_c3_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C3);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c3_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1eb08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c3_masked of_oxm_nsh_c3_masked
 */

/**
 * Create a new of_oxm_nsh_c3_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c3_masked
 */

of_object_t *
of_oxm_nsh_c3_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C3_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c3_masked_init(obj, version, bytes, 0);
    of_oxm_nsh_c3_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c3_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c3_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C3_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C3_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C3_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c3_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c3_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c3_masked_value_get(
    of_oxm_nsh_c3_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C3_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c3_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c3_masked.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c3_masked_value_set(
    of_oxm_nsh_c3_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C3_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_nsh_c3_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c3_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c3_masked_value_mask_get(
    of_oxm_nsh_c3_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C3_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_nsh_c3_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c3_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_nsh_c3_masked_value_mask_set(
    of_oxm_nsh_c3_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C3_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c4_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1ec04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c4 of_oxm_nsh_c4
 */

/**
 * Create a new of_oxm_nsh_c4 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c4
 */

of_object_t *
of_oxm_nsh_c4_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C4];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c4_init(obj, version, bytes, 0);
    of_oxm_nsh_c4_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c4.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c4_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C4] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C4];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C4;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c4.
 * @param obj Pointer to an object of type of_oxm_nsh_c4.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c4_value_get(
    of_oxm_nsh_c4_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C4);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c4.
 * @param obj Pointer to an object of type of_oxm_nsh_c4.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c4_value_set(
    of_oxm_nsh_c4_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C4);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_c4_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1ed08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_c4_masked of_oxm_nsh_c4_masked
 */

/**
 * Create a new of_oxm_nsh_c4_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_c4_masked
 */

of_object_t *
of_oxm_nsh_c4_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_C4_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_c4_masked_init(obj, version, bytes, 0);
    of_oxm_nsh_c4_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_c4_masked.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_c4_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_C4_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_C4_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_C4_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_c4_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c4_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c4_masked_value_get(
    of_oxm_nsh_c4_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C4_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_c4_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c4_masked.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_c4_masked_value_set(
    of_oxm_nsh_c4_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C4_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_nsh_c4_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c4_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_nsh_c4_masked_value_mask_get(
    of_oxm_nsh_c4_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C4_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_nsh_c4_masked.
 * @param obj Pointer to an object of type of_oxm_nsh_c4_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_nsh_c4_masked_value_mask_set(
    of_oxm_nsh_c4_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_C4_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

void
of_oxm_nsh_mdtype_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x1ee01); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_nsh_mdtype of_oxm_nsh_mdtype
 */

/**
 * Create a new of_oxm_nsh_mdtype object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_nsh_mdtype
 */

of_object_t *
of_oxm_nsh_mdtype_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_NSH_MDTYPE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_nsh_mdtype_init(obj, version, bytes, 0);
    of_oxm_nsh_mdtype_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_nsh_mdtype.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_oxm_nsh_mdtype_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_NSH_MDTYPE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_NSH_MDTYPE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_NSH_MDTYPE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_nsh_mdtype.
 * @param obj Pointer to an object of type of_oxm_nsh_mdtype.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_nsh_mdtype_value_get(
    of_oxm_nsh_mdtype_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_MDTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_nsh_mdtype.
 * @param obj Pointer to an object of type of_oxm_nsh_mdtype.
 * @param value The value to write into the object
 */
void
of_oxm_nsh_mdtype_value_set(
    of_oxm_nsh_mdtype_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_NSH_MDTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
