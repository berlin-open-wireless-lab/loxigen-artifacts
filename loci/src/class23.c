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
of_oxm_circuit_och_sigtype_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x85901); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_circuit_och_sigtype_masked of_oxm_circuit_och_sigtype_masked
 */

/**
 * Create a new of_oxm_circuit_och_sigtype_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_circuit_och_sigtype_masked
 */

of_object_t *
of_oxm_circuit_och_sigtype_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_circuit_och_sigtype_masked_init(obj, version, bytes, 0);
    of_oxm_circuit_och_sigtype_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_circuit_och_sigtype_masked.
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
of_oxm_circuit_och_sigtype_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_circuit_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_circuit_och_sigtype_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_circuit_och_sigtype_masked_value_get(
    of_oxm_circuit_och_sigtype_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_oxm_circuit_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_circuit_och_sigtype_masked.
 * @param value The value to write into the object
 */
void
of_oxm_circuit_och_sigtype_masked_value_set(
    of_oxm_circuit_och_sigtype_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get value_mask from an object of type of_oxm_circuit_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_circuit_och_sigtype_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_circuit_och_sigtype_masked_value_mask_get(
    of_oxm_circuit_och_sigtype_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value_mask in an object of type of_oxm_circuit_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_circuit_och_sigtype_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_circuit_och_sigtype_masked_value_mask_set(
    of_oxm_circuit_och_sigtype_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
of_oxm_exp_och_sigid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0a06); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_och_sigid of_oxm_exp_och_sigid
 */

/**
 * Create a new of_oxm_exp_och_sigid object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_och_sigid
 */

of_object_t *
of_oxm_exp_och_sigid_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_exp_och_sigid_init(obj, version, bytes, 0);
    of_oxm_exp_och_sigid_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_och_sigid.
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
of_oxm_exp_och_sigid_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_OCH_SIGID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_och_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigid_experimenter_get(
    of_oxm_exp_och_sigid_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_och_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_och_sigid_experimenter_set(
    of_oxm_exp_och_sigid_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_och_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid.
 * @param value Pointer to the child object of type
 * of_och_sig_id_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigid_value_get(
    of_oxm_exp_och_sigid_t *obj,
    of_och_sig_id_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_och_sig_id_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_exp_och_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid.
 * @param value The value to write into the object
 */
void
of_oxm_exp_och_sigid_value_set(
    of_oxm_exp_och_sigid_t *obj,
    of_och_sig_id_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_och_sig_id_set(wbuf, abs_offset, value);

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
of_oxm_exp_och_sigid_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0b06); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_och_sigid_masked of_oxm_exp_och_sigid_masked
 */

/**
 * Create a new of_oxm_exp_och_sigid_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_och_sigid_masked
 */

of_object_t *
of_oxm_exp_och_sigid_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGID_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_exp_och_sigid_masked_init(obj, version, bytes, 0);
    of_oxm_exp_och_sigid_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_och_sigid_masked.
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
of_oxm_exp_och_sigid_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGID_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGID_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_OCH_SIGID_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_och_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid_masked.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigid_masked_experimenter_get(
    of_oxm_exp_och_sigid_masked_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_och_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid_masked.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_och_sigid_masked_experimenter_set(
    of_oxm_exp_och_sigid_masked_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_och_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid_masked.
 * @param value Pointer to the child object of type
 * of_och_sig_id_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigid_masked_value_get(
    of_oxm_exp_och_sigid_masked_t *obj,
    of_och_sig_id_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_och_sig_id_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_exp_och_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid_masked.
 * @param value The value to write into the object
 */
void
of_oxm_exp_och_sigid_masked_value_set(
    of_oxm_exp_och_sigid_masked_t *obj,
    of_och_sig_id_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_och_sig_id_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_exp_och_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid_masked.
 * @param value_mask Pointer to the child object of type
 * of_och_sig_id_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigid_masked_value_mask_get(
    of_oxm_exp_och_sigid_masked_t *obj,
    of_och_sig_id_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_och_sig_id_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_exp_och_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigid_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_exp_och_sigid_masked_value_mask_set(
    of_oxm_exp_och_sigid_masked_t *obj,
    of_och_sig_id_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_och_sig_id_set(wbuf, abs_offset, value_mask);

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
of_oxm_exp_och_sigtype_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0801); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_och_sigtype of_oxm_exp_och_sigtype
 */

/**
 * Create a new of_oxm_exp_och_sigtype object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_och_sigtype
 */

of_object_t *
of_oxm_exp_och_sigtype_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGTYPE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_exp_och_sigtype_init(obj, version, bytes, 0);
    of_oxm_exp_och_sigtype_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_och_sigtype.
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
of_oxm_exp_och_sigtype_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGTYPE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGTYPE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_OCH_SIGTYPE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_och_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigtype_experimenter_get(
    of_oxm_exp_och_sigtype_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_och_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_och_sigtype_experimenter_set(
    of_oxm_exp_och_sigtype_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_och_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigtype_value_get(
    of_oxm_exp_och_sigtype_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_exp_och_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype.
 * @param value The value to write into the object
 */
void
of_oxm_exp_och_sigtype_value_set(
    of_oxm_exp_och_sigtype_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
of_oxm_exp_och_sigtype_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0901); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_och_sigtype_masked of_oxm_exp_och_sigtype_masked
 */

/**
 * Create a new of_oxm_exp_och_sigtype_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_och_sigtype_masked
 */

of_object_t *
of_oxm_exp_och_sigtype_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGTYPE_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_exp_och_sigtype_masked_init(obj, version, bytes, 0);
    of_oxm_exp_och_sigtype_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_och_sigtype_masked.
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
of_oxm_exp_och_sigtype_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGTYPE_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_OCH_SIGTYPE_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_OCH_SIGTYPE_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype_masked.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigtype_masked_experimenter_get(
    of_oxm_exp_och_sigtype_masked_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype_masked.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_och_sigtype_masked_experimenter_set(
    of_oxm_exp_och_sigtype_masked_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigtype_masked_value_get(
    of_oxm_exp_och_sigtype_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_exp_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype_masked.
 * @param value The value to write into the object
 */
void
of_oxm_exp_och_sigtype_masked_value_set(
    of_oxm_exp_och_sigtype_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Get value_mask from an object of type of_oxm_exp_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_exp_och_sigtype_masked_value_mask_get(
    of_oxm_exp_och_sigtype_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 9;
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
 * Set value_mask in an object of type of_oxm_exp_och_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_och_sigtype_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_exp_och_sigtype_masked_value_mask_set(
    of_oxm_exp_och_sigtype_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_OCH_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 9;
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
of_oxm_exp_odu_sigid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0610); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_odu_sigid of_oxm_exp_odu_sigid
 */

/**
 * Create a new of_oxm_exp_odu_sigid object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_odu_sigid
 */

of_object_t *
of_oxm_exp_odu_sigid_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGID];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_oxm_exp_odu_sigid_init(obj, version, bytes, 0);
    of_oxm_exp_odu_sigid_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_odu_sigid.
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
of_oxm_exp_odu_sigid_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_ODU_SIGID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_odu_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigid_experimenter_get(
    of_oxm_exp_odu_sigid_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_odu_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_odu_sigid_experimenter_set(
    of_oxm_exp_odu_sigid_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_odu_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid.
 * @param value Pointer to the child object of type
 * of_odu_sig_id_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigid_value_get(
    of_oxm_exp_odu_sigid_t *obj,
    of_odu_sig_id_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_odu_sig_id_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_exp_odu_sigid.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid.
 * @param value The value to write into the object
 */
void
of_oxm_exp_odu_sigid_value_set(
    of_oxm_exp_odu_sigid_t *obj,
    of_odu_sig_id_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_odu_sig_id_set(wbuf, abs_offset, value);

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
of_oxm_exp_odu_sigid_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0710); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_odu_sigid_masked of_oxm_exp_odu_sigid_masked
 */

/**
 * Create a new of_oxm_exp_odu_sigid_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_odu_sigid_masked
 */

of_object_t *
of_oxm_exp_odu_sigid_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGID_MASKED];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_oxm_exp_odu_sigid_masked_init(obj, version, bytes, 0);
    of_oxm_exp_odu_sigid_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_odu_sigid_masked.
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
of_oxm_exp_odu_sigid_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGID_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGID_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_ODU_SIGID_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_odu_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid_masked.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigid_masked_experimenter_get(
    of_oxm_exp_odu_sigid_masked_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_odu_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid_masked.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_odu_sigid_masked_experimenter_set(
    of_oxm_exp_odu_sigid_masked_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_odu_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid_masked.
 * @param value Pointer to the child object of type
 * of_odu_sig_id_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigid_masked_value_get(
    of_oxm_exp_odu_sigid_masked_t *obj,
    of_odu_sig_id_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_odu_sig_id_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_exp_odu_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid_masked.
 * @param value The value to write into the object
 */
void
of_oxm_exp_odu_sigid_masked_value_set(
    of_oxm_exp_odu_sigid_masked_t *obj,
    of_odu_sig_id_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_odu_sig_id_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_exp_odu_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid_masked.
 * @param value_mask Pointer to the child object of type
 * of_odu_sig_id_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigid_masked_value_mask_get(
    of_oxm_exp_odu_sigid_masked_t *obj,
    of_odu_sig_id_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = _OXM_EXP_ODU_SIGID_MASKED_VALUE_MASK_OFFSET(obj);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_odu_sig_id_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_exp_odu_sigid_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigid_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_exp_odu_sigid_masked_value_mask_set(
    of_oxm_exp_odu_sigid_masked_t *obj,
    of_odu_sig_id_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = _OXM_EXP_ODU_SIGID_MASKED_VALUE_MASK_OFFSET(obj);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_odu_sig_id_set(wbuf, abs_offset, value_mask);

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
of_oxm_exp_odu_sigtype_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0401); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_odu_sigtype of_oxm_exp_odu_sigtype
 */

/**
 * Create a new of_oxm_exp_odu_sigtype object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_odu_sigtype
 */

of_object_t *
of_oxm_exp_odu_sigtype_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGTYPE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_exp_odu_sigtype_init(obj, version, bytes, 0);
    of_oxm_exp_odu_sigtype_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_odu_sigtype.
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
of_oxm_exp_odu_sigtype_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGTYPE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGTYPE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_ODU_SIGTYPE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_odu_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigtype_experimenter_get(
    of_oxm_exp_odu_sigtype_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_odu_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_odu_sigtype_experimenter_set(
    of_oxm_exp_odu_sigtype_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_odu_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigtype_value_get(
    of_oxm_exp_odu_sigtype_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_exp_odu_sigtype.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype.
 * @param value The value to write into the object
 */
void
of_oxm_exp_odu_sigtype_value_set(
    of_oxm_exp_odu_sigtype_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
of_oxm_exp_odu_sigtype_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0501); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0xff000007); /* experimenter */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_exp_odu_sigtype_masked of_oxm_exp_odu_sigtype_masked
 */

/**
 * Create a new of_oxm_exp_odu_sigtype_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_exp_odu_sigtype_masked
 */

of_object_t *
of_oxm_exp_odu_sigtype_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGTYPE_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_exp_odu_sigtype_masked_init(obj, version, bytes, 0);
    of_oxm_exp_odu_sigtype_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_exp_odu_sigtype_masked.
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
of_oxm_exp_odu_sigtype_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGTYPE_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_EXP_ODU_SIGTYPE_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_EXP_ODU_SIGTYPE_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_oxm_exp_odu_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype_masked.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigtype_masked_experimenter_get(
    of_oxm_exp_odu_sigtype_masked_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_oxm_exp_odu_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype_masked.
 * @param experimenter The value to write into the object
 */
void
of_oxm_exp_odu_sigtype_masked_experimenter_set(
    of_oxm_exp_odu_sigtype_masked_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_exp_odu_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigtype_masked_value_get(
    of_oxm_exp_odu_sigtype_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_exp_odu_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype_masked.
 * @param value The value to write into the object
 */
void
of_oxm_exp_odu_sigtype_masked_value_set(
    of_oxm_exp_odu_sigtype_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Get value_mask from an object of type of_oxm_exp_odu_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_exp_odu_sigtype_masked_value_mask_get(
    of_oxm_exp_odu_sigtype_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 9;
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
 * Set value_mask in an object of type of_oxm_exp_odu_sigtype_masked.
 * @param obj Pointer to an object of type of_oxm_exp_odu_sigtype_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_exp_odu_sigtype_masked_value_mask_set(
    of_oxm_exp_odu_sigtype_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_EXP_ODU_SIGTYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 9;
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
of_oxm_ipv6_exthdr_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004e02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_exthdr of_oxm_ipv6_exthdr
 */

/**
 * Create a new of_oxm_ipv6_exthdr object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_exthdr
 */

of_object_t *
of_oxm_ipv6_exthdr_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_EXTHDR];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_exthdr_init(obj, version, bytes, 0);
    of_oxm_ipv6_exthdr_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_exthdr.
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
of_oxm_ipv6_exthdr_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_EXTHDR] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_EXTHDR];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_EXTHDR;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_exthdr.
 * @param obj Pointer to an object of type of_oxm_ipv6_exthdr.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ipv6_exthdr_value_get(
    of_oxm_ipv6_exthdr_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_EXTHDR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_exthdr.
 * @param obj Pointer to an object of type of_oxm_ipv6_exthdr.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_exthdr_value_set(
    of_oxm_ipv6_exthdr_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_EXTHDR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

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
of_oxm_ipv6_exthdr_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004f04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ipv6_exthdr_masked of_oxm_ipv6_exthdr_masked
 */

/**
 * Create a new of_oxm_ipv6_exthdr_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ipv6_exthdr_masked
 */

of_object_t *
of_oxm_ipv6_exthdr_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_IPV6_EXTHDR_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ipv6_exthdr_masked_init(obj, version, bytes, 0);
    of_oxm_ipv6_exthdr_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ipv6_exthdr_masked.
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
of_oxm_ipv6_exthdr_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_IPV6_EXTHDR_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_IPV6_EXTHDR_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_IPV6_EXTHDR_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_ipv6_exthdr_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_exthdr_masked.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ipv6_exthdr_masked_value_get(
    of_oxm_ipv6_exthdr_masked_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_EXTHDR_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ipv6_exthdr_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_exthdr_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ipv6_exthdr_masked_value_set(
    of_oxm_ipv6_exthdr_masked_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_EXTHDR_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ipv6_exthdr_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_exthdr_masked.
 * @param value_mask Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ipv6_exthdr_masked_value_mask_get(
    of_oxm_ipv6_exthdr_masked_t *obj,
    uint16_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_EXTHDR_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 6;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ipv6_exthdr_masked.
 * @param obj Pointer to an object of type of_oxm_ipv6_exthdr_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ipv6_exthdr_masked_value_mask_set(
    of_oxm_ipv6_exthdr_masked_t *obj,
    uint16_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_IPV6_EXTHDR_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 6;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value_mask);

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
of_oxm_mpls_bos_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004801); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_mpls_bos of_oxm_mpls_bos
 */

/**
 * Create a new of_oxm_mpls_bos object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_mpls_bos
 */

of_object_t *
of_oxm_mpls_bos_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_MPLS_BOS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_bos_init(obj, version, bytes, 0);
    of_oxm_mpls_bos_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_mpls_bos.
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
of_oxm_mpls_bos_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_MPLS_BOS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_MPLS_BOS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_MPLS_BOS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_mpls_bos.
 * @param obj Pointer to an object of type of_oxm_mpls_bos.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_mpls_bos_value_get(
    of_oxm_mpls_bos_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_BOS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_mpls_bos.
 * @param obj Pointer to an object of type of_oxm_mpls_bos.
 * @param value The value to write into the object
 */
void
of_oxm_mpls_bos_value_set(
    of_oxm_mpls_bos_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_BOS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_oxm_mpls_bos_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004902); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_mpls_bos_masked of_oxm_mpls_bos_masked
 */

/**
 * Create a new of_oxm_mpls_bos_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_mpls_bos_masked
 */

of_object_t *
of_oxm_mpls_bos_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_MPLS_BOS_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_mpls_bos_masked_init(obj, version, bytes, 0);
    of_oxm_mpls_bos_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_mpls_bos_masked.
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
of_oxm_mpls_bos_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_MPLS_BOS_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_MPLS_BOS_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_MPLS_BOS_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_mpls_bos_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_bos_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_mpls_bos_masked_value_get(
    of_oxm_mpls_bos_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_BOS_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_mpls_bos_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_bos_masked.
 * @param value The value to write into the object
 */
void
of_oxm_mpls_bos_masked_value_set(
    of_oxm_mpls_bos_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_BOS_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get value_mask from an object of type of_oxm_mpls_bos_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_bos_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_mpls_bos_masked_value_mask_get(
    of_oxm_mpls_bos_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_BOS_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value_mask in an object of type of_oxm_mpls_bos_masked.
 * @param obj Pointer to an object of type of_oxm_mpls_bos_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_mpls_bos_masked_value_mask_set(
    of_oxm_mpls_bos_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_MPLS_BOS_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_oxm_och_sigatt_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x85c04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_och_sigatt of_oxm_och_sigatt
 */

/**
 * Create a new of_oxm_och_sigatt object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_och_sigatt
 */

of_object_t *
of_oxm_och_sigatt_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_och_sigatt_init(obj, version, bytes, 0);
    of_oxm_och_sigatt_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_och_sigatt.
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
of_oxm_och_sigatt_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OCH_SIGATT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OCH_SIGATT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_och_sigatt.
 * @param obj Pointer to an object of type of_oxm_och_sigatt.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_och_sigatt_value_get(
    of_oxm_och_sigatt_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_oxm_och_sigatt.
 * @param obj Pointer to an object of type of_oxm_och_sigatt.
 * @param value The value to write into the object
 */
void
of_oxm_och_sigatt_value_set(
    of_oxm_och_sigatt_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
of_oxm_och_sigatt_basic_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80005c04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_och_sigatt_basic of_oxm_och_sigatt_basic
 */

/**
 * Create a new of_oxm_och_sigatt_basic object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_och_sigatt_basic
 */

of_object_t *
of_oxm_och_sigatt_basic_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT_BASIC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_och_sigatt_basic_init(obj, version, bytes, 0);
    of_oxm_och_sigatt_basic_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_och_sigatt_basic.
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
of_oxm_och_sigatt_basic_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OCH_SIGATT_BASIC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT_BASIC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OCH_SIGATT_BASIC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_och_sigatt_basic.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_basic.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_och_sigatt_basic_value_get(
    of_oxm_och_sigatt_basic_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_BASIC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_oxm_och_sigatt_basic.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_basic.
 * @param value The value to write into the object
 */
void
of_oxm_och_sigatt_basic_value_set(
    of_oxm_och_sigatt_basic_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_BASIC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
of_oxm_och_sigatt_basic_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80005d04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_och_sigatt_basic_masked of_oxm_och_sigatt_basic_masked
 */

/**
 * Create a new of_oxm_och_sigatt_basic_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_och_sigatt_basic_masked
 */

of_object_t *
of_oxm_och_sigatt_basic_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT_BASIC_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_och_sigatt_basic_masked_init(obj, version, bytes, 0);
    of_oxm_och_sigatt_basic_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_och_sigatt_basic_masked.
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
of_oxm_och_sigatt_basic_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OCH_SIGATT_BASIC_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT_BASIC_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OCH_SIGATT_BASIC_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_och_sigatt_basic_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_basic_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_och_sigatt_basic_masked_value_get(
    of_oxm_och_sigatt_basic_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_BASIC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_oxm_och_sigatt_basic_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_basic_masked.
 * @param value The value to write into the object
 */
void
of_oxm_och_sigatt_basic_masked_value_set(
    of_oxm_och_sigatt_basic_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_BASIC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get value_mask from an object of type of_oxm_och_sigatt_basic_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_basic_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_och_sigatt_basic_masked_value_mask_get(
    of_oxm_och_sigatt_basic_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_BASIC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value_mask in an object of type of_oxm_och_sigatt_basic_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_basic_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_och_sigatt_basic_masked_value_mask_set(
    of_oxm_och_sigatt_basic_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_BASIC_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
of_oxm_och_sigatt_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x85d04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_och_sigatt_masked of_oxm_och_sigatt_masked
 */

/**
 * Create a new of_oxm_och_sigatt_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_och_sigatt_masked
 */

of_object_t *
of_oxm_och_sigatt_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_och_sigatt_masked_init(obj, version, bytes, 0);
    of_oxm_och_sigatt_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_och_sigatt_masked.
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
of_oxm_och_sigatt_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OCH_SIGATT_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OCH_SIGATT_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OCH_SIGATT_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_och_sigatt_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_och_sigatt_masked_value_get(
    of_oxm_och_sigatt_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value in an object of type of_oxm_och_sigatt_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_masked.
 * @param value The value to write into the object
 */
void
of_oxm_och_sigatt_masked_value_set(
    of_oxm_och_sigatt_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Get value_mask from an object of type of_oxm_och_sigatt_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_och_sigatt_masked_value_mask_get(
    of_oxm_och_sigatt_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
 * Set value_mask in an object of type of_oxm_och_sigatt_masked.
 * @param obj Pointer to an object of type of_oxm_och_sigatt_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_och_sigatt_masked_value_mask_set(
    of_oxm_och_sigatt_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OCH_SIGATT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
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
of_oxm_ofdpa_mpls_l2_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff1008); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_mpls_l2_port of_oxm_ofdpa_mpls_l2_port
 */

/**
 * Create a new of_oxm_ofdpa_mpls_l2_port object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_mpls_l2_port
 */

of_object_t *
of_oxm_ofdpa_mpls_l2_port_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_L2_PORT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_mpls_l2_port_init(obj, version, bytes, 0);
    of_oxm_ofdpa_mpls_l2_port_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_mpls_l2_port.
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
of_oxm_ofdpa_mpls_l2_port_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_L2_PORT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_L2_PORT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_MPLS_L2_PORT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_l2_port_experimenter_id_get(
    of_oxm_ofdpa_mpls_l2_port_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_mpls_l2_port_experimenter_id_set(
    of_oxm_ofdpa_mpls_l2_port_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_l2_port_value_get(
    of_oxm_ofdpa_mpls_l2_port_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_mpls_l2_port_value_set(
    of_oxm_ofdpa_mpls_l2_port_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
of_oxm_ofdpa_mpls_l2_port_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff110c); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_mpls_l2_port_masked of_oxm_ofdpa_mpls_l2_port_masked
 */

/**
 * Create a new of_oxm_ofdpa_mpls_l2_port_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_mpls_l2_port_masked
 */

of_object_t *
of_oxm_ofdpa_mpls_l2_port_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_L2_PORT_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_mpls_l2_port_masked_init(obj, version, bytes, 0);
    of_oxm_ofdpa_mpls_l2_port_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_mpls_l2_port_masked.
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
of_oxm_ofdpa_mpls_l2_port_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_L2_PORT_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_L2_PORT_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_MPLS_L2_PORT_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_l2_port_masked_experimenter_id_get(
    of_oxm_ofdpa_mpls_l2_port_masked_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_mpls_l2_port_masked_experimenter_id_set(
    of_oxm_ofdpa_mpls_l2_port_masked_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_l2_port_masked_value_get(
    of_oxm_ofdpa_mpls_l2_port_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_mpls_l2_port_masked_value_set(
    of_oxm_ofdpa_mpls_l2_port_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Get value_mask from an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_l2_port_masked_value_mask_get(
    of_oxm_ofdpa_mpls_l2_port_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
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
 * Set value_mask in an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_l2_port_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ofdpa_mpls_l2_port_masked_value_mask_set(
    of_oxm_ofdpa_mpls_l2_port_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_L2_PORT_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
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
of_oxm_ofdpa_mpls_type_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff2e06); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_mpls_type of_oxm_ofdpa_mpls_type
 */

/**
 * Create a new of_oxm_ofdpa_mpls_type object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_mpls_type
 */

of_object_t *
of_oxm_ofdpa_mpls_type_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_TYPE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_mpls_type_init(obj, version, bytes, 0);
    of_oxm_ofdpa_mpls_type_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_mpls_type.
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
of_oxm_ofdpa_mpls_type_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_TYPE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_TYPE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_MPLS_TYPE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_mpls_type.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_type_experimenter_id_get(
    of_oxm_ofdpa_mpls_type_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_mpls_type.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_mpls_type_experimenter_id_set(
    of_oxm_ofdpa_mpls_type_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_mpls_type.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_type_value_get(
    of_oxm_ofdpa_mpls_type_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ofdpa_mpls_type.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_mpls_type_value_set(
    of_oxm_ofdpa_mpls_type_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

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
of_oxm_ofdpa_mpls_type_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff2f06); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_mpls_type_masked of_oxm_ofdpa_mpls_type_masked
 */

/**
 * Create a new of_oxm_ofdpa_mpls_type_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_mpls_type_masked
 */

of_object_t *
of_oxm_ofdpa_mpls_type_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_TYPE_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_mpls_type_masked_init(obj, version, bytes, 0);
    of_oxm_ofdpa_mpls_type_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_mpls_type_masked.
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
of_oxm_ofdpa_mpls_type_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_TYPE_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_MPLS_TYPE_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_MPLS_TYPE_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_type_masked_experimenter_id_get(
    of_oxm_ofdpa_mpls_type_masked_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_mpls_type_masked_experimenter_id_set(
    of_oxm_ofdpa_mpls_type_masked_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_type_masked_value_get(
    of_oxm_ofdpa_mpls_type_masked_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_mpls_type_masked_value_set(
    of_oxm_ofdpa_mpls_type_masked_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param value_mask Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ofdpa_mpls_type_masked_value_mask_get(
    of_oxm_ofdpa_mpls_type_masked_t *obj,
    uint16_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_mpls_type_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ofdpa_mpls_type_masked_value_mask_set(
    of_oxm_ofdpa_mpls_type_masked_t *obj,
    uint16_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_MPLS_TYPE_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value_mask);

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
of_oxm_ofdpa_ovid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff1406); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_ovid of_oxm_ofdpa_ovid
 */

/**
 * Create a new of_oxm_ofdpa_ovid object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_ovid
 */

of_object_t *
of_oxm_ofdpa_ovid_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_OVID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_ovid_init(obj, version, bytes, 0);
    of_oxm_ofdpa_ovid_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_ovid.
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
of_oxm_ofdpa_ovid_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_OVID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_OVID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_OVID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_ovid.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_ovid_experimenter_id_get(
    of_oxm_ofdpa_ovid_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_ovid.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_ovid_experimenter_id_set(
    of_oxm_ofdpa_ovid_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_ovid.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ofdpa_ovid_value_get(
    of_oxm_ofdpa_ovid_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ofdpa_ovid.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_ovid_value_set(
    of_oxm_ofdpa_ovid_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

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
of_oxm_ofdpa_ovid_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff1506); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_ovid_masked of_oxm_ofdpa_ovid_masked
 */

/**
 * Create a new of_oxm_ofdpa_ovid_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_ovid_masked
 */

of_object_t *
of_oxm_ofdpa_ovid_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_OVID_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_ovid_masked_init(obj, version, bytes, 0);
    of_oxm_ofdpa_ovid_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_ovid_masked.
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
of_oxm_ofdpa_ovid_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_OVID_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_OVID_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_OVID_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_ovid_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid_masked.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_ovid_masked_experimenter_id_get(
    of_oxm_ofdpa_ovid_masked_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_ovid_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid_masked.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_ovid_masked_experimenter_id_set(
    of_oxm_ofdpa_ovid_masked_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_ovid_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid_masked.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ofdpa_ovid_masked_value_get(
    of_oxm_ofdpa_ovid_masked_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_ofdpa_ovid_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_ovid_masked_value_set(
    of_oxm_ofdpa_ovid_masked_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_ofdpa_ovid_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid_masked.
 * @param value_mask Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_ofdpa_ovid_masked_value_mask_get(
    of_oxm_ofdpa_ovid_masked_t *obj,
    uint16_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_ofdpa_ovid_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_ovid_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ofdpa_ovid_masked_value_mask_set(
    of_oxm_ofdpa_ovid_masked_t *obj,
    uint16_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_OVID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, value_mask);

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
of_oxm_ofdpa_qos_index_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0a05); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_qos_index of_oxm_ofdpa_qos_index
 */

/**
 * Create a new of_oxm_ofdpa_qos_index object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_qos_index
 */

of_object_t *
of_oxm_ofdpa_qos_index_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_QOS_INDEX];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_qos_index_init(obj, version, bytes, 0);
    of_oxm_ofdpa_qos_index_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_qos_index.
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
of_oxm_ofdpa_qos_index_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_QOS_INDEX] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_QOS_INDEX];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_QOS_INDEX;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_qos_index.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_qos_index_experimenter_id_get(
    of_oxm_ofdpa_qos_index_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_qos_index.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_qos_index_experimenter_id_set(
    of_oxm_ofdpa_qos_index_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_qos_index.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_ofdpa_qos_index_value_get(
    of_oxm_ofdpa_qos_index_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_ofdpa_qos_index.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_qos_index_value_set(
    of_oxm_ofdpa_qos_index_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
of_oxm_ofdpa_qos_index_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0xffff0b05); /* type_len */
        *(uint32_t *)(buf + 4) = U32_HTON(0x1018); /* experimenter_id */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_ofdpa_qos_index_masked of_oxm_ofdpa_qos_index_masked
 */

/**
 * Create a new of_oxm_ofdpa_qos_index_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_ofdpa_qos_index_masked
 */

of_object_t *
of_oxm_ofdpa_qos_index_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_OFDPA_QOS_INDEX_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_ofdpa_qos_index_masked_init(obj, version, bytes, 0);
    of_oxm_ofdpa_qos_index_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_ofdpa_qos_index_masked.
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
of_oxm_ofdpa_qos_index_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_OFDPA_QOS_INDEX_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_OFDPA_QOS_INDEX_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_OFDPA_QOS_INDEX_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter_id from an object of type of_oxm_ofdpa_qos_index_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index_masked.
 * @param experimenter_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_ofdpa_qos_index_masked_experimenter_id_get(
    of_oxm_ofdpa_qos_index_masked_t *obj,
    uint32_t *experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter_id in an object of type of_oxm_ofdpa_qos_index_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index_masked.
 * @param experimenter_id The value to write into the object
 */
void
of_oxm_ofdpa_qos_index_masked_experimenter_id_set(
    of_oxm_ofdpa_qos_index_masked_t *obj,
    uint32_t experimenter_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value from an object of type of_oxm_ofdpa_qos_index_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_ofdpa_qos_index_masked_value_get(
    of_oxm_ofdpa_qos_index_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Set value in an object of type of_oxm_ofdpa_qos_index_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index_masked.
 * @param value The value to write into the object
 */
void
of_oxm_ofdpa_qos_index_masked_value_set(
    of_oxm_ofdpa_qos_index_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
 * Get value_mask from an object of type of_oxm_ofdpa_qos_index_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_ofdpa_qos_index_masked_value_mask_get(
    of_oxm_ofdpa_qos_index_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 9;
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
 * Set value_mask in an object of type of_oxm_ofdpa_qos_index_masked.
 * @param obj Pointer to an object of type of_oxm_ofdpa_qos_index_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_ofdpa_qos_index_masked_value_mask_set(
    of_oxm_ofdpa_qos_index_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_OFDPA_QOS_INDEX_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 9;
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
of_oxm_tunnel_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004c08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_tunnel_id of_oxm_tunnel_id
 */

/**
 * Create a new of_oxm_tunnel_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_tunnel_id
 */

of_object_t *
of_oxm_tunnel_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_TUNNEL_ID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_tunnel_id_init(obj, version, bytes, 0);
    of_oxm_tunnel_id_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_tunnel_id.
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
of_oxm_tunnel_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_TUNNEL_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_TUNNEL_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_TUNNEL_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_tunnel_id.
 * @param obj Pointer to an object of type of_oxm_tunnel_id.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_oxm_tunnel_id_value_get(
    of_oxm_tunnel_id_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_TUNNEL_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_tunnel_id.
 * @param obj Pointer to an object of type of_oxm_tunnel_id.
 * @param value The value to write into the object
 */
void
of_oxm_tunnel_id_value_set(
    of_oxm_tunnel_id_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_TUNNEL_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_oxm_tunnel_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80004d10); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_tunnel_id_masked of_oxm_tunnel_id_masked
 */

/**
 * Create a new of_oxm_tunnel_id_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_tunnel_id_masked
 */

of_object_t *
of_oxm_tunnel_id_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_TUNNEL_ID_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_tunnel_id_masked_init(obj, version, bytes, 0);
    of_oxm_tunnel_id_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_tunnel_id_masked.
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
of_oxm_tunnel_id_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_TUNNEL_ID_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_TUNNEL_ID_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_TUNNEL_ID_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_tunnel_id_masked.
 * @param obj Pointer to an object of type of_oxm_tunnel_id_masked.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_oxm_tunnel_id_masked_value_get(
    of_oxm_tunnel_id_masked_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_TUNNEL_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value in an object of type of_oxm_tunnel_id_masked.
 * @param obj Pointer to an object of type of_oxm_tunnel_id_masked.
 * @param value The value to write into the object
 */
void
of_oxm_tunnel_id_masked_value_set(
    of_oxm_tunnel_id_masked_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_TUNNEL_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get value_mask from an object of type of_oxm_tunnel_id_masked.
 * @param obj Pointer to an object of type of_oxm_tunnel_id_masked.
 * @param value_mask Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_oxm_tunnel_id_masked_value_mask_get(
    of_oxm_tunnel_id_masked_t *obj,
    uint64_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_TUNNEL_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set value_mask in an object of type of_oxm_tunnel_id_masked.
 * @param obj Pointer to an object of type of_oxm_tunnel_id_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_tunnel_id_masked_value_mask_set(
    of_oxm_tunnel_id_masked_t *obj,
    uint64_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_TUNNEL_ID_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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



/**
 * \defgroup of_port_desc_prop_optical_transport of_port_desc_prop_optical_transport
 */

/**
 * Create a new of_port_desc_prop_optical_transport object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_prop_optical_transport
 */

of_object_t *
of_port_desc_prop_optical_transport_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_OPTICAL_TRANSPORT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_prop_optical_transport_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_prop_optical_transport.
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
of_port_desc_prop_optical_transport_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_PROP_OPTICAL_TRANSPORT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_PROP_OPTICAL_TRANSPORT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_PROP_OPTICAL_TRANSPORT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get port_signal_type from an object of type of_port_desc_prop_optical_transport.
 * @param obj Pointer to an object of type of_port_desc_prop_optical_transport.
 * @param port_signal_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_transport_port_signal_type_get(
    of_port_desc_prop_optical_transport_t *obj,
    uint8_t *port_signal_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL_TRANSPORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, port_signal_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_signal_type in an object of type of_port_desc_prop_optical_transport.
 * @param obj Pointer to an object of type of_port_desc_prop_optical_transport.
 * @param port_signal_type The value to write into the object
 */
void
of_port_desc_prop_optical_transport_port_signal_type_set(
    of_port_desc_prop_optical_transport_t *obj,
    uint8_t port_signal_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL_TRANSPORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, port_signal_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get reserved from an object of type of_port_desc_prop_optical_transport.
 * @param obj Pointer to an object of type of_port_desc_prop_optical_transport.
 * @param reserved Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_transport_reserved_get(
    of_port_desc_prop_optical_transport_t *obj,
    uint8_t *reserved)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL_TRANSPORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, reserved);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set reserved in an object of type of_port_desc_prop_optical_transport.
 * @param obj Pointer to an object of type of_port_desc_prop_optical_transport.
 * @param reserved The value to write into the object
 */
void
of_port_desc_prop_optical_transport_reserved_set(
    of_port_desc_prop_optical_transport_t *obj,
    uint8_t reserved)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL_TRANSPORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 5;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, reserved);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_type from an object of type of_port_desc_prop_optical_transport.
 * @param obj Pointer to an object of type of_port_desc_prop_optical_transport.
 * @param port_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_desc_prop_optical_transport_port_type_get(
    of_port_desc_prop_optical_transport_t *obj,
    uint8_t *port_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL_TRANSPORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 7;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, port_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_type in an object of type of_port_desc_prop_optical_transport.
 * @param obj Pointer to an object of type of_port_desc_prop_optical_transport.
 * @param port_type The value to write into the object
 */
void
of_port_desc_prop_optical_transport_port_type_set(
    of_port_desc_prop_optical_transport_t *obj,
    uint8_t port_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_PROP_OPTICAL_TRANSPORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 7;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, port_type);

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
of_port_desc_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xd); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_stats_reply of_port_desc_stats_reply
 */

/**
 * Create a new of_port_desc_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_stats_reply
 */

of_object_t *
of_port_desc_stats_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_STATS_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_desc_stats_reply_init(obj, version, bytes, 0);
    of_port_desc_stats_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_stats_reply.
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
of_port_desc_stats_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_STATS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_port_desc_stats_reply.
 * @param obj Pointer to an object of type of_port_desc_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_stats_reply_xid_get(
    of_port_desc_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_port_desc_stats_reply.
 * @param obj Pointer to an object of type of_port_desc_stats_reply.
 * @param xid The value to write into the object
 */
void
of_port_desc_stats_reply_xid_set(
    of_port_desc_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_port_desc_stats_reply.
 * @param obj Pointer to an object of type of_port_desc_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_port_desc_stats_reply_flags_get(
    of_port_desc_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_port_desc_stats_reply.
 * @param obj Pointer to an object of type of_port_desc_stats_reply.
 * @param flags The value to write into the object
 */
void
of_port_desc_stats_reply_flags_set(
    of_port_desc_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_port_desc_t to the parent of type of_port_desc_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_port_desc_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_port_desc_t to be filled out.
 * \ingroup of_port_desc_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_desc_stats_reply_entries_bind(
    of_port_desc_stats_reply_t *obj,
    of_list_port_desc_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_port_desc_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, entries, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_port_desc_t from
 * a of_port_desc_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_port_desc_stats_reply_t
 * @returns A pointer to a new instance of type of_list_port_desc_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_port_desc_t *
of_port_desc_stats_reply_entries_get(of_port_desc_stats_reply_t *obj) {
    of_list_port_desc_t _entries;
    of_list_port_desc_t *_entries_ptr;

    of_port_desc_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_port_desc_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_port_desc_stats_reply.
 * @param obj Pointer to an object of type of_port_desc_stats_reply.
 * @param entries Pointer to the child of type of_list_port_desc_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_desc_stats_reply_entries_set(
    of_port_desc_stats_reply_t *obj,
    of_list_port_desc_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == entries->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)entries, entries->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
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
of_port_desc_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xd); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_port_desc_stats_request of_port_desc_stats_request
 */

/**
 * Create a new of_port_desc_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_desc_stats_request
 */

of_object_t *
of_port_desc_stats_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_DESC_STATS_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_desc_stats_request_init(obj, version, bytes, 0);
    of_port_desc_stats_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_port_desc_stats_request.
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
of_port_desc_stats_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_DESC_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_DESC_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_DESC_STATS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_port_desc_stats_request.
 * @param obj Pointer to an object of type of_port_desc_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_desc_stats_request_xid_get(
    of_port_desc_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_port_desc_stats_request.
 * @param obj Pointer to an object of type of_port_desc_stats_request.
 * @param xid The value to write into the object
 */
void
of_port_desc_stats_request_xid_set(
    of_port_desc_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_port_desc_stats_request.
 * @param obj Pointer to an object of type of_port_desc_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_port_desc_stats_request_flags_get(
    of_port_desc_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_port_desc_stats_request.
 * @param obj Pointer to an object of type of_port_desc_stats_request.
 * @param flags The value to write into the object
 */
void
of_port_desc_stats_request_flags_set(
    of_port_desc_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_DESC_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

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



/**
 * \defgroup of_port_optical of_port_optical
 */

/**
 * Create a new of_port_optical object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_optical
 */

of_object_t *
of_port_optical_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_OPTICAL];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_optical_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_optical.
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
of_port_optical_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_OPTICAL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_OPTICAL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_OPTICAL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get port_no from an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_port_optical_port_no_get(
    of_port_optical_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param port_no The value to write into the object
 */
void
of_port_optical_port_no_set(
    of_port_optical_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hw_addr from an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param hw_addr Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_port_optical_hw_addr_get(
    of_port_optical_t *obj,
    of_mac_addr_t *hw_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, hw_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hw_addr in an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param hw_addr The value to write into the object
 */
void
of_port_optical_hw_addr_set(
    of_port_optical_t *obj,
    of_mac_addr_t hw_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, hw_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get name from an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param name Pointer to the child object of type
 * of_port_name_t to be filled out.
 *
 */
void
of_port_optical_name_get(
    of_port_optical_t *obj,
    of_port_name_t *name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_name_get(wbuf, abs_offset, name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set name in an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param name The value to write into the object
 */
void
of_port_optical_name_set(
    of_port_optical_t *obj,
    of_port_name_t name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_name_set(wbuf, abs_offset, name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get config from an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param config Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_optical_config_get(
    of_port_optical_t *obj,
    uint32_t *config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set config in an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param config The value to write into the object
 */
void
of_port_optical_config_set(
    of_port_optical_t *obj,
    uint32_t config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get state from an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param state Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_port_optical_state_get(
    of_port_optical_t *obj,
    uint32_t *state)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, state);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set state in an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param state The value to write into the object
 */
void
of_port_optical_state_set(
    of_port_optical_t *obj,
    uint32_t state)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, state);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_port_desc_prop_optical_transport_t to the parent of type of_port_optical for
 * member desc
 * @param obj Pointer to an object of type of_port_optical.
 * @param desc Pointer to the child object of type
 * of_list_port_desc_prop_optical_transport_t to be filled out.
 * \ingroup of_port_optical
 *
 * The parameter desc is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_optical_desc_bind(
    of_port_optical_t *obj,
    of_list_port_desc_prop_optical_transport_t *desc)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_port_desc_prop_optical_transport_init(desc, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, desc, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of desc into a new variable of type of_list_port_desc_prop_optical_transport_t from
 * a of_port_optical instance.
 *
 * @param obj Pointer to the source of type of_port_optical_t
 * @returns A pointer to a new instance of type of_list_port_desc_prop_optical_transport_t whose contents
 * match that of desc from source
 * @returns NULL if an error occurs
 */
of_list_port_desc_prop_optical_transport_t *
of_port_optical_desc_get(of_port_optical_t *obj) {
    of_list_port_desc_prop_optical_transport_t _desc;
    of_list_port_desc_prop_optical_transport_t *_desc_ptr;

    of_port_optical_desc_bind(obj, &_desc);
    _desc_ptr = (of_list_port_desc_prop_optical_transport_t *)of_object_dup(&_desc);
    return _desc_ptr;
}

/**
 * Set desc in an object of type of_port_optical.
 * @param obj Pointer to an object of type of_port_optical.
 * @param desc Pointer to the child of type of_list_port_desc_prop_optical_transport_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_optical_desc_set(
    of_port_optical_t *obj,
    of_list_port_desc_prop_optical_transport_t *desc)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = desc->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == desc->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(desc, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(desc, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)desc, desc->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
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



/**
 * \defgroup of_port_optical_transport_application_code of_port_optical_transport_application_code
 */

/**
 * Create a new of_port_optical_transport_application_code object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_optical_transport_application_code
 */

of_object_t *
of_port_optical_transport_application_code_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_optical_transport_application_code_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_optical_transport_application_code.
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
of_port_optical_transport_application_code_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get feature_type from an object of type of_port_optical_transport_application_code.
 * @param obj Pointer to an object of type of_port_optical_transport_application_code.
 * @param feature_type Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_port_optical_transport_application_code_feature_type_get(
    of_port_optical_transport_application_code_t *obj,
    uint16_t *feature_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, feature_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set feature_type in an object of type of_port_optical_transport_application_code.
 * @param obj Pointer to an object of type of_port_optical_transport_application_code.
 * @param feature_type The value to write into the object
 */
void
of_port_optical_transport_application_code_feature_type_set(
    of_port_optical_transport_application_code_t *obj,
    uint16_t feature_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, feature_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get oic_type from an object of type of_port_optical_transport_application_code.
 * @param obj Pointer to an object of type of_port_optical_transport_application_code.
 * @param oic_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_optical_transport_application_code_oic_type_get(
    of_port_optical_transport_application_code_t *obj,
    uint8_t *oic_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 2;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, oic_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set oic_type in an object of type of_port_optical_transport_application_code.
 * @param obj Pointer to an object of type of_port_optical_transport_application_code.
 * @param oic_type The value to write into the object
 */
void
of_port_optical_transport_application_code_oic_type_set(
    of_port_optical_transport_application_code_t *obj,
    uint8_t oic_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 2;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, oic_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get app_code from an object of type of_port_optical_transport_application_code.
 * @param obj Pointer to an object of type of_port_optical_transport_application_code.
 * @param app_code Pointer to the child object of type
 * of_app_code_t to be filled out.
 *
 */
void
of_port_optical_transport_application_code_app_code_get(
    of_port_optical_transport_application_code_t *obj,
    of_app_code_t *app_code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 3;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_app_code_get(wbuf, abs_offset, app_code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set app_code in an object of type of_port_optical_transport_application_code.
 * @param obj Pointer to an object of type of_port_optical_transport_application_code.
 * @param app_code The value to write into the object
 */
void
of_port_optical_transport_application_code_app_code_set(
    of_port_optical_transport_application_code_t *obj,
    of_app_code_t app_code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_APPLICATION_CODE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 3;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_app_code_set(wbuf, abs_offset, app_code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
