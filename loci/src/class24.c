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
 * \defgroup of_port_optical_transport_layer_entry of_port_optical_transport_layer_entry
 */

/**
 * Create a new of_port_optical_transport_layer_entry object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_optical_transport_layer_entry
 */

of_object_t *
of_port_optical_transport_layer_entry_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_port_optical_transport_layer_entry_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_optical_transport_layer_entry.
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
of_port_optical_transport_layer_entry_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get layer_class from an object of type of_port_optical_transport_layer_entry.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_entry.
 * @param layer_class Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_optical_transport_layer_entry_layer_class_get(
    of_port_optical_transport_layer_entry_t *obj,
    uint8_t *layer_class)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY);
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
    of_wire_buffer_u8_get(wbuf, abs_offset, layer_class);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set layer_class in an object of type of_port_optical_transport_layer_entry.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_entry.
 * @param layer_class The value to write into the object
 */
void
of_port_optical_transport_layer_entry_layer_class_set(
    of_port_optical_transport_layer_entry_t *obj,
    uint8_t layer_class)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY);
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
    of_wire_buffer_u8_set(wbuf, abs_offset, layer_class);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get signal_type from an object of type of_port_optical_transport_layer_entry.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_entry.
 * @param signal_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_optical_transport_layer_entry_signal_type_get(
    of_port_optical_transport_layer_entry_t *obj,
    uint8_t *signal_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, signal_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set signal_type in an object of type of_port_optical_transport_layer_entry.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_entry.
 * @param signal_type The value to write into the object
 */
void
of_port_optical_transport_layer_entry_signal_type_set(
    of_port_optical_transport_layer_entry_t *obj,
    uint8_t signal_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, signal_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get adaptation from an object of type of_port_optical_transport_layer_entry.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_entry.
 * @param adaptation Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_port_optical_transport_layer_entry_adaptation_get(
    of_port_optical_transport_layer_entry_t *obj,
    uint8_t *adaptation)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY);
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
    of_wire_buffer_u8_get(wbuf, abs_offset, adaptation);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set adaptation in an object of type of_port_optical_transport_layer_entry.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_entry.
 * @param adaptation The value to write into the object
 */
void
of_port_optical_transport_layer_entry_adaptation_set(
    of_port_optical_transport_layer_entry_t *obj,
    uint8_t adaptation)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_ENTRY);
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
    of_wire_buffer_u8_set(wbuf, abs_offset, adaptation);

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
 * \defgroup of_port_optical_transport_layer_stack of_port_optical_transport_layer_stack
 */

/**
 * Create a new of_port_optical_transport_layer_stack object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_port_optical_transport_layer_stack
 */

of_object_t *
of_port_optical_transport_layer_stack_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_port_optical_transport_layer_stack_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_port_optical_transport_layer_stack.
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
of_port_optical_transport_layer_stack_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get feature_type from an object of type of_port_optical_transport_layer_stack.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_stack.
 * @param feature_type Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_port_optical_transport_layer_stack_feature_type_get(
    of_port_optical_transport_layer_stack_t *obj,
    uint16_t *feature_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK);
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
 * Set feature_type in an object of type of_port_optical_transport_layer_stack.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_stack.
 * @param feature_type The value to write into the object
 */
void
of_port_optical_transport_layer_stack_feature_type_set(
    of_port_optical_transport_layer_stack_t *obj,
    uint16_t feature_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK);
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
 * Bind an object of type of_list_port_optical_transport_layer_entry_t to the parent of type of_port_optical_transport_layer_stack for
 * member entries
 * @param obj Pointer to an object of type of_port_optical_transport_layer_stack.
 * @param entries Pointer to the child object of type
 * of_list_port_optical_transport_layer_entry_t to be filled out.
 * \ingroup of_port_optical_transport_layer_stack
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_port_optical_transport_layer_stack_entries_bind(
    of_port_optical_transport_layer_stack_t *obj,
    of_list_port_optical_transport_layer_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_port_optical_transport_layer_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, entries, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_port_optical_transport_layer_entry_t from
 * a of_port_optical_transport_layer_stack instance.
 *
 * @param obj Pointer to the source of type of_port_optical_transport_layer_stack_t
 * @returns A pointer to a new instance of type of_list_port_optical_transport_layer_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_port_optical_transport_layer_entry_t *
of_port_optical_transport_layer_stack_entries_get(of_port_optical_transport_layer_stack_t *obj) {
    of_list_port_optical_transport_layer_entry_t _entries;
    of_list_port_optical_transport_layer_entry_t *_entries_ptr;

    of_port_optical_transport_layer_stack_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_port_optical_transport_layer_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_port_optical_transport_layer_stack.
 * @param obj Pointer to an object of type of_port_optical_transport_layer_stack.
 * @param entries Pointer to the child of type of_list_port_optical_transport_layer_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_port_optical_transport_layer_stack_entries_set(
    of_port_optical_transport_layer_stack_t *obj,
    of_list_port_optical_transport_layer_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_PORT_OPTICAL_TRANSPORT_LAYER_STACK);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
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
of_sdwn_header_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 12)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_SDWN_ADD_CLIENT;
            break;
        case 0x2:
            *id = OF_SDWN_PACKET_IN;
            break;
        case 0x3:
            *id = OF_SDWN_ADD_LVAP;
            break;
        case 0x4:
            *id = OF_SDWN_DEL_CLIENT;
            break;
        case 0x5:
            *id = OF_SDWN_DEL_LVAP;
            break;
        case 0x6:
            *id = OF_SDWN_GET_REMOTE_PORT_REQUEST;
            break;
        case 0x7:
            *id = OF_SDWN_GET_REMOTE_PORT_REPLY;
            break;
        case 0x8:
            *id = OF_SDWN_MOD_LVAP;
            break;
        case 0x9:
            *id = OF_SDWN_IEEE80211_MGMT;
            break;
        case 0xa:
            *id = OF_SDWN_IEEE80211_MGMT_REPLY;
            break;
        case 0xd:
            *id = OF_SDWN_SET_CHANNEL;
            break;
        default:
            *id = OF_SDWN_HEADER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_sdwn_header of_sdwn_header
 */

/**
 * Create a new of_sdwn_header object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_header
 */

of_object_t *
of_sdwn_header_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_HEADER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_header_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_header.
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
of_sdwn_header_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_HEADER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_HEADER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_HEADER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_header.
 * @param obj Pointer to an object of type of_sdwn_header.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_header_xid_get(
    of_sdwn_header_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_HEADER);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_header.
 * @param obj Pointer to an object of type of_sdwn_header.
 * @param xid The value to write into the object
 */
void
of_sdwn_header_xid_set(
    of_sdwn_header_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_HEADER);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_header.
 * @param obj Pointer to an object of type of_sdwn_header.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_header_experimenter_get(
    of_sdwn_header_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_HEADER);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_header.
 * @param obj Pointer to an object of type of_sdwn_header.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_header_experimenter_set(
    of_sdwn_header_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_HEADER);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_header.
 * @param obj Pointer to an object of type of_sdwn_header.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_header_subtype_get(
    of_sdwn_header_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_HEADER);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_header.
 * @param obj Pointer to an object of type of_sdwn_header.
 * @param subtype The value to write into the object
 */
void
of_sdwn_header_subtype_set(
    of_sdwn_header_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_HEADER);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

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
of_sdwn_add_client_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_add_client of_sdwn_add_client
 */

/**
 * Create a new of_sdwn_add_client object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_add_client
 */

of_object_t *
of_sdwn_add_client_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ADD_CLIENT];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_add_client_init(obj, version, bytes, 0);
    of_sdwn_add_client_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_add_client.
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
of_sdwn_add_client_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ADD_CLIENT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ADD_CLIENT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ADD_CLIENT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_add_client_xid_get(
    of_sdwn_add_client_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param xid The value to write into the object
 */
void
of_sdwn_add_client_xid_set(
    of_sdwn_add_client_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_add_client_experimenter_get(
    of_sdwn_add_client_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_add_client_experimenter_set(
    of_sdwn_add_client_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_add_client_subtype_get(
    of_sdwn_add_client_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param subtype The value to write into the object
 */
void
of_sdwn_add_client_subtype_set(
    of_sdwn_add_client_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get client from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param client Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_add_client_client_get(
    of_sdwn_add_client_t *obj,
    of_mac_addr_t *client)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, client);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set client in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param client The value to write into the object
 */
void
of_sdwn_add_client_client_set(
    of_sdwn_add_client_t *obj,
    of_mac_addr_t client)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, client);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ap from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param ap Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_add_client_ap_get(
    of_sdwn_add_client_t *obj,
    of_port_no_t *ap)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, ap);
    OF_PORT_NO_VALUE_CHECK(*ap, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ap in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param ap The value to write into the object
 */
void
of_sdwn_add_client_ap_set(
    of_sdwn_add_client_t *obj,
    of_port_no_t ap)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, ap);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get assoc_id from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param assoc_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_add_client_assoc_id_get(
    of_sdwn_add_client_t *obj,
    uint16_t *assoc_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, assoc_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set assoc_id in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param assoc_id The value to write into the object
 */
void
of_sdwn_add_client_assoc_id_set(
    of_sdwn_add_client_t *obj,
    uint16_t assoc_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, assoc_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get capabilities from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param capabilities Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_add_client_capabilities_get(
    of_sdwn_add_client_t *obj,
    uint16_t *capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set capabilities in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param capabilities The value to write into the object
 */
void
of_sdwn_add_client_capabilities_set(
    of_sdwn_add_client_t *obj,
    uint16_t capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cap_flags from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param cap_flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_add_client_cap_flags_get(
    of_sdwn_add_client_t *obj,
    uint16_t *cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cap_flags in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param cap_flags The value to write into the object
 */
void
of_sdwn_add_client_cap_flags_set(
    of_sdwn_add_client_t *obj,
    uint16_t cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_ieee80211_ht_cap_t to the parent of type of_sdwn_add_client for
 * member ht_capabilities
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param ht_capabilities Pointer to the child object of type
 * of_ieee80211_ht_cap_t to be filled out.
 * \ingroup of_sdwn_add_client
 *
 * The parameter ht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_add_client_ht_capabilities_bind(
    of_sdwn_add_client_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_ht_cap_init(ht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, ht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of ht_capabilities into a new variable of type of_ieee80211_ht_cap_t from
 * a of_sdwn_add_client instance.
 *
 * @param obj Pointer to the source of type of_sdwn_add_client_t
 * @returns A pointer to a new instance of type of_ieee80211_ht_cap_t whose contents
 * match that of ht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_ht_cap_t *
of_sdwn_add_client_ht_capabilities_get(of_sdwn_add_client_t *obj) {
    of_ieee80211_ht_cap_t _ht_capabilities;
    of_ieee80211_ht_cap_t *_ht_capabilities_ptr;

    of_sdwn_add_client_ht_capabilities_bind(obj, &_ht_capabilities);
    _ht_capabilities_ptr = (of_ieee80211_ht_cap_t *)of_object_dup(&_ht_capabilities);
    return _ht_capabilities_ptr;
}

/**
 * Set ht_capabilities in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param ht_capabilities Pointer to the child of type of_ieee80211_ht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_add_client_ht_capabilities_set(
    of_sdwn_add_client_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = ht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == ht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(ht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(ht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)ht_capabilities, ht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_ieee80211_vht_cap_t to the parent of type of_sdwn_add_client for
 * member vht_capabilities
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param vht_capabilities Pointer to the child object of type
 * of_ieee80211_vht_cap_t to be filled out.
 * \ingroup of_sdwn_add_client
 *
 * The parameter vht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_add_client_vht_capabilities_bind(
    of_sdwn_add_client_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 60;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_vht_cap_init(vht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, vht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of vht_capabilities into a new variable of type of_ieee80211_vht_cap_t from
 * a of_sdwn_add_client instance.
 *
 * @param obj Pointer to the source of type of_sdwn_add_client_t
 * @returns A pointer to a new instance of type of_ieee80211_vht_cap_t whose contents
 * match that of vht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_vht_cap_t *
of_sdwn_add_client_vht_capabilities_get(of_sdwn_add_client_t *obj) {
    of_ieee80211_vht_cap_t _vht_capabilities;
    of_ieee80211_vht_cap_t *_vht_capabilities_ptr;

    of_sdwn_add_client_vht_capabilities_bind(obj, &_vht_capabilities);
    _vht_capabilities_ptr = (of_ieee80211_vht_cap_t *)of_object_dup(&_vht_capabilities);
    return _vht_capabilities_ptr;
}

/**
 * Set vht_capabilities in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param vht_capabilities Pointer to the child of type of_ieee80211_vht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_add_client_vht_capabilities_set(
    of_sdwn_add_client_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 60;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = vht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == vht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(vht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(vht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)vht_capabilities, vht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Get supported_rates from an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param supported_rates Pointer to the child object of type
 * of_desc_str_t to be filled out.
 *
 */
void
of_sdwn_add_client_supported_rates_get(
    of_sdwn_add_client_t *obj,
    of_desc_str_t *supported_rates)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 72;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_get(wbuf, abs_offset, supported_rates);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported_rates in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param supported_rates The value to write into the object
 */
void
of_sdwn_add_client_supported_rates_set(
    of_sdwn_add_client_t *obj,
    of_desc_str_t supported_rates)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 72;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_set(wbuf, abs_offset, supported_rates);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_tlv_data_t to the parent of type of_sdwn_add_client for
 * member keys
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param keys Pointer to the child object of type
 * of_list_bsn_tlv_data_t to be filled out.
 * \ingroup of_sdwn_add_client
 *
 * The parameter keys is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_add_client_keys_bind(
    of_sdwn_add_client_t *obj,
    of_list_bsn_tlv_data_t *keys)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 328;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_tlv_data_init(keys, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, keys, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of keys into a new variable of type of_list_bsn_tlv_data_t from
 * a of_sdwn_add_client instance.
 *
 * @param obj Pointer to the source of type of_sdwn_add_client_t
 * @returns A pointer to a new instance of type of_list_bsn_tlv_data_t whose contents
 * match that of keys from source
 * @returns NULL if an error occurs
 */
of_list_bsn_tlv_data_t *
of_sdwn_add_client_keys_get(of_sdwn_add_client_t *obj) {
    of_list_bsn_tlv_data_t _keys;
    of_list_bsn_tlv_data_t *_keys_ptr;

    of_sdwn_add_client_keys_bind(obj, &_keys);
    _keys_ptr = (of_list_bsn_tlv_data_t *)of_object_dup(&_keys);
    return _keys_ptr;
}

/**
 * Set keys in an object of type of_sdwn_add_client.
 * @param obj Pointer to an object of type of_sdwn_add_client.
 * @param keys Pointer to the child of type of_list_bsn_tlv_data_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_add_client_keys_set(
    of_sdwn_add_client_t *obj,
    of_list_bsn_tlv_data_t *keys)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 328;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = keys->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == keys->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(keys, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(keys, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)keys, keys->length);

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
of_sdwn_add_lvap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x3); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_add_lvap of_sdwn_add_lvap
 */

/**
 * Create a new of_sdwn_add_lvap object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_add_lvap
 */

of_object_t *
of_sdwn_add_lvap_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ADD_LVAP];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_add_lvap_init(obj, version, bytes, 0);
    of_sdwn_add_lvap_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_add_lvap.
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
of_sdwn_add_lvap_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ADD_LVAP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ADD_LVAP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ADD_LVAP;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_xid_get(
    of_sdwn_add_lvap_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param xid The value to write into the object
 */
void
of_sdwn_add_lvap_xid_set(
    of_sdwn_add_lvap_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_experimenter_get(
    of_sdwn_add_lvap_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_add_lvap_experimenter_set(
    of_sdwn_add_lvap_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_subtype_get(
    of_sdwn_add_lvap_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param subtype The value to write into the object
 */
void
of_sdwn_add_lvap_subtype_set(
    of_sdwn_add_lvap_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get bssid from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param bssid Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_bssid_get(
    of_sdwn_add_lvap_t *obj,
    of_mac_addr_t *bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bssid in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param bssid The value to write into the object
 */
void
of_sdwn_add_lvap_bssid_set(
    of_sdwn_add_lvap_t *obj,
    of_mac_addr_t bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get phy_mac from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param phy_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_phy_mac_get(
    of_sdwn_add_lvap_t *obj,
    of_mac_addr_t *phy_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, phy_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set phy_mac in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param phy_mac The value to write into the object
 */
void
of_sdwn_add_lvap_phy_mac_set(
    of_sdwn_add_lvap_t *obj,
    of_mac_addr_t phy_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, phy_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cap_flags from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param cap_flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_cap_flags_get(
    of_sdwn_add_lvap_t *obj,
    uint16_t *cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cap_flags in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param cap_flags The value to write into the object
 */
void
of_sdwn_add_lvap_cap_flags_set(
    of_sdwn_add_lvap_t *obj,
    uint16_t cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_ieee80211_ht_cap_t to the parent of type of_sdwn_add_lvap for
 * member ht_capabilities
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param ht_capabilities Pointer to the child object of type
 * of_ieee80211_ht_cap_t to be filled out.
 * \ingroup of_sdwn_add_lvap
 *
 * The parameter ht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_add_lvap_ht_capabilities_bind(
    of_sdwn_add_lvap_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_ht_cap_init(ht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, ht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of ht_capabilities into a new variable of type of_ieee80211_ht_cap_t from
 * a of_sdwn_add_lvap instance.
 *
 * @param obj Pointer to the source of type of_sdwn_add_lvap_t
 * @returns A pointer to a new instance of type of_ieee80211_ht_cap_t whose contents
 * match that of ht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_ht_cap_t *
of_sdwn_add_lvap_ht_capabilities_get(of_sdwn_add_lvap_t *obj) {
    of_ieee80211_ht_cap_t _ht_capabilities;
    of_ieee80211_ht_cap_t *_ht_capabilities_ptr;

    of_sdwn_add_lvap_ht_capabilities_bind(obj, &_ht_capabilities);
    _ht_capabilities_ptr = (of_ieee80211_ht_cap_t *)of_object_dup(&_ht_capabilities);
    return _ht_capabilities_ptr;
}

/**
 * Set ht_capabilities in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param ht_capabilities Pointer to the child of type of_ieee80211_ht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_add_lvap_ht_capabilities_set(
    of_sdwn_add_lvap_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = ht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == ht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(ht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(ht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)ht_capabilities, ht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_ieee80211_vht_cap_t to the parent of type of_sdwn_add_lvap for
 * member vht_capabilities
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param vht_capabilities Pointer to the child object of type
 * of_ieee80211_vht_cap_t to be filled out.
 * \ingroup of_sdwn_add_lvap
 *
 * The parameter vht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_add_lvap_vht_capabilities_bind(
    of_sdwn_add_lvap_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 56;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_vht_cap_init(vht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, vht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of vht_capabilities into a new variable of type of_ieee80211_vht_cap_t from
 * a of_sdwn_add_lvap instance.
 *
 * @param obj Pointer to the source of type of_sdwn_add_lvap_t
 * @returns A pointer to a new instance of type of_ieee80211_vht_cap_t whose contents
 * match that of vht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_vht_cap_t *
of_sdwn_add_lvap_vht_capabilities_get(of_sdwn_add_lvap_t *obj) {
    of_ieee80211_vht_cap_t _vht_capabilities;
    of_ieee80211_vht_cap_t *_vht_capabilities_ptr;

    of_sdwn_add_lvap_vht_capabilities_bind(obj, &_vht_capabilities);
    _vht_capabilities_ptr = (of_ieee80211_vht_cap_t *)of_object_dup(&_vht_capabilities);
    return _vht_capabilities_ptr;
}

/**
 * Set vht_capabilities in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param vht_capabilities Pointer to the child of type of_ieee80211_vht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_add_lvap_vht_capabilities_set(
    of_sdwn_add_lvap_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 56;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = vht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == vht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(vht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(vht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)vht_capabilities, vht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Get beacon from an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param beacon Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_sdwn_add_lvap_beacon_get(
    of_sdwn_add_lvap_t *obj,
    of_octets_t *beacon)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 68;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    beacon->bytes = cur_len;
    beacon->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set beacon in an object of type of_sdwn_add_lvap.
 * @param obj Pointer to an object of type of_sdwn_add_lvap.
 * @param beacon The value to write into the object
 */
int WARN_UNUSED_RESULT
of_sdwn_add_lvap_beacon_set(
    of_sdwn_add_lvap_t *obj,
    of_octets_t *beacon)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ADD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 68;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = beacon->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, beacon, cur_len);

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
of_sdwn_del_client_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x4); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_del_client of_sdwn_del_client
 */

/**
 * Create a new of_sdwn_del_client object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_del_client
 */

of_object_t *
of_sdwn_del_client_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_DEL_CLIENT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_del_client_init(obj, version, bytes, 0);
    of_sdwn_del_client_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_del_client.
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
of_sdwn_del_client_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_DEL_CLIENT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_DEL_CLIENT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_DEL_CLIENT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_client_xid_get(
    of_sdwn_del_client_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param xid The value to write into the object
 */
void
of_sdwn_del_client_xid_set(
    of_sdwn_del_client_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_client_experimenter_get(
    of_sdwn_del_client_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_del_client_experimenter_set(
    of_sdwn_del_client_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_client_subtype_get(
    of_sdwn_del_client_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param subtype The value to write into the object
 */
void
of_sdwn_del_client_subtype_set(
    of_sdwn_del_client_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get client from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param client Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_del_client_client_get(
    of_sdwn_del_client_t *obj,
    of_mac_addr_t *client)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, client);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set client in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param client The value to write into the object
 */
void
of_sdwn_del_client_client_set(
    of_sdwn_del_client_t *obj,
    of_mac_addr_t client)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, client);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ap from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param ap Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_del_client_ap_get(
    of_sdwn_del_client_t *obj,
    of_port_no_t *ap)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, ap);
    OF_PORT_NO_VALUE_CHECK(*ap, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ap in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param ap The value to write into the object
 */
void
of_sdwn_del_client_ap_set(
    of_sdwn_del_client_t *obj,
    of_port_no_t ap)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, ap);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get reason from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param reason Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_del_client_reason_get(
    of_sdwn_del_client_t *obj,
    uint16_t *reason)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, reason);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set reason in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param reason The value to write into the object
 */
void
of_sdwn_del_client_reason_set(
    of_sdwn_del_client_t *obj,
    uint16_t reason)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, reason);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get deauth from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param deauth Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_del_client_deauth_get(
    of_sdwn_del_client_t *obj,
    uint8_t *deauth)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, deauth);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set deauth in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param deauth The value to write into the object
 */
void
of_sdwn_del_client_deauth_set(
    of_sdwn_del_client_t *obj,
    uint8_t deauth)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, deauth);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ban_time from an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param ban_time Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_client_ban_time_get(
    of_sdwn_del_client_t *obj,
    uint32_t *ban_time)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, ban_time);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ban_time in an object of type of_sdwn_del_client.
 * @param obj Pointer to an object of type of_sdwn_del_client.
 * @param ban_time The value to write into the object
 */
void
of_sdwn_del_client_ban_time_set(
    of_sdwn_del_client_t *obj,
    uint32_t ban_time)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_CLIENT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, ban_time);

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
of_sdwn_del_lvap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_del_lvap of_sdwn_del_lvap
 */

/**
 * Create a new of_sdwn_del_lvap object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_del_lvap
 */

of_object_t *
of_sdwn_del_lvap_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_DEL_LVAP];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_del_lvap_init(obj, version, bytes, 0);
    of_sdwn_del_lvap_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_del_lvap.
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
of_sdwn_del_lvap_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_DEL_LVAP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_DEL_LVAP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_DEL_LVAP;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_lvap_xid_get(
    of_sdwn_del_lvap_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param xid The value to write into the object
 */
void
of_sdwn_del_lvap_xid_set(
    of_sdwn_del_lvap_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_lvap_experimenter_get(
    of_sdwn_del_lvap_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_del_lvap_experimenter_set(
    of_sdwn_del_lvap_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_del_lvap_subtype_get(
    of_sdwn_del_lvap_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param subtype The value to write into the object
 */
void
of_sdwn_del_lvap_subtype_set(
    of_sdwn_del_lvap_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get bssid from an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param bssid Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_del_lvap_bssid_get(
    of_sdwn_del_lvap_t *obj,
    of_mac_addr_t *bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bssid in an object of type of_sdwn_del_lvap.
 * @param obj Pointer to an object of type of_sdwn_del_lvap.
 * @param bssid The value to write into the object
 */
void
of_sdwn_del_lvap_bssid_set(
    of_sdwn_del_lvap_t *obj,
    of_mac_addr_t bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_DEL_LVAP);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, bssid);

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
of_sdwn_entity_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_SDWN_ENTITY_NIC;
            break;
        case 0x1:
            *id = OF_SDWN_ENTITY_ACCESSPOINT;
            break;
        case 0x3:
            *id = OF_SDWN_ENTITY_BAND;
            break;
        case 0x4:
            *id = OF_SDWN_ENTITY_FREQ;
            break;
        case 0x5:
            *id = OF_SDWN_ENTITY_RATE;
            break;
        case 0x6:
            *id = OF_SDWN_ENTITY_RELATED_SWITCH;
            break;
        default:
            *id = OF_SDWN_ENTITY;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_sdwn_entity of_sdwn_entity
 */

/**
 * Create a new of_sdwn_entity object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity
 */

of_object_t *
of_sdwn_entity_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity.
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
of_sdwn_entity_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
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
of_sdwn_entity_accesspoint_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_entity_accesspoint of_sdwn_entity_accesspoint
 */

/**
 * Create a new of_sdwn_entity_accesspoint object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity_accesspoint
 */

of_object_t *
of_sdwn_entity_accesspoint_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_ACCESSPOINT];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_accesspoint_init(obj, version, bytes, 0);
    of_sdwn_entity_accesspoint_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity_accesspoint.
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
of_sdwn_entity_accesspoint_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY_ACCESSPOINT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_ACCESSPOINT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY_ACCESSPOINT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get if_no from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_if_no_get(
    of_sdwn_entity_accesspoint_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param if_no The value to write into the object
 */
void
of_sdwn_entity_accesspoint_if_no_set(
    of_sdwn_entity_accesspoint_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get name from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param name Pointer to the child object of type
 * of_port_name_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_name_get(
    of_sdwn_entity_accesspoint_t *obj,
    of_port_name_t *name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
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
    of_wire_buffer_port_name_get(wbuf, abs_offset, name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set name in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param name The value to write into the object
 */
void
of_sdwn_entity_accesspoint_name_set(
    of_sdwn_entity_accesspoint_t *obj,
    of_port_name_t name)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
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
    of_wire_buffer_port_name_set(wbuf, abs_offset, name);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get config from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param config Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_config_get(
    of_sdwn_entity_accesspoint_t *obj,
    uint16_t *config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set config in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param config The value to write into the object
 */
void
of_sdwn_entity_accesspoint_config_set(
    of_sdwn_entity_accesspoint_t *obj,
    uint16_t config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get bssid from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param bssid Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_bssid_get(
    of_sdwn_entity_accesspoint_t *obj,
    of_mac_addr_t *bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bssid in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param bssid The value to write into the object
 */
void
of_sdwn_entity_accesspoint_bssid_set(
    of_sdwn_entity_accesspoint_t *obj,
    of_mac_addr_t bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get phy_mac from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param phy_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_phy_mac_get(
    of_sdwn_entity_accesspoint_t *obj,
    of_mac_addr_t *phy_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, phy_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set phy_mac in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param phy_mac The value to write into the object
 */
void
of_sdwn_entity_accesspoint_phy_mac_set(
    of_sdwn_entity_accesspoint_t *obj,
    of_mac_addr_t phy_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, phy_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get curr_freq from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param curr_freq Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_curr_freq_get(
    of_sdwn_entity_accesspoint_t *obj,
    uint32_t *curr_freq)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, curr_freq);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set curr_freq in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param curr_freq The value to write into the object
 */
void
of_sdwn_entity_accesspoint_curr_freq_set(
    of_sdwn_entity_accesspoint_t *obj,
    uint32_t curr_freq)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, curr_freq);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get curr_speed from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param curr_speed Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_curr_speed_get(
    of_sdwn_entity_accesspoint_t *obj,
    uint32_t *curr_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, curr_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set curr_speed in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param curr_speed The value to write into the object
 */
void
of_sdwn_entity_accesspoint_curr_speed_set(
    of_sdwn_entity_accesspoint_t *obj,
    uint32_t curr_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, curr_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_speed from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param max_speed Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_max_speed_get(
    of_sdwn_entity_accesspoint_t *obj,
    uint32_t *max_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_speed in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param max_speed The value to write into the object
 */
void
of_sdwn_entity_accesspoint_max_speed_set(
    of_sdwn_entity_accesspoint_t *obj,
    uint32_t max_speed)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_speed);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ssid from an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param ssid Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_sdwn_entity_accesspoint_ssid_get(
    of_sdwn_entity_accesspoint_t *obj,
    of_octets_t *ssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 52;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    ssid->bytes = cur_len;
    ssid->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ssid in an object of type of_sdwn_entity_accesspoint.
 * @param obj Pointer to an object of type of_sdwn_entity_accesspoint.
 * @param ssid The value to write into the object
 */
int WARN_UNUSED_RESULT
of_sdwn_entity_accesspoint_ssid_set(
    of_sdwn_entity_accesspoint_t *obj,
    of_octets_t *ssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_ACCESSPOINT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 52;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = ssid->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, ssid, cur_len);

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
of_sdwn_entity_band_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = U16_HTON(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_entity_band of_sdwn_entity_band
 */

/**
 * Create a new of_sdwn_entity_band object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity_band
 */

of_object_t *
of_sdwn_entity_band_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_BAND];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_band_init(obj, version, bytes, 0);
    of_sdwn_entity_band_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity_band.
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
of_sdwn_entity_band_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY_BAND] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_BAND];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY_BAND;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get index from an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param index Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_band_index_get(
    of_sdwn_entity_band_t *obj,
    uint32_t *index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set index in an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param index The value to write into the object
 */
void
of_sdwn_entity_band_index_set(
    of_sdwn_entity_band_t *obj,
    uint32_t index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get band_no from an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param band_no Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_entity_band_band_no_get(
    of_sdwn_entity_band_t *obj,
    uint16_t *band_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, band_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set band_no in an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param band_no The value to write into the object
 */
void
of_sdwn_entity_band_band_no_set(
    of_sdwn_entity_band_t *obj,
    uint16_t band_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, band_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cap_flags from an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param cap_flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_entity_band_cap_flags_get(
    of_sdwn_entity_band_t *obj,
    uint16_t *cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cap_flags in an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param cap_flags The value to write into the object
 */
void
of_sdwn_entity_band_cap_flags_set(
    of_sdwn_entity_band_t *obj,
    uint16_t cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_ieee80211_ht_cap_t to the parent of type of_sdwn_entity_band for
 * member ht_capabilities
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param ht_capabilities Pointer to the child object of type
 * of_ieee80211_ht_cap_t to be filled out.
 * \ingroup of_sdwn_entity_band
 *
 * The parameter ht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_entity_band_ht_capabilities_bind(
    of_sdwn_entity_band_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_ht_cap_init(ht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, ht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of ht_capabilities into a new variable of type of_ieee80211_ht_cap_t from
 * a of_sdwn_entity_band instance.
 *
 * @param obj Pointer to the source of type of_sdwn_entity_band_t
 * @returns A pointer to a new instance of type of_ieee80211_ht_cap_t whose contents
 * match that of ht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_ht_cap_t *
of_sdwn_entity_band_ht_capabilities_get(of_sdwn_entity_band_t *obj) {
    of_ieee80211_ht_cap_t _ht_capabilities;
    of_ieee80211_ht_cap_t *_ht_capabilities_ptr;

    of_sdwn_entity_band_ht_capabilities_bind(obj, &_ht_capabilities);
    _ht_capabilities_ptr = (of_ieee80211_ht_cap_t *)of_object_dup(&_ht_capabilities);
    return _ht_capabilities_ptr;
}

/**
 * Set ht_capabilities in an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param ht_capabilities Pointer to the child of type of_ieee80211_ht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_entity_band_ht_capabilities_set(
    of_sdwn_entity_band_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = ht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == ht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(ht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(ht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)ht_capabilities, ht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_ieee80211_vht_cap_t to the parent of type of_sdwn_entity_band for
 * member vht_capabilities
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param vht_capabilities Pointer to the child object of type
 * of_ieee80211_vht_cap_t to be filled out.
 * \ingroup of_sdwn_entity_band
 *
 * The parameter vht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_entity_band_vht_capabilities_bind(
    of_sdwn_entity_band_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_vht_cap_init(vht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, vht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of vht_capabilities into a new variable of type of_ieee80211_vht_cap_t from
 * a of_sdwn_entity_band instance.
 *
 * @param obj Pointer to the source of type of_sdwn_entity_band_t
 * @returns A pointer to a new instance of type of_ieee80211_vht_cap_t whose contents
 * match that of vht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_vht_cap_t *
of_sdwn_entity_band_vht_capabilities_get(of_sdwn_entity_band_t *obj) {
    of_ieee80211_vht_cap_t _vht_capabilities;
    of_ieee80211_vht_cap_t *_vht_capabilities_ptr;

    of_sdwn_entity_band_vht_capabilities_bind(obj, &_vht_capabilities);
    _vht_capabilities_ptr = (of_ieee80211_vht_cap_t *)of_object_dup(&_vht_capabilities);
    return _vht_capabilities_ptr;
}

/**
 * Set vht_capabilities in an object of type of_sdwn_entity_band.
 * @param obj Pointer to an object of type of_sdwn_entity_band.
 * @param vht_capabilities Pointer to the child of type of_ieee80211_vht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_entity_band_vht_capabilities_set(
    of_sdwn_entity_band_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_BAND);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = vht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == vht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(vht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(vht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)vht_capabilities, vht_capabilities->length);

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
of_sdwn_entity_freq_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = U16_HTON(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_entity_freq of_sdwn_entity_freq
 */

/**
 * Create a new of_sdwn_entity_freq object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity_freq
 */

of_object_t *
of_sdwn_entity_freq_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_FREQ];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_freq_init(obj, version, bytes, 0);
    of_sdwn_entity_freq_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity_freq.
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
of_sdwn_entity_freq_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY_FREQ] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_FREQ];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY_FREQ;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get index from an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param index Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_freq_index_get(
    of_sdwn_entity_freq_t *obj,
    uint32_t *index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set index in an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param index The value to write into the object
 */
void
of_sdwn_entity_freq_index_set(
    of_sdwn_entity_freq_t *obj,
    uint32_t index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get band_no from an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param band_no Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_entity_freq_band_no_get(
    of_sdwn_entity_freq_t *obj,
    uint16_t *band_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, band_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set band_no in an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param band_no The value to write into the object
 */
void
of_sdwn_entity_freq_band_no_set(
    of_sdwn_entity_freq_t *obj,
    uint16_t band_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, band_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get freq from an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param freq Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_freq_freq_get(
    of_sdwn_entity_freq_t *obj,
    uint32_t *freq)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, freq);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set freq in an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param freq The value to write into the object
 */
void
of_sdwn_entity_freq_freq_set(
    of_sdwn_entity_freq_t *obj,
    uint32_t freq)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, freq);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_tx_power from an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param max_tx_power Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_freq_max_tx_power_get(
    of_sdwn_entity_freq_t *obj,
    uint32_t *max_tx_power)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, max_tx_power);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_tx_power in an object of type of_sdwn_entity_freq.
 * @param obj Pointer to an object of type of_sdwn_entity_freq.
 * @param max_tx_power The value to write into the object
 */
void
of_sdwn_entity_freq_max_tx_power_set(
    of_sdwn_entity_freq_t *obj,
    uint32_t max_tx_power)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_FREQ);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, max_tx_power);

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
of_sdwn_entity_nic_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_entity_nic of_sdwn_entity_nic
 */

/**
 * Create a new of_sdwn_entity_nic object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity_nic
 */

of_object_t *
of_sdwn_entity_nic_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_NIC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_nic_init(obj, version, bytes, 0);
    of_sdwn_entity_nic_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity_nic.
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
of_sdwn_entity_nic_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY_NIC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_NIC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY_NIC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get index from an object of type of_sdwn_entity_nic.
 * @param obj Pointer to an object of type of_sdwn_entity_nic.
 * @param index Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_nic_index_get(
    of_sdwn_entity_nic_t *obj,
    uint32_t *index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_NIC);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set index in an object of type of_sdwn_entity_nic.
 * @param obj Pointer to an object of type of_sdwn_entity_nic.
 * @param index The value to write into the object
 */
void
of_sdwn_entity_nic_index_set(
    of_sdwn_entity_nic_t *obj,
    uint32_t index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_NIC);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mac_addr from an object of type of_sdwn_entity_nic.
 * @param obj Pointer to an object of type of_sdwn_entity_nic.
 * @param mac_addr Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_entity_nic_mac_addr_get(
    of_sdwn_entity_nic_t *obj,
    of_mac_addr_t *mac_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_NIC);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, mac_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mac_addr in an object of type of_sdwn_entity_nic.
 * @param obj Pointer to an object of type of_sdwn_entity_nic.
 * @param mac_addr The value to write into the object
 */
void
of_sdwn_entity_nic_mac_addr_set(
    of_sdwn_entity_nic_t *obj,
    of_mac_addr_t mac_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_NIC);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, mac_addr);

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
of_sdwn_entity_rate_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = U16_HTON(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_entity_rate of_sdwn_entity_rate
 */

/**
 * Create a new of_sdwn_entity_rate object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity_rate
 */

of_object_t *
of_sdwn_entity_rate_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_RATE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_rate_init(obj, version, bytes, 0);
    of_sdwn_entity_rate_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity_rate.
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
of_sdwn_entity_rate_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY_RATE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_RATE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY_RATE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get index from an object of type of_sdwn_entity_rate.
 * @param obj Pointer to an object of type of_sdwn_entity_rate.
 * @param index Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_rate_index_get(
    of_sdwn_entity_rate_t *obj,
    uint32_t *index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RATE);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set index in an object of type of_sdwn_entity_rate.
 * @param obj Pointer to an object of type of_sdwn_entity_rate.
 * @param index The value to write into the object
 */
void
of_sdwn_entity_rate_index_set(
    of_sdwn_entity_rate_t *obj,
    uint32_t index)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RATE);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, index);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get band_no from an object of type of_sdwn_entity_rate.
 * @param obj Pointer to an object of type of_sdwn_entity_rate.
 * @param band_no Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_entity_rate_band_no_get(
    of_sdwn_entity_rate_t *obj,
    uint16_t *band_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RATE);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, band_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set band_no in an object of type of_sdwn_entity_rate.
 * @param obj Pointer to an object of type of_sdwn_entity_rate.
 * @param band_no The value to write into the object
 */
void
of_sdwn_entity_rate_band_no_set(
    of_sdwn_entity_rate_t *obj,
    uint16_t band_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RATE);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, band_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get rate from an object of type of_sdwn_entity_rate.
 * @param obj Pointer to an object of type of_sdwn_entity_rate.
 * @param rate Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_entity_rate_rate_get(
    of_sdwn_entity_rate_t *obj,
    uint32_t *rate)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RATE);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, rate);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set rate in an object of type of_sdwn_entity_rate.
 * @param obj Pointer to an object of type of_sdwn_entity_rate.
 * @param rate The value to write into the object
 */
void
of_sdwn_entity_rate_rate_set(
    of_sdwn_entity_rate_t *obj,
    uint32_t rate)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RATE);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, rate);

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
of_sdwn_entity_related_switch_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = U16_HTON(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_entity_related_switch of_sdwn_entity_related_switch
 */

/**
 * Create a new of_sdwn_entity_related_switch object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_entity_related_switch
 */

of_object_t *
of_sdwn_entity_related_switch_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_RELATED_SWITCH];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_entity_related_switch_init(obj, version, bytes, 0);
    of_sdwn_entity_related_switch_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_entity_related_switch.
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
of_sdwn_entity_related_switch_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_ENTITY_RELATED_SWITCH] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_ENTITY_RELATED_SWITCH];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_ENTITY_RELATED_SWITCH;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get datapath_id from an object of type of_sdwn_entity_related_switch.
 * @param obj Pointer to an object of type of_sdwn_entity_related_switch.
 * @param datapath_id Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_sdwn_entity_related_switch_datapath_id_get(
    of_sdwn_entity_related_switch_t *obj,
    uint64_t *datapath_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RELATED_SWITCH);
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
    of_wire_buffer_u64_get(wbuf, abs_offset, datapath_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set datapath_id in an object of type of_sdwn_entity_related_switch.
 * @param obj Pointer to an object of type of_sdwn_entity_related_switch.
 * @param datapath_id The value to write into the object
 */
void
of_sdwn_entity_related_switch_datapath_id_set(
    of_sdwn_entity_related_switch_t *obj,
    uint64_t datapath_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_ENTITY_RELATED_SWITCH);
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
    of_wire_buffer_u64_set(wbuf, abs_offset, datapath_id);

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
of_sdwn_reply_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 20)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_SDWN_PORT_DESC_REPLY;
            break;
        case 0x2:
            of_sdwn_get_clients_reply_wire_object_id_get(obj, id);
            break;
        case 0x5:
            *id = OF_SDWN_GET_CHANNEL_REPLY;
            break;
        default:
            *id = OF_SDWN_REPLY;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_sdwn_reply of_sdwn_reply
 */

/**
 * Create a new of_sdwn_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_reply
 */

of_object_t *
of_sdwn_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_reply_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_reply.
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
of_sdwn_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_reply_xid_get(
    of_sdwn_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param xid The value to write into the object
 */
void
of_sdwn_reply_xid_set(
    of_sdwn_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_reply_flags_get(
    of_sdwn_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param flags The value to write into the object
 */
void
of_sdwn_reply_flags_set(
    of_sdwn_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_reply_experimenter_get(
    of_sdwn_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_reply_experimenter_set(
    of_sdwn_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_reply_subtype_get(
    of_sdwn_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_reply.
 * @param obj Pointer to an object of type of_sdwn_reply.
 * @param subtype The value to write into the object
 */
void
of_sdwn_reply_subtype_set(
    of_sdwn_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

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
of_sdwn_get_channel_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_channel_reply of_sdwn_get_channel_reply
 */

/**
 * Create a new of_sdwn_get_channel_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_channel_reply
 */

of_object_t *
of_sdwn_get_channel_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CHANNEL_REPLY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_channel_reply_init(obj, version, bytes, 0);
    of_sdwn_get_channel_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_channel_reply.
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
of_sdwn_get_channel_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CHANNEL_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CHANNEL_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CHANNEL_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_reply_xid_get(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_channel_reply_xid_set(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_channel_reply_flags_get(
    of_sdwn_get_channel_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_channel_reply_flags_set(
    of_sdwn_get_channel_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_reply_experimenter_get(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_channel_reply_experimenter_set(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_reply_subtype_get(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_channel_reply_subtype_set(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get channel from an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param channel Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_reply_channel_get(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t *channel)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, channel);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set channel in an object of type of_sdwn_get_channel_reply.
 * @param obj Pointer to an object of type of_sdwn_get_channel_reply.
 * @param channel The value to write into the object
 */
void
of_sdwn_get_channel_reply_channel_set(
    of_sdwn_get_channel_reply_t *obj,
    uint32_t channel)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, channel);

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
of_sdwn_request_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 20)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_SDWN_PORT_DESC_REQUEST;
            break;
        case 0x2:
            *id = OF_SDWN_GET_CLIENTS_REQUEST;
            break;
        case 0x5:
            *id = OF_SDWN_GET_CHANNEL_REQUEST;
            break;
        default:
            *id = OF_SDWN_REQUEST;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_sdwn_request of_sdwn_request
 */

/**
 * Create a new of_sdwn_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_request
 */

of_object_t *
of_sdwn_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_REQUEST];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_request_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_request.
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
of_sdwn_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_request_xid_get(
    of_sdwn_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param xid The value to write into the object
 */
void
of_sdwn_request_xid_set(
    of_sdwn_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_request_flags_get(
    of_sdwn_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param flags The value to write into the object
 */
void
of_sdwn_request_flags_set(
    of_sdwn_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_request_experimenter_get(
    of_sdwn_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_request_experimenter_set(
    of_sdwn_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_request_subtype_get(
    of_sdwn_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_request.
 * @param obj Pointer to an object of type of_sdwn_request.
 * @param subtype The value to write into the object
 */
void
of_sdwn_request_subtype_set(
    of_sdwn_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

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
of_sdwn_get_channel_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x5); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_channel_request of_sdwn_get_channel_request
 */

/**
 * Create a new of_sdwn_get_channel_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_channel_request
 */

of_object_t *
of_sdwn_get_channel_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CHANNEL_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_channel_request_init(obj, version, bytes, 0);
    of_sdwn_get_channel_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_channel_request.
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
of_sdwn_get_channel_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CHANNEL_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CHANNEL_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CHANNEL_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_request_xid_get(
    of_sdwn_get_channel_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_channel_request_xid_set(
    of_sdwn_get_channel_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_channel_request_flags_get(
    of_sdwn_get_channel_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_channel_request_flags_set(
    of_sdwn_get_channel_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_request_experimenter_get(
    of_sdwn_get_channel_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_channel_request_experimenter_set(
    of_sdwn_get_channel_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_channel_request_subtype_get(
    of_sdwn_get_channel_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_channel_request_subtype_set(
    of_sdwn_get_channel_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_get_channel_request_if_no_get(
    of_sdwn_get_channel_request_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_get_channel_request.
 * @param obj Pointer to an object of type of_sdwn_get_channel_request.
 * @param if_no The value to write into the object
 */
void
of_sdwn_get_channel_request_if_no_set(
    of_sdwn_get_channel_request_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CHANNEL_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

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
of_sdwn_get_clients_reply_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3: {
        uint8_t value = *(uint8_t *)(buf + 24); /* client_type */
        switch (value) {
        case 0x0:
            *id = OF_SDWN_GET_CLIENTS_REPLY_LVAP;
            break;
        case 0x1:
            *id = OF_SDWN_GET_CLIENTS_REPLY_NORMAL;
            break;
        case 0x2:
            *id = OF_SDWN_GET_CLIENTS_REPLY_CRYPTO;
            break;
        default:
            *id = OF_SDWN_GET_CLIENTS_REPLY;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_sdwn_get_clients_reply of_sdwn_get_clients_reply
 */

/**
 * Create a new of_sdwn_get_clients_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_clients_reply
 */

of_object_t *
of_sdwn_get_clients_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_get_clients_reply_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_clients_reply.
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
of_sdwn_get_clients_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CLIENTS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_xid_get(
    of_sdwn_get_clients_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_clients_reply_xid_set(
    of_sdwn_get_clients_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_flags_get(
    of_sdwn_get_clients_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_clients_reply_flags_set(
    of_sdwn_get_clients_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_experimenter_get(
    of_sdwn_get_clients_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_clients_reply_experimenter_set(
    of_sdwn_get_clients_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_subtype_get(
    of_sdwn_get_clients_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_clients_reply_subtype_set(
    of_sdwn_get_clients_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get client_type from an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param client_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_client_type_get(
    of_sdwn_get_clients_reply_t *obj,
    uint8_t *client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set client_type in an object of type of_sdwn_get_clients_reply.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply.
 * @param client_type The value to write into the object
 */
void
of_sdwn_get_clients_reply_client_type_set(
    of_sdwn_get_clients_reply_t *obj,
    uint8_t client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, client_type);

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
of_sdwn_get_clients_reply_crypto_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x2); /* subtype */
        *(uint8_t *)(buf + 24) = 0x2; /* client_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_clients_reply_crypto of_sdwn_get_clients_reply_crypto
 */

/**
 * Create a new of_sdwn_get_clients_reply_crypto object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_clients_reply_crypto
 */

of_object_t *
of_sdwn_get_clients_reply_crypto_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_CRYPTO];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_get_clients_reply_crypto_init(obj, version, bytes, 0);
    of_sdwn_get_clients_reply_crypto_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_clients_reply_crypto.
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
of_sdwn_get_clients_reply_crypto_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_CRYPTO] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_CRYPTO];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CLIENTS_REPLY_CRYPTO;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_xid_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_xid_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_flags_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_flags_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_experimenter_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_experimenter_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_subtype_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_subtype_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get client_type from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param client_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_client_type_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint8_t *client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set client_type in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param client_type The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_client_type_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint8_t client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mac from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_mac_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_mac_addr_t *mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mac in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param mac The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_mac_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_mac_addr_t mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get assoc_id from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param assoc_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_assoc_id_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t *assoc_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, assoc_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set assoc_id in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param assoc_id The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_assoc_id_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t assoc_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, assoc_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get capabilities from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param capabilities Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_capabilities_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t *capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set capabilities in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param capabilities The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_capabilities_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cap_flags from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param cap_flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_cap_flags_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t *cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cap_flags in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param cap_flags The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_cap_flags_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    uint16_t cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_ieee80211_ht_cap_t to the parent of type of_sdwn_get_clients_reply_crypto for
 * member ht_capabilities
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param ht_capabilities Pointer to the child object of type
 * of_ieee80211_ht_cap_t to be filled out.
 * \ingroup of_sdwn_get_clients_reply_crypto
 *
 * The parameter ht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_get_clients_reply_crypto_ht_capabilities_bind(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_ht_cap_init(ht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, ht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of ht_capabilities into a new variable of type of_ieee80211_ht_cap_t from
 * a of_sdwn_get_clients_reply_crypto instance.
 *
 * @param obj Pointer to the source of type of_sdwn_get_clients_reply_crypto_t
 * @returns A pointer to a new instance of type of_ieee80211_ht_cap_t whose contents
 * match that of ht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_ht_cap_t *
of_sdwn_get_clients_reply_crypto_ht_capabilities_get(of_sdwn_get_clients_reply_crypto_t *obj) {
    of_ieee80211_ht_cap_t _ht_capabilities;
    of_ieee80211_ht_cap_t *_ht_capabilities_ptr;

    of_sdwn_get_clients_reply_crypto_ht_capabilities_bind(obj, &_ht_capabilities);
    _ht_capabilities_ptr = (of_ieee80211_ht_cap_t *)of_object_dup(&_ht_capabilities);
    return _ht_capabilities_ptr;
}

/**
 * Set ht_capabilities in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param ht_capabilities Pointer to the child of type of_ieee80211_ht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_get_clients_reply_crypto_ht_capabilities_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = ht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == ht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(ht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(ht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)ht_capabilities, ht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_ieee80211_vht_cap_t to the parent of type of_sdwn_get_clients_reply_crypto for
 * member vht_capabilities
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param vht_capabilities Pointer to the child object of type
 * of_ieee80211_vht_cap_t to be filled out.
 * \ingroup of_sdwn_get_clients_reply_crypto
 *
 * The parameter vht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_get_clients_reply_crypto_vht_capabilities_bind(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 66;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_vht_cap_init(vht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, vht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of vht_capabilities into a new variable of type of_ieee80211_vht_cap_t from
 * a of_sdwn_get_clients_reply_crypto instance.
 *
 * @param obj Pointer to the source of type of_sdwn_get_clients_reply_crypto_t
 * @returns A pointer to a new instance of type of_ieee80211_vht_cap_t whose contents
 * match that of vht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_vht_cap_t *
of_sdwn_get_clients_reply_crypto_vht_capabilities_get(of_sdwn_get_clients_reply_crypto_t *obj) {
    of_ieee80211_vht_cap_t _vht_capabilities;
    of_ieee80211_vht_cap_t *_vht_capabilities_ptr;

    of_sdwn_get_clients_reply_crypto_vht_capabilities_bind(obj, &_vht_capabilities);
    _vht_capabilities_ptr = (of_ieee80211_vht_cap_t *)of_object_dup(&_vht_capabilities);
    return _vht_capabilities_ptr;
}

/**
 * Set vht_capabilities in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param vht_capabilities Pointer to the child of type of_ieee80211_vht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_get_clients_reply_crypto_vht_capabilities_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 66;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = vht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == vht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(vht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(vht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)vht_capabilities, vht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Get supported_rates from an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param supported_rates Pointer to the child object of type
 * of_desc_str_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_crypto_supported_rates_get(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_desc_str_t *supported_rates)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 78;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_get(wbuf, abs_offset, supported_rates);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported_rates in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param supported_rates The value to write into the object
 */
void
of_sdwn_get_clients_reply_crypto_supported_rates_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_desc_str_t supported_rates)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 78;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_set(wbuf, abs_offset, supported_rates);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_tlv_data_t to the parent of type of_sdwn_get_clients_reply_crypto for
 * member keys
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param keys Pointer to the child object of type
 * of_list_bsn_tlv_data_t to be filled out.
 * \ingroup of_sdwn_get_clients_reply_crypto
 *
 * The parameter keys is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_get_clients_reply_crypto_keys_bind(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_list_bsn_tlv_data_t *keys)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 334;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_tlv_data_init(keys, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, keys, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of keys into a new variable of type of_list_bsn_tlv_data_t from
 * a of_sdwn_get_clients_reply_crypto instance.
 *
 * @param obj Pointer to the source of type of_sdwn_get_clients_reply_crypto_t
 * @returns A pointer to a new instance of type of_list_bsn_tlv_data_t whose contents
 * match that of keys from source
 * @returns NULL if an error occurs
 */
of_list_bsn_tlv_data_t *
of_sdwn_get_clients_reply_crypto_keys_get(of_sdwn_get_clients_reply_crypto_t *obj) {
    of_list_bsn_tlv_data_t _keys;
    of_list_bsn_tlv_data_t *_keys_ptr;

    of_sdwn_get_clients_reply_crypto_keys_bind(obj, &_keys);
    _keys_ptr = (of_list_bsn_tlv_data_t *)of_object_dup(&_keys);
    return _keys_ptr;
}

/**
 * Set keys in an object of type of_sdwn_get_clients_reply_crypto.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_crypto.
 * @param keys Pointer to the child of type of_list_bsn_tlv_data_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_get_clients_reply_crypto_keys_set(
    of_sdwn_get_clients_reply_crypto_t *obj,
    of_list_bsn_tlv_data_t *keys)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_CRYPTO);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 334;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = keys->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == keys->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(keys, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(keys, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)keys, keys->length);

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
of_sdwn_get_clients_reply_lvap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x2); /* subtype */
        *(uint8_t *)(buf + 24) = 0x0; /* client_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_clients_reply_lvap of_sdwn_get_clients_reply_lvap
 */

/**
 * Create a new of_sdwn_get_clients_reply_lvap object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_clients_reply_lvap
 */

of_object_t *
of_sdwn_get_clients_reply_lvap_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_LVAP];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_clients_reply_lvap_init(obj, version, bytes, 0);
    of_sdwn_get_clients_reply_lvap_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_clients_reply_lvap.
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
of_sdwn_get_clients_reply_lvap_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_LVAP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_LVAP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CLIENTS_REPLY_LVAP;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_lvap_xid_get(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_clients_reply_lvap_xid_set(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_lvap_flags_get(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_clients_reply_lvap_flags_set(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_lvap_experimenter_get(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_clients_reply_lvap_experimenter_set(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_lvap_subtype_get(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_clients_reply_lvap_subtype_set(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get client_type from an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param client_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_lvap_client_type_get(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint8_t *client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set client_type in an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param client_type The value to write into the object
 */
void
of_sdwn_get_clients_reply_lvap_client_type_set(
    of_sdwn_get_clients_reply_lvap_t *obj,
    uint8_t client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mac from an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_lvap_mac_get(
    of_sdwn_get_clients_reply_lvap_t *obj,
    of_mac_addr_t *mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mac in an object of type of_sdwn_get_clients_reply_lvap.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_lvap.
 * @param mac The value to write into the object
 */
void
of_sdwn_get_clients_reply_lvap_mac_set(
    of_sdwn_get_clients_reply_lvap_t *obj,
    of_mac_addr_t mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, mac);

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
of_sdwn_get_clients_reply_normal_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x2); /* subtype */
        *(uint8_t *)(buf + 24) = 0x1; /* client_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_clients_reply_normal of_sdwn_get_clients_reply_normal
 */

/**
 * Create a new of_sdwn_get_clients_reply_normal object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_clients_reply_normal
 */

of_object_t *
of_sdwn_get_clients_reply_normal_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_NORMAL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_clients_reply_normal_init(obj, version, bytes, 0);
    of_sdwn_get_clients_reply_normal_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_clients_reply_normal.
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
of_sdwn_get_clients_reply_normal_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_NORMAL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REPLY_NORMAL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CLIENTS_REPLY_NORMAL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_xid_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_xid_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_flags_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_flags_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_experimenter_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_experimenter_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_subtype_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_subtype_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get client_type from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param client_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_client_type_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint8_t *client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set client_type in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param client_type The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_client_type_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint8_t client_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, client_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mac from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_mac_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_mac_addr_t *mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mac in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param mac The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_mac_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_mac_addr_t mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get assoc_id from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param assoc_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_assoc_id_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t *assoc_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, assoc_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set assoc_id in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param assoc_id The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_assoc_id_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t assoc_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, assoc_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get capabilities from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param capabilities Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_capabilities_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t *capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set capabilities in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param capabilities The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_capabilities_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cap_flags from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param cap_flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_cap_flags_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t *cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cap_flags in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param cap_flags The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_cap_flags_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    uint16_t cap_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 38;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, cap_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_ieee80211_ht_cap_t to the parent of type of_sdwn_get_clients_reply_normal for
 * member ht_capabilities
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param ht_capabilities Pointer to the child object of type
 * of_ieee80211_ht_cap_t to be filled out.
 * \ingroup of_sdwn_get_clients_reply_normal
 *
 * The parameter ht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_get_clients_reply_normal_ht_capabilities_bind(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_ht_cap_init(ht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, ht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of ht_capabilities into a new variable of type of_ieee80211_ht_cap_t from
 * a of_sdwn_get_clients_reply_normal instance.
 *
 * @param obj Pointer to the source of type of_sdwn_get_clients_reply_normal_t
 * @returns A pointer to a new instance of type of_ieee80211_ht_cap_t whose contents
 * match that of ht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_ht_cap_t *
of_sdwn_get_clients_reply_normal_ht_capabilities_get(of_sdwn_get_clients_reply_normal_t *obj) {
    of_ieee80211_ht_cap_t _ht_capabilities;
    of_ieee80211_ht_cap_t *_ht_capabilities_ptr;

    of_sdwn_get_clients_reply_normal_ht_capabilities_bind(obj, &_ht_capabilities);
    _ht_capabilities_ptr = (of_ieee80211_ht_cap_t *)of_object_dup(&_ht_capabilities);
    return _ht_capabilities_ptr;
}

/**
 * Set ht_capabilities in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param ht_capabilities Pointer to the child of type of_ieee80211_ht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_get_clients_reply_normal_ht_capabilities_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_ieee80211_ht_cap_t *ht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 40;
        cur_len = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = ht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == ht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(ht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(ht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)ht_capabilities, ht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Bind an object of type of_ieee80211_vht_cap_t to the parent of type of_sdwn_get_clients_reply_normal for
 * member vht_capabilities
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param vht_capabilities Pointer to the child object of type
 * of_ieee80211_vht_cap_t to be filled out.
 * \ingroup of_sdwn_get_clients_reply_normal
 *
 * The parameter vht_capabilities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_get_clients_reply_normal_vht_capabilities_bind(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 66;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_ieee80211_vht_cap_init(vht_capabilities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, vht_capabilities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of vht_capabilities into a new variable of type of_ieee80211_vht_cap_t from
 * a of_sdwn_get_clients_reply_normal instance.
 *
 * @param obj Pointer to the source of type of_sdwn_get_clients_reply_normal_t
 * @returns A pointer to a new instance of type of_ieee80211_vht_cap_t whose contents
 * match that of vht_capabilities from source
 * @returns NULL if an error occurs
 */
of_ieee80211_vht_cap_t *
of_sdwn_get_clients_reply_normal_vht_capabilities_get(of_sdwn_get_clients_reply_normal_t *obj) {
    of_ieee80211_vht_cap_t _vht_capabilities;
    of_ieee80211_vht_cap_t *_vht_capabilities_ptr;

    of_sdwn_get_clients_reply_normal_vht_capabilities_bind(obj, &_vht_capabilities);
    _vht_capabilities_ptr = (of_ieee80211_vht_cap_t *)of_object_dup(&_vht_capabilities);
    return _vht_capabilities_ptr;
}

/**
 * Set vht_capabilities in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param vht_capabilities Pointer to the child of type of_ieee80211_vht_cap_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_get_clients_reply_normal_vht_capabilities_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_ieee80211_vht_cap_t *vht_capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 66;
        cur_len = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = vht_capabilities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == vht_capabilities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(vht_capabilities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(vht_capabilities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)vht_capabilities, vht_capabilities->length);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Get supported_rates from an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param supported_rates Pointer to the child object of type
 * of_desc_str_t to be filled out.
 *
 */
void
of_sdwn_get_clients_reply_normal_supported_rates_get(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_desc_str_t *supported_rates)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 78;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_get(wbuf, abs_offset, supported_rates);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set supported_rates in an object of type of_sdwn_get_clients_reply_normal.
 * @param obj Pointer to an object of type of_sdwn_get_clients_reply_normal.
 * @param supported_rates The value to write into the object
 */
void
of_sdwn_get_clients_reply_normal_supported_rates_set(
    of_sdwn_get_clients_reply_normal_t *obj,
    of_desc_str_t supported_rates)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REPLY_NORMAL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 78;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_set(wbuf, abs_offset, supported_rates);

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
of_sdwn_get_clients_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_clients_request of_sdwn_get_clients_request
 */

/**
 * Create a new of_sdwn_get_clients_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_clients_request
 */

of_object_t *
of_sdwn_get_clients_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_clients_request_init(obj, version, bytes, 0);
    of_sdwn_get_clients_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_clients_request.
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
of_sdwn_get_clients_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_CLIENTS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_CLIENTS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_request_xid_get(
    of_sdwn_get_clients_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_clients_request_xid_set(
    of_sdwn_get_clients_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_get_clients_request_flags_get(
    of_sdwn_get_clients_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param flags The value to write into the object
 */
void
of_sdwn_get_clients_request_flags_set(
    of_sdwn_get_clients_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_request_experimenter_get(
    of_sdwn_get_clients_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_clients_request_experimenter_set(
    of_sdwn_get_clients_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_clients_request_subtype_get(
    of_sdwn_get_clients_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_clients_request_subtype_set(
    of_sdwn_get_clients_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_get_clients_request_if_no_get(
    of_sdwn_get_clients_request_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_get_clients_request.
 * @param obj Pointer to an object of type of_sdwn_get_clients_request.
 * @param if_no The value to write into the object
 */
void
of_sdwn_get_clients_request_if_no_set(
    of_sdwn_get_clients_request_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_CLIENTS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

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
of_sdwn_get_remote_port_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x7); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_remote_port_reply of_sdwn_get_remote_port_reply
 */

/**
 * Create a new of_sdwn_get_remote_port_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_remote_port_reply
 */

of_object_t *
of_sdwn_get_remote_port_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_REMOTE_PORT_REPLY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_remote_port_reply_init(obj, version, bytes, 0);
    of_sdwn_get_remote_port_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_remote_port_reply.
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
of_sdwn_get_remote_port_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_REMOTE_PORT_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_REMOTE_PORT_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_REMOTE_PORT_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_reply_xid_get(
    of_sdwn_get_remote_port_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_remote_port_reply_xid_set(
    of_sdwn_get_remote_port_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_reply_experimenter_get(
    of_sdwn_get_remote_port_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_remote_port_reply_experimenter_set(
    of_sdwn_get_remote_port_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_reply_subtype_get(
    of_sdwn_get_remote_port_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_remote_port_reply_subtype_set(
    of_sdwn_get_remote_port_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_reply_if_no_get(
    of_sdwn_get_remote_port_reply_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_get_remote_port_reply.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_reply.
 * @param if_no The value to write into the object
 */
void
of_sdwn_get_remote_port_reply_if_no_set(
    of_sdwn_get_remote_port_reply_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REPLY);
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

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
of_sdwn_get_remote_port_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_get_remote_port_request of_sdwn_get_remote_port_request
 */

/**
 * Create a new of_sdwn_get_remote_port_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_get_remote_port_request
 */

of_object_t *
of_sdwn_get_remote_port_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_GET_REMOTE_PORT_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_get_remote_port_request_init(obj, version, bytes, 0);
    of_sdwn_get_remote_port_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_get_remote_port_request.
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
of_sdwn_get_remote_port_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_GET_REMOTE_PORT_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_GET_REMOTE_PORT_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_GET_REMOTE_PORT_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_get_remote_port_request.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_request_xid_get(
    of_sdwn_get_remote_port_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_get_remote_port_request.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_request.
 * @param xid The value to write into the object
 */
void
of_sdwn_get_remote_port_request_xid_set(
    of_sdwn_get_remote_port_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_get_remote_port_request.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_request_experimenter_get(
    of_sdwn_get_remote_port_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_get_remote_port_request.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_request.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_get_remote_port_request_experimenter_set(
    of_sdwn_get_remote_port_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_get_remote_port_request.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_get_remote_port_request_subtype_get(
    of_sdwn_get_remote_port_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_get_remote_port_request.
 * @param obj Pointer to an object of type of_sdwn_get_remote_port_request.
 * @param subtype The value to write into the object
 */
void
of_sdwn_get_remote_port_request_subtype_set(
    of_sdwn_get_remote_port_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_GET_REMOTE_PORT_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

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
of_sdwn_ieee80211_mgmt_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x9); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_ieee80211_mgmt of_sdwn_ieee80211_mgmt
 */

/**
 * Create a new of_sdwn_ieee80211_mgmt object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_ieee80211_mgmt
 */

of_object_t *
of_sdwn_ieee80211_mgmt_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_IEEE80211_MGMT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_ieee80211_mgmt_init(obj, version, bytes, 0);
    of_sdwn_ieee80211_mgmt_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_ieee80211_mgmt.
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
of_sdwn_ieee80211_mgmt_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_IEEE80211_MGMT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_IEEE80211_MGMT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_IEEE80211_MGMT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_xid_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param xid The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_xid_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_experimenter_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_experimenter_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_subtype_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param subtype The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_subtype_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ieee80211_type from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param ieee80211_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_ieee80211_type_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint8_t *ieee80211_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u8_get(wbuf, abs_offset, ieee80211_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ieee80211_type in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param ieee80211_type The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_ieee80211_type_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint8_t ieee80211_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
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
    of_wire_buffer_u8_set(wbuf, abs_offset, ieee80211_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get addr from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param addr Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_addr_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    of_mac_addr_t *addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 17;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set addr in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param addr The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_addr_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    of_mac_addr_t addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 17;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get target from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param target Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_target_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    of_mac_addr_t *target)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 23;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, target);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set target in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param target The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_target_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    of_mac_addr_t target)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 23;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, target);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ssi from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param ssi Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_ssi_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t *ssi)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 29;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, ssi);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ssi in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param ssi The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_ssi_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t ssi)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 29;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, ssi);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get freq from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param freq Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_freq_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t *freq)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 33;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, freq);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set freq in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param freq The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_freq_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    uint32_t freq)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 33;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, freq);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_if_no_get(
    of_sdwn_ieee80211_mgmt_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 37;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_ieee80211_mgmt.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt.
 * @param if_no The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_if_no_set(
    of_sdwn_ieee80211_mgmt_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 37;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

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
of_sdwn_ieee80211_mgmt_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0xa); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_ieee80211_mgmt_reply of_sdwn_ieee80211_mgmt_reply
 */

/**
 * Create a new of_sdwn_ieee80211_mgmt_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_ieee80211_mgmt_reply
 */

of_object_t *
of_sdwn_ieee80211_mgmt_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_IEEE80211_MGMT_REPLY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_ieee80211_mgmt_reply_init(obj, version, bytes, 0);
    of_sdwn_ieee80211_mgmt_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_ieee80211_mgmt_reply.
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
of_sdwn_ieee80211_mgmt_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_IEEE80211_MGMT_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_IEEE80211_MGMT_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_IEEE80211_MGMT_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_reply_xid_get(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param xid The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_reply_xid_set(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_reply_experimenter_get(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_reply_experimenter_set(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_reply_subtype_get(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param subtype The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_reply_subtype_set(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_reply_if_no_get(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param if_no The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_reply_if_no_set(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get deny from an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param deny Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_ieee80211_mgmt_reply_deny_get(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint8_t *deny)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 23;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, deny);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set deny in an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param obj Pointer to an object of type of_sdwn_ieee80211_mgmt_reply.
 * @param deny The value to write into the object
 */
void
of_sdwn_ieee80211_mgmt_reply_deny_set(
    of_sdwn_ieee80211_mgmt_reply_t *obj,
    uint8_t deny)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_IEEE80211_MGMT_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 23;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, deny);

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
of_sdwn_mod_lvap_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_mod_lvap of_sdwn_mod_lvap
 */

/**
 * Create a new of_sdwn_mod_lvap object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_mod_lvap
 */

of_object_t *
of_sdwn_mod_lvap_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_MOD_LVAP];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_mod_lvap_init(obj, version, bytes, 0);
    of_sdwn_mod_lvap_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_mod_lvap.
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
of_sdwn_mod_lvap_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_MOD_LVAP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_MOD_LVAP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_MOD_LVAP;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_mod_lvap_xid_get(
    of_sdwn_mod_lvap_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param xid The value to write into the object
 */
void
of_sdwn_mod_lvap_xid_set(
    of_sdwn_mod_lvap_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_mod_lvap_experimenter_get(
    of_sdwn_mod_lvap_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_mod_lvap_experimenter_set(
    of_sdwn_mod_lvap_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_mod_lvap_subtype_get(
    of_sdwn_mod_lvap_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param subtype The value to write into the object
 */
void
of_sdwn_mod_lvap_subtype_set(
    of_sdwn_mod_lvap_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get bssid from an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param bssid Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_mod_lvap_bssid_get(
    of_sdwn_mod_lvap_t *obj,
    of_mac_addr_t *bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set bssid in an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param bssid The value to write into the object
 */
void
of_sdwn_mod_lvap_bssid_set(
    of_sdwn_mod_lvap_t *obj,
    of_mac_addr_t bssid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, bssid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get config from an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param config Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_mod_lvap_config_get(
    of_sdwn_mod_lvap_t *obj,
    uint16_t *config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set config in an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param config The value to write into the object
 */
void
of_sdwn_mod_lvap_config_set(
    of_sdwn_mod_lvap_t *obj,
    uint16_t config)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, config);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mask from an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param mask Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_mod_lvap_mask_get(
    of_sdwn_mod_lvap_t *obj,
    uint16_t *mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mask in an object of type of_sdwn_mod_lvap.
 * @param obj Pointer to an object of type of_sdwn_mod_lvap.
 * @param mask The value to write into the object
 */
void
of_sdwn_mod_lvap_mask_set(
    of_sdwn_mod_lvap_t *obj,
    uint16_t mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_MOD_LVAP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, mask);

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
of_sdwn_packet_in_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_packet_in of_sdwn_packet_in
 */

/**
 * Create a new of_sdwn_packet_in object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_packet_in
 */

of_object_t *
of_sdwn_packet_in_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_PACKET_IN];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_packet_in_init(obj, version, bytes, 0);
    of_sdwn_packet_in_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_packet_in.
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
of_sdwn_packet_in_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_PACKET_IN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_PACKET_IN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_PACKET_IN;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_packet_in_xid_get(
    of_sdwn_packet_in_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param xid The value to write into the object
 */
void
of_sdwn_packet_in_xid_set(
    of_sdwn_packet_in_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_packet_in_experimenter_get(
    of_sdwn_packet_in_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_packet_in_experimenter_set(
    of_sdwn_packet_in_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_packet_in_subtype_get(
    of_sdwn_packet_in_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param subtype The value to write into the object
 */
void
of_sdwn_packet_in_subtype_set(
    of_sdwn_packet_in_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_packet_in_if_no_get(
    of_sdwn_packet_in_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param if_no The value to write into the object
 */
void
of_sdwn_packet_in_if_no_set(
    of_sdwn_packet_in_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_version_type from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_version_type Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_version_type_get(
    of_sdwn_packet_in_t *obj,
    uint8_t *hdr_version_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, hdr_version_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_version_type in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_version_type The value to write into the object
 */
void
of_sdwn_packet_in_hdr_version_type_set(
    of_sdwn_packet_in_t *obj,
    uint8_t hdr_version_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, hdr_version_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_flags from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_flags Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_flags_get(
    of_sdwn_packet_in_t *obj,
    uint8_t *hdr_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 21;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, hdr_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_flags in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_flags The value to write into the object
 */
void
of_sdwn_packet_in_hdr_flags_set(
    of_sdwn_packet_in_t *obj,
    uint8_t hdr_flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 21;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, hdr_flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_duration from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_duration Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_duration_get(
    of_sdwn_packet_in_t *obj,
    uint16_t *hdr_duration)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, hdr_duration);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_duration in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_duration The value to write into the object
 */
void
of_sdwn_packet_in_hdr_duration_set(
    of_sdwn_packet_in_t *obj,
    uint16_t hdr_duration)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, hdr_duration);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_addr1 from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr1 Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_addr1_get(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t *hdr_addr1)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, hdr_addr1);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_addr1 in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr1 The value to write into the object
 */
void
of_sdwn_packet_in_hdr_addr1_set(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t hdr_addr1)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, hdr_addr1);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_addr2 from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr2 Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_addr2_get(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t *hdr_addr2)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, hdr_addr2);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_addr2 in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr2 The value to write into the object
 */
void
of_sdwn_packet_in_hdr_addr2_set(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t hdr_addr2)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, hdr_addr2);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_addr3 from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr3 Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_addr3_get(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t *hdr_addr3)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_mac_get(wbuf, abs_offset, hdr_addr3);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_addr3 in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr3 The value to write into the object
 */
void
of_sdwn_packet_in_hdr_addr3_set(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t hdr_addr3)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
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
    of_wire_buffer_mac_set(wbuf, abs_offset, hdr_addr3);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_seq_ctrl from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_seq_ctrl Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_seq_ctrl_get(
    of_sdwn_packet_in_t *obj,
    uint16_t *hdr_seq_ctrl)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 42;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, hdr_seq_ctrl);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_seq_ctrl in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_seq_ctrl The value to write into the object
 */
void
of_sdwn_packet_in_hdr_seq_ctrl_set(
    of_sdwn_packet_in_t *obj,
    uint16_t hdr_seq_ctrl)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 42;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, hdr_seq_ctrl);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get hdr_addr4 from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr4 Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_sdwn_packet_in_hdr_addr4_get(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t *hdr_addr4)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, hdr_addr4);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set hdr_addr4 in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param hdr_addr4 The value to write into the object
 */
void
of_sdwn_packet_in_hdr_addr4_set(
    of_sdwn_packet_in_t *obj,
    of_mac_addr_t hdr_addr4)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, hdr_addr4);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get frame from an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param frame Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_sdwn_packet_in_frame_get(
    of_sdwn_packet_in_t *obj,
    of_octets_t *frame)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 50;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    frame->bytes = cur_len;
    frame->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set frame in an object of type of_sdwn_packet_in.
 * @param obj Pointer to an object of type of_sdwn_packet_in.
 * @param frame The value to write into the object
 */
int WARN_UNUSED_RESULT
of_sdwn_packet_in_frame_set(
    of_sdwn_packet_in_t *obj,
    of_octets_t *frame)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_PACKET_IN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 50;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = frame->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, frame, cur_len);

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
of_sdwn_port_desc_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_port_desc_reply of_sdwn_port_desc_reply
 */

/**
 * Create a new of_sdwn_port_desc_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_port_desc_reply
 */

of_object_t *
of_sdwn_port_desc_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_PORT_DESC_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_sdwn_port_desc_reply_init(obj, version, bytes, 0);
    of_sdwn_port_desc_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_port_desc_reply.
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
of_sdwn_port_desc_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_PORT_DESC_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_PORT_DESC_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_PORT_DESC_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_port_desc_reply_xid_get(
    of_sdwn_port_desc_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param xid The value to write into the object
 */
void
of_sdwn_port_desc_reply_xid_set(
    of_sdwn_port_desc_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_port_desc_reply_flags_get(
    of_sdwn_port_desc_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param flags The value to write into the object
 */
void
of_sdwn_port_desc_reply_flags_set(
    of_sdwn_port_desc_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_port_desc_reply_experimenter_get(
    of_sdwn_port_desc_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_port_desc_reply_experimenter_set(
    of_sdwn_port_desc_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_port_desc_reply_subtype_get(
    of_sdwn_port_desc_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param subtype The value to write into the object
 */
void
of_sdwn_port_desc_reply_subtype_set(
    of_sdwn_port_desc_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_sdwn_entity_t to the parent of type of_sdwn_port_desc_reply for
 * member entities
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param entities Pointer to the child object of type
 * of_list_sdwn_entity_t to be filled out.
 * \ingroup of_sdwn_port_desc_reply
 *
 * The parameter entities is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_sdwn_port_desc_reply_entities_bind(
    of_sdwn_port_desc_reply_t *obj,
    of_list_sdwn_entity_t *entities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_sdwn_entity_init(entities, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, entities, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entities into a new variable of type of_list_sdwn_entity_t from
 * a of_sdwn_port_desc_reply instance.
 *
 * @param obj Pointer to the source of type of_sdwn_port_desc_reply_t
 * @returns A pointer to a new instance of type of_list_sdwn_entity_t whose contents
 * match that of entities from source
 * @returns NULL if an error occurs
 */
of_list_sdwn_entity_t *
of_sdwn_port_desc_reply_entities_get(of_sdwn_port_desc_reply_t *obj) {
    of_list_sdwn_entity_t _entities;
    of_list_sdwn_entity_t *_entities_ptr;

    of_sdwn_port_desc_reply_entities_bind(obj, &_entities);
    _entities_ptr = (of_list_sdwn_entity_t *)of_object_dup(&_entities);
    return _entities_ptr;
}

/**
 * Set entities in an object of type of_sdwn_port_desc_reply.
 * @param obj Pointer to an object of type of_sdwn_port_desc_reply.
 * @param entities Pointer to the child of type of_list_sdwn_entity_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_sdwn_port_desc_reply_entities_set(
    of_sdwn_port_desc_reply_t *obj,
    of_list_sdwn_entity_t *entities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entities->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == entities->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entities, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entities, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)entities, entities->length);

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
of_sdwn_port_desc_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 20) = U32_HTON(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_port_desc_request of_sdwn_port_desc_request
 */

/**
 * Create a new of_sdwn_port_desc_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_port_desc_request
 */

of_object_t *
of_sdwn_port_desc_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_PORT_DESC_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_port_desc_request_init(obj, version, bytes, 0);
    of_sdwn_port_desc_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_port_desc_request.
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
of_sdwn_port_desc_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_PORT_DESC_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_PORT_DESC_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_PORT_DESC_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_port_desc_request_xid_get(
    of_sdwn_port_desc_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param xid The value to write into the object
 */
void
of_sdwn_port_desc_request_xid_set(
    of_sdwn_port_desc_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_sdwn_port_desc_request_flags_get(
    of_sdwn_port_desc_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param flags The value to write into the object
 */
void
of_sdwn_port_desc_request_flags_set(
    of_sdwn_port_desc_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_port_desc_request_experimenter_get(
    of_sdwn_port_desc_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_port_desc_request_experimenter_set(
    of_sdwn_port_desc_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_port_desc_request_subtype_get(
    of_sdwn_port_desc_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_port_desc_request.
 * @param obj Pointer to an object of type of_sdwn_port_desc_request.
 * @param subtype The value to write into the object
 */
void
of_sdwn_port_desc_request_subtype_set(
    of_sdwn_port_desc_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_PORT_DESC_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

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
of_sdwn_set_channel_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = U32_HTON(0x421337); /* experimenter */
        *(uint32_t *)(buf + 12) = U32_HTON(0xd); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_sdwn_set_channel of_sdwn_set_channel
 */

/**
 * Create a new of_sdwn_set_channel object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_sdwn_set_channel
 */

of_object_t *
of_sdwn_set_channel_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SDWN_SET_CHANNEL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_sdwn_set_channel_init(obj, version, bytes, 0);
    of_sdwn_set_channel_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_sdwn_set_channel.
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
of_sdwn_set_channel_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SDWN_SET_CHANNEL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SDWN_SET_CHANNEL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SDWN_SET_CHANNEL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_set_channel_xid_get(
    of_sdwn_set_channel_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param xid The value to write into the object
 */
void
of_sdwn_set_channel_xid_set(
    of_sdwn_set_channel_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_set_channel_experimenter_get(
    of_sdwn_set_channel_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param experimenter The value to write into the object
 */
void
of_sdwn_set_channel_experimenter_set(
    of_sdwn_set_channel_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_set_channel_subtype_get(
    of_sdwn_set_channel_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param subtype The value to write into the object
 */
void
of_sdwn_set_channel_subtype_set(
    of_sdwn_set_channel_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get if_no from an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param if_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_sdwn_set_channel_if_no_get(
    of_sdwn_set_channel_t *obj,
    of_port_no_t *if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, if_no);
    OF_PORT_NO_VALUE_CHECK(*if_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set if_no in an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param if_no The value to write into the object
 */
void
of_sdwn_set_channel_if_no_set(
    of_sdwn_set_channel_t *obj,
    of_port_no_t if_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, if_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get frequency from an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param frequency Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_set_channel_frequency_get(
    of_sdwn_set_channel_t *obj,
    uint32_t *frequency)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, frequency);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set frequency in an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param frequency The value to write into the object
 */
void
of_sdwn_set_channel_frequency_set(
    of_sdwn_set_channel_t *obj,
    uint32_t frequency)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, frequency);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get beacon_count from an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param beacon_count Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_sdwn_set_channel_beacon_count_get(
    of_sdwn_set_channel_t *obj,
    uint32_t *beacon_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, beacon_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set beacon_count in an object of type of_sdwn_set_channel.
 * @param obj Pointer to an object of type of_sdwn_set_channel.
 * @param beacon_count The value to write into the object
 */
void
of_sdwn_set_channel_beacon_count_set(
    of_sdwn_set_channel_t *obj,
    uint32_t beacon_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SDWN_SET_CHANNEL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, beacon_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
