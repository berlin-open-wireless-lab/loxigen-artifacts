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
of_instruction_experimenter_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        default:
            *id = OF_INSTRUCTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_2: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        default:
            *id = OF_INSTRUCTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x5c16c7:
            of_instruction_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_INSTRUCTION_EXPERIMENTER;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 4)); /* experimenter */
        switch (value) {
        case 0x5c16c7:
            of_instruction_bsn_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_INSTRUCTION_EXPERIMENTER;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_instruction_experimenter of_instruction_experimenter
 */

/**
 * Create a new of_instruction_experimenter object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_instruction_experimenter
 */

of_object_t *
of_instruction_experimenter_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_EXPERIMENTER];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_experimenter_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_instruction_experimenter.
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
of_instruction_experimenter_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_EXPERIMENTER] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_EXPERIMENTER];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_EXPERIMENTER;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get experimenter from an object of type of_instruction_experimenter.
 * @param obj Pointer to an object of type of_instruction_experimenter.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_instruction_experimenter_experimenter_get(
    of_instruction_experimenter_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set experimenter in an object of type of_instruction_experimenter.
 * @param obj Pointer to an object of type of_instruction_experimenter.
 * @param experimenter The value to write into the object
 */
void
of_instruction_experimenter_experimenter_set(
    of_instruction_experimenter_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get data from an object of type of_instruction_experimenter.
 * @param obj Pointer to an object of type of_instruction_experimenter.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_instruction_experimenter_data_get(
    of_instruction_experimenter_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set data in an object of type of_instruction_experimenter.
 * @param obj Pointer to an object of type of_instruction_experimenter.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_instruction_experimenter_data_set(
    of_instruction_experimenter_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_EXPERIMENTER);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_instruction_goto_table_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_instruction_goto_table of_instruction_goto_table
 */

/**
 * Create a new of_instruction_goto_table object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_instruction_goto_table
 */

of_object_t *
of_instruction_goto_table_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_GOTO_TABLE];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_instruction_goto_table_init(obj, version, bytes, 0);
    of_instruction_goto_table_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_instruction_goto_table.
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
of_instruction_goto_table_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_GOTO_TABLE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_GOTO_TABLE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_GOTO_TABLE;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get table_id from an object of type of_instruction_goto_table.
 * @param obj Pointer to an object of type of_instruction_goto_table.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_instruction_goto_table_table_id_get(
    of_instruction_goto_table_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_GOTO_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u8_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_instruction_goto_table.
 * @param obj Pointer to an object of type of_instruction_goto_table.
 * @param table_id The value to write into the object
 */
void
of_instruction_goto_table_table_id_set(
    of_instruction_goto_table_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_GOTO_TABLE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u8_set(wbuf, abs_offset, table_id);

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
of_instruction_write_actions_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x3); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_instruction_write_actions of_instruction_write_actions
 */

/**
 * Create a new of_instruction_write_actions object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_instruction_write_actions
 */

of_object_t *
of_instruction_write_actions_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_WRITE_ACTIONS];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_instruction_write_actions_init(obj, version, bytes, 0);
    of_instruction_write_actions_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_instruction_write_actions.
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
of_instruction_write_actions_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_WRITE_ACTIONS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_WRITE_ACTIONS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_WRITE_ACTIONS;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Bind an object of type of_list_action_t to the parent of type of_instruction_write_actions for
 * member actions
 * @param obj Pointer to an object of type of_instruction_write_actions.
 * @param actions Pointer to the child object of type
 * of_list_action_t to be filled out.
 * \ingroup of_instruction_write_actions
 *
 * The parameter actions is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_instruction_write_actions_actions_bind(
    of_instruction_write_actions_t *obj,
    of_list_action_t *actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_ACTIONS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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

    /* Initialize child */
    of_list_action_init(actions, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, actions, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of actions into a new variable of type of_list_action_t from
 * a of_instruction_write_actions instance.
 *
 * @param obj Pointer to the source of type of_instruction_write_actions_t
 * @returns A pointer to a new instance of type of_list_action_t whose contents
 * match that of actions from source
 * @returns NULL if an error occurs
 */
of_list_action_t *
of_instruction_write_actions_actions_get(of_instruction_write_actions_t *obj) {
    of_list_action_t _actions;
    of_list_action_t *_actions_ptr;

    of_instruction_write_actions_actions_bind(obj, &_actions);
    _actions_ptr = (of_list_action_t *)of_object_dup(&_actions);
    return _actions_ptr;
}

/**
 * Set actions in an object of type of_instruction_write_actions.
 * @param obj Pointer to an object of type of_instruction_write_actions.
 * @param actions Pointer to the child of type of_list_action_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_instruction_write_actions_actions_set(
    of_instruction_write_actions_t *obj,
    of_list_action_t *actions)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_ACTIONS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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

    /* LOCI object type */
    new_len = actions->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == actions->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(actions, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(actions, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)actions, actions->length);

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
of_instruction_write_metadata_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x2); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_instruction_write_metadata of_instruction_write_metadata
 */

/**
 * Create a new of_instruction_write_metadata object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_instruction_write_metadata
 */

of_object_t *
of_instruction_write_metadata_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_INSTRUCTION_WRITE_METADATA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_instruction_write_metadata_init(obj, version, bytes, 0);
    of_instruction_write_metadata_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_instruction_write_metadata.
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
of_instruction_write_metadata_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_INSTRUCTION_WRITE_METADATA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_INSTRUCTION_WRITE_METADATA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_INSTRUCTION_WRITE_METADATA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get metadata from an object of type of_instruction_write_metadata.
 * @param obj Pointer to an object of type of_instruction_write_metadata.
 * @param metadata Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_instruction_write_metadata_metadata_get(
    of_instruction_write_metadata_t *obj,
    uint64_t *metadata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata in an object of type of_instruction_write_metadata.
 * @param obj Pointer to an object of type of_instruction_write_metadata.
 * @param metadata The value to write into the object
 */
void
of_instruction_write_metadata_metadata_set(
    of_instruction_write_metadata_t *obj,
    uint64_t metadata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata_mask from an object of type of_instruction_write_metadata.
 * @param obj Pointer to an object of type of_instruction_write_metadata.
 * @param metadata_mask Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_instruction_write_metadata_metadata_mask_get(
    of_instruction_write_metadata_t *obj,
    uint64_t *metadata_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata_mask in an object of type of_instruction_write_metadata.
 * @param obj Pointer to an object of type of_instruction_write_metadata.
 * @param metadata_mask The value to write into the object
 */
void
of_instruction_write_metadata_metadata_mask_set(
    of_instruction_write_metadata_t *obj,
    uint64_t metadata_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_INSTRUCTION_WRITE_METADATA);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata_mask);

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
of_match_v2_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
        *(uint16_t *)(buf + 0) = U16_HTON(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_match_v2 of_match_v2
 */

/**
 * Create a new of_match_v2 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_match_v2
 */

of_object_t *
of_match_v2_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_MATCH_V2];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_match_v2_init(obj, version, bytes, 0);
    of_match_v2_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_match_v2.
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
of_match_v2_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_MATCH_V2] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_MATCH_V2];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_MATCH_V2;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get in_port from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param in_port Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_match_v2_in_port_get(
    of_match_v2_t *obj,
    of_port_no_t *in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, in_port);
    OF_PORT_NO_VALUE_CHECK(*in_port, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set in_port in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param in_port The value to write into the object
 */
void
of_match_v2_in_port_set(
    of_match_v2_t *obj,
    of_port_no_t in_port)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, in_port);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get wildcards from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param wildcards Pointer to the child object of type
 * of_wc_bmap_t to be filled out.
 *
 */
void
of_match_v2_wildcards_get(
    of_match_v2_t *obj,
    of_wc_bmap_t *wildcards)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_wc_bmap_get(ver, wbuf, abs_offset, wildcards);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set wildcards in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param wildcards The value to write into the object
 */
void
of_match_v2_wildcards_set(
    of_match_v2_t *obj,
    of_wc_bmap_t wildcards)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_wc_bmap_set(ver, wbuf, abs_offset, wildcards);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_src from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_src_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_src in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src The value to write into the object
 */
void
of_match_v2_eth_src_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_src_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_src_mask_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 18;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_src_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_src_mask The value to write into the object
 */
void
of_match_v2_eth_src_mask_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 18;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_dst from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_dst_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_dst in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst The value to write into the object
 */
void
of_match_v2_eth_dst_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get eth_dst_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_match_v2_eth_dst_mask_get(
    of_match_v2_t *obj,
    of_mac_addr_t *eth_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, eth_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_dst_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_dst_mask The value to write into the object
 */
void
of_match_v2_eth_dst_mask_set(
    of_match_v2_t *obj,
    of_mac_addr_t eth_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, eth_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get vlan_vid from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_vid Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_vlan_vid_get(
    of_match_v2_t *obj,
    uint16_t *vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 36;
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
 * Set vlan_vid in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_vid The value to write into the object
 */
void
of_match_v2_vlan_vid_set(
    of_match_v2_t *obj,
    uint16_t vlan_vid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 36;
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

/**
 * Get vlan_pcp from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_pcp Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_vlan_pcp_get(
    of_match_v2_t *obj,
    uint8_t *vlan_pcp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 38;
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
 * Set vlan_pcp in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param vlan_pcp The value to write into the object
 */
void
of_match_v2_vlan_pcp_set(
    of_match_v2_t *obj,
    uint8_t vlan_pcp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 38;
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

/**
 * Get eth_type from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_type Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_eth_type_get(
    of_match_v2_t *obj,
    uint16_t *eth_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, eth_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set eth_type in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param eth_type The value to write into the object
 */
void
of_match_v2_eth_type_set(
    of_match_v2_t *obj,
    uint16_t eth_type)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 40;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, eth_type);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ip_dscp from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_dscp Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_ip_dscp_get(
    of_match_v2_t *obj,
    uint8_t *ip_dscp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 42;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, ip_dscp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ip_dscp in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_dscp The value to write into the object
 */
void
of_match_v2_ip_dscp_set(
    of_match_v2_t *obj,
    uint8_t ip_dscp)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 42;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, ip_dscp);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ip_proto from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_proto Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_ip_proto_get(
    of_match_v2_t *obj,
    uint8_t *ip_proto)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 43;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, ip_proto);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ip_proto in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ip_proto The value to write into the object
 */
void
of_match_v2_ip_proto_set(
    of_match_v2_t *obj,
    uint8_t ip_proto)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 43;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, ip_proto);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_src from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_src_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_src in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src The value to write into the object
 */
void
of_match_v2_ipv4_src_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_src_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src_mask Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_src_mask_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_src_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_src_mask The value to write into the object
 */
void
of_match_v2_ipv4_src_mask_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_src_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_src_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_dst from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_dst_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 52;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_dst in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst The value to write into the object
 */
void
of_match_v2_ipv4_dst_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 52;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get ipv4_dst_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst_mask Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_match_v2_ipv4_dst_mask_get(
    of_match_v2_t *obj,
    of_ipv4_t *ipv4_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 56;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, ipv4_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set ipv4_dst_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param ipv4_dst_mask The value to write into the object
 */
void
of_match_v2_ipv4_dst_mask_set(
    of_match_v2_t *obj,
    of_ipv4_t ipv4_dst_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 56;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, ipv4_dst_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tcp_src from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_src Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_tcp_src_get(
    of_match_v2_t *obj,
    uint16_t *tcp_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 60;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tcp_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tcp_src in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_src The value to write into the object
 */
void
of_match_v2_tcp_src_set(
    of_match_v2_t *obj,
    uint16_t tcp_src)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 60;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tcp_src);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get tcp_dst from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_dst Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_match_v2_tcp_dst_get(
    of_match_v2_t *obj,
    uint16_t *tcp_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 62;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, tcp_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set tcp_dst in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param tcp_dst The value to write into the object
 */
void
of_match_v2_tcp_dst_set(
    of_match_v2_t *obj,
    uint16_t tcp_dst)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 62;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, tcp_dst);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mpls_label from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_label Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_match_v2_mpls_label_get(
    of_match_v2_t *obj,
    uint32_t *mpls_label)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 64;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, mpls_label);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mpls_label in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_label The value to write into the object
 */
void
of_match_v2_mpls_label_set(
    of_match_v2_t *obj,
    uint32_t mpls_label)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 64;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, mpls_label);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get mpls_tc from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_tc Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_match_v2_mpls_tc_get(
    of_match_v2_t *obj,
    uint8_t *mpls_tc)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 68;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, mpls_tc);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set mpls_tc in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param mpls_tc The value to write into the object
 */
void
of_match_v2_mpls_tc_set(
    of_match_v2_t *obj,
    uint8_t mpls_tc)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 68;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, mpls_tc);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_match_v2_metadata_get(
    of_match_v2_t *obj,
    uint64_t *metadata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 72;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata The value to write into the object
 */
void
of_match_v2_metadata_set(
    of_match_v2_t *obj,
    uint64_t metadata)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 72;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get metadata_mask from an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata_mask Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_match_v2_metadata_mask_get(
    of_match_v2_t *obj,
    uint64_t *metadata_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 80;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, metadata_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set metadata_mask in an object of type of_match_v2.
 * @param obj Pointer to an object of type of_match_v2.
 * @param metadata_mask The value to write into the object
 */
void
of_match_v2_metadata_mask_set(
    of_match_v2_t *obj,
    uint64_t metadata_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_MATCH_V2);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_1:
        offset = 80;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, metadata_mask);

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
of_switch_config_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0xa); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_switch_config_failed_error_msg of_switch_config_failed_error_msg
 */

/**
 * Create a new of_switch_config_failed_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_switch_config_failed_error_msg
 */

of_object_t *
of_switch_config_failed_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_SWITCH_CONFIG_FAILED_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_switch_config_failed_error_msg_init(obj, version, bytes, 0);
    of_switch_config_failed_error_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_switch_config_failed_error_msg.
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
of_switch_config_failed_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_SWITCH_CONFIG_FAILED_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_SWITCH_CONFIG_FAILED_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_SWITCH_CONFIG_FAILED_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_switch_config_failed_error_msg.
 * @param obj Pointer to an object of type of_switch_config_failed_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_switch_config_failed_error_msg_xid_get(
    of_switch_config_failed_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set xid in an object of type of_switch_config_failed_error_msg.
 * @param obj Pointer to an object of type of_switch_config_failed_error_msg.
 * @param xid The value to write into the object
 */
void
of_switch_config_failed_error_msg_xid_set(
    of_switch_config_failed_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get code from an object of type of_switch_config_failed_error_msg.
 * @param obj Pointer to an object of type of_switch_config_failed_error_msg.
 * @param code Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_switch_config_failed_error_msg_code_get(
    of_switch_config_failed_error_msg_t *obj,
    uint16_t *code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set code in an object of type of_switch_config_failed_error_msg.
 * @param obj Pointer to an object of type of_switch_config_failed_error_msg.
 * @param code The value to write into the object
 */
void
of_switch_config_failed_error_msg_code_set(
    of_switch_config_failed_error_msg_t *obj,
    uint16_t code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get data from an object of type of_switch_config_failed_error_msg.
 * @param obj Pointer to an object of type of_switch_config_failed_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_switch_config_failed_error_msg_data_get(
    of_switch_config_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set data in an object of type of_switch_config_failed_error_msg.
 * @param obj Pointer to an object of type of_switch_config_failed_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_switch_config_failed_error_msg_data_set(
    of_switch_config_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_SWITCH_CONFIG_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_table_mod_failed_error_msg_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_1:
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x1; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x8); /* err_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_table_mod_failed_error_msg of_table_mod_failed_error_msg
 */

/**
 * Create a new of_table_mod_failed_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_table_mod_failed_error_msg
 */

of_object_t *
of_table_mod_failed_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_TABLE_MOD_FAILED_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_table_mod_failed_error_msg_init(obj, version, bytes, 0);
    of_table_mod_failed_error_msg_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_table_mod_failed_error_msg.
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
of_table_mod_failed_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_TABLE_MOD_FAILED_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_TABLE_MOD_FAILED_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_TABLE_MOD_FAILED_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_table_mod_failed_error_msg.
 * @param obj Pointer to an object of type of_table_mod_failed_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_table_mod_failed_error_msg_xid_get(
    of_table_mod_failed_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set xid in an object of type of_table_mod_failed_error_msg.
 * @param obj Pointer to an object of type of_table_mod_failed_error_msg.
 * @param xid The value to write into the object
 */
void
of_table_mod_failed_error_msg_xid_set(
    of_table_mod_failed_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get code from an object of type of_table_mod_failed_error_msg.
 * @param obj Pointer to an object of type of_table_mod_failed_error_msg.
 * @param code Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_table_mod_failed_error_msg_code_get(
    of_table_mod_failed_error_msg_t *obj,
    uint16_t *code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set code in an object of type of_table_mod_failed_error_msg.
 * @param obj Pointer to an object of type of_table_mod_failed_error_msg.
 * @param code The value to write into the object
 */
void
of_table_mod_failed_error_msg_code_set(
    of_table_mod_failed_error_msg_t *obj,
    uint16_t code)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Get data from an object of type of_table_mod_failed_error_msg.
 * @param obj Pointer to an object of type of_table_mod_failed_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_table_mod_failed_error_msg_data_get(
    of_table_mod_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
 * Set data in an object of type of_table_mod_failed_error_msg.
 * @param obj Pointer to an object of type of_table_mod_failed_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_table_mod_failed_error_msg_data_set(
    of_table_mod_failed_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_TABLE_MOD_FAILED_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
of_oxm_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 0)); /* type_len */
        switch (value) {
        case 0x13e04:
            *id = OF_OXM_TUNNEL_IPV4_SRC;
            break;
        case 0x13f08:
            *id = OF_OXM_TUNNEL_IPV4_SRC_MASKED;
            break;
        case 0x14004:
            *id = OF_OXM_TUNNEL_IPV4_DST;
            break;
        case 0x14108:
            *id = OF_OXM_TUNNEL_IPV4_DST_MASKED;
            break;
        case 0x14c02:
            *id = OF_OXM_TUN_GBP_ID;
            break;
        case 0x14d04:
            *id = OF_OXM_TUN_GBP_ID_MASKED;
            break;
        case 0x14e01:
            *id = OF_OXM_TUN_GBP_FLAGS;
            break;
        case 0x14f02:
            *id = OF_OXM_TUN_GBP_FLAGS_MASKED;
            break;
        case 0x1d002:
            *id = OF_OXM_TUN_FLAGS;
            break;
        case 0x1d104:
            *id = OF_OXM_TUN_FLAGS_MASKED;
            break;
        case 0x1de01:
            *id = OF_OXM_TUN_GPE_NP;
            break;
        case 0x1df02:
            *id = OF_OXM_TUN_GPE_NP_MASKED;
            break;
        case 0x1e001:
            *id = OF_OXM_TUN_GPE_FLAGS;
            break;
        case 0x1e102:
            *id = OF_OXM_TUN_GPE_FLAGS_MASKED;
            break;
        case 0x1e204:
            *id = OF_OXM_NSP;
            break;
        case 0x1e308:
            *id = OF_OXM_NSP_MASKED;
            break;
        case 0x1e401:
            *id = OF_OXM_NSI;
            break;
        case 0x1e502:
            *id = OF_OXM_NSI_MASKED;
            break;
        case 0x1e604:
            *id = OF_OXM_NSH_C1;
            break;
        case 0x1e708:
            *id = OF_OXM_NSH_C1_MASKED;
            break;
        case 0x1e804:
            *id = OF_OXM_NSH_C2;
            break;
        case 0x1e908:
            *id = OF_OXM_NSH_C2_MASKED;
            break;
        case 0x1ea04:
            *id = OF_OXM_NSH_C3;
            break;
        case 0x1eb08:
            *id = OF_OXM_NSH_C3_MASKED;
            break;
        case 0x1ec04:
            *id = OF_OXM_NSH_C4;
            break;
        case 0x1ed08:
            *id = OF_OXM_NSH_C4_MASKED;
            break;
        case 0x1ee01:
            *id = OF_OXM_NSH_MDTYPE;
            break;
        case 0x1ef02:
            *id = OF_OXM_NSH_MDTYPE_MASKED;
            break;
        case 0x1f001:
            *id = OF_OXM_NSH_NP;
            break;
        case 0x1f102:
            *id = OF_OXM_NSH_NP_MASKED;
            break;
        case 0x1f206:
            *id = OF_OXM_ENCAP_ETH_SRC;
            break;
        case 0x1f30c:
            *id = OF_OXM_ENCAP_ETH_SRC_MASKED;
            break;
        case 0x1f406:
            *id = OF_OXM_ENCAP_ETH_DST;
            break;
        case 0x1f50c:
            *id = OF_OXM_ENCAP_ETH_DST_MASKED;
            break;
        case 0x1f602:
            *id = OF_OXM_ENCAP_ETH_TYPE;
            break;
        case 0x1f704:
            *id = OF_OXM_ENCAP_ETH_TYPE_MASKED;
            break;
        case 0x30010:
            *id = OF_OXM_BSN_IN_PORTS_128;
            break;
        case 0x30120:
            *id = OF_OXM_BSN_IN_PORTS_128_MASKED;
            break;
        case 0x30204:
            *id = OF_OXM_BSN_LAG_ID;
            break;
        case 0x30308:
            *id = OF_OXM_BSN_LAG_ID_MASKED;
            break;
        case 0x30404:
            *id = OF_OXM_BSN_VRF;
            break;
        case 0x30508:
            *id = OF_OXM_BSN_VRF_MASKED;
            break;
        case 0x30601:
            *id = OF_OXM_BSN_GLOBAL_VRF_ALLOWED;
            break;
        case 0x30702:
            *id = OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED;
            break;
        case 0x30804:
            *id = OF_OXM_BSN_L3_INTERFACE_CLASS_ID;
            break;
        case 0x30908:
            *id = OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED;
            break;
        case 0x30a04:
            *id = OF_OXM_BSN_L3_SRC_CLASS_ID;
            break;
        case 0x30b08:
            *id = OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED;
            break;
        case 0x30c04:
            *id = OF_OXM_BSN_L3_DST_CLASS_ID;
            break;
        case 0x30d08:
            *id = OF_OXM_BSN_L3_DST_CLASS_ID_MASKED;
            break;
        case 0x30e04:
            *id = OF_OXM_BSN_EGR_PORT_GROUP_ID;
            break;
        case 0x30f08:
            *id = OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED;
            break;
        case 0x31004:
            *id = OF_OXM_BSN_UDF0;
            break;
        case 0x31108:
            *id = OF_OXM_BSN_UDF0_MASKED;
            break;
        case 0x31204:
            *id = OF_OXM_BSN_UDF1;
            break;
        case 0x31308:
            *id = OF_OXM_BSN_UDF1_MASKED;
            break;
        case 0x31404:
            *id = OF_OXM_BSN_UDF2;
            break;
        case 0x31508:
            *id = OF_OXM_BSN_UDF2_MASKED;
            break;
        case 0x31604:
            *id = OF_OXM_BSN_UDF3;
            break;
        case 0x31708:
            *id = OF_OXM_BSN_UDF3_MASKED;
            break;
        case 0x31804:
            *id = OF_OXM_BSN_UDF4;
            break;
        case 0x31908:
            *id = OF_OXM_BSN_UDF4_MASKED;
            break;
        case 0x31a04:
            *id = OF_OXM_BSN_UDF5;
            break;
        case 0x31b08:
            *id = OF_OXM_BSN_UDF5_MASKED;
            break;
        case 0x31c04:
            *id = OF_OXM_BSN_UDF6;
            break;
        case 0x31d08:
            *id = OF_OXM_BSN_UDF6_MASKED;
            break;
        case 0x31e04:
            *id = OF_OXM_BSN_UDF7;
            break;
        case 0x31f08:
            *id = OF_OXM_BSN_UDF7_MASKED;
            break;
        case 0x32002:
            *id = OF_OXM_BSN_TCP_FLAGS;
            break;
        case 0x32104:
            *id = OF_OXM_BSN_TCP_FLAGS_MASKED;
            break;
        case 0x32204:
            *id = OF_OXM_BSN_VLAN_XLATE_PORT_GROUP_ID;
            break;
        case 0x32308:
            *id = OF_OXM_BSN_VLAN_XLATE_PORT_GROUP_ID_MASKED;
            break;
        case 0x32401:
            *id = OF_OXM_BSN_L2_CACHE_HIT;
            break;
        case 0x32502:
            *id = OF_OXM_BSN_L2_CACHE_HIT_MASKED;
            break;
        case 0x32640:
            *id = OF_OXM_BSN_IN_PORTS_512;
            break;
        case 0x32780:
            *id = OF_OXM_BSN_IN_PORTS_512_MASKED;
            break;
        case 0x32804:
            *id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID;
            break;
        case 0x32908:
            *id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID_MASKED;
            break;
        case 0x33401:
            *id = OF_OXM_BSN_IP_FRAGMENTATION;
            break;
        case 0x33502:
            *id = OF_OXM_BSN_IP_FRAGMENTATION_MASKED;
            break;
        case 0x80000004:
            *id = OF_OXM_IN_PORT;
            break;
        case 0x80000108:
            *id = OF_OXM_IN_PORT_MASKED;
            break;
        case 0x80000204:
            *id = OF_OXM_IN_PHY_PORT;
            break;
        case 0x80000308:
            *id = OF_OXM_IN_PHY_PORT_MASKED;
            break;
        case 0x80000408:
            *id = OF_OXM_METADATA;
            break;
        case 0x80000510:
            *id = OF_OXM_METADATA_MASKED;
            break;
        case 0x80000606:
            *id = OF_OXM_ETH_DST;
            break;
        case 0x8000070c:
            *id = OF_OXM_ETH_DST_MASKED;
            break;
        case 0x80000806:
            *id = OF_OXM_ETH_SRC;
            break;
        case 0x8000090c:
            *id = OF_OXM_ETH_SRC_MASKED;
            break;
        case 0x80000a02:
            *id = OF_OXM_ETH_TYPE;
            break;
        case 0x80000b04:
            *id = OF_OXM_ETH_TYPE_MASKED;
            break;
        case 0x80000c02:
            *id = OF_OXM_VLAN_VID;
            break;
        case 0x80000d04:
            *id = OF_OXM_VLAN_VID_MASKED;
            break;
        case 0x80000e01:
            *id = OF_OXM_VLAN_PCP;
            break;
        case 0x80000f02:
            *id = OF_OXM_VLAN_PCP_MASKED;
            break;
        case 0x80001001:
            *id = OF_OXM_IP_DSCP;
            break;
        case 0x80001102:
            *id = OF_OXM_IP_DSCP_MASKED;
            break;
        case 0x80001201:
            *id = OF_OXM_IP_ECN;
            break;
        case 0x80001302:
            *id = OF_OXM_IP_ECN_MASKED;
            break;
        case 0x80001401:
            *id = OF_OXM_IP_PROTO;
            break;
        case 0x80001502:
            *id = OF_OXM_IP_PROTO_MASKED;
            break;
        case 0x80001604:
            *id = OF_OXM_IPV4_SRC;
            break;
        case 0x80001708:
            *id = OF_OXM_IPV4_SRC_MASKED;
            break;
        case 0x80001804:
            *id = OF_OXM_IPV4_DST;
            break;
        case 0x80001908:
            *id = OF_OXM_IPV4_DST_MASKED;
            break;
        case 0x80001a02:
            *id = OF_OXM_TCP_SRC;
            break;
        case 0x80001b04:
            *id = OF_OXM_TCP_SRC_MASKED;
            break;
        case 0x80001c02:
            *id = OF_OXM_TCP_DST;
            break;
        case 0x80001d04:
            *id = OF_OXM_TCP_DST_MASKED;
            break;
        case 0x80001e02:
            *id = OF_OXM_UDP_SRC;
            break;
        case 0x80001f04:
            *id = OF_OXM_UDP_SRC_MASKED;
            break;
        case 0x80002002:
            *id = OF_OXM_UDP_DST;
            break;
        case 0x80002104:
            *id = OF_OXM_UDP_DST_MASKED;
            break;
        case 0x80002202:
            *id = OF_OXM_SCTP_SRC;
            break;
        case 0x80002304:
            *id = OF_OXM_SCTP_SRC_MASKED;
            break;
        case 0x80002402:
            *id = OF_OXM_SCTP_DST;
            break;
        case 0x80002504:
            *id = OF_OXM_SCTP_DST_MASKED;
            break;
        case 0x80002601:
            *id = OF_OXM_ICMPV4_TYPE;
            break;
        case 0x80002702:
            *id = OF_OXM_ICMPV4_TYPE_MASKED;
            break;
        case 0x80002801:
            *id = OF_OXM_ICMPV4_CODE;
            break;
        case 0x80002902:
            *id = OF_OXM_ICMPV4_CODE_MASKED;
            break;
        case 0x80002a02:
            *id = OF_OXM_ARP_OP;
            break;
        case 0x80002b04:
            *id = OF_OXM_ARP_OP_MASKED;
            break;
        case 0x80002c04:
            *id = OF_OXM_ARP_SPA;
            break;
        case 0x80002d08:
            *id = OF_OXM_ARP_SPA_MASKED;
            break;
        case 0x80002e04:
            *id = OF_OXM_ARP_TPA;
            break;
        case 0x80002f08:
            *id = OF_OXM_ARP_TPA_MASKED;
            break;
        case 0x80003006:
            *id = OF_OXM_ARP_SHA;
            break;
        case 0x8000310c:
            *id = OF_OXM_ARP_SHA_MASKED;
            break;
        case 0x80003206:
            *id = OF_OXM_ARP_THA;
            break;
        case 0x8000330c:
            *id = OF_OXM_ARP_THA_MASKED;
            break;
        case 0x80003410:
            *id = OF_OXM_IPV6_SRC;
            break;
        case 0x80003520:
            *id = OF_OXM_IPV6_SRC_MASKED;
            break;
        case 0x80003610:
            *id = OF_OXM_IPV6_DST;
            break;
        case 0x80003720:
            *id = OF_OXM_IPV6_DST_MASKED;
            break;
        case 0x80003804:
            *id = OF_OXM_IPV6_FLABEL;
            break;
        case 0x80003908:
            *id = OF_OXM_IPV6_FLABEL_MASKED;
            break;
        case 0x80003a01:
            *id = OF_OXM_ICMPV6_TYPE;
            break;
        case 0x80003b02:
            *id = OF_OXM_ICMPV6_TYPE_MASKED;
            break;
        case 0x80003c01:
            *id = OF_OXM_ICMPV6_CODE;
            break;
        case 0x80003d02:
            *id = OF_OXM_ICMPV6_CODE_MASKED;
            break;
        case 0x80003e10:
            *id = OF_OXM_IPV6_ND_TARGET;
            break;
        case 0x80003f20:
            *id = OF_OXM_IPV6_ND_TARGET_MASKED;
            break;
        case 0x80004006:
            *id = OF_OXM_IPV6_ND_SLL;
            break;
        case 0x8000410c:
            *id = OF_OXM_IPV6_ND_SLL_MASKED;
            break;
        case 0x80004206:
            *id = OF_OXM_IPV6_ND_TLL;
            break;
        case 0x8000430c:
            *id = OF_OXM_IPV6_ND_TLL_MASKED;
            break;
        case 0x80004404:
            *id = OF_OXM_MPLS_LABEL;
            break;
        case 0x80004508:
            *id = OF_OXM_MPLS_LABEL_MASKED;
            break;
        case 0x80004601:
            *id = OF_OXM_MPLS_TC;
            break;
        case 0x80004702:
            *id = OF_OXM_MPLS_TC_MASKED;
            break;
        case 0xffff5406:
            *id = OF_OXM_OVS_TCP_FLAGS;
            break;
        case 0xffff5508:
            *id = OF_OXM_OVS_TCP_FLAGS_MASKED;
            break;
        default:
            *id = OF_OXM;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 0)); /* type_len */
        switch (value) {
        case 0x13e04:
            *id = OF_OXM_TUNNEL_IPV4_SRC;
            break;
        case 0x13f08:
            *id = OF_OXM_TUNNEL_IPV4_SRC_MASKED;
            break;
        case 0x14004:
            *id = OF_OXM_TUNNEL_IPV4_DST;
            break;
        case 0x14108:
            *id = OF_OXM_TUNNEL_IPV4_DST_MASKED;
            break;
        case 0x14c02:
            *id = OF_OXM_TUN_GBP_ID;
            break;
        case 0x14d04:
            *id = OF_OXM_TUN_GBP_ID_MASKED;
            break;
        case 0x14e01:
            *id = OF_OXM_TUN_GBP_FLAGS;
            break;
        case 0x14f02:
            *id = OF_OXM_TUN_GBP_FLAGS_MASKED;
            break;
        case 0x1d002:
            *id = OF_OXM_TUN_FLAGS;
            break;
        case 0x1d104:
            *id = OF_OXM_TUN_FLAGS_MASKED;
            break;
        case 0x1de01:
            *id = OF_OXM_TUN_GPE_NP;
            break;
        case 0x1df02:
            *id = OF_OXM_TUN_GPE_NP_MASKED;
            break;
        case 0x1e001:
            *id = OF_OXM_TUN_GPE_FLAGS;
            break;
        case 0x1e102:
            *id = OF_OXM_TUN_GPE_FLAGS_MASKED;
            break;
        case 0x1e204:
            *id = OF_OXM_NSP;
            break;
        case 0x1e308:
            *id = OF_OXM_NSP_MASKED;
            break;
        case 0x1e401:
            *id = OF_OXM_NSI;
            break;
        case 0x1e502:
            *id = OF_OXM_NSI_MASKED;
            break;
        case 0x1e604:
            *id = OF_OXM_NSH_C1;
            break;
        case 0x1e708:
            *id = OF_OXM_NSH_C1_MASKED;
            break;
        case 0x1e804:
            *id = OF_OXM_NSH_C2;
            break;
        case 0x1e908:
            *id = OF_OXM_NSH_C2_MASKED;
            break;
        case 0x1ea04:
            *id = OF_OXM_NSH_C3;
            break;
        case 0x1eb08:
            *id = OF_OXM_NSH_C3_MASKED;
            break;
        case 0x1ec04:
            *id = OF_OXM_NSH_C4;
            break;
        case 0x1ed08:
            *id = OF_OXM_NSH_C4_MASKED;
            break;
        case 0x1ee01:
            *id = OF_OXM_NSH_MDTYPE;
            break;
        case 0x1ef02:
            *id = OF_OXM_NSH_MDTYPE_MASKED;
            break;
        case 0x1f001:
            *id = OF_OXM_NSH_NP;
            break;
        case 0x1f102:
            *id = OF_OXM_NSH_NP_MASKED;
            break;
        case 0x1f206:
            *id = OF_OXM_ENCAP_ETH_SRC;
            break;
        case 0x1f30c:
            *id = OF_OXM_ENCAP_ETH_SRC_MASKED;
            break;
        case 0x1f406:
            *id = OF_OXM_ENCAP_ETH_DST;
            break;
        case 0x1f50c:
            *id = OF_OXM_ENCAP_ETH_DST_MASKED;
            break;
        case 0x1f602:
            *id = OF_OXM_ENCAP_ETH_TYPE;
            break;
        case 0x1f704:
            *id = OF_OXM_ENCAP_ETH_TYPE_MASKED;
            break;
        case 0x30010:
            *id = OF_OXM_BSN_IN_PORTS_128;
            break;
        case 0x30120:
            *id = OF_OXM_BSN_IN_PORTS_128_MASKED;
            break;
        case 0x30204:
            *id = OF_OXM_BSN_LAG_ID;
            break;
        case 0x30308:
            *id = OF_OXM_BSN_LAG_ID_MASKED;
            break;
        case 0x30404:
            *id = OF_OXM_BSN_VRF;
            break;
        case 0x30508:
            *id = OF_OXM_BSN_VRF_MASKED;
            break;
        case 0x30601:
            *id = OF_OXM_BSN_GLOBAL_VRF_ALLOWED;
            break;
        case 0x30702:
            *id = OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED;
            break;
        case 0x30804:
            *id = OF_OXM_BSN_L3_INTERFACE_CLASS_ID;
            break;
        case 0x30908:
            *id = OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED;
            break;
        case 0x30a04:
            *id = OF_OXM_BSN_L3_SRC_CLASS_ID;
            break;
        case 0x30b08:
            *id = OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED;
            break;
        case 0x30c04:
            *id = OF_OXM_BSN_L3_DST_CLASS_ID;
            break;
        case 0x30d08:
            *id = OF_OXM_BSN_L3_DST_CLASS_ID_MASKED;
            break;
        case 0x30e04:
            *id = OF_OXM_BSN_EGR_PORT_GROUP_ID;
            break;
        case 0x30f08:
            *id = OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED;
            break;
        case 0x31004:
            *id = OF_OXM_BSN_UDF0;
            break;
        case 0x31108:
            *id = OF_OXM_BSN_UDF0_MASKED;
            break;
        case 0x31204:
            *id = OF_OXM_BSN_UDF1;
            break;
        case 0x31308:
            *id = OF_OXM_BSN_UDF1_MASKED;
            break;
        case 0x31404:
            *id = OF_OXM_BSN_UDF2;
            break;
        case 0x31508:
            *id = OF_OXM_BSN_UDF2_MASKED;
            break;
        case 0x31604:
            *id = OF_OXM_BSN_UDF3;
            break;
        case 0x31708:
            *id = OF_OXM_BSN_UDF3_MASKED;
            break;
        case 0x31804:
            *id = OF_OXM_BSN_UDF4;
            break;
        case 0x31908:
            *id = OF_OXM_BSN_UDF4_MASKED;
            break;
        case 0x31a04:
            *id = OF_OXM_BSN_UDF5;
            break;
        case 0x31b08:
            *id = OF_OXM_BSN_UDF5_MASKED;
            break;
        case 0x31c04:
            *id = OF_OXM_BSN_UDF6;
            break;
        case 0x31d08:
            *id = OF_OXM_BSN_UDF6_MASKED;
            break;
        case 0x31e04:
            *id = OF_OXM_BSN_UDF7;
            break;
        case 0x31f08:
            *id = OF_OXM_BSN_UDF7_MASKED;
            break;
        case 0x32002:
            *id = OF_OXM_BSN_TCP_FLAGS;
            break;
        case 0x32104:
            *id = OF_OXM_BSN_TCP_FLAGS_MASKED;
            break;
        case 0x32204:
            *id = OF_OXM_BSN_VLAN_XLATE_PORT_GROUP_ID;
            break;
        case 0x32308:
            *id = OF_OXM_BSN_VLAN_XLATE_PORT_GROUP_ID_MASKED;
            break;
        case 0x32401:
            *id = OF_OXM_BSN_L2_CACHE_HIT;
            break;
        case 0x32502:
            *id = OF_OXM_BSN_L2_CACHE_HIT_MASKED;
            break;
        case 0x32640:
            *id = OF_OXM_BSN_IN_PORTS_512;
            break;
        case 0x32780:
            *id = OF_OXM_BSN_IN_PORTS_512_MASKED;
            break;
        case 0x32804:
            *id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID;
            break;
        case 0x32908:
            *id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID_MASKED;
            break;
        case 0x32a04:
            *id = OF_OXM_BSN_VXLAN_NETWORK_ID;
            break;
        case 0x32b08:
            *id = OF_OXM_BSN_VXLAN_NETWORK_ID_MASKED;
            break;
        case 0x32c06:
            *id = OF_OXM_BSN_INNER_ETH_DST;
            break;
        case 0x32d0c:
            *id = OF_OXM_BSN_INNER_ETH_DST_MASKED;
            break;
        case 0x32e06:
            *id = OF_OXM_BSN_INNER_ETH_SRC;
            break;
        case 0x32f0c:
            *id = OF_OXM_BSN_INNER_ETH_SRC_MASKED;
            break;
        case 0x33002:
            *id = OF_OXM_BSN_INNER_VLAN_VID;
            break;
        case 0x33104:
            *id = OF_OXM_BSN_INNER_VLAN_VID_MASKED;
            break;
        case 0x33202:
            *id = OF_OXM_BSN_VFI;
            break;
        case 0x33304:
            *id = OF_OXM_BSN_VFI_MASKED;
            break;
        case 0x33401:
            *id = OF_OXM_BSN_IP_FRAGMENTATION;
            break;
        case 0x33502:
            *id = OF_OXM_BSN_IP_FRAGMENTATION_MASKED;
            break;
        case 0x85801:
            *id = OF_OXM_CIRCUIT_OCH_SIGTYPE;
            break;
        case 0x85901:
            *id = OF_OXM_CIRCUIT_OCH_SIGTYPE_MASKED;
            break;
        case 0x85a06:
            *id = OF_OXM_CIRCUIT_OCH_SIGID;
            break;
        case 0x85b06:
            *id = OF_OXM_CIRCUIT_OCH_SIGID_MASKED;
            break;
        case 0x85c04:
            *id = OF_OXM_OCH_SIGATT;
            break;
        case 0x85d04:
            *id = OF_OXM_OCH_SIGATT_MASKED;
            break;
        case 0x80000004:
            *id = OF_OXM_IN_PORT;
            break;
        case 0x80000108:
            *id = OF_OXM_IN_PORT_MASKED;
            break;
        case 0x80000204:
            *id = OF_OXM_IN_PHY_PORT;
            break;
        case 0x80000308:
            *id = OF_OXM_IN_PHY_PORT_MASKED;
            break;
        case 0x80000408:
            *id = OF_OXM_METADATA;
            break;
        case 0x80000510:
            *id = OF_OXM_METADATA_MASKED;
            break;
        case 0x80000606:
            *id = OF_OXM_ETH_DST;
            break;
        case 0x8000070c:
            *id = OF_OXM_ETH_DST_MASKED;
            break;
        case 0x80000806:
            *id = OF_OXM_ETH_SRC;
            break;
        case 0x8000090c:
            *id = OF_OXM_ETH_SRC_MASKED;
            break;
        case 0x80000a02:
            *id = OF_OXM_ETH_TYPE;
            break;
        case 0x80000b04:
            *id = OF_OXM_ETH_TYPE_MASKED;
            break;
        case 0x80000c02:
            *id = OF_OXM_VLAN_VID;
            break;
        case 0x80000d04:
            *id = OF_OXM_VLAN_VID_MASKED;
            break;
        case 0x80000e01:
            *id = OF_OXM_VLAN_PCP;
            break;
        case 0x80000f02:
            *id = OF_OXM_VLAN_PCP_MASKED;
            break;
        case 0x80001001:
            *id = OF_OXM_IP_DSCP;
            break;
        case 0x80001102:
            *id = OF_OXM_IP_DSCP_MASKED;
            break;
        case 0x80001201:
            *id = OF_OXM_IP_ECN;
            break;
        case 0x80001302:
            *id = OF_OXM_IP_ECN_MASKED;
            break;
        case 0x80001401:
            *id = OF_OXM_IP_PROTO;
            break;
        case 0x80001502:
            *id = OF_OXM_IP_PROTO_MASKED;
            break;
        case 0x80001604:
            *id = OF_OXM_IPV4_SRC;
            break;
        case 0x80001708:
            *id = OF_OXM_IPV4_SRC_MASKED;
            break;
        case 0x80001804:
            *id = OF_OXM_IPV4_DST;
            break;
        case 0x80001908:
            *id = OF_OXM_IPV4_DST_MASKED;
            break;
        case 0x80001a02:
            *id = OF_OXM_TCP_SRC;
            break;
        case 0x80001b04:
            *id = OF_OXM_TCP_SRC_MASKED;
            break;
        case 0x80001c02:
            *id = OF_OXM_TCP_DST;
            break;
        case 0x80001d04:
            *id = OF_OXM_TCP_DST_MASKED;
            break;
        case 0x80001e02:
            *id = OF_OXM_UDP_SRC;
            break;
        case 0x80001f04:
            *id = OF_OXM_UDP_SRC_MASKED;
            break;
        case 0x80002002:
            *id = OF_OXM_UDP_DST;
            break;
        case 0x80002104:
            *id = OF_OXM_UDP_DST_MASKED;
            break;
        case 0x80002202:
            *id = OF_OXM_SCTP_SRC;
            break;
        case 0x80002304:
            *id = OF_OXM_SCTP_SRC_MASKED;
            break;
        case 0x80002402:
            *id = OF_OXM_SCTP_DST;
            break;
        case 0x80002504:
            *id = OF_OXM_SCTP_DST_MASKED;
            break;
        case 0x80002601:
            *id = OF_OXM_ICMPV4_TYPE;
            break;
        case 0x80002702:
            *id = OF_OXM_ICMPV4_TYPE_MASKED;
            break;
        case 0x80002801:
            *id = OF_OXM_ICMPV4_CODE;
            break;
        case 0x80002902:
            *id = OF_OXM_ICMPV4_CODE_MASKED;
            break;
        case 0x80002a02:
            *id = OF_OXM_ARP_OP;
            break;
        case 0x80002b04:
            *id = OF_OXM_ARP_OP_MASKED;
            break;
        case 0x80002c04:
            *id = OF_OXM_ARP_SPA;
            break;
        case 0x80002d08:
            *id = OF_OXM_ARP_SPA_MASKED;
            break;
        case 0x80002e04:
            *id = OF_OXM_ARP_TPA;
            break;
        case 0x80002f08:
            *id = OF_OXM_ARP_TPA_MASKED;
            break;
        case 0x80003006:
            *id = OF_OXM_ARP_SHA;
            break;
        case 0x8000310c:
            *id = OF_OXM_ARP_SHA_MASKED;
            break;
        case 0x80003206:
            *id = OF_OXM_ARP_THA;
            break;
        case 0x8000330c:
            *id = OF_OXM_ARP_THA_MASKED;
            break;
        case 0x80003410:
            *id = OF_OXM_IPV6_SRC;
            break;
        case 0x80003520:
            *id = OF_OXM_IPV6_SRC_MASKED;
            break;
        case 0x80003610:
            *id = OF_OXM_IPV6_DST;
            break;
        case 0x80003720:
            *id = OF_OXM_IPV6_DST_MASKED;
            break;
        case 0x80003804:
            *id = OF_OXM_IPV6_FLABEL;
            break;
        case 0x80003908:
            *id = OF_OXM_IPV6_FLABEL_MASKED;
            break;
        case 0x80003a01:
            *id = OF_OXM_ICMPV6_TYPE;
            break;
        case 0x80003b02:
            *id = OF_OXM_ICMPV6_TYPE_MASKED;
            break;
        case 0x80003c01:
            *id = OF_OXM_ICMPV6_CODE;
            break;
        case 0x80003d02:
            *id = OF_OXM_ICMPV6_CODE_MASKED;
            break;
        case 0x80003e10:
            *id = OF_OXM_IPV6_ND_TARGET;
            break;
        case 0x80003f20:
            *id = OF_OXM_IPV6_ND_TARGET_MASKED;
            break;
        case 0x80004006:
            *id = OF_OXM_IPV6_ND_SLL;
            break;
        case 0x8000410c:
            *id = OF_OXM_IPV6_ND_SLL_MASKED;
            break;
        case 0x80004206:
            *id = OF_OXM_IPV6_ND_TLL;
            break;
        case 0x8000430c:
            *id = OF_OXM_IPV6_ND_TLL_MASKED;
            break;
        case 0x80004404:
            *id = OF_OXM_MPLS_LABEL;
            break;
        case 0x80004508:
            *id = OF_OXM_MPLS_LABEL_MASKED;
            break;
        case 0x80004601:
            *id = OF_OXM_MPLS_TC;
            break;
        case 0x80004702:
            *id = OF_OXM_MPLS_TC_MASKED;
            break;
        case 0x80004801:
            *id = OF_OXM_MPLS_BOS;
            break;
        case 0x80004902:
            *id = OF_OXM_MPLS_BOS_MASKED;
            break;
        case 0x80004c08:
            *id = OF_OXM_TUNNEL_ID;
            break;
        case 0x80004d10:
            *id = OF_OXM_TUNNEL_ID_MASKED;
            break;
        case 0x80004e02:
            *id = OF_OXM_IPV6_EXTHDR;
            break;
        case 0x80004f04:
            *id = OF_OXM_IPV6_EXTHDR_MASKED;
            break;
        case 0x80005801:
            *id = OF_OXM_CIRCUIT_OCH_SIGTYPE_BASIC;
            break;
        case 0x80005901:
            *id = OF_OXM_CIRCUIT_OCH_SIGTYPE_BASIC_MASKED;
            break;
        case 0x80005a06:
            *id = OF_OXM_CIRCUIT_OCH_SIGID_BASIC;
            break;
        case 0x80005b06:
            *id = OF_OXM_CIRCUIT_OCH_SIGID_BASIC_MASKED;
            break;
        case 0x80005c04:
            *id = OF_OXM_OCH_SIGATT_BASIC;
            break;
        case 0x80005d04:
            *id = OF_OXM_OCH_SIGATT_BASIC_MASKED;
            break;
        case 0xffff0401:
            *id = OF_OXM_EXP_ODU_SIGTYPE;
            break;
        case 0xffff0501:
            *id = OF_OXM_EXP_ODU_SIGTYPE_MASKED;
            break;
        case 0xffff0610:
            *id = OF_OXM_EXP_ODU_SIGID;
            break;
        case 0xffff0710:
            *id = OF_OXM_EXP_ODU_SIGID_MASKED;
            break;
        case 0xffff0801:
            *id = OF_OXM_EXP_OCH_SIGTYPE;
            break;
        case 0xffff0901:
            *id = OF_OXM_EXP_OCH_SIGTYPE_MASKED;
            break;
        case 0xffff0a05:
            *id = OF_OXM_OFDPA_QOS_INDEX;
            break;
        case 0xffff0a06:
            *id = OF_OXM_EXP_OCH_SIGID;
            break;
        case 0xffff0b05:
            *id = OF_OXM_OFDPA_QOS_INDEX_MASKED;
            break;
        case 0xffff0b06:
            *id = OF_OXM_EXP_OCH_SIGID_MASKED;
            break;
        case 0xffff1008:
            *id = OF_OXM_OFDPA_MPLS_L2_PORT;
            break;
        case 0xffff110c:
            *id = OF_OXM_OFDPA_MPLS_L2_PORT_MASKED;
            break;
        case 0xffff1406:
            *id = OF_OXM_OFDPA_OVID;
            break;
        case 0xffff1506:
            *id = OF_OXM_OFDPA_OVID_MASKED;
            break;
        case 0xffff2e06:
            *id = OF_OXM_OFDPA_MPLS_TYPE;
            break;
        case 0xffff2f06:
            *id = OF_OXM_OFDPA_MPLS_TYPE_MASKED;
            break;
        case 0xffff5406:
            *id = OF_OXM_OVS_TCP_FLAGS;
            break;
        case 0xffff5508:
            *id = OF_OXM_OVS_TCP_FLAGS_MASKED;
            break;
        default:
            *id = OF_OXM;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 0)); /* type_len */
        switch (value) {
        case 0x13e04:
            *id = OF_OXM_TUNNEL_IPV4_SRC;
            break;
        case 0x13f08:
            *id = OF_OXM_TUNNEL_IPV4_SRC_MASKED;
            break;
        case 0x14004:
            *id = OF_OXM_TUNNEL_IPV4_DST;
            break;
        case 0x14108:
            *id = OF_OXM_TUNNEL_IPV4_DST_MASKED;
            break;
        case 0x14c02:
            *id = OF_OXM_TUN_GBP_ID;
            break;
        case 0x14d04:
            *id = OF_OXM_TUN_GBP_ID_MASKED;
            break;
        case 0x14e01:
            *id = OF_OXM_TUN_GBP_FLAGS;
            break;
        case 0x14f02:
            *id = OF_OXM_TUN_GBP_FLAGS_MASKED;
            break;
        case 0x1d002:
            *id = OF_OXM_TUN_FLAGS;
            break;
        case 0x1d104:
            *id = OF_OXM_TUN_FLAGS_MASKED;
            break;
        case 0x1de01:
            *id = OF_OXM_TUN_GPE_NP;
            break;
        case 0x1df02:
            *id = OF_OXM_TUN_GPE_NP_MASKED;
            break;
        case 0x1e001:
            *id = OF_OXM_TUN_GPE_FLAGS;
            break;
        case 0x1e102:
            *id = OF_OXM_TUN_GPE_FLAGS_MASKED;
            break;
        case 0x1e204:
            *id = OF_OXM_NSP;
            break;
        case 0x1e308:
            *id = OF_OXM_NSP_MASKED;
            break;
        case 0x1e401:
            *id = OF_OXM_NSI;
            break;
        case 0x1e502:
            *id = OF_OXM_NSI_MASKED;
            break;
        case 0x1e604:
            *id = OF_OXM_NSH_C1;
            break;
        case 0x1e708:
            *id = OF_OXM_NSH_C1_MASKED;
            break;
        case 0x1e804:
            *id = OF_OXM_NSH_C2;
            break;
        case 0x1e908:
            *id = OF_OXM_NSH_C2_MASKED;
            break;
        case 0x1ea04:
            *id = OF_OXM_NSH_C3;
            break;
        case 0x1eb08:
            *id = OF_OXM_NSH_C3_MASKED;
            break;
        case 0x1ec04:
            *id = OF_OXM_NSH_C4;
            break;
        case 0x1ed08:
            *id = OF_OXM_NSH_C4_MASKED;
            break;
        case 0x1ee01:
            *id = OF_OXM_NSH_MDTYPE;
            break;
        case 0x1ef02:
            *id = OF_OXM_NSH_MDTYPE_MASKED;
            break;
        case 0x1f001:
            *id = OF_OXM_NSH_NP;
            break;
        case 0x1f102:
            *id = OF_OXM_NSH_NP_MASKED;
            break;
        case 0x1f206:
            *id = OF_OXM_ENCAP_ETH_SRC;
            break;
        case 0x1f30c:
            *id = OF_OXM_ENCAP_ETH_SRC_MASKED;
            break;
        case 0x1f406:
            *id = OF_OXM_ENCAP_ETH_DST;
            break;
        case 0x1f50c:
            *id = OF_OXM_ENCAP_ETH_DST_MASKED;
            break;
        case 0x1f602:
            *id = OF_OXM_ENCAP_ETH_TYPE;
            break;
        case 0x1f704:
            *id = OF_OXM_ENCAP_ETH_TYPE_MASKED;
            break;
        case 0x30010:
            *id = OF_OXM_BSN_IN_PORTS_128;
            break;
        case 0x30120:
            *id = OF_OXM_BSN_IN_PORTS_128_MASKED;
            break;
        case 0x30204:
            *id = OF_OXM_BSN_LAG_ID;
            break;
        case 0x30308:
            *id = OF_OXM_BSN_LAG_ID_MASKED;
            break;
        case 0x30404:
            *id = OF_OXM_BSN_VRF;
            break;
        case 0x30508:
            *id = OF_OXM_BSN_VRF_MASKED;
            break;
        case 0x30804:
            *id = OF_OXM_BSN_L3_INTERFACE_CLASS_ID;
            break;
        case 0x30908:
            *id = OF_OXM_BSN_L3_INTERFACE_CLASS_ID_MASKED;
            break;
        case 0x30a04:
            *id = OF_OXM_BSN_L3_SRC_CLASS_ID;
            break;
        case 0x30b08:
            *id = OF_OXM_BSN_L3_SRC_CLASS_ID_MASKED;
            break;
        case 0x30e04:
            *id = OF_OXM_BSN_EGR_PORT_GROUP_ID;
            break;
        case 0x30f08:
            *id = OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED;
            break;
        case 0x31004:
            *id = OF_OXM_BSN_UDF0;
            break;
        case 0x31108:
            *id = OF_OXM_BSN_UDF0_MASKED;
            break;
        case 0x31204:
            *id = OF_OXM_BSN_UDF1;
            break;
        case 0x31308:
            *id = OF_OXM_BSN_UDF1_MASKED;
            break;
        case 0x31404:
            *id = OF_OXM_BSN_UDF2;
            break;
        case 0x31508:
            *id = OF_OXM_BSN_UDF2_MASKED;
            break;
        case 0x31604:
            *id = OF_OXM_BSN_UDF3;
            break;
        case 0x31708:
            *id = OF_OXM_BSN_UDF3_MASKED;
            break;
        case 0x31804:
            *id = OF_OXM_BSN_UDF4;
            break;
        case 0x31908:
            *id = OF_OXM_BSN_UDF4_MASKED;
            break;
        case 0x31a04:
            *id = OF_OXM_BSN_UDF5;
            break;
        case 0x31b08:
            *id = OF_OXM_BSN_UDF5_MASKED;
            break;
        case 0x31c04:
            *id = OF_OXM_BSN_UDF6;
            break;
        case 0x31d08:
            *id = OF_OXM_BSN_UDF6_MASKED;
            break;
        case 0x31e04:
            *id = OF_OXM_BSN_UDF7;
            break;
        case 0x31f08:
            *id = OF_OXM_BSN_UDF7_MASKED;
            break;
        case 0x32002:
            *id = OF_OXM_BSN_TCP_FLAGS;
            break;
        case 0x32104:
            *id = OF_OXM_BSN_TCP_FLAGS_MASKED;
            break;
        case 0x32204:
            *id = OF_OXM_BSN_VLAN_XLATE_PORT_GROUP_ID;
            break;
        case 0x32308:
            *id = OF_OXM_BSN_VLAN_XLATE_PORT_GROUP_ID_MASKED;
            break;
        case 0x32401:
            *id = OF_OXM_BSN_L2_CACHE_HIT;
            break;
        case 0x32502:
            *id = OF_OXM_BSN_L2_CACHE_HIT_MASKED;
            break;
        case 0x32640:
            *id = OF_OXM_BSN_IN_PORTS_512;
            break;
        case 0x32780:
            *id = OF_OXM_BSN_IN_PORTS_512_MASKED;
            break;
        case 0x32804:
            *id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID;
            break;
        case 0x32908:
            *id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID_MASKED;
            break;
        case 0x32a04:
            *id = OF_OXM_BSN_VXLAN_NETWORK_ID;
            break;
        case 0x32b08:
            *id = OF_OXM_BSN_VXLAN_NETWORK_ID_MASKED;
            break;
        case 0x32c06:
            *id = OF_OXM_BSN_INNER_ETH_DST;
            break;
        case 0x32d0c:
            *id = OF_OXM_BSN_INNER_ETH_DST_MASKED;
            break;
        case 0x32e06:
            *id = OF_OXM_BSN_INNER_ETH_SRC;
            break;
        case 0x32f0c:
            *id = OF_OXM_BSN_INNER_ETH_SRC_MASKED;
            break;
        case 0x33002:
            *id = OF_OXM_BSN_INNER_VLAN_VID;
            break;
        case 0x33104:
            *id = OF_OXM_BSN_INNER_VLAN_VID_MASKED;
            break;
        case 0x33202:
            *id = OF_OXM_BSN_VFI;
            break;
        case 0x33304:
            *id = OF_OXM_BSN_VFI_MASKED;
            break;
        case 0x33401:
            *id = OF_OXM_BSN_IP_FRAGMENTATION;
            break;
        case 0x33502:
            *id = OF_OXM_BSN_IP_FRAGMENTATION_MASKED;
            break;
        case 0x80000004:
            *id = OF_OXM_IN_PORT;
            break;
        case 0x80000108:
            *id = OF_OXM_IN_PORT_MASKED;
            break;
        case 0x80000204:
            *id = OF_OXM_IN_PHY_PORT;
            break;
        case 0x80000308:
            *id = OF_OXM_IN_PHY_PORT_MASKED;
            break;
        case 0x80000408:
            *id = OF_OXM_METADATA;
            break;
        case 0x80000510:
            *id = OF_OXM_METADATA_MASKED;
            break;
        case 0x80000606:
            *id = OF_OXM_ETH_DST;
            break;
        case 0x8000070c:
            *id = OF_OXM_ETH_DST_MASKED;
            break;
        case 0x80000806:
            *id = OF_OXM_ETH_SRC;
            break;
        case 0x8000090c:
            *id = OF_OXM_ETH_SRC_MASKED;
            break;
        case 0x80000a02:
            *id = OF_OXM_ETH_TYPE;
            break;
        case 0x80000b04:
            *id = OF_OXM_ETH_TYPE_MASKED;
            break;
        case 0x80000c02:
            *id = OF_OXM_VLAN_VID;
            break;
        case 0x80000d04:
            *id = OF_OXM_VLAN_VID_MASKED;
            break;
        case 0x80000e01:
            *id = OF_OXM_VLAN_PCP;
            break;
        case 0x80000f02:
            *id = OF_OXM_VLAN_PCP_MASKED;
            break;
        case 0x80001001:
            *id = OF_OXM_IP_DSCP;
            break;
        case 0x80001102:
            *id = OF_OXM_IP_DSCP_MASKED;
            break;
        case 0x80001201:
            *id = OF_OXM_IP_ECN;
            break;
        case 0x80001302:
            *id = OF_OXM_IP_ECN_MASKED;
            break;
        case 0x80001401:
            *id = OF_OXM_IP_PROTO;
            break;
        case 0x80001502:
            *id = OF_OXM_IP_PROTO_MASKED;
            break;
        case 0x80001604:
            *id = OF_OXM_IPV4_SRC;
            break;
        case 0x80001708:
            *id = OF_OXM_IPV4_SRC_MASKED;
            break;
        case 0x80001804:
            *id = OF_OXM_IPV4_DST;
            break;
        case 0x80001908:
            *id = OF_OXM_IPV4_DST_MASKED;
            break;
        case 0x80001a02:
            *id = OF_OXM_TCP_SRC;
            break;
        case 0x80001b04:
            *id = OF_OXM_TCP_SRC_MASKED;
            break;
        case 0x80001c02:
            *id = OF_OXM_TCP_DST;
            break;
        case 0x80001d04:
            *id = OF_OXM_TCP_DST_MASKED;
            break;
        case 0x80001e02:
            *id = OF_OXM_UDP_SRC;
            break;
        case 0x80001f04:
            *id = OF_OXM_UDP_SRC_MASKED;
            break;
        case 0x80002002:
            *id = OF_OXM_UDP_DST;
            break;
        case 0x80002104:
            *id = OF_OXM_UDP_DST_MASKED;
            break;
        case 0x80002202:
            *id = OF_OXM_SCTP_SRC;
            break;
        case 0x80002304:
            *id = OF_OXM_SCTP_SRC_MASKED;
            break;
        case 0x80002402:
            *id = OF_OXM_SCTP_DST;
            break;
        case 0x80002504:
            *id = OF_OXM_SCTP_DST_MASKED;
            break;
        case 0x80002601:
            *id = OF_OXM_ICMPV4_TYPE;
            break;
        case 0x80002702:
            *id = OF_OXM_ICMPV4_TYPE_MASKED;
            break;
        case 0x80002801:
            *id = OF_OXM_ICMPV4_CODE;
            break;
        case 0x80002902:
            *id = OF_OXM_ICMPV4_CODE_MASKED;
            break;
        case 0x80002a02:
            *id = OF_OXM_ARP_OP;
            break;
        case 0x80002b04:
            *id = OF_OXM_ARP_OP_MASKED;
            break;
        case 0x80002c04:
            *id = OF_OXM_ARP_SPA;
            break;
        case 0x80002d08:
            *id = OF_OXM_ARP_SPA_MASKED;
            break;
        case 0x80002e04:
            *id = OF_OXM_ARP_TPA;
            break;
        case 0x80002f08:
            *id = OF_OXM_ARP_TPA_MASKED;
            break;
        case 0x80003006:
            *id = OF_OXM_ARP_SHA;
            break;
        case 0x8000310c:
            *id = OF_OXM_ARP_SHA_MASKED;
            break;
        case 0x80003206:
            *id = OF_OXM_ARP_THA;
            break;
        case 0x8000330c:
            *id = OF_OXM_ARP_THA_MASKED;
            break;
        case 0x80003410:
            *id = OF_OXM_IPV6_SRC;
            break;
        case 0x80003520:
            *id = OF_OXM_IPV6_SRC_MASKED;
            break;
        case 0x80003610:
            *id = OF_OXM_IPV6_DST;
            break;
        case 0x80003720:
            *id = OF_OXM_IPV6_DST_MASKED;
            break;
        case 0x80003804:
            *id = OF_OXM_IPV6_FLABEL;
            break;
        case 0x80003908:
            *id = OF_OXM_IPV6_FLABEL_MASKED;
            break;
        case 0x80003a01:
            *id = OF_OXM_ICMPV6_TYPE;
            break;
        case 0x80003b02:
            *id = OF_OXM_ICMPV6_TYPE_MASKED;
            break;
        case 0x80003c01:
            *id = OF_OXM_ICMPV6_CODE;
            break;
        case 0x80003d02:
            *id = OF_OXM_ICMPV6_CODE_MASKED;
            break;
        case 0x80003e10:
            *id = OF_OXM_IPV6_ND_TARGET;
            break;
        case 0x80003f20:
            *id = OF_OXM_IPV6_ND_TARGET_MASKED;
            break;
        case 0x80004006:
            *id = OF_OXM_IPV6_ND_SLL;
            break;
        case 0x8000410c:
            *id = OF_OXM_IPV6_ND_SLL_MASKED;
            break;
        case 0x80004206:
            *id = OF_OXM_IPV6_ND_TLL;
            break;
        case 0x8000430c:
            *id = OF_OXM_IPV6_ND_TLL_MASKED;
            break;
        case 0x80004404:
            *id = OF_OXM_MPLS_LABEL;
            break;
        case 0x80004508:
            *id = OF_OXM_MPLS_LABEL_MASKED;
            break;
        case 0x80004601:
            *id = OF_OXM_MPLS_TC;
            break;
        case 0x80004702:
            *id = OF_OXM_MPLS_TC_MASKED;
            break;
        case 0x80004801:
            *id = OF_OXM_MPLS_BOS;
            break;
        case 0x80004902:
            *id = OF_OXM_MPLS_BOS_MASKED;
            break;
        case 0x80004c08:
            *id = OF_OXM_TUNNEL_ID;
            break;
        case 0x80004d10:
            *id = OF_OXM_TUNNEL_ID_MASKED;
            break;
        case 0x80004e02:
            *id = OF_OXM_IPV6_EXTHDR;
            break;
        case 0x80004f04:
            *id = OF_OXM_IPV6_EXTHDR_MASKED;
            break;
        case 0x80005201:
            *id = OF_OXM_PBB_UCA;
            break;
        case 0x80005302:
            *id = OF_OXM_PBB_UCA_MASKED;
            break;
        case 0xffff5406:
            *id = OF_OXM_OVS_TCP_FLAGS;
            break;
        case 0xffff5508:
            *id = OF_OXM_OVS_TCP_FLAGS_MASKED;
            break;
        default:
            *id = OF_OXM;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_oxm of_oxm
 */

/**
 * Create a new of_oxm object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm
 */

of_object_t *
of_oxm_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_oxm_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_oxm.
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
of_oxm_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM;

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
of_action_set_field_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x19); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_action_set_field of_action_set_field
 */

/**
 * Create a new of_action_set_field object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_action_set_field
 */

of_object_t *
of_action_set_field_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_ACTION_SET_FIELD];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_action_set_field_init(obj, version, bytes, 0);
    of_action_set_field_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_action_set_field.
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
of_action_set_field_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_ACTION_SET_FIELD] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_ACTION_SET_FIELD];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_ACTION_SET_FIELD;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Bind an object of type of_oxm_t to the parent of type of_action_set_field for
 * member field
 * @param obj Pointer to an object of type of_action_set_field.
 * @param field Pointer to the child object of type
 * of_oxm_t to be filled out.
 * \ingroup of_action_set_field
 *
 * The parameter field is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_action_set_field_field_bind(
    of_action_set_field_t *obj,
    of_oxm_t *field)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_FIELD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_oxm_init(field, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, field, offset, cur_len);
    of_object_wire_init(field, OF_OXM, 0);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of field into a new variable of type of_oxm_t from
 * a of_action_set_field instance.
 *
 * @param obj Pointer to the source of type of_action_set_field_t
 * @returns A pointer to a new instance of type of_oxm_t whose contents
 * match that of field from source
 * @returns NULL if an error occurs
 */
of_oxm_t *
of_action_set_field_field_get(of_action_set_field_t *obj) {
    of_oxm_t _field;
    of_oxm_t *_field_ptr;

    of_action_set_field_field_bind(obj, &_field);
    _field_ptr = (of_oxm_t *)of_object_dup(&_field);
    return _field_ptr;
}

/**
 * Set field in an object of type of_action_set_field.
 * @param obj Pointer to an object of type of_action_set_field.
 * @param field Pointer to the child of type of_oxm_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_action_set_field_field_set(
    of_action_set_field_t *obj,
    of_oxm_t *field)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_ACTION_SET_FIELD);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = field->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == field->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(field, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(field, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)field, field->length);

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
of_experimenter_error_msg_wire_object_id_get(of_object_t *obj, of_object_id_t *id)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 12)); /* experimenter */
        switch (value) {
        default:
            *id = OF_EXPERIMENTER_ERROR_MSG;
            break;
        }
        break;
    }
    case OF_VERSION_1_3: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 12)); /* experimenter */
        switch (value) {
        case 0x5c16c7:
            of_bsn_base_error_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_EXPERIMENTER_ERROR_MSG;
            break;
        }
        break;
    }
    case OF_VERSION_1_4: {
        uint32_t value = U32_NTOH(*(uint32_t *)(buf + 12)); /* experimenter */
        switch (value) {
        case 0x5c16c7:
            of_bsn_base_error_wire_object_id_get(obj, id);
            break;
        default:
            *id = OF_EXPERIMENTER_ERROR_MSG;
            break;
        }
        break;
    }
    default:
        LOCI_ASSERT(0);
    }
}


/**
 * \defgroup of_experimenter_error_msg of_experimenter_error_msg
 */

/**
 * Create a new of_experimenter_error_msg object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_experimenter_error_msg
 */

of_object_t *
of_experimenter_error_msg_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_EXPERIMENTER_ERROR_MSG];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_experimenter_error_msg_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_experimenter_error_msg.
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
of_experimenter_error_msg_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_EXPERIMENTER_ERROR_MSG] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_EXPERIMENTER_ERROR_MSG];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_EXPERIMENTER_ERROR_MSG;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_experimenter_error_msg_xid_get(
    of_experimenter_error_msg_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param xid The value to write into the object
 */
void
of_experimenter_error_msg_xid_set(
    of_experimenter_error_msg_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param subtype Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_experimenter_error_msg_subtype_get(
    of_experimenter_error_msg_t *obj,
    uint16_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param subtype The value to write into the object
 */
void
of_experimenter_error_msg_subtype_set(
    of_experimenter_error_msg_t *obj,
    uint16_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_experimenter_error_msg_experimenter_get(
    of_experimenter_error_msg_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param experimenter The value to write into the object
 */
void
of_experimenter_error_msg_experimenter_set(
    of_experimenter_error_msg_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get data from an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param data Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_experimenter_error_msg_data_get(
    of_experimenter_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    data->bytes = cur_len;
    data->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set data in an object of type of_experimenter_error_msg.
 * @param obj Pointer to an object of type of_experimenter_error_msg.
 * @param data The value to write into the object
 */
int WARN_UNUSED_RESULT
of_experimenter_error_msg_data_set(
    of_experimenter_error_msg_t *obj,
    of_octets_t *data)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_EXPERIMENTER_ERROR_MSG);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
of_group_features_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x8); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_group_features_stats_reply of_group_features_stats_reply
 */

/**
 * Create a new of_group_features_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_group_features_stats_reply
 */

of_object_t *
of_group_features_stats_reply_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REPLY];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_group_features_stats_reply_init(obj, version, bytes, 0);
    of_group_features_stats_reply_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_group_features_stats_reply.
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
of_group_features_stats_reply_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_GROUP_FEATURES_STATS_REPLY;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_xid_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param xid The value to write into the object
 */
void
of_group_features_stats_reply_xid_set(
    of_group_features_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_group_features_stats_reply_flags_get(
    of_group_features_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param flags The value to write into the object
 */
void
of_group_features_stats_reply_flags_set(
    of_group_features_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get types from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param types Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_types_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *types)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_get(wbuf, abs_offset, types);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set types in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param types The value to write into the object
 */
void
of_group_features_stats_reply_types_set(
    of_group_features_stats_reply_t *obj,
    uint32_t types)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_set(wbuf, abs_offset, types);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get capabilities from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param capabilities Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_capabilities_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set capabilities in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param capabilities The value to write into the object
 */
void
of_group_features_stats_reply_capabilities_set(
    of_group_features_stats_reply_t *obj,
    uint32_t capabilities)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, capabilities);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_all from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_all Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_all_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_all in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_all The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_all_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_select from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_select Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_select_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_select in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_select The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_select_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_indirect from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_indirect Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_indirect_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_indirect in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_indirect The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_indirect_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get max_groups_ff from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_ff Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_max_groups_ff_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *max_groups_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, max_groups_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set max_groups_ff in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param max_groups_ff The value to write into the object
 */
void
of_group_features_stats_reply_max_groups_ff_set(
    of_group_features_stats_reply_t *obj,
    uint32_t max_groups_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, max_groups_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_all from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_all Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_all_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_all in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_all The value to write into the object
 */
void
of_group_features_stats_reply_actions_all_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_all)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
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
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_all);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_select from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_select Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_select_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_select in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_select The value to write into the object
 */
void
of_group_features_stats_reply_actions_select_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_select)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 44;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_select);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_indirect from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_indirect Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_indirect_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_indirect in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_indirect The value to write into the object
 */
void
of_group_features_stats_reply_actions_indirect_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_indirect)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 48;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_indirect);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actions_ff from an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_ff Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_reply_actions_ff_get(
    of_group_features_stats_reply_t *obj,
    uint32_t *actions_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 52;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, actions_ff);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actions_ff in an object of type of_group_features_stats_reply.
 * @param obj Pointer to an object of type of_group_features_stats_reply.
 * @param actions_ff The value to write into the object
 */
void
of_group_features_stats_reply_actions_ff_set(
    of_group_features_stats_reply_t *obj,
    uint32_t actions_ff)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 52;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, actions_ff);

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
of_group_features_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = U16_HTON(0x8); /* stats_type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_group_features_stats_request of_group_features_stats_request
 */

/**
 * Create a new of_group_features_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_group_features_stats_request
 */

of_object_t *
of_group_features_stats_request_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REQUEST];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_group_features_stats_request_init(obj, version, bytes, 0);
    of_group_features_stats_request_push_wire_types(obj);
    of_object_message_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_group_features_stats_request.
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
of_group_features_stats_request_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_GROUP_FEATURES_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_GROUP_FEATURES_STATS_REQUEST;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get xid from an object of type of_group_features_stats_request.
 * @param obj Pointer to an object of type of_group_features_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_group_features_stats_request_xid_get(
    of_group_features_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);
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
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_group_features_stats_request.
 * @param obj Pointer to an object of type of_group_features_stats_request.
 * @param xid The value to write into the object
 */
void
of_group_features_stats_request_xid_set(
    of_group_features_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);
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
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_group_features_stats_request.
 * @param obj Pointer to an object of type of_group_features_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_group_features_stats_request_flags_get(
    of_group_features_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_group_features_stats_request.
 * @param obj Pointer to an object of type of_group_features_stats_request.
 * @param flags The value to write into the object
 */
void
of_group_features_stats_request_flags_set(
    of_group_features_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_GROUP_FEATURES_STATS_REQUEST);
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
of_match_v3_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint16_t *)(buf + 0) = U16_HTON(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_match_v3 of_match_v3
 */

/**
 * Create a new of_match_v3 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_match_v3
 */

of_object_t *
of_match_v3_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_MATCH_V3];

    if ((obj = of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_match_v3_init(obj, version, bytes, 0);
    of_match_v3_push_wire_types(obj);
    of_tlv16_wire_length_set(obj, obj->length);

    return obj;
}

/**
 * Initialize an object of type of_match_v3.
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
of_match_v3_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_MATCH_V3] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_MATCH_V3];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_MATCH_V3;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Bind an object of type of_list_oxm_t to the parent of type of_match_v3 for
 * member oxm_list
 * @param obj Pointer to an object of type of_match_v3.
 * @param oxm_list Pointer to the child object of type
 * of_list_oxm_t to be filled out.
 * \ingroup of_match_v3
 *
 * The parameter oxm_list is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_match_v3_oxm_list_bind(
    of_match_v3_t *obj,
    of_list_oxm_t *oxm_list)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_MATCH_V3);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = wire_match_len(obj, 0) - 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_oxm_init(oxm_list, obj->version, 0, 1);
    /* Attach to parent */
    of_object_attach(obj, oxm_list, offset, cur_len);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of oxm_list into a new variable of type of_list_oxm_t from
 * a of_match_v3 instance.
 *
 * @param obj Pointer to the source of type of_match_v3_t
 * @returns A pointer to a new instance of type of_list_oxm_t whose contents
 * match that of oxm_list from source
 * @returns NULL if an error occurs
 */
of_list_oxm_t *
of_match_v3_oxm_list_get(of_match_v3_t *obj) {
    of_list_oxm_t _oxm_list;
    of_list_oxm_t *_oxm_list_ptr;

    of_match_v3_oxm_list_bind(obj, &_oxm_list);
    _oxm_list_ptr = (of_list_oxm_t *)of_object_dup(&_oxm_list);
    return _oxm_list_ptr;
}

/**
 * Set oxm_list in an object of type of_match_v3.
 * @param obj Pointer to an object of type of_match_v3.
 * @param oxm_list Pointer to the child of type of_list_oxm_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_match_v3_oxm_list_set(
    of_match_v3_t *obj,
    of_list_oxm_t *oxm_list)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_MATCH_V3);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 4;
        cur_len = wire_match_len(obj, 0) - 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = oxm_list->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wbuf == oxm_list->wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(oxm_list, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(oxm_list, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    of_object_wire_length_set((of_object_t *)oxm_list, oxm_list->length);

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
of_oxm_arp_op_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80002a02); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_op of_oxm_arp_op
 */

/**
 * Create a new of_oxm_arp_op object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_op
 */

of_object_t *
of_oxm_arp_op_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_OP];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_op_init(obj, version, bytes, 0);
    of_oxm_arp_op_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_op.
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
of_oxm_arp_op_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_OP] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_OP];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_OP;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_op.
 * @param obj Pointer to an object of type of_oxm_arp_op.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_arp_op_value_get(
    of_oxm_arp_op_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_OP);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_arp_op.
 * @param obj Pointer to an object of type of_oxm_arp_op.
 * @param value The value to write into the object
 */
void
of_oxm_arp_op_value_set(
    of_oxm_arp_op_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_OP);
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
of_oxm_arp_op_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80002b04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_op_masked of_oxm_arp_op_masked
 */

/**
 * Create a new of_oxm_arp_op_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_op_masked
 */

of_object_t *
of_oxm_arp_op_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_OP_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_op_masked_init(obj, version, bytes, 0);
    of_oxm_arp_op_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_op_masked.
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
of_oxm_arp_op_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_OP_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_OP_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_OP_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_op_masked.
 * @param obj Pointer to an object of type of_oxm_arp_op_masked.
 * @param value Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_arp_op_masked_value_get(
    of_oxm_arp_op_masked_t *obj,
    uint16_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_OP_MASKED);
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
    of_wire_buffer_u16_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_arp_op_masked.
 * @param obj Pointer to an object of type of_oxm_arp_op_masked.
 * @param value The value to write into the object
 */
void
of_oxm_arp_op_masked_value_set(
    of_oxm_arp_op_masked_t *obj,
    uint16_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_OP_MASKED);
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
    of_wire_buffer_u16_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_arp_op_masked.
 * @param obj Pointer to an object of type of_oxm_arp_op_masked.
 * @param value_mask Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_oxm_arp_op_masked_value_mask_get(
    of_oxm_arp_op_masked_t *obj,
    uint16_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_OP_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Set value_mask in an object of type of_oxm_arp_op_masked.
 * @param obj Pointer to an object of type of_oxm_arp_op_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_arp_op_masked_value_mask_set(
    of_oxm_arp_op_masked_t *obj,
    uint16_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_OP_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
of_oxm_arp_sha_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003006); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_sha of_oxm_arp_sha
 */

/**
 * Create a new of_oxm_arp_sha object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_sha
 */

of_object_t *
of_oxm_arp_sha_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_SHA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_sha_init(obj, version, bytes, 0);
    of_oxm_arp_sha_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_sha.
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
of_oxm_arp_sha_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_SHA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_SHA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_SHA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_sha.
 * @param obj Pointer to an object of type of_oxm_arp_sha.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_arp_sha_value_get(
    of_oxm_arp_sha_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SHA);
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
 * Set value in an object of type of_oxm_arp_sha.
 * @param obj Pointer to an object of type of_oxm_arp_sha.
 * @param value The value to write into the object
 */
void
of_oxm_arp_sha_value_set(
    of_oxm_arp_sha_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SHA);
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
of_oxm_arp_sha_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x8000310c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_sha_masked of_oxm_arp_sha_masked
 */

/**
 * Create a new of_oxm_arp_sha_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_sha_masked
 */

of_object_t *
of_oxm_arp_sha_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_SHA_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_sha_masked_init(obj, version, bytes, 0);
    of_oxm_arp_sha_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_sha_masked.
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
of_oxm_arp_sha_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_SHA_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_SHA_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_SHA_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_sha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_sha_masked.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_arp_sha_masked_value_get(
    of_oxm_arp_sha_masked_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SHA_MASKED);
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
 * Set value in an object of type of_oxm_arp_sha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_sha_masked.
 * @param value The value to write into the object
 */
void
of_oxm_arp_sha_masked_value_set(
    of_oxm_arp_sha_masked_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SHA_MASKED);
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
 * Get value_mask from an object of type of_oxm_arp_sha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_sha_masked.
 * @param value_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_arp_sha_masked_value_mask_get(
    of_oxm_arp_sha_masked_t *obj,
    of_mac_addr_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SHA_MASKED);
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
 * Set value_mask in an object of type of_oxm_arp_sha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_sha_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_arp_sha_masked_value_mask_set(
    of_oxm_arp_sha_masked_t *obj,
    of_mac_addr_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SHA_MASKED);
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
of_oxm_arp_spa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80002c04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_spa of_oxm_arp_spa
 */

/**
 * Create a new of_oxm_arp_spa object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_spa
 */

of_object_t *
of_oxm_arp_spa_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_SPA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_spa_init(obj, version, bytes, 0);
    of_oxm_arp_spa_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_spa.
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
of_oxm_arp_spa_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_SPA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_SPA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_SPA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_spa.
 * @param obj Pointer to an object of type of_oxm_arp_spa.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_arp_spa_value_get(
    of_oxm_arp_spa_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SPA);
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
 * Set value in an object of type of_oxm_arp_spa.
 * @param obj Pointer to an object of type of_oxm_arp_spa.
 * @param value The value to write into the object
 */
void
of_oxm_arp_spa_value_set(
    of_oxm_arp_spa_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SPA);
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
of_oxm_arp_spa_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80002d08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_spa_masked of_oxm_arp_spa_masked
 */

/**
 * Create a new of_oxm_arp_spa_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_spa_masked
 */

of_object_t *
of_oxm_arp_spa_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_SPA_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_spa_masked_init(obj, version, bytes, 0);
    of_oxm_arp_spa_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_spa_masked.
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
of_oxm_arp_spa_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_SPA_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_SPA_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_SPA_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_spa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_spa_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_arp_spa_masked_value_get(
    of_oxm_arp_spa_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SPA_MASKED);
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
 * Set value in an object of type of_oxm_arp_spa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_spa_masked.
 * @param value The value to write into the object
 */
void
of_oxm_arp_spa_masked_value_set(
    of_oxm_arp_spa_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SPA_MASKED);
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
 * Get value_mask from an object of type of_oxm_arp_spa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_spa_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_arp_spa_masked_value_mask_get(
    of_oxm_arp_spa_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SPA_MASKED);
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
 * Set value_mask in an object of type of_oxm_arp_spa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_spa_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_arp_spa_masked_value_mask_set(
    of_oxm_arp_spa_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_SPA_MASKED);
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
of_oxm_arp_tha_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80003206); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_tha of_oxm_arp_tha
 */

/**
 * Create a new of_oxm_arp_tha object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_tha
 */

of_object_t *
of_oxm_arp_tha_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_THA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tha_init(obj, version, bytes, 0);
    of_oxm_arp_tha_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_tha.
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
of_oxm_arp_tha_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_THA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_THA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_THA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_tha.
 * @param obj Pointer to an object of type of_oxm_arp_tha.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_arp_tha_value_get(
    of_oxm_arp_tha_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_THA);
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
 * Set value in an object of type of_oxm_arp_tha.
 * @param obj Pointer to an object of type of_oxm_arp_tha.
 * @param value The value to write into the object
 */
void
of_oxm_arp_tha_value_set(
    of_oxm_arp_tha_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_THA);
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
of_oxm_arp_tha_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x8000330c); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_tha_masked of_oxm_arp_tha_masked
 */

/**
 * Create a new of_oxm_arp_tha_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_tha_masked
 */

of_object_t *
of_oxm_arp_tha_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_THA_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tha_masked_init(obj, version, bytes, 0);
    of_oxm_arp_tha_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_tha_masked.
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
of_oxm_arp_tha_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_THA_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_THA_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_THA_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_tha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tha_masked.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_arp_tha_masked_value_get(
    of_oxm_arp_tha_masked_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_THA_MASKED);
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
 * Set value in an object of type of_oxm_arp_tha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tha_masked.
 * @param value The value to write into the object
 */
void
of_oxm_arp_tha_masked_value_set(
    of_oxm_arp_tha_masked_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_THA_MASKED);
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
 * Get value_mask from an object of type of_oxm_arp_tha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tha_masked.
 * @param value_mask Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_oxm_arp_tha_masked_value_mask_get(
    of_oxm_arp_tha_masked_t *obj,
    of_mac_addr_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_THA_MASKED);
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
 * Set value_mask in an object of type of_oxm_arp_tha_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tha_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_arp_tha_masked_value_mask_set(
    of_oxm_arp_tha_masked_t *obj,
    of_mac_addr_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_THA_MASKED);
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
of_oxm_arp_tpa_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80002e04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_tpa of_oxm_arp_tpa
 */

/**
 * Create a new of_oxm_arp_tpa object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_tpa
 */

of_object_t *
of_oxm_arp_tpa_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_TPA];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tpa_init(obj, version, bytes, 0);
    of_oxm_arp_tpa_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_tpa.
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
of_oxm_arp_tpa_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_TPA] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_TPA];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_TPA;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_tpa.
 * @param obj Pointer to an object of type of_oxm_arp_tpa.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_arp_tpa_value_get(
    of_oxm_arp_tpa_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_TPA);
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
 * Set value in an object of type of_oxm_arp_tpa.
 * @param obj Pointer to an object of type of_oxm_arp_tpa.
 * @param value The value to write into the object
 */
void
of_oxm_arp_tpa_value_set(
    of_oxm_arp_tpa_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_TPA);
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
of_oxm_arp_tpa_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x80002f08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_arp_tpa_masked of_oxm_arp_tpa_masked
 */

/**
 * Create a new of_oxm_arp_tpa_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_arp_tpa_masked
 */

of_object_t *
of_oxm_arp_tpa_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_ARP_TPA_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_arp_tpa_masked_init(obj, version, bytes, 0);
    of_oxm_arp_tpa_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_arp_tpa_masked.
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
of_oxm_arp_tpa_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_ARP_TPA_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_ARP_TPA_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_ARP_TPA_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_arp_tpa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tpa_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_arp_tpa_masked_value_get(
    of_oxm_arp_tpa_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_TPA_MASKED);
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
 * Set value in an object of type of_oxm_arp_tpa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tpa_masked.
 * @param value The value to write into the object
 */
void
of_oxm_arp_tpa_masked_value_set(
    of_oxm_arp_tpa_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_TPA_MASKED);
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
 * Get value_mask from an object of type of_oxm_arp_tpa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tpa_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_arp_tpa_masked_value_mask_get(
    of_oxm_arp_tpa_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_TPA_MASKED);
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
 * Set value_mask in an object of type of_oxm_arp_tpa_masked.
 * @param obj Pointer to an object of type of_oxm_arp_tpa_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_arp_tpa_masked_value_mask_set(
    of_oxm_arp_tpa_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_ARP_TPA_MASKED);
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
of_oxm_bsn_egr_port_group_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x30e04); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_egr_port_group_id of_oxm_bsn_egr_port_group_id
 */

/**
 * Create a new of_oxm_bsn_egr_port_group_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_egr_port_group_id
 */

of_object_t *
of_oxm_bsn_egr_port_group_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_EGR_PORT_GROUP_ID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_egr_port_group_id_init(obj, version, bytes, 0);
    of_oxm_bsn_egr_port_group_id_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_egr_port_group_id.
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
of_oxm_bsn_egr_port_group_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_EGR_PORT_GROUP_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_EGR_PORT_GROUP_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_EGR_PORT_GROUP_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_egr_port_group_id.
 * @param obj Pointer to an object of type of_oxm_bsn_egr_port_group_id.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_egr_port_group_id_value_get(
    of_oxm_bsn_egr_port_group_id_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_EGR_PORT_GROUP_ID);
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
 * Set value in an object of type of_oxm_bsn_egr_port_group_id.
 * @param obj Pointer to an object of type of_oxm_bsn_egr_port_group_id.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_egr_port_group_id_value_set(
    of_oxm_bsn_egr_port_group_id_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_EGR_PORT_GROUP_ID);
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
of_oxm_bsn_egr_port_group_id_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x30f08); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_egr_port_group_id_masked of_oxm_bsn_egr_port_group_id_masked
 */

/**
 * Create a new of_oxm_bsn_egr_port_group_id_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_egr_port_group_id_masked
 */

of_object_t *
of_oxm_bsn_egr_port_group_id_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_egr_port_group_id_masked_init(obj, version, bytes, 0);
    of_oxm_bsn_egr_port_group_id_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_egr_port_group_id_masked.
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
of_oxm_bsn_egr_port_group_id_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_egr_port_group_id_masked_value_get(
    of_oxm_bsn_egr_port_group_id_masked_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED);
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
 * Set value in an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_egr_port_group_id_masked_value_set(
    of_oxm_bsn_egr_port_group_id_masked_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED);
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
 * Get value_mask from an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param value_mask Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_egr_port_group_id_masked_value_mask_get(
    of_oxm_bsn_egr_port_group_id_masked_t *obj,
    uint32_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED);
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
 * Set value_mask in an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_egr_port_group_id_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_bsn_egr_port_group_id_masked_value_mask_set(
    of_oxm_bsn_egr_port_group_id_masked_t *obj,
    uint32_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_EGR_PORT_GROUP_ID_MASKED);
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
of_oxm_bsn_global_vrf_allowed_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x30601); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_global_vrf_allowed of_oxm_bsn_global_vrf_allowed
 */

/**
 * Create a new of_oxm_bsn_global_vrf_allowed object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_global_vrf_allowed
 */

of_object_t *
of_oxm_bsn_global_vrf_allowed_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_GLOBAL_VRF_ALLOWED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_global_vrf_allowed_init(obj, version, bytes, 0);
    of_oxm_bsn_global_vrf_allowed_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_global_vrf_allowed.
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
of_oxm_bsn_global_vrf_allowed_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_GLOBAL_VRF_ALLOWED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_GLOBAL_VRF_ALLOWED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_GLOBAL_VRF_ALLOWED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_global_vrf_allowed.
 * @param obj Pointer to an object of type of_oxm_bsn_global_vrf_allowed.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_bsn_global_vrf_allowed_value_get(
    of_oxm_bsn_global_vrf_allowed_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Set value in an object of type of_oxm_bsn_global_vrf_allowed.
 * @param obj Pointer to an object of type of_oxm_bsn_global_vrf_allowed.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_global_vrf_allowed_value_set(
    of_oxm_bsn_global_vrf_allowed_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
of_oxm_bsn_global_vrf_allowed_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
        *(uint32_t *)(buf + 0) = U32_HTON(0x30702); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_global_vrf_allowed_masked of_oxm_bsn_global_vrf_allowed_masked
 */

/**
 * Create a new of_oxm_bsn_global_vrf_allowed_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_global_vrf_allowed_masked
 */

of_object_t *
of_oxm_bsn_global_vrf_allowed_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_global_vrf_allowed_masked_init(obj, version, bytes, 0);
    of_oxm_bsn_global_vrf_allowed_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_global_vrf_allowed_masked.
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
of_oxm_bsn_global_vrf_allowed_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param value Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_bsn_global_vrf_allowed_masked_value_get(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj,
    uint8_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Set value in an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_global_vrf_allowed_masked_value_set(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj,
    uint8_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Get value_mask from an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param value_mask Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_oxm_bsn_global_vrf_allowed_masked_value_mask_get(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj,
    uint8_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
 * Set value_mask in an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_global_vrf_allowed_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_bsn_global_vrf_allowed_masked_value_mask_set(
    of_oxm_bsn_global_vrf_allowed_masked_t *obj,
    uint8_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_GLOBAL_VRF_ALLOWED_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
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
of_oxm_bsn_in_ports_128_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x30010); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_in_ports_128 of_oxm_bsn_in_ports_128
 */

/**
 * Create a new of_oxm_bsn_in_ports_128 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_in_ports_128
 */

of_object_t *
of_oxm_bsn_in_ports_128_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_128];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_128_init(obj, version, bytes, 0);
    of_oxm_bsn_in_ports_128_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_in_ports_128.
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
of_oxm_bsn_in_ports_128_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_128] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_128];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_IN_PORTS_128;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_in_ports_128.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_128.
 * @param value Pointer to the child object of type
 * of_bitmap_128_t to be filled out.
 *
 */
void
of_oxm_bsn_in_ports_128_value_get(
    of_oxm_bsn_in_ports_128_t *obj,
    of_bitmap_128_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128);
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
    of_wire_buffer_bitmap_128_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_bsn_in_ports_128.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_128.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_in_ports_128_value_set(
    of_oxm_bsn_in_ports_128_t *obj,
    of_bitmap_128_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128);
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
    of_wire_buffer_bitmap_128_set(wbuf, abs_offset, value);

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
of_oxm_bsn_in_ports_128_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x30120); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_in_ports_128_masked of_oxm_bsn_in_ports_128_masked
 */

/**
 * Create a new of_oxm_bsn_in_ports_128_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_in_ports_128_masked
 */

of_object_t *
of_oxm_bsn_in_ports_128_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_128_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_128_masked_init(obj, version, bytes, 0);
    of_oxm_bsn_in_ports_128_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_in_ports_128_masked.
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
of_oxm_bsn_in_ports_128_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_128_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_128_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_IN_PORTS_128_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_in_ports_128_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_128_masked.
 * @param value Pointer to the child object of type
 * of_bitmap_128_t to be filled out.
 *
 */
void
of_oxm_bsn_in_ports_128_masked_value_get(
    of_oxm_bsn_in_ports_128_masked_t *obj,
    of_bitmap_128_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128_MASKED);
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
    of_wire_buffer_bitmap_128_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_bsn_in_ports_128_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_128_masked.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_in_ports_128_masked_value_set(
    of_oxm_bsn_in_ports_128_masked_t *obj,
    of_bitmap_128_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128_MASKED);
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
    of_wire_buffer_bitmap_128_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_bsn_in_ports_128_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_128_masked.
 * @param value_mask Pointer to the child object of type
 * of_bitmap_128_t to be filled out.
 *
 */
void
of_oxm_bsn_in_ports_128_masked_value_mask_get(
    of_oxm_bsn_in_ports_128_masked_t *obj,
    of_bitmap_128_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128_MASKED);
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
    of_wire_buffer_bitmap_128_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_bsn_in_ports_128_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_128_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_bsn_in_ports_128_masked_value_mask_set(
    of_oxm_bsn_in_ports_128_masked_t *obj,
    of_bitmap_128_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_128_MASKED);
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
    of_wire_buffer_bitmap_128_set(wbuf, abs_offset, value_mask);

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
of_oxm_bsn_in_ports_512_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x32640); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_in_ports_512 of_oxm_bsn_in_ports_512
 */

/**
 * Create a new of_oxm_bsn_in_ports_512 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_in_ports_512
 */

of_object_t *
of_oxm_bsn_in_ports_512_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_512];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_512_init(obj, version, bytes, 0);
    of_oxm_bsn_in_ports_512_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_in_ports_512.
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
of_oxm_bsn_in_ports_512_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_512] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_512];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_IN_PORTS_512;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_in_ports_512.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_512.
 * @param value Pointer to the child object of type
 * of_bitmap_512_t to be filled out.
 *
 */
void
of_oxm_bsn_in_ports_512_value_get(
    of_oxm_bsn_in_ports_512_t *obj,
    of_bitmap_512_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_512);
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
    of_wire_buffer_bitmap_512_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_bsn_in_ports_512.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_512.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_in_ports_512_value_set(
    of_oxm_bsn_in_ports_512_t *obj,
    of_bitmap_512_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_512);
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
    of_wire_buffer_bitmap_512_set(wbuf, abs_offset, value);

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
of_oxm_bsn_in_ports_512_masked_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x32780); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_in_ports_512_masked of_oxm_bsn_in_ports_512_masked
 */

/**
 * Create a new of_oxm_bsn_in_ports_512_masked object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_in_ports_512_masked
 */

of_object_t *
of_oxm_bsn_in_ports_512_masked_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_512_MASKED];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_in_ports_512_masked_init(obj, version, bytes, 0);
    of_oxm_bsn_in_ports_512_masked_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_in_ports_512_masked.
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
of_oxm_bsn_in_ports_512_masked_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_512_MASKED] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_IN_PORTS_512_MASKED];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_IN_PORTS_512_MASKED;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_in_ports_512_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_512_masked.
 * @param value Pointer to the child object of type
 * of_bitmap_512_t to be filled out.
 *
 */
void
of_oxm_bsn_in_ports_512_masked_value_get(
    of_oxm_bsn_in_ports_512_masked_t *obj,
    of_bitmap_512_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_512_MASKED);
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
    of_wire_buffer_bitmap_512_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_oxm_bsn_in_ports_512_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_512_masked.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_in_ports_512_masked_value_set(
    of_oxm_bsn_in_ports_512_masked_t *obj,
    of_bitmap_512_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_512_MASKED);
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
    of_wire_buffer_bitmap_512_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get value_mask from an object of type of_oxm_bsn_in_ports_512_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_512_masked.
 * @param value_mask Pointer to the child object of type
 * of_bitmap_512_t to be filled out.
 *
 */
void
of_oxm_bsn_in_ports_512_masked_value_mask_get(
    of_oxm_bsn_in_ports_512_masked_t *obj,
    of_bitmap_512_t *value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_512_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 68;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_bitmap_512_get(wbuf, abs_offset, value_mask);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value_mask in an object of type of_oxm_bsn_in_ports_512_masked.
 * @param obj Pointer to an object of type of_oxm_bsn_in_ports_512_masked.
 * @param value_mask The value to write into the object
 */
void
of_oxm_bsn_in_ports_512_masked_value_mask_set(
    of_oxm_bsn_in_ports_512_masked_t *obj,
    of_bitmap_512_t value_mask)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_IN_PORTS_512_MASKED);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        offset = 68;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_bitmap_512_set(wbuf, abs_offset, value_mask);

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
of_oxm_bsn_ingress_port_group_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_2:
    case OF_VERSION_1_3:
    case OF_VERSION_1_4:
        *(uint32_t *)(buf + 0) = U32_HTON(0x32804); /* type_len */
        break;
    default:
        UNREACHABLE();
    }
}



/**
 * \defgroup of_oxm_bsn_ingress_port_group_id of_oxm_bsn_ingress_port_group_id
 */

/**
 * Create a new of_oxm_bsn_ingress_port_group_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * \ingroup of_oxm_bsn_ingress_port_group_id
 */

of_object_t *
of_oxm_bsn_ingress_port_group_id_new(of_version_t version)
{
    of_object_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_OXM_BSN_INGRESS_PORT_GROUP_ID];

    if ((obj = of_object_new(bytes)) == NULL) {
        return NULL;
    }

    of_oxm_bsn_ingress_port_group_id_init(obj, version, bytes, 0);
    of_oxm_bsn_ingress_port_group_id_push_wire_types(obj);

    return obj;
}

/**
 * Initialize an object of type of_oxm_bsn_ingress_port_group_id.
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
of_oxm_bsn_ingress_port_group_id_init(of_object_t *obj,
    of_version_t version, int bytes, int clean_wire)
{
    LOCI_ASSERT(of_object_fixed_len[version][OF_OXM_BSN_INGRESS_PORT_GROUP_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_OXM_BSN_INGRESS_PORT_GROUP_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_OXM_BSN_INGRESS_PORT_GROUP_ID;

    /* Grow the wire buffer */
    if (obj->wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->obj_offset;
        of_wire_buffer_grow(obj->wbuf, tot_bytes);
    }
}

/**
 * Get value from an object of type of_oxm_bsn_ingress_port_group_id.
 * @param obj Pointer to an object of type of_oxm_bsn_ingress_port_group_id.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_oxm_bsn_ingress_port_group_id_value_get(
    of_oxm_bsn_ingress_port_group_id_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_INGRESS_PORT_GROUP_ID);
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
 * Set value in an object of type of_oxm_bsn_ingress_port_group_id.
 * @param obj Pointer to an object of type of_oxm_bsn_ingress_port_group_id.
 * @param value The value to write into the object
 */
void
of_oxm_bsn_ingress_port_group_id_value_set(
    of_oxm_bsn_ingress_port_group_id_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_OXM_BSN_INGRESS_PORT_GROUP_ID);
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
