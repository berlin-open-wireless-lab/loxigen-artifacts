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
of_action_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_ACTION_OUTPUT;
            break;
        case 0x1:
            *id = OF_ACTION_SET_VLAN_VID;
            break;
        case 0x2:
            *id = OF_ACTION_SET_VLAN_PCP;
            break;
        case 0x3:
            *id = OF_ACTION_STRIP_VLAN;
            break;
        case 0x4:
            *id = OF_ACTION_SET_DL_SRC;
            break;
        case 0x5:
            *id = OF_ACTION_SET_DL_DST;
            break;
        case 0x6:
            *id = OF_ACTION_SET_NW_SRC;
            break;
        case 0x7:
            *id = OF_ACTION_SET_NW_DST;
            break;
        case 0x8:
            *id = OF_ACTION_SET_NW_TOS;
            break;
        case 0x9:
            *id = OF_ACTION_SET_TP_SRC;
            break;
        case 0xa:
            *id = OF_ACTION_SET_TP_DST;
            break;
        case 0xb:
            *id = OF_ACTION_ENQUEUE;
            break;
        case 0xffff:
            of_action_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_ACTION_OUTPUT;
            break;
        case 0x1:
            *id = OF_ACTION_SET_VLAN_VID;
            break;
        case 0x2:
            *id = OF_ACTION_SET_VLAN_PCP;
            break;
        case 0x3:
            *id = OF_ACTION_SET_DL_SRC;
            break;
        case 0x4:
            *id = OF_ACTION_SET_DL_DST;
            break;
        case 0x5:
            *id = OF_ACTION_SET_NW_SRC;
            break;
        case 0x6:
            *id = OF_ACTION_SET_NW_DST;
            break;
        case 0x7:
            *id = OF_ACTION_SET_NW_TOS;
            break;
        case 0x8:
            *id = OF_ACTION_SET_NW_ECN;
            break;
        case 0x9:
            *id = OF_ACTION_SET_TP_SRC;
            break;
        case 0xa:
            *id = OF_ACTION_SET_TP_DST;
            break;
        case 0xb:
            *id = OF_ACTION_COPY_TTL_OUT;
            break;
        case 0xc:
            *id = OF_ACTION_COPY_TTL_IN;
            break;
        case 0xd:
            *id = OF_ACTION_SET_MPLS_LABEL;
            break;
        case 0xe:
            *id = OF_ACTION_SET_MPLS_TC;
            break;
        case 0xf:
            *id = OF_ACTION_SET_MPLS_TTL;
            break;
        case 0x10:
            *id = OF_ACTION_DEC_MPLS_TTL;
            break;
        case 0x11:
            *id = OF_ACTION_PUSH_VLAN;
            break;
        case 0x12:
            *id = OF_ACTION_POP_VLAN;
            break;
        case 0x13:
            *id = OF_ACTION_PUSH_MPLS;
            break;
        case 0x14:
            *id = OF_ACTION_POP_MPLS;
            break;
        case 0x15:
            *id = OF_ACTION_SET_QUEUE;
            break;
        case 0x16:
            *id = OF_ACTION_GROUP;
            break;
        case 0x17:
            *id = OF_ACTION_SET_NW_TTL;
            break;
        case 0x18:
            *id = OF_ACTION_DEC_NW_TTL;
            break;
        case 0xffff:
            of_action_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_ACTION_OUTPUT;
            break;
        case 0xb:
            *id = OF_ACTION_COPY_TTL_OUT;
            break;
        case 0xc:
            *id = OF_ACTION_COPY_TTL_IN;
            break;
        case 0xf:
            *id = OF_ACTION_SET_MPLS_TTL;
            break;
        case 0x10:
            *id = OF_ACTION_DEC_MPLS_TTL;
            break;
        case 0x11:
            *id = OF_ACTION_PUSH_VLAN;
            break;
        case 0x12:
            *id = OF_ACTION_POP_VLAN;
            break;
        case 0x13:
            *id = OF_ACTION_PUSH_MPLS;
            break;
        case 0x14:
            *id = OF_ACTION_POP_MPLS;
            break;
        case 0x15:
            *id = OF_ACTION_SET_QUEUE;
            break;
        case 0x16:
            *id = OF_ACTION_GROUP;
            break;
        case 0x17:
            *id = OF_ACTION_SET_NW_TTL;
            break;
        case 0x18:
            *id = OF_ACTION_DEC_NW_TTL;
            break;
        case 0x19:
            *id = OF_ACTION_SET_FIELD;
            break;
        case 0xffff:
            of_action_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_ACTION_OUTPUT;
            break;
        case 0xb:
            *id = OF_ACTION_COPY_TTL_OUT;
            break;
        case 0xc:
            *id = OF_ACTION_COPY_TTL_IN;
            break;
        case 0xf:
            *id = OF_ACTION_SET_MPLS_TTL;
            break;
        case 0x10:
            *id = OF_ACTION_DEC_MPLS_TTL;
            break;
        case 0x11:
            *id = OF_ACTION_PUSH_VLAN;
            break;
        case 0x12:
            *id = OF_ACTION_POP_VLAN;
            break;
        case 0x13:
            *id = OF_ACTION_PUSH_MPLS;
            break;
        case 0x14:
            *id = OF_ACTION_POP_MPLS;
            break;
        case 0x15:
            *id = OF_ACTION_SET_QUEUE;
            break;
        case 0x16:
            *id = OF_ACTION_GROUP;
            break;
        case 0x17:
            *id = OF_ACTION_SET_NW_TTL;
            break;
        case 0x18:
            *id = OF_ACTION_DEC_NW_TTL;
            break;
        case 0x19:
            *id = OF_ACTION_SET_FIELD;
            break;
        case 0x1a:
            *id = OF_ACTION_PUSH_PBB;
            break;
        case 0x1b:
            *id = OF_ACTION_POP_PBB;
            break;
        case 0xffff:
            of_action_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 0)); /* type */
        switch (value) {
        case 0x0:
            *id = OF_ACTION_OUTPUT;
            break;
        case 0xb:
            *id = OF_ACTION_COPY_TTL_OUT;
            break;
        case 0xc:
            *id = OF_ACTION_COPY_TTL_IN;
            break;
        case 0xf:
            *id = OF_ACTION_SET_MPLS_TTL;
            break;
        case 0x10:
            *id = OF_ACTION_DEC_MPLS_TTL;
            break;
        case 0x11:
            *id = OF_ACTION_PUSH_VLAN;
            break;
        case 0x12:
            *id = OF_ACTION_POP_VLAN;
            break;
        case 0x13:
            *id = OF_ACTION_PUSH_MPLS;
            break;
        case 0x14:
            *id = OF_ACTION_POP_MPLS;
            break;
        case 0x15:
            *id = OF_ACTION_SET_QUEUE;
            break;
        case 0x16:
            *id = OF_ACTION_GROUP;
            break;
        case 0x17:
            *id = OF_ACTION_SET_NW_TTL;
            break;
        case 0x18:
            *id = OF_ACTION_DEC_NW_TTL;
            break;
        case 0x19:
            *id = OF_ACTION_SET_FIELD;
            break;
        case 0x1a:
            *id = OF_ACTION_PUSH_PBB;
            break;
        case 0x1b:
            *id = OF_ACTION_POP_PBB;
            break;
        case 0xffff:
            of_action_experimenter_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_action of_action
 */

/**
 * Create a new of_action object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action
 */

of_object_t *
of_action_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action.
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
of_action_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION;

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
of_action_experimenter_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x2320:
            of_action_nicira_wire_object_id_get(obj, id);
            break;
        case 0x5c16c7:
            of_action_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x2320:
            of_action_nicira_wire_object_id_get(obj, id);
            break;
        case 0x5c16c7:
            of_action_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x2320:
            of_action_nicira_wire_object_id_get(obj, id);
            break;
        case 0x5c16c7:
            of_action_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x1018:
            of_action_ofdpa_wire_object_id_get(obj, id);
            break;
        case 0x2320:
            of_action_nicira_wire_object_id_get(obj, id);
            break;
        case 0x5c16c7:
            of_action_bsn_wire_object_id_get(obj, id);
            break;
        case 0x748771:
            *id = OF_ACTION_CIRCUIT;
            break;
        case 0xff000088:
            *id = OF_ACTION_OPLINK_ATT;
            break;
        default:
            *id = OF_ACTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x2320:
            of_action_nicira_wire_object_id_get(obj, id);
            break;
        case 0x5c16c7:
            of_action_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ACTION_EXPERIMENTER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_action_experimenter of_action_experimenter
 */

/**
 * Create a new of_action_experimenter object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_experimenter
 */

of_object_t *
of_action_experimenter_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_EXPERIMENTER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_experimenter.
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
of_action_experimenter_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_EXPERIMENTER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_experimenter.
 * @param obj Pointer to an object of type of_action_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_experimenter_experimenter_get(
    of_action_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_experimenter.
 * @param obj Pointer to an object of type of_action_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_action_experimenter_experimenter_set(
    of_action_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get data from an object of type of_action_experimenter.
 * @param obj Pointer to an object of type of_action_experimenter.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_action_experimenter_data_get(
    of_action_experimenter_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_action_experimenter.
 * @param obj Pointer to an object of type of_action_experimenter.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_action_experimenter_data_set(
    of_action_experimenter_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_ACTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = data->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, data, cur_len);

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
of_action_bsn_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_BSN_MIRROR;
            break;
        case 0x2:
            *id = OF_ACTION_BSN_SET_TUNNEL_DST;
            break;
        case 0x4:
            *id = OF_ACTION_BSN_CHECKSUM;
            break;
        default:
            *id = OF_ACTION_BSN;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_BSN_MIRROR;
            break;
        case 0x2:
            *id = OF_ACTION_BSN_SET_TUNNEL_DST;
            break;
        case 0x4:
            *id = OF_ACTION_BSN_CHECKSUM;
            break;
        default:
            *id = OF_ACTION_BSN;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_BSN_MIRROR;
            break;
        case 0x2:
            *id = OF_ACTION_BSN_SET_TUNNEL_DST;
            break;
        case 0x4:
            *id = OF_ACTION_BSN_CHECKSUM;
            break;
        default:
            *id = OF_ACTION_BSN;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_BSN_MIRROR;
            break;
        case 0x2:
            *id = OF_ACTION_BSN_SET_TUNNEL_DST;
            break;
        case 0x4:
            *id = OF_ACTION_BSN_CHECKSUM;
            break;
        case 0x5:
            *id = OF_ACTION_BSN_GENTABLE;
            break;
        default:
            *id = OF_ACTION_BSN;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_BSN_MIRROR;
            break;
        case 0x2:
            *id = OF_ACTION_BSN_SET_TUNNEL_DST;
            break;
        case 0x4:
            *id = OF_ACTION_BSN_CHECKSUM;
            break;
        case 0x5:
            *id = OF_ACTION_BSN_GENTABLE;
            break;
        default:
            *id = OF_ACTION_BSN;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_action_bsn of_action_bsn
 */

/**
 * Create a new of_action_bsn object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_bsn
 */

of_object_t *
of_action_bsn_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_BSN];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_bsn_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_bsn.
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
of_action_bsn_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_BSN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_BSN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_BSN;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_bsn.
 * @param obj Pointer to an object of type of_action_bsn.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_experimenter_get(
    of_action_bsn_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_bsn.
 * @param obj Pointer to an object of type of_action_bsn.
 * @param experimenter The value to write into the object
 */
void
of_action_bsn_experimenter_set(
    of_action_bsn_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_bsn.
 * @param obj Pointer to an object of type of_action_bsn.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_subtype_get(
    of_action_bsn_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_bsn.
 * @param obj Pointer to an object of type of_action_bsn.
 * @param subtype The value to write into the object
 */
void
of_action_bsn_subtype_set(
    of_action_bsn_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
of_action_bsn_checksum_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x4); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_bsn_checksum of_action_bsn_checksum
 */

/**
 * Create a new of_action_bsn_checksum object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_bsn_checksum
 */

of_object_t *
of_action_bsn_checksum_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_BSN_CHECKSUM];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_bsn_checksum_init(obj, version, bytes, 0);
    of_action_bsn_checksum_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_bsn_checksum.
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
of_action_bsn_checksum_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_BSN_CHECKSUM] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_BSN_CHECKSUM];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_BSN_CHECKSUM;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_bsn_checksum.
 * @param obj Pointer to an object of type of_action_bsn_checksum.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_checksum_experimenter_get(
    of_action_bsn_checksum_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_CHECKSUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_bsn_checksum.
 * @param obj Pointer to an object of type of_action_bsn_checksum.
 * @param experimenter The value to write into the object
 */
void
of_action_bsn_checksum_experimenter_set(
    of_action_bsn_checksum_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_CHECKSUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_bsn_checksum.
 * @param obj Pointer to an object of type of_action_bsn_checksum.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_checksum_subtype_get(
    of_action_bsn_checksum_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_CHECKSUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_bsn_checksum.
 * @param obj Pointer to an object of type of_action_bsn_checksum.
 * @param subtype The value to write into the object
 */
void
of_action_bsn_checksum_subtype_set(
    of_action_bsn_checksum_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_CHECKSUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get checksum from an object of type of_action_bsn_checksum.
 * @param obj Pointer to an object of type of_action_bsn_checksum.
 * @param checksum Pointer to the child object of type
 * of_checksum_128_t to be filled out.
 *
 */
void
of_action_bsn_checksum_checksum_get(
    of_action_bsn_checksum_t *obj,
    of_checksum_128_t *checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_CHECKSUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_checksum_128_get(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set checksum in an object of type of_action_bsn_checksum.
 * @param obj Pointer to an object of type of_action_bsn_checksum.
 * @param checksum The value to write into the object
 */
void
of_action_bsn_checksum_checksum_set(
    of_action_bsn_checksum_t *obj,
    of_checksum_128_t checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_CHECKSUM);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_checksum_128_set(wbuf, abs_offset, checksum);

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
of_action_bsn_mirror_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_bsn_mirror of_action_bsn_mirror
 */

/**
 * Create a new of_action_bsn_mirror object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_bsn_mirror
 */

of_object_t *
of_action_bsn_mirror_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_BSN_MIRROR];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_bsn_mirror_init(obj, version, bytes, 0);
    of_action_bsn_mirror_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_bsn_mirror.
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
of_action_bsn_mirror_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_BSN_MIRROR] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_BSN_MIRROR];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_BSN_MIRROR;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_mirror_experimenter_get(
    of_action_bsn_mirror_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param experimenter The value to write into the object
 */
void
of_action_bsn_mirror_experimenter_set(
    of_action_bsn_mirror_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_mirror_subtype_get(
    of_action_bsn_mirror_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param subtype The value to write into the object
 */
void
of_action_bsn_mirror_subtype_set(
    of_action_bsn_mirror_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get dest_port from an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param dest_port Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_mirror_dest_port_get(
    of_action_bsn_mirror_t *obj,
    uint32_t *dest_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, dest_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set dest_port in an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param dest_port The value to write into the object
 */
void
of_action_bsn_mirror_dest_port_set(
    of_action_bsn_mirror_t *obj,
    uint32_t dest_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, dest_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vlan_tag from an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param vlan_tag Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_mirror_vlan_tag_get(
    of_action_bsn_mirror_t *obj,
    uint32_t *vlan_tag)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, vlan_tag);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_tag in an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param vlan_tag The value to write into the object
 */
void
of_action_bsn_mirror_vlan_tag_set(
    of_action_bsn_mirror_t *obj,
    uint32_t vlan_tag)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, vlan_tag);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get copy_stage from an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param copy_stage Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_action_bsn_mirror_copy_stage_get(
    of_action_bsn_mirror_t *obj,
    uint8_t *copy_stage)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u8_get(wbuf, abs_offset, copy_stage);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set copy_stage in an object of type of_action_bsn_mirror.
 * @param obj Pointer to an object of type of_action_bsn_mirror.
 * @param copy_stage The value to write into the object
 */
void
of_action_bsn_mirror_copy_stage_set(
    of_action_bsn_mirror_t *obj,
    uint8_t copy_stage)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_MIRROR);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u8_set(wbuf, abs_offset, copy_stage);

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
of_action_bsn_set_tunnel_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 8) = U32_HTON(0x2); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_bsn_set_tunnel_dst of_action_bsn_set_tunnel_dst
 */

/**
 * Create a new of_action_bsn_set_tunnel_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_bsn_set_tunnel_dst
 */

of_object_t *
of_action_bsn_set_tunnel_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_BSN_SET_TUNNEL_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_bsn_set_tunnel_dst_init(obj, version, bytes, 0);
    of_action_bsn_set_tunnel_dst_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_bsn_set_tunnel_dst.
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
of_action_bsn_set_tunnel_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_BSN_SET_TUNNEL_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_BSN_SET_TUNNEL_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_BSN_SET_TUNNEL_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_bsn_set_tunnel_dst.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_set_tunnel_dst_experimenter_get(
    of_action_bsn_set_tunnel_dst_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_bsn_set_tunnel_dst.
 * @param experimenter The value to write into the object
 */
void
of_action_bsn_set_tunnel_dst_experimenter_set(
    of_action_bsn_set_tunnel_dst_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_bsn_set_tunnel_dst.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_set_tunnel_dst_subtype_get(
    of_action_bsn_set_tunnel_dst_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_bsn_set_tunnel_dst.
 * @param subtype The value to write into the object
 */
void
of_action_bsn_set_tunnel_dst_subtype_set(
    of_action_bsn_set_tunnel_dst_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get dst from an object of type of_action_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_bsn_set_tunnel_dst.
 * @param dst Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_bsn_set_tunnel_dst_dst_get(
    of_action_bsn_set_tunnel_dst_t *obj,
    uint32_t *dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set dst in an object of type of_action_bsn_set_tunnel_dst.
 * @param obj Pointer to an object of type of_action_bsn_set_tunnel_dst.
 * @param dst The value to write into the object
 */
void
of_action_bsn_set_tunnel_dst_dst_set(
    of_action_bsn_set_tunnel_dst_t *obj,
    uint32_t dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_BSN_SET_TUNNEL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, dst);

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
of_action_enqueue_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0xb); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_enqueue of_action_enqueue
 */

/**
 * Create a new of_action_enqueue object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_enqueue
 */

of_object_t *
of_action_enqueue_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_ENQUEUE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_enqueue_init(obj, version, bytes, 0);
    of_action_enqueue_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_enqueue.
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
of_action_enqueue_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_ENQUEUE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_ENQUEUE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_ENQUEUE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get port from an object of type of_action_enqueue.
 * @param obj Pointer to an object of type of_action_enqueue.
 * @param port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_action_enqueue_port_get(
    of_action_enqueue_t *obj,
    of_port_no_t *port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ENQUEUE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port);
    OF_PORT_NO_VALUE_CHECK(*port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port in an object of type of_action_enqueue.
 * @param obj Pointer to an object of type of_action_enqueue.
 * @param port The value to write into the object
 */
void
of_action_enqueue_port_set(
    of_action_enqueue_t *obj,
    of_port_no_t port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ENQUEUE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get queue_id from an object of type of_action_enqueue.
 * @param obj Pointer to an object of type of_action_enqueue.
 * @param queue_id Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_enqueue_queue_id_get(
    of_action_enqueue_t *obj,
    uint32_t *queue_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ENQUEUE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, queue_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set queue_id in an object of type of_action_enqueue.
 * @param obj Pointer to an object of type of_action_enqueue.
 * @param queue_id The value to write into the object
 */
void
of_action_enqueue_queue_id_set(
    of_action_enqueue_t *obj,
    uint32_t queue_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_ENQUEUE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, queue_id);

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
of_action_nicira_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_NICIRA_RESUBMIT;
            break;
        case 0x6:
            *id = OF_ACTION_NICIRA_MOVE;
            break;
        case 0xe:
            *id = OF_ACTION_NICIRA_RESUBMIT_TABLE;
            break;
        case 0x12:
            *id = OF_ACTION_NICIRA_DEC_TTL;
            break;
        case 0x26:
            *id = OF_ACTION_NICIRA_PUSH_NSH;
            break;
        case 0x27:
            *id = OF_ACTION_NICIRA_POP_NSH;
            break;
        default:
            *id = OF_ACTION_NICIRA;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_NICIRA_RESUBMIT;
            break;
        case 0x6:
            *id = OF_ACTION_NICIRA_MOVE;
            break;
        case 0xe:
            *id = OF_ACTION_NICIRA_RESUBMIT_TABLE;
            break;
        case 0x12:
            *id = OF_ACTION_NICIRA_DEC_TTL;
            break;
        case 0x26:
            *id = OF_ACTION_NICIRA_PUSH_NSH;
            break;
        case 0x27:
            *id = OF_ACTION_NICIRA_POP_NSH;
            break;
        default:
            *id = OF_ACTION_NICIRA;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_NICIRA_RESUBMIT;
            break;
        case 0x6:
            *id = OF_ACTION_NICIRA_MOVE;
            break;
        case 0xe:
            *id = OF_ACTION_NICIRA_RESUBMIT_TABLE;
            break;
        case 0x12:
            *id = OF_ACTION_NICIRA_DEC_TTL;
            break;
        case 0x26:
            *id = OF_ACTION_NICIRA_PUSH_NSH;
            break;
        case 0x27:
            *id = OF_ACTION_NICIRA_POP_NSH;
            break;
        default:
            *id = OF_ACTION_NICIRA;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_NICIRA_RESUBMIT;
            break;
        case 0x6:
            *id = OF_ACTION_NICIRA_MOVE;
            break;
        case 0xe:
            *id = OF_ACTION_NICIRA_RESUBMIT_TABLE;
            break;
        case 0x12:
            *id = OF_ACTION_NICIRA_DEC_TTL;
            break;
        case 0x26:
            *id = OF_ACTION_NICIRA_PUSH_NSH;
            break;
        case 0x27:
            *id = OF_ACTION_NICIRA_POP_NSH;
            break;
        default:
            *id = OF_ACTION_NICIRA;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* subtype */
        switch (value) {
        case 0x1:
            *id = OF_ACTION_NICIRA_RESUBMIT;
            break;
        case 0x6:
            *id = OF_ACTION_NICIRA_MOVE;
            break;
        case 0xe:
            *id = OF_ACTION_NICIRA_RESUBMIT_TABLE;
            break;
        case 0x12:
            *id = OF_ACTION_NICIRA_DEC_TTL;
            break;
        case 0x26:
            *id = OF_ACTION_NICIRA_PUSH_NSH;
            break;
        case 0x27:
            *id = OF_ACTION_NICIRA_POP_NSH;
            break;
        default:
            *id = OF_ACTION_NICIRA;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_action_nicira of_action_nicira
 */

/**
 * Create a new of_action_nicira object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira
 */

of_object_t *
of_action_nicira_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_nicira_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira.
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
of_action_nicira_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira.
 * @param obj Pointer to an object of type of_action_nicira.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_experimenter_get(
    of_action_nicira_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira.
 * @param obj Pointer to an object of type of_action_nicira.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_experimenter_set(
    of_action_nicira_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira.
 * @param obj Pointer to an object of type of_action_nicira.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_subtype_get(
    of_action_nicira_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira.
 * @param obj Pointer to an object of type of_action_nicira.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_subtype_set(
    of_action_nicira_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

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
of_action_nicira_dec_ttl_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = U16_HTON(0x12); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_nicira_dec_ttl of_action_nicira_dec_ttl
 */

/**
 * Create a new of_action_nicira_dec_ttl object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira_dec_ttl
 */

of_object_t *
of_action_nicira_dec_ttl_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_DEC_TTL];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_nicira_dec_ttl_init(obj, version, bytes, 0);
    of_action_nicira_dec_ttl_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira_dec_ttl.
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
of_action_nicira_dec_ttl_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA_DEC_TTL] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_DEC_TTL];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA_DEC_TTL;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_nicira_dec_ttl.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_dec_ttl_experimenter_get(
    of_action_nicira_dec_ttl_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_nicira_dec_ttl.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_dec_ttl_experimenter_set(
    of_action_nicira_dec_ttl_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_nicira_dec_ttl.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_dec_ttl_subtype_get(
    of_action_nicira_dec_ttl_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira_dec_ttl.
 * @param obj Pointer to an object of type of_action_nicira_dec_ttl.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_dec_ttl_subtype_set(
    of_action_nicira_dec_ttl_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_DEC_TTL);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

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
of_action_nicira_move_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = U16_HTON(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_nicira_move of_action_nicira_move
 */

/**
 * Create a new of_action_nicira_move object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira_move
 */

of_object_t *
of_action_nicira_move_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_MOVE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_nicira_move_init(obj, version, bytes, 0);
    of_action_nicira_move_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira_move.
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
of_action_nicira_move_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA_MOVE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_MOVE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA_MOVE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_move_experimenter_get(
    of_action_nicira_move_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_move_experimenter_set(
    of_action_nicira_move_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_move_subtype_get(
    of_action_nicira_move_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_move_subtype_set(
    of_action_nicira_move_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get n_bits from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param n_bits Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_move_n_bits_get(
    of_action_nicira_move_t *obj,
    uint16_t *n_bits)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, n_bits);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set n_bits in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param n_bits The value to write into the object
 */
void
of_action_nicira_move_n_bits_set(
    of_action_nicira_move_t *obj,
    uint16_t n_bits)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, n_bits);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get src_ofs from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param src_ofs Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_move_src_ofs_get(
    of_action_nicira_move_t *obj,
    uint16_t *src_ofs)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, src_ofs);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set src_ofs in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param src_ofs The value to write into the object
 */
void
of_action_nicira_move_src_ofs_set(
    of_action_nicira_move_t *obj,
    uint16_t src_ofs)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, src_ofs);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get dst_ofs from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param dst_ofs Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_move_dst_ofs_get(
    of_action_nicira_move_t *obj,
    uint16_t *dst_ofs)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, dst_ofs);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set dst_ofs in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param dst_ofs The value to write into the object
 */
void
of_action_nicira_move_dst_ofs_set(
    of_action_nicira_move_t *obj,
    uint16_t dst_ofs)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, dst_ofs);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get src from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param src Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_move_src_get(
    of_action_nicira_move_t *obj,
    uint32_t *src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set src in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param src The value to write into the object
 */
void
of_action_nicira_move_src_set(
    of_action_nicira_move_t *obj,
    uint32_t src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get dst from an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param dst Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_move_dst_get(
    of_action_nicira_move_t *obj,
    uint32_t *dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set dst in an object of type of_action_nicira_move.
 * @param obj Pointer to an object of type of_action_nicira_move.
 * @param dst The value to write into the object
 */
void
of_action_nicira_move_dst_set(
    of_action_nicira_move_t *obj,
    uint32_t dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_MOVE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, dst);

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
of_action_nicira_pop_nsh_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = U16_HTON(0x27); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_nicira_pop_nsh of_action_nicira_pop_nsh
 */

/**
 * Create a new of_action_nicira_pop_nsh object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira_pop_nsh
 */

of_object_t *
of_action_nicira_pop_nsh_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_POP_NSH];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_nicira_pop_nsh_init(obj, version, bytes, 0);
    of_action_nicira_pop_nsh_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira_pop_nsh.
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
of_action_nicira_pop_nsh_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA_POP_NSH] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_POP_NSH];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA_POP_NSH;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira_pop_nsh.
 * @param obj Pointer to an object of type of_action_nicira_pop_nsh.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_pop_nsh_experimenter_get(
    of_action_nicira_pop_nsh_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_POP_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira_pop_nsh.
 * @param obj Pointer to an object of type of_action_nicira_pop_nsh.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_pop_nsh_experimenter_set(
    of_action_nicira_pop_nsh_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_POP_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira_pop_nsh.
 * @param obj Pointer to an object of type of_action_nicira_pop_nsh.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_pop_nsh_subtype_get(
    of_action_nicira_pop_nsh_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_POP_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira_pop_nsh.
 * @param obj Pointer to an object of type of_action_nicira_pop_nsh.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_pop_nsh_subtype_set(
    of_action_nicira_pop_nsh_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_POP_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

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
of_action_nicira_push_nsh_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = U16_HTON(0x26); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_nicira_push_nsh of_action_nicira_push_nsh
 */

/**
 * Create a new of_action_nicira_push_nsh object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira_push_nsh
 */

of_object_t *
of_action_nicira_push_nsh_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_PUSH_NSH];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_nicira_push_nsh_init(obj, version, bytes, 0);
    of_action_nicira_push_nsh_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira_push_nsh.
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
of_action_nicira_push_nsh_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA_PUSH_NSH] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_PUSH_NSH];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA_PUSH_NSH;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira_push_nsh.
 * @param obj Pointer to an object of type of_action_nicira_push_nsh.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_push_nsh_experimenter_get(
    of_action_nicira_push_nsh_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_PUSH_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira_push_nsh.
 * @param obj Pointer to an object of type of_action_nicira_push_nsh.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_push_nsh_experimenter_set(
    of_action_nicira_push_nsh_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_PUSH_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira_push_nsh.
 * @param obj Pointer to an object of type of_action_nicira_push_nsh.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_push_nsh_subtype_get(
    of_action_nicira_push_nsh_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_PUSH_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira_push_nsh.
 * @param obj Pointer to an object of type of_action_nicira_push_nsh.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_push_nsh_subtype_set(
    of_action_nicira_push_nsh_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_PUSH_NSH);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

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
of_action_nicira_resubmit_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = U16_HTON(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_nicira_resubmit of_action_nicira_resubmit
 */

/**
 * Create a new of_action_nicira_resubmit object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira_resubmit
 */

of_object_t *
of_action_nicira_resubmit_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_RESUBMIT];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_nicira_resubmit_init(obj, version, bytes, 0);
    of_action_nicira_resubmit_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira_resubmit.
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
of_action_nicira_resubmit_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA_RESUBMIT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_RESUBMIT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA_RESUBMIT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_experimenter_get(
    of_action_nicira_resubmit_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_resubmit_experimenter_set(
    of_action_nicira_resubmit_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_subtype_get(
    of_action_nicira_resubmit_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_resubmit_subtype_set(
    of_action_nicira_resubmit_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get in_port from an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param in_port Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_in_port_get(
    of_action_nicira_resubmit_t *obj,
    uint16_t *in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set in_port in an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param in_port The value to write into the object
 */
void
of_action_nicira_resubmit_in_port_set(
    of_action_nicira_resubmit_t *obj,
    uint16_t in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get table from an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param table Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_table_get(
    of_action_nicira_resubmit_t *obj,
    uint8_t *table)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u8_get(wbuf, abs_offset, table);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table in an object of type of_action_nicira_resubmit.
 * @param obj Pointer to an object of type of_action_nicira_resubmit.
 * @param table The value to write into the object
 */
void
of_action_nicira_resubmit_table_set(
    of_action_nicira_resubmit_t *obj,
    uint8_t table)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u8_set(wbuf, abs_offset, table);

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
of_action_nicira_resubmit_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0xffff); /* type */
        *(uint32_t *)(buf + 4) = U32_HTON(0x2320); /* experimenter */
        *(uint16_t *)(buf + 8) = U16_HTON(0xe); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_nicira_resubmit_table of_action_nicira_resubmit_table
 */

/**
 * Create a new of_action_nicira_resubmit_table object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_nicira_resubmit_table
 */

of_object_t *
of_action_nicira_resubmit_table_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_RESUBMIT_TABLE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_nicira_resubmit_table_init(obj, version, bytes, 0);
    of_action_nicira_resubmit_table_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_nicira_resubmit_table.
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
of_action_nicira_resubmit_table_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_NICIRA_RESUBMIT_TABLE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_NICIRA_RESUBMIT_TABLE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_NICIRA_RESUBMIT_TABLE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_table_experimenter_get(
    of_action_nicira_resubmit_table_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param experimenter The value to write into the object
 */
void
of_action_nicira_resubmit_table_experimenter_set(
    of_action_nicira_resubmit_table_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_table_subtype_get(
    of_action_nicira_resubmit_table_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param subtype The value to write into the object
 */
void
of_action_nicira_resubmit_table_subtype_set(
    of_action_nicira_resubmit_table_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get in_port from an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param in_port Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_table_in_port_get(
    of_action_nicira_resubmit_table_t *obj,
    uint16_t *in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set in_port in an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param in_port The value to write into the object
 */
void
of_action_nicira_resubmit_table_in_port_set(
    of_action_nicira_resubmit_table_t *obj,
    uint16_t in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get table from an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param table Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_action_nicira_resubmit_table_table_get(
    of_action_nicira_resubmit_table_t *obj,
    uint8_t *table)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u8_get(wbuf, abs_offset, table);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table in an object of type of_action_nicira_resubmit_table.
 * @param obj Pointer to an object of type of_action_nicira_resubmit_table.
 * @param table The value to write into the object
 */
void
of_action_nicira_resubmit_table_table_set(
    of_action_nicira_resubmit_table_t *obj,
    uint8_t table)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_NICIRA_RESUBMIT_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u8_set(wbuf, abs_offset, table);

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
of_action_output_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_output of_action_output
 */

/**
 * Create a new of_action_output object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_output
 */

of_object_t *
of_action_output_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_OUTPUT];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_output_init(obj, version, bytes, 0);
    of_action_output_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_output.
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
of_action_output_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_OUTPUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_OUTPUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_OUTPUT;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get port from an object of type of_action_output.
 * @param obj Pointer to an object of type of_action_output.
 * @param port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_action_output_port_get(
    of_action_output_t *obj,
    of_port_no_t *port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_OUTPUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        break;
    case OF_VERSION_1_1:
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port);
    OF_PORT_NO_VALUE_CHECK(*port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port in an object of type of_action_output.
 * @param obj Pointer to an object of type of_action_output.
 * @param port The value to write into the object
 */
void
of_action_output_port_set(
    of_action_output_t *obj,
    of_port_no_t port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_OUTPUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 4;
        break;
    case OF_VERSION_1_1:
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_len from an object of type of_action_output.
 * @param obj Pointer to an object of type of_action_output.
 * @param max_len Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_output_max_len_get(
    of_action_output_t *obj,
    uint16_t *max_len)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_OUTPUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 6;
        break;
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, max_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_len in an object of type of_action_output.
 * @param obj Pointer to an object of type of_action_output.
 * @param max_len The value to write into the object
 */
void
of_action_output_max_len_set(
    of_action_output_t *obj,
    uint16_t max_len)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_OUTPUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 6;
        break;
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, max_len);

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
of_action_set_dl_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0x5); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_dl_dst of_action_set_dl_dst
 */

/**
 * Create a new of_action_set_dl_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_dl_dst
 */

of_object_t *
of_action_set_dl_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_DL_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_dl_dst_init(obj, version, bytes, 0);
    of_action_set_dl_dst_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_dl_dst.
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
of_action_set_dl_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_DL_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_DL_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_DL_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get dl_addr from an object of type of_action_set_dl_dst.
 * @param obj Pointer to an object of type of_action_set_dl_dst.
 * @param dl_addr Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_action_set_dl_dst_dl_addr_get(
    of_action_set_dl_dst_t *obj,
    of_mac_addr_t *dl_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_DL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, dl_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set dl_addr in an object of type of_action_set_dl_dst.
 * @param obj Pointer to an object of type of_action_set_dl_dst.
 * @param dl_addr The value to write into the object
 */
void
of_action_set_dl_dst_dl_addr_set(
    of_action_set_dl_dst_t *obj,
    of_mac_addr_t dl_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_DL_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, dl_addr);

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
of_action_set_dl_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0x4); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_dl_src of_action_set_dl_src
 */

/**
 * Create a new of_action_set_dl_src object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_dl_src
 */

of_object_t *
of_action_set_dl_src_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_DL_SRC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_dl_src_init(obj, version, bytes, 0);
    of_action_set_dl_src_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_dl_src.
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
of_action_set_dl_src_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_DL_SRC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_DL_SRC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_DL_SRC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get dl_addr from an object of type of_action_set_dl_src.
 * @param obj Pointer to an object of type of_action_set_dl_src.
 * @param dl_addr Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_action_set_dl_src_dl_addr_get(
    of_action_set_dl_src_t *obj,
    of_mac_addr_t *dl_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_DL_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, dl_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set dl_addr in an object of type of_action_set_dl_src.
 * @param obj Pointer to an object of type of_action_set_dl_src.
 * @param dl_addr The value to write into the object
 */
void
of_action_set_dl_src_dl_addr_set(
    of_action_set_dl_src_t *obj,
    of_mac_addr_t dl_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_DL_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, dl_addr);

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
of_action_set_nw_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0x7); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x6); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_nw_dst of_action_set_nw_dst
 */

/**
 * Create a new of_action_set_nw_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_nw_dst
 */

of_object_t *
of_action_set_nw_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_NW_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_nw_dst_init(obj, version, bytes, 0);
    of_action_set_nw_dst_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_nw_dst.
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
of_action_set_nw_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_NW_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_NW_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_NW_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get nw_addr from an object of type of_action_set_nw_dst.
 * @param obj Pointer to an object of type of_action_set_nw_dst.
 * @param nw_addr Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_set_nw_dst_nw_addr_get(
    of_action_set_nw_dst_t *obj,
    uint32_t *nw_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_NW_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, nw_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set nw_addr in an object of type of_action_set_nw_dst.
 * @param obj Pointer to an object of type of_action_set_nw_dst.
 * @param nw_addr The value to write into the object
 */
void
of_action_set_nw_dst_nw_addr_set(
    of_action_set_nw_dst_t *obj,
    uint32_t nw_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_NW_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, nw_addr);

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
of_action_set_nw_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0x6); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_nw_src of_action_set_nw_src
 */

/**
 * Create a new of_action_set_nw_src object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_nw_src
 */

of_object_t *
of_action_set_nw_src_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_NW_SRC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_nw_src_init(obj, version, bytes, 0);
    of_action_set_nw_src_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_nw_src.
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
of_action_set_nw_src_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_NW_SRC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_NW_SRC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_NW_SRC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get nw_addr from an object of type of_action_set_nw_src.
 * @param obj Pointer to an object of type of_action_set_nw_src.
 * @param nw_addr Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_action_set_nw_src_nw_addr_get(
    of_action_set_nw_src_t *obj,
    uint32_t *nw_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_NW_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, nw_addr);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set nw_addr in an object of type of_action_set_nw_src.
 * @param obj Pointer to an object of type of_action_set_nw_src.
 * @param nw_addr The value to write into the object
 */
void
of_action_set_nw_src_nw_addr_set(
    of_action_set_nw_src_t *obj,
    uint32_t nw_addr)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_NW_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, nw_addr);

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
of_action_set_nw_tos_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0x8); /* type */
        break;
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_nw_tos of_action_set_nw_tos
 */

/**
 * Create a new of_action_set_nw_tos object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_nw_tos
 */

of_object_t *
of_action_set_nw_tos_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_NW_TOS];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_nw_tos_init(obj, version, bytes, 0);
    of_action_set_nw_tos_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_nw_tos.
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
of_action_set_nw_tos_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_NW_TOS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_NW_TOS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_NW_TOS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get nw_tos from an object of type of_action_set_nw_tos.
 * @param obj Pointer to an object of type of_action_set_nw_tos.
 * @param nw_tos Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_action_set_nw_tos_nw_tos_get(
    of_action_set_nw_tos_t *obj,
    uint8_t *nw_tos)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_NW_TOS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, nw_tos);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set nw_tos in an object of type of_action_set_nw_tos.
 * @param obj Pointer to an object of type of_action_set_nw_tos.
 * @param nw_tos The value to write into the object
 */
void
of_action_set_nw_tos_nw_tos_set(
    of_action_set_nw_tos_t *obj,
    uint8_t nw_tos)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_NW_TOS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, nw_tos);

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
of_action_set_tp_dst_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0xa); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_tp_dst of_action_set_tp_dst
 */

/**
 * Create a new of_action_set_tp_dst object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_tp_dst
 */

of_object_t *
of_action_set_tp_dst_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_TP_DST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_tp_dst_init(obj, version, bytes, 0);
    of_action_set_tp_dst_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_tp_dst.
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
of_action_set_tp_dst_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_TP_DST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_TP_DST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_TP_DST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get tp_port from an object of type of_action_set_tp_dst.
 * @param obj Pointer to an object of type of_action_set_tp_dst.
 * @param tp_port Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_set_tp_dst_tp_port_get(
    of_action_set_tp_dst_t *obj,
    uint16_t *tp_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_TP_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tp_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tp_port in an object of type of_action_set_tp_dst.
 * @param obj Pointer to an object of type of_action_set_tp_dst.
 * @param tp_port The value to write into the object
 */
void
of_action_set_tp_dst_tp_port_set(
    of_action_set_tp_dst_t *obj,
    uint16_t tp_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_TP_DST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tp_port);

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
of_action_set_tp_src_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x9); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_tp_src of_action_set_tp_src
 */

/**
 * Create a new of_action_set_tp_src object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_tp_src
 */

of_object_t *
of_action_set_tp_src_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_TP_SRC];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_tp_src_init(obj, version, bytes, 0);
    of_action_set_tp_src_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_tp_src.
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
of_action_set_tp_src_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_TP_SRC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_TP_SRC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_TP_SRC;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get tp_port from an object of type of_action_set_tp_src.
 * @param obj Pointer to an object of type of_action_set_tp_src.
 * @param tp_port Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_set_tp_src_tp_port_get(
    of_action_set_tp_src_t *obj,
    uint16_t *tp_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_TP_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tp_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tp_port in an object of type of_action_set_tp_src.
 * @param obj Pointer to an object of type of_action_set_tp_src.
 * @param tp_port The value to write into the object
 */
void
of_action_set_tp_src_tp_port_set(
    of_action_set_tp_src_t *obj,
    uint16_t tp_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_TP_SRC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tp_port);

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
of_action_set_vlan_pcp_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_vlan_pcp of_action_set_vlan_pcp
 */

/**
 * Create a new of_action_set_vlan_pcp object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_vlan_pcp
 */

of_object_t *
of_action_set_vlan_pcp_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_VLAN_PCP];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_vlan_pcp_init(obj, version, bytes, 0);
    of_action_set_vlan_pcp_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_vlan_pcp.
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
of_action_set_vlan_pcp_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_VLAN_PCP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_VLAN_PCP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_VLAN_PCP;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get vlan_pcp from an object of type of_action_set_vlan_pcp.
 * @param obj Pointer to an object of type of_action_set_vlan_pcp.
 * @param vlan_pcp Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_action_set_vlan_pcp_vlan_pcp_get(
    of_action_set_vlan_pcp_t *obj,
    uint8_t *vlan_pcp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_PCP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, vlan_pcp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_pcp in an object of type of_action_set_vlan_pcp.
 * @param obj Pointer to an object of type of_action_set_vlan_pcp.
 * @param vlan_pcp The value to write into the object
 */
void
of_action_set_vlan_pcp_vlan_pcp_set(
    of_action_set_vlan_pcp_t *obj,
    uint8_t vlan_pcp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_PCP);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, vlan_pcp);

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
of_action_set_vlan_vid_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_vlan_vid of_action_set_vlan_vid
 */

/**
 * Create a new of_action_set_vlan_vid object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_vlan_vid
 */

of_object_t *
of_action_set_vlan_vid_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_VLAN_VID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_set_vlan_vid_init(obj, version, bytes, 0);
    of_action_set_vlan_vid_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_vlan_vid.
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
of_action_set_vlan_vid_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_VLAN_VID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_VLAN_VID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_VLAN_VID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get vlan_vid from an object of type of_action_set_vlan_vid.
 * @param obj Pointer to an object of type of_action_set_vlan_vid.
 * @param vlan_vid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_action_set_vlan_vid_vlan_vid_get(
    of_action_set_vlan_vid_t *obj,
    uint16_t *vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_VID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, vlan_vid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set vlan_vid in an object of type of_action_set_vlan_vid.
 * @param obj Pointer to an object of type of_action_set_vlan_vid.
 * @param vlan_vid The value to write into the object
 */
void
of_action_set_vlan_vid_vlan_vid_set(
    of_action_set_vlan_vid_t *obj,
    uint16_t vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_VLAN_VID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, vlan_vid);

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
of_action_strip_vlan_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint16_t *)(buf + 0) = U16_HTON(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_strip_vlan of_action_strip_vlan
 */

/**
 * Create a new of_action_strip_vlan object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_strip_vlan
 */

of_object_t *
of_action_strip_vlan_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_STRIP_VLAN];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_action_strip_vlan_init(obj, version, bytes, 0);
    of_action_strip_vlan_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_strip_vlan.
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
of_action_strip_vlan_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_STRIP_VLAN] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_STRIP_VLAN];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_STRIP_VLAN;

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
of_header_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint8_t value = *(uint8_t *)(buf + 1); /* type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO;
            break;
        case 0x1:
            of_error_msg_wire_object_id_get(obj, id);
            break;
        case 0x2:
            *id = OF_ECHO_REQUEST;
            break;
        case 0x3:
            *id = OF_ECHO_REPLY;
            break;
        case 0x4:
            of_experimenter_wire_object_id_get(obj, id);
            break;
        case 0x5:
            *id = OF_FEATURES_REQUEST;
            break;
        case 0x6:
            *id = OF_FEATURES_REPLY;
            break;
        case 0x7:
            *id = OF_GET_CONFIG_REQUEST;
            break;
        case 0x8:
            *id = OF_GET_CONFIG_REPLY;
            break;
        case 0x9:
            *id = OF_SET_CONFIG;
            break;
        case 0xa:
            *id = OF_PACKET_IN;
            break;
        case 0xb:
            *id = OF_FLOW_REMOVED;
            break;
        case 0xc:
            *id = OF_PORT_STATUS;
            break;
        case 0xd:
            *id = OF_PACKET_OUT;
            break;
        case 0xe:
            of_flow_mod_wire_object_id_get(obj, id);
            break;
        case 0xf:
            *id = OF_PORT_MOD;
            break;
        case 0x10:
            of_stats_request_wire_object_id_get(obj, id);
            break;
        case 0x11:
            of_stats_reply_wire_object_id_get(obj, id);
            break;
        case 0x12:
            *id = OF_BARRIER_REQUEST;
            break;
        case 0x13:
            *id = OF_BARRIER_REPLY;
            break;
        case 0x14:
            *id = OF_QUEUE_GET_CONFIG_REQUEST;
            break;
        case 0x15:
            *id = OF_QUEUE_GET_CONFIG_REPLY;
            break;
        case 0x16:
            *id = OF_TABLE_MOD;
            break;
        default:
            *id = OF_HEADER;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint8_t value = *(uint8_t *)(buf + 1); /* type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO;
            break;
        case 0x1:
            of_error_msg_wire_object_id_get(obj, id);
            break;
        case 0x2:
            *id = OF_ECHO_REQUEST;
            break;
        case 0x3:
            *id = OF_ECHO_REPLY;
            break;
        case 0x4:
            of_experimenter_wire_object_id_get(obj, id);
            break;
        case 0x5:
            *id = OF_FEATURES_REQUEST;
            break;
        case 0x6:
            *id = OF_FEATURES_REPLY;
            break;
        case 0x7:
            *id = OF_GET_CONFIG_REQUEST;
            break;
        case 0x8:
            *id = OF_GET_CONFIG_REPLY;
            break;
        case 0x9:
            *id = OF_SET_CONFIG;
            break;
        case 0xa:
            *id = OF_PACKET_IN;
            break;
        case 0xb:
            *id = OF_FLOW_REMOVED;
            break;
        case 0xc:
            *id = OF_PORT_STATUS;
            break;
        case 0xd:
            *id = OF_PACKET_OUT;
            break;
        case 0xe:
            of_flow_mod_wire_object_id_get(obj, id);
            break;
        case 0xf:
            of_group_mod_wire_object_id_get(obj, id);
            break;
        case 0x10:
            *id = OF_PORT_MOD;
            break;
        case 0x11:
            *id = OF_TABLE_MOD;
            break;
        case 0x12:
            of_stats_request_wire_object_id_get(obj, id);
            break;
        case 0x13:
            of_stats_reply_wire_object_id_get(obj, id);
            break;
        case 0x14:
            *id = OF_BARRIER_REQUEST;
            break;
        case 0x15:
            *id = OF_BARRIER_REPLY;
            break;
        case 0x16:
            *id = OF_QUEUE_GET_CONFIG_REQUEST;
            break;
        case 0x17:
            *id = OF_QUEUE_GET_CONFIG_REPLY;
            break;
        default:
            *id = OF_HEADER;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint8_t value = *(uint8_t *)(buf + 1); /* type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO;
            break;
        case 0x1:
            of_error_msg_wire_object_id_get(obj, id);
            break;
        case 0x2:
            *id = OF_ECHO_REQUEST;
            break;
        case 0x3:
            *id = OF_ECHO_REPLY;
            break;
        case 0x4:
            of_experimenter_wire_object_id_get(obj, id);
            break;
        case 0x5:
            *id = OF_FEATURES_REQUEST;
            break;
        case 0x6:
            *id = OF_FEATURES_REPLY;
            break;
        case 0x7:
            *id = OF_GET_CONFIG_REQUEST;
            break;
        case 0x8:
            *id = OF_GET_CONFIG_REPLY;
            break;
        case 0x9:
            *id = OF_SET_CONFIG;
            break;
        case 0xa:
            *id = OF_PACKET_IN;
            break;
        case 0xb:
            *id = OF_FLOW_REMOVED;
            break;
        case 0xc:
            *id = OF_PORT_STATUS;
            break;
        case 0xd:
            *id = OF_PACKET_OUT;
            break;
        case 0xe:
            of_flow_mod_wire_object_id_get(obj, id);
            break;
        case 0xf:
            of_group_mod_wire_object_id_get(obj, id);
            break;
        case 0x10:
            *id = OF_PORT_MOD;
            break;
        case 0x11:
            *id = OF_TABLE_MOD;
            break;
        case 0x12:
            of_stats_request_wire_object_id_get(obj, id);
            break;
        case 0x13:
            of_stats_reply_wire_object_id_get(obj, id);
            break;
        case 0x14:
            *id = OF_BARRIER_REQUEST;
            break;
        case 0x15:
            *id = OF_BARRIER_REPLY;
            break;
        case 0x16:
            *id = OF_QUEUE_GET_CONFIG_REQUEST;
            break;
        case 0x17:
            *id = OF_QUEUE_GET_CONFIG_REPLY;
            break;
        case 0x18:
            *id = OF_ROLE_REQUEST;
            break;
        case 0x19:
            *id = OF_ROLE_REPLY;
            break;
        default:
            *id = OF_HEADER;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint8_t value = *(uint8_t *)(buf + 1); /* type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO;
            break;
        case 0x1:
            of_error_msg_wire_object_id_get(obj, id);
            break;
        case 0x2:
            *id = OF_ECHO_REQUEST;
            break;
        case 0x3:
            *id = OF_ECHO_REPLY;
            break;
        case 0x4:
            of_experimenter_wire_object_id_get(obj, id);
            break;
        case 0x5:
            *id = OF_FEATURES_REQUEST;
            break;
        case 0x6:
            *id = OF_FEATURES_REPLY;
            break;
        case 0x7:
            *id = OF_GET_CONFIG_REQUEST;
            break;
        case 0x8:
            *id = OF_GET_CONFIG_REPLY;
            break;
        case 0x9:
            *id = OF_SET_CONFIG;
            break;
        case 0xa:
            *id = OF_PACKET_IN;
            break;
        case 0xb:
            *id = OF_FLOW_REMOVED;
            break;
        case 0xc:
            *id = OF_PORT_STATUS;
            break;
        case 0xd:
            *id = OF_PACKET_OUT;
            break;
        case 0xe:
            of_flow_mod_wire_object_id_get(obj, id);
            break;
        case 0xf:
            of_group_mod_wire_object_id_get(obj, id);
            break;
        case 0x10:
            *id = OF_PORT_MOD;
            break;
        case 0x11:
            *id = OF_TABLE_MOD;
            break;
        case 0x12:
            of_stats_request_wire_object_id_get(obj, id);
            break;
        case 0x13:
            of_stats_reply_wire_object_id_get(obj, id);
            break;
        case 0x14:
            *id = OF_BARRIER_REQUEST;
            break;
        case 0x15:
            *id = OF_BARRIER_REPLY;
            break;
        case 0x16:
            *id = OF_QUEUE_GET_CONFIG_REQUEST;
            break;
        case 0x17:
            *id = OF_QUEUE_GET_CONFIG_REPLY;
            break;
        case 0x18:
            *id = OF_ROLE_REQUEST;
            break;
        case 0x19:
            *id = OF_ROLE_REPLY;
            break;
        case 0x1a:
            *id = OF_ASYNC_GET_REQUEST;
            break;
        case 0x1b:
            *id = OF_ASYNC_GET_REPLY;
            break;
        case 0x1c:
            *id = OF_ASYNC_SET;
            break;
        case 0x1d:
            *id = OF_METER_MOD;
            break;
        default:
            *id = OF_HEADER;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint8_t value = *(uint8_t *)(buf + 1); /* type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO;
            break;
        case 0x1:
            of_error_msg_wire_object_id_get(obj, id);
            break;
        case 0x2:
            *id = OF_ECHO_REQUEST;
            break;
        case 0x3:
            *id = OF_ECHO_REPLY;
            break;
        case 0x4:
            of_experimenter_wire_object_id_get(obj, id);
            break;
        case 0x5:
            *id = OF_FEATURES_REQUEST;
            break;
        case 0x6:
            *id = OF_FEATURES_REPLY;
            break;
        case 0x7:
            *id = OF_GET_CONFIG_REQUEST;
            break;
        case 0x8:
            *id = OF_GET_CONFIG_REPLY;
            break;
        case 0x9:
            *id = OF_SET_CONFIG;
            break;
        case 0xa:
            *id = OF_PACKET_IN;
            break;
        case 0xb:
            *id = OF_FLOW_REMOVED;
            break;
        case 0xc:
            *id = OF_PORT_STATUS;
            break;
        case 0xd:
            *id = OF_PACKET_OUT;
            break;
        case 0xe:
            of_flow_mod_wire_object_id_get(obj, id);
            break;
        case 0xf:
            of_group_mod_wire_object_id_get(obj, id);
            break;
        case 0x10:
            *id = OF_PORT_MOD;
            break;
        case 0x11:
            *id = OF_TABLE_MOD;
            break;
        case 0x12:
            of_stats_request_wire_object_id_get(obj, id);
            break;
        case 0x13:
            of_stats_reply_wire_object_id_get(obj, id);
            break;
        case 0x14:
            *id = OF_BARRIER_REQUEST;
            break;
        case 0x15:
            *id = OF_BARRIER_REPLY;
            break;
        case 0x18:
            *id = OF_ROLE_REQUEST;
            break;
        case 0x19:
            *id = OF_ROLE_REPLY;
            break;
        case 0x1a:
            *id = OF_ASYNC_GET_REQUEST;
            break;
        case 0x1b:
            *id = OF_ASYNC_GET_REPLY;
            break;
        case 0x1c:
            *id = OF_ASYNC_SET;
            break;
        case 0x1d:
            *id = OF_METER_MOD;
            break;
        case 0x1e:
            *id = OF_ROLE_STATUS;
            break;
        case 0x1f:
            *id = OF_TABLE_STATUS;
            break;
        case 0x20:
            *id = OF_REQUESTFORWARD;
            break;
        case 0x21:
            *id = OF_BUNDLE_CTRL_MSG;
            break;
        case 0x22:
            *id = OF_BUNDLE_ADD_MSG;
            break;
        default:
            *id = OF_HEADER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_header of_header
 */

/**
 * Create a new of_header object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_header
 */

of_object_t *
of_header_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_HEADER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_header_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_header.
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
of_header_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_HEADER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_HEADER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_HEADER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_header.
 * @param obj Pointer to an object of type of_header.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_header_xid_get(
    of_header_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_HEADER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_header.
 * @param obj Pointer to an object of type of_header.
 * @param xid The value to write into the object
 */
void
of_header_xid_set(
    of_header_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_HEADER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

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
of_stats_reply_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REPLY;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REPLY;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REPLY;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REPLY;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REPLY;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REPLY;
            break;
        case 0xffff:
            of_experimenter_stats_reply_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REPLY;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REPLY;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REPLY;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REPLY;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REPLY;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REPLY;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REPLY;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REPLY;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REPLY;
            break;
        case 0xffff:
            of_experimenter_stats_reply_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REPLY;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REPLY;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REPLY;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REPLY;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REPLY;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REPLY;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REPLY;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REPLY;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REPLY;
            break;
        case 0x8:
            *id = OF_GROUP_FEATURES_STATS_REPLY;
            break;
        case 0xffff:
            of_experimenter_stats_reply_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REPLY;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REPLY;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REPLY;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REPLY;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REPLY;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REPLY;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REPLY;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REPLY;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REPLY;
            break;
        case 0x8:
            *id = OF_GROUP_FEATURES_STATS_REPLY;
            break;
        case 0x9:
            *id = OF_METER_STATS_REPLY;
            break;
        case 0xa:
            *id = OF_METER_CONFIG_STATS_REPLY;
            break;
        case 0xb:
            *id = OF_METER_FEATURES_STATS_REPLY;
            break;
        case 0xc:
            *id = OF_TABLE_FEATURES_STATS_REPLY;
            break;
        case 0xd:
            *id = OF_PORT_DESC_STATS_REPLY;
            break;
        case 0xffff:
            of_experimenter_stats_reply_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REPLY;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REPLY;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REPLY;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REPLY;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REPLY;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REPLY;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REPLY;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REPLY;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REPLY;
            break;
        case 0x8:
            *id = OF_GROUP_FEATURES_STATS_REPLY;
            break;
        case 0x9:
            *id = OF_METER_STATS_REPLY;
            break;
        case 0xa:
            *id = OF_METER_CONFIG_STATS_REPLY;
            break;
        case 0xb:
            *id = OF_METER_FEATURES_STATS_REPLY;
            break;
        case 0xc:
            *id = OF_TABLE_FEATURES_STATS_REPLY;
            break;
        case 0xd:
            *id = OF_PORT_DESC_STATS_REPLY;
            break;
        case 0xe:
            *id = OF_TABLE_DESC_STATS_REPLY;
            break;
        case 0xf:
            *id = OF_QUEUE_DESC_STATS_REPLY;
            break;
        case 0xffff:
            of_experimenter_stats_reply_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REPLY;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_stats_reply of_stats_reply
 */

/**
 * Create a new of_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_stats_reply
 */

of_object_t *
of_stats_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_STATS_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_stats_reply_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_stats_reply.
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
of_stats_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_STATS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_stats_reply.
 * @param obj Pointer to an object of type of_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_stats_reply_xid_get(
    of_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_stats_reply.
 * @param obj Pointer to an object of type of_stats_reply.
 * @param xid The value to write into the object
 */
void
of_stats_reply_xid_set(
    of_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_stats_reply.
 * @param obj Pointer to an object of type of_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_stats_reply_flags_get(
    of_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_stats_reply.
 * @param obj Pointer to an object of type of_stats_reply.
 * @param flags The value to write into the object
 */
void
of_stats_reply_flags_set(
    of_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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

void
of_aggregate_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x11; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x2); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x2); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_aggregate_stats_reply of_aggregate_stats_reply
 */

/**
 * Create a new of_aggregate_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_aggregate_stats_reply
 */

of_object_t *
of_aggregate_stats_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_AGGREGATE_STATS_REPLY];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_reply_init(obj, version, bytes, 0);
    of_aggregate_stats_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_aggregate_stats_reply.
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
of_aggregate_stats_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_AGGREGATE_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_AGGREGATE_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_AGGREGATE_STATS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_aggregate_stats_reply_xid_get(
    of_aggregate_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param xid The value to write into the object
 */
void
of_aggregate_stats_reply_xid_set(
    of_aggregate_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_aggregate_stats_reply_flags_get(
    of_aggregate_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param flags The value to write into the object
 */
void
of_aggregate_stats_reply_flags_set(
    of_aggregate_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get packet_count from an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param packet_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_aggregate_stats_reply_packet_count_get(
    of_aggregate_stats_reply_t *obj,
    uint64_t *packet_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, packet_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set packet_count in an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param packet_count The value to write into the object
 */
void
of_aggregate_stats_reply_packet_count_set(
    of_aggregate_stats_reply_t *obj,
    uint64_t packet_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, packet_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get byte_count from an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param byte_count Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_aggregate_stats_reply_byte_count_get(
    of_aggregate_stats_reply_t *obj,
    uint64_t *byte_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 20;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, byte_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set byte_count in an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param byte_count The value to write into the object
 */
void
of_aggregate_stats_reply_byte_count_set(
    of_aggregate_stats_reply_t *obj,
    uint64_t byte_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 20;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, byte_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flow_count from an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param flow_count Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_aggregate_stats_reply_flow_count_get(
    of_aggregate_stats_reply_t *obj,
    uint32_t *flow_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 28;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, flow_count);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flow_count in an object of type of_aggregate_stats_reply.
 * @param obj Pointer to an object of type of_aggregate_stats_reply.
 * @param flow_count The value to write into the object
 */
void
of_aggregate_stats_reply_flow_count_set(
    of_aggregate_stats_reply_t *obj,
    uint32_t flow_count)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 28;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, flow_count);

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
of_stats_request_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REQUEST;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REQUEST;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REQUEST;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REQUEST;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REQUEST;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REQUEST;
            break;
        case 0xffff:
            of_experimenter_stats_request_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REQUEST;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REQUEST;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REQUEST;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REQUEST;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REQUEST;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REQUEST;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REQUEST;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REQUEST;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REQUEST;
            break;
        case 0xffff:
            of_experimenter_stats_request_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REQUEST;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REQUEST;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REQUEST;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REQUEST;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REQUEST;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REQUEST;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REQUEST;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REQUEST;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REQUEST;
            break;
        case 0x8:
            *id = OF_GROUP_FEATURES_STATS_REQUEST;
            break;
        case 0xffff:
            of_experimenter_stats_request_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REQUEST;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REQUEST;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REQUEST;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REQUEST;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REQUEST;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REQUEST;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REQUEST;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REQUEST;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REQUEST;
            break;
        case 0x8:
            *id = OF_GROUP_FEATURES_STATS_REQUEST;
            break;
        case 0x9:
            *id = OF_METER_STATS_REQUEST;
            break;
        case 0xa:
            *id = OF_METER_CONFIG_STATS_REQUEST;
            break;
        case 0xb:
            *id = OF_METER_FEATURES_STATS_REQUEST;
            break;
        case 0xc:
            *id = OF_TABLE_FEATURES_STATS_REQUEST;
            break;
        case 0xd:
            *id = OF_PORT_DESC_STATS_REQUEST;
            break;
        case 0xffff:
            of_experimenter_stats_request_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REQUEST;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* stats_type */
        switch (value) {
        case 0x0:
            *id = OF_DESC_STATS_REQUEST;
            break;
        case 0x1:
            *id = OF_FLOW_STATS_REQUEST;
            break;
        case 0x2:
            *id = OF_AGGREGATE_STATS_REQUEST;
            break;
        case 0x3:
            *id = OF_TABLE_STATS_REQUEST;
            break;
        case 0x4:
            *id = OF_PORT_STATS_REQUEST;
            break;
        case 0x5:
            *id = OF_QUEUE_STATS_REQUEST;
            break;
        case 0x6:
            *id = OF_GROUP_STATS_REQUEST;
            break;
        case 0x7:
            *id = OF_GROUP_DESC_STATS_REQUEST;
            break;
        case 0x8:
            *id = OF_GROUP_FEATURES_STATS_REQUEST;
            break;
        case 0x9:
            *id = OF_METER_STATS_REQUEST;
            break;
        case 0xa:
            *id = OF_METER_CONFIG_STATS_REQUEST;
            break;
        case 0xb:
            *id = OF_METER_FEATURES_STATS_REQUEST;
            break;
        case 0xc:
            *id = OF_TABLE_FEATURES_STATS_REQUEST;
            break;
        case 0xd:
            *id = OF_PORT_DESC_STATS_REQUEST;
            break;
        case 0xe:
            *id = OF_TABLE_DESC_STATS_REQUEST;
            break;
        case 0xf:
            *id = OF_QUEUE_DESC_STATS_REQUEST;
            break;
        case 0xffff:
            of_experimenter_stats_request_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_STATS_REQUEST;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_stats_request of_stats_request
 */

/**
 * Create a new of_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_stats_request
 */

of_object_t *
of_stats_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_STATS_REQUEST];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_stats_request_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_stats_request.
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
of_stats_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_STATS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_stats_request.
 * @param obj Pointer to an object of type of_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_stats_request_xid_get(
    of_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_stats_request.
 * @param obj Pointer to an object of type of_stats_request.
 * @param xid The value to write into the object
 */
void
of_stats_request_xid_set(
    of_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_stats_request.
 * @param obj Pointer to an object of type of_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_stats_request_flags_get(
    of_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_stats_request.
 * @param obj Pointer to an object of type of_stats_request.
 * @param flags The value to write into the object
 */
void
of_stats_request_flags_set(
    of_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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

void
of_aggregate_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x10; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x2); /* stats_type */
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x2); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_aggregate_stats_request of_aggregate_stats_request
 */

/**
 * Create a new of_aggregate_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_aggregate_stats_request
 */

of_object_t *
of_aggregate_stats_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_AGGREGATE_STATS_REQUEST];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_aggregate_stats_request_init(obj, version, bytes, 0);
    of_aggregate_stats_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    /* Initialize match TLV for 1.2 */
    if ((version >= OF_VERSION_1_2)) {
        of_object_u16_set((of_object_t *)obj, 48 + 2, 4);
    }

    return obj;
}

/**
 * Initialize an object of type of_aggregate_stats_request.
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
of_aggregate_stats_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_AGGREGATE_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_AGGREGATE_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_AGGREGATE_STATS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_aggregate_stats_request_xid_get(
    of_aggregate_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param xid The value to write into the object
 */
void
of_aggregate_stats_request_xid_set(
    of_aggregate_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_aggregate_stats_request_flags_get(
    of_aggregate_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param flags The value to write into the object
 */
void
of_aggregate_stats_request_flags_set(
    of_aggregate_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get table_id from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_aggregate_stats_request_table_id_get(
    of_aggregate_stats_request_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 52;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param table_id The value to write into the object
 */
void
of_aggregate_stats_request_table_id_set(
    of_aggregate_stats_request_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 52;
        break;
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get out_port from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param out_port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_aggregate_stats_request_out_port_get(
    of_aggregate_stats_request_t *obj,
    of_port_no_t *out_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 54;
        break;
    case OF_VERSION_1_1:
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
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, out_port);
    OF_PORT_NO_VALUE_CHECK(*out_port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set out_port in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param out_port The value to write into the object
 */
void
of_aggregate_stats_request_out_port_set(
    of_aggregate_stats_request_t *obj,
    of_port_no_t out_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 54;
        break;
    case OF_VERSION_1_1:
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
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, out_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get out_group from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param out_group Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_aggregate_stats_request_out_group_get(
    of_aggregate_stats_request_t *obj,
    uint32_t *out_group)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, out_group);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set out_group in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param out_group The value to write into the object
 */
void
of_aggregate_stats_request_out_group_set(
    of_aggregate_stats_request_t *obj,
    uint32_t out_group)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, out_group);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cookie from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param cookie Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_aggregate_stats_request_cookie_get(
    of_aggregate_stats_request_t *obj,
    uint64_t *cookie)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, cookie);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cookie in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param cookie The value to write into the object
 */
void
of_aggregate_stats_request_cookie_set(
    of_aggregate_stats_request_t *obj,
    uint64_t cookie)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, cookie);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get cookie_mask from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param cookie_mask Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_aggregate_stats_request_cookie_mask_get(
    of_aggregate_stats_request_t *obj,
    uint64_t *cookie_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, cookie_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set cookie_mask in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param cookie_mask The value to write into the object
 */
void
of_aggregate_stats_request_cookie_mask_set(
    of_aggregate_stats_request_t *obj,
    uint64_t cookie_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, cookie_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get match from an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param match Pointer to the child object of type
 * of_match_t to be filled out.
 *
 */
int WARN_UNUSED_RESULT
of_aggregate_stats_request_match_get(
    of_aggregate_stats_request_t *obj,
    of_match_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    OF_TRY(of_match_deserialize(ver, match, obj, offset, cur_len));

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}

/**
 * Set match in an object of type of_aggregate_stats_request.
 * @param obj Pointer to an object of type of_aggregate_stats_request.
 * @param match Pointer to the child of type of_match_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_aggregate_stats_request_match_set(
    of_aggregate_stats_request_t *obj,
    of_match_t *match)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_AGGREGATE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
        offset = 12;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_1:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 48;
        cur_len = _WIRE_MATCH_PADDED_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    {
        /* Match object */
        of_octets_t match_octets;
        OF_TRY(of_match_serialize(ver, match, &match_octets));
        new_len = match_octets.bytes;
        of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
            match_octets.data, new_len);
        /* Free match serialized octets */
        FREE(match_octets.data);
    }

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
of_error_msg_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* err_type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO_FAILED_ERROR_MSG;
            break;
        case 0x1:
            *id = OF_BAD_REQUEST_ERROR_MSG;
            break;
        case 0x2:
            *id = OF_BAD_ACTION_ERROR_MSG;
            break;
        case 0x3:
            *id = OF_FLOW_MOD_FAILED_ERROR_MSG;
            break;
        case 0x4:
            *id = OF_PORT_MOD_FAILED_ERROR_MSG;
            break;
        case 0x5:
            *id = OF_QUEUE_OP_FAILED_ERROR_MSG;
            break;
        default:
            *id = OF_ERROR_MSG;
            break;
        }
        break;
    }
    case OF_VERSION_1_1: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* err_type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO_FAILED_ERROR_MSG;
            break;
        case 0x1:
            *id = OF_BAD_REQUEST_ERROR_MSG;
            break;
        case 0x2:
            *id = OF_BAD_ACTION_ERROR_MSG;
            break;
        case 0x3:
            *id = OF_BAD_INSTRUCTION_ERROR_MSG;
            break;
        case 0x4:
            *id = OF_BAD_MATCH_ERROR_MSG;
            break;
        case 0x5:
            *id = OF_FLOW_MOD_FAILED_ERROR_MSG;
            break;
        case 0x6:
            *id = OF_GROUP_MOD_FAILED_ERROR_MSG;
            break;
        case 0x7:
            *id = OF_PORT_MOD_FAILED_ERROR_MSG;
            break;
        case 0x8:
            *id = OF_TABLE_MOD_FAILED_ERROR_MSG;
            break;
        case 0x9:
            *id = OF_QUEUE_OP_FAILED_ERROR_MSG;
            break;
        case 0xa:
            *id = OF_SWITCH_CONFIG_FAILED_ERROR_MSG;
            break;
        default:
            *id = OF_ERROR_MSG;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* err_type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO_FAILED_ERROR_MSG;
            break;
        case 0x1:
            *id = OF_BAD_REQUEST_ERROR_MSG;
            break;
        case 0x2:
            *id = OF_BAD_ACTION_ERROR_MSG;
            break;
        case 0x3:
            *id = OF_BAD_INSTRUCTION_ERROR_MSG;
            break;
        case 0x4:
            *id = OF_BAD_MATCH_ERROR_MSG;
            break;
        case 0x5:
            *id = OF_FLOW_MOD_FAILED_ERROR_MSG;
            break;
        case 0x6:
            *id = OF_GROUP_MOD_FAILED_ERROR_MSG;
            break;
        case 0x7:
            *id = OF_PORT_MOD_FAILED_ERROR_MSG;
            break;
        case 0x8:
            *id = OF_TABLE_MOD_FAILED_ERROR_MSG;
            break;
        case 0x9:
            *id = OF_QUEUE_OP_FAILED_ERROR_MSG;
            break;
        case 0xa:
            *id = OF_SWITCH_CONFIG_FAILED_ERROR_MSG;
            break;
        case 0xb:
            *id = OF_ROLE_REQUEST_FAILED_ERROR_MSG;
            break;
        case 0xffff:
            of_experimenter_error_msg_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ERROR_MSG;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* err_type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO_FAILED_ERROR_MSG;
            break;
        case 0x1:
            *id = OF_BAD_REQUEST_ERROR_MSG;
            break;
        case 0x2:
            *id = OF_BAD_ACTION_ERROR_MSG;
            break;
        case 0x3:
            *id = OF_BAD_INSTRUCTION_ERROR_MSG;
            break;
        case 0x4:
            *id = OF_BAD_MATCH_ERROR_MSG;
            break;
        case 0x5:
            *id = OF_FLOW_MOD_FAILED_ERROR_MSG;
            break;
        case 0x6:
            *id = OF_GROUP_MOD_FAILED_ERROR_MSG;
            break;
        case 0x7:
            *id = OF_PORT_MOD_FAILED_ERROR_MSG;
            break;
        case 0x8:
            *id = OF_TABLE_MOD_FAILED_ERROR_MSG;
            break;
        case 0x9:
            *id = OF_QUEUE_OP_FAILED_ERROR_MSG;
            break;
        case 0xa:
            *id = OF_SWITCH_CONFIG_FAILED_ERROR_MSG;
            break;
        case 0xb:
            *id = OF_ROLE_REQUEST_FAILED_ERROR_MSG;
            break;
        case 0xc:
            *id = OF_METER_MOD_FAILED_ERROR_MSG;
            break;
        case 0xd:
            *id = OF_TABLE_FEATURES_FAILED_ERROR_MSG;
            break;
        case 0xffff:
            of_experimenter_error_msg_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ERROR_MSG;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint16_t value = U16_NTOH(*(uint16_t *)(buf + 8)); /* err_type */
        switch (value) {
        case 0x0:
            *id = OF_HELLO_FAILED_ERROR_MSG;
            break;
        case 0x1:
            *id = OF_BAD_REQUEST_ERROR_MSG;
            break;
        case 0x2:
            *id = OF_BAD_ACTION_ERROR_MSG;
            break;
        case 0x3:
            *id = OF_BAD_INSTRUCTION_ERROR_MSG;
            break;
        case 0x4:
            *id = OF_BAD_MATCH_ERROR_MSG;
            break;
        case 0x5:
            *id = OF_FLOW_MOD_FAILED_ERROR_MSG;
            break;
        case 0x6:
            *id = OF_GROUP_MOD_FAILED_ERROR_MSG;
            break;
        case 0x7:
            *id = OF_PORT_MOD_FAILED_ERROR_MSG;
            break;
        case 0x8:
            *id = OF_TABLE_MOD_FAILED_ERROR_MSG;
            break;
        case 0x9:
            *id = OF_QUEUE_OP_FAILED_ERROR_MSG;
            break;
        case 0xa:
            *id = OF_SWITCH_CONFIG_FAILED_ERROR_MSG;
            break;
        case 0xb:
            *id = OF_ROLE_REQUEST_FAILED_ERROR_MSG;
            break;
        case 0xc:
            *id = OF_METER_MOD_FAILED_ERROR_MSG;
            break;
        case 0xd:
            *id = OF_TABLE_FEATURES_FAILED_ERROR_MSG;
            break;
        case 0xe:
            *id = OF_BAD_PROPERTY_ERROR_MSG;
            break;
        case 0xf:
            *id = OF_ASYNC_CONFIG_FAILED_ERROR_MSG;
            break;
        case 0x10:
            *id = OF_FLOW_MONITOR_FAILED_ERROR_MSG;
            break;
        case 0x11:
            *id = OF_BUNDLE_FAILED_ERROR_MSG;
            break;
        case 0xffff:
            of_experimenter_error_msg_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_ERROR_MSG;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_error_msg of_error_msg
 */

/**
 * Create a new of_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_error_msg
 */

of_object_t *
of_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_error_msg_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_error_msg.
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
of_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_error_msg.
 * @param obj Pointer to an object of type of_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_error_msg_xid_get(
    of_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_error_msg.
 * @param obj Pointer to an object of type of_error_msg.
 * @param xid The value to write into the object
 */
void
of_error_msg_xid_set(
    of_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

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
of_bad_action_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x2); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_bad_action_error_msg of_bad_action_error_msg
 */

/**
 * Create a new of_bad_action_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_bad_action_error_msg
 */

of_object_t *
of_bad_action_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BAD_ACTION_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bad_action_error_msg_init(obj, version, bytes, 0);
    of_bad_action_error_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_bad_action_error_msg.
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
of_bad_action_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_BAD_ACTION_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BAD_ACTION_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BAD_ACTION_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_bad_action_error_msg.
 * @param obj Pointer to an object of type of_bad_action_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bad_action_error_msg_xid_get(
    of_bad_action_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bad_action_error_msg.
 * @param obj Pointer to an object of type of_bad_action_error_msg.
 * @param xid The value to write into the object
 */
void
of_bad_action_error_msg_xid_set(
    of_bad_action_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get code from an object of type of_bad_action_error_msg.
 * @param obj Pointer to an object of type of_bad_action_error_msg.
 * @param code Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bad_action_error_msg_code_get(
    of_bad_action_error_msg_t *obj,
    uint16_t *code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_get(wbuf, abs_offset, code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set code in an object of type of_bad_action_error_msg.
 * @param obj Pointer to an object of type of_bad_action_error_msg.
 * @param code The value to write into the object
 */
void
of_bad_action_error_msg_code_set(
    of_bad_action_error_msg_t *obj,
    uint16_t code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
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
    of_wire_buffer_u16_set(wbuf, abs_offset, code);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get data from an object of type of_bad_action_error_msg.
 * @param obj Pointer to an object of type of_bad_action_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bad_action_error_msg_data_get(
    of_bad_action_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_bad_action_error_msg.
 * @param obj Pointer to an object of type of_bad_action_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bad_action_error_msg_data_set(
    of_bad_action_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BAD_ACTION_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_0:
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 12;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = data->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, data, cur_len);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
