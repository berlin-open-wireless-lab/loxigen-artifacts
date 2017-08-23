/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/******************************************************************************
 *
 *  /module/src/loci_int.h
 *
 *  loci Internal Header
 *
 *****************************************************************************/
#ifndef __LOCI_INT_H__
#define __LOCI_INT_H__

#include <loci/loci.h>

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
#define UNREACHABLE() __builtin_unreachable()
#else
#define UNREACHABLE()
#endif

/****************************************************************
 * Special case macros for calculating variable lengths and offsets
 ****************************************************************/

/**
 * Get a u16 directly from an offset in an object's wire buffer
 * @param obj An of_object_t object
 * @param offset Base offset of the uint16 relative to the object
 *
 */

static inline int
of_object_u16_get(of_object_t *obj, int offset) {
    uint16_t val16;

    of_wire_buffer_u16_get(obj->wbuf,
        obj->obj_offset + offset, &val16);

    return (int)val16;
}

/**
 * Set a u16 directly at an offset in an object's wire buffer
 * @param obj An of_object_t object
 * @param offset Base offset of the uint16 relative to the object
 * @param val The value to store
 *
 */

static inline void
of_object_u16_set(of_object_t *obj, int offset, int value) {
    uint16_t val16;

    val16 = (uint16_t)value;
    of_wire_buffer_u16_set(obj->wbuf,
        obj->obj_offset + offset, val16);
}

/**
 * Get length of an object with a TLV header with uint16_t
 * @param obj An object with a match member
 * @param offset The wire offset of the start of the object
 *
 * The length field follows the type field.
 */

#define _TLV16_LEN(obj, offset) \
    (of_object_u16_get((of_object_t *)(obj), (offset) + 2))

/**
 * Get length of an object that is the "rest" of the object
 * @param obj An object with a match member
 * @param offset The wire offset of the start of the object
 *
 */

#define _END_LEN(obj, offset) ((obj)->length - (offset))

/**
 * Offset of the action_len member in a packet-out object
 */

#define _PACKET_OUT_ACTION_LEN_OFFSET(obj) \
    (((obj)->version == OF_VERSION_1_0) ? 14 : 16)

/**
 * Get length of the action list object in a packet_out object
 * @param obj An object of type of_packet_out
 */

#define _PACKET_OUT_ACTION_LEN(obj) \
    (of_object_u16_get((of_object_t *)(obj), _PACKET_OUT_ACTION_LEN_OFFSET(obj)))

/**
 * Set length of the action list object in a packet_out object
 * @param obj An object of type of_packet_out
 */

#define _PACKET_OUT_ACTION_LEN_SET(obj, len) \
    (of_object_u16_set((of_object_t *)(obj), _PACKET_OUT_ACTION_LEN_OFFSET(obj), len))

/*
 * Match structs in 1.2 come at the end of the fixed length part
 * of structures.  They add 8 bytes to the minimal length of the
 * message, but are also variable length.  This means that the
 * type/length offsets are 8 bytes back from the end of the fixed
 * length part of the object.  The right way to handle this is to
 * expose the offset of the match member more explicitly.  For now,
 * we make the calculation as described here.
 */

/* 1.2 min length of match is 8 bytes */
#define _MATCH_MIN_LENGTH_V3 8

/**
 * The offset of a 1.2 match object relative to fixed length of obj
 */
#define _MATCH_OFFSET_V3(fixed_obj_len) \
    ((fixed_obj_len) - _MATCH_MIN_LENGTH_V3)

/**
 * The "extra" length beyond the minimal 8 bytes of a match struct
 * in an object
 */
#define _MATCH_EXTRA_LENGTH_V3(obj, fixed_obj_len) \
    (OF_MATCH_BYTES(_TLV16_LEN(obj, _MATCH_OFFSET_V3(fixed_obj_len))) - \
     _MATCH_MIN_LENGTH_V3)

/**
 * The offset of an object following a match object for 1.2
 */
#define _OFFSET_FOLLOWING_MATCH_V3(obj, fixed_obj_len) \
    ((fixed_obj_len) + _MATCH_EXTRA_LENGTH_V3(obj, fixed_obj_len))

/**
 * Get length of a match object from its wire representation
 * @param obj An object with a match member
 * @param match_offset The wire offset of the match object.
 *
 * See above; for 1.2,
 * The match length is raw bytes but the actual space it takes
 * up is padded for alignment to 64-bits
 */
#define _WIRE_MATCH_LEN(obj, match_offset) \
    (((obj)->version == OF_VERSION_1_0) ? 40 : \
     (((obj)->version == OF_VERSION_1_1) ? 88 : \
      _TLV16_LEN(obj, match_offset)))

#define _WIRE_LEN_MIN 4

/*
 * Wrapper function for match len.  There are cases where the wire buffer
 * has not been set with the proper minimum length.  In this case, the
 * wire match len is interpretted as its minimum length, 4 bytes.
 */

static inline int
wire_match_len(of_object_t *obj, int match_offset) {
    int len;

    len = _WIRE_MATCH_LEN(obj, match_offset);

    return (len == 0) ? _WIRE_LEN_MIN : len;
}

#define _WIRE_MATCH_PADDED_LEN(obj, match_offset) \
    OF_MATCH_BYTES(wire_match_len((of_object_t *)(obj), (match_offset)))

/**
 * Macro to calculate variable offset of instructions member in flow mod
 * @param obj An object of some type of flow modify/add/delete
 *
 * Get length of preceding match object and add to fixed length
 * Applies only to version 1.2
 */

#define _FLOW_MOD_INSTRUCTIONS_OFFSET(obj) \
    _OFFSET_FOLLOWING_MATCH_V3(obj, 56)

/* The different flavors of flow mod all use the above */
#define _FLOW_ADD_INSTRUCTIONS_OFFSET(obj) \
    _FLOW_MOD_INSTRUCTIONS_OFFSET(obj)
#define _FLOW_MODIFY_INSTRUCTIONS_OFFSET(obj) \
    _FLOW_MOD_INSTRUCTIONS_OFFSET(obj)
#define _FLOW_MODIFY_STRICT_INSTRUCTIONS_OFFSET(obj) \
    _FLOW_MOD_INSTRUCTIONS_OFFSET(obj)
#define _FLOW_DELETE_INSTRUCTIONS_OFFSET(obj) \
    _FLOW_MOD_INSTRUCTIONS_OFFSET(obj)
#define _FLOW_DELETE_STRICT_INSTRUCTIONS_OFFSET(obj) \
    _FLOW_MOD_INSTRUCTIONS_OFFSET(obj)

/**
 * Macro to calculate variable offset of instructions member in flow stats
 * @param obj An object of type of_flow_mod_t
 *
 * Get length of preceding match object and add to fixed length
 * Applies only to version 1.2 and 1.3
 */

#define _FLOW_STATS_ENTRY_INSTRUCTIONS_OFFSET(obj) \
    _OFFSET_FOLLOWING_MATCH_V3(obj, 56)

/**
 * Macro to calculate variable offset of data (packet) member in packet_in
 * @param obj An object of type of_packet_in_t
 *
 * Get length of preceding match object and add to fixed length
 * Applies only to version 1.2+
 * There are 2 bytes of padding between the match and data. The
 * _OFFSET_FOLLOWING_MATCH_V3 macro assumes the match is at the end of the
 * fixed length, so we need to subtract 2 from the fixed length we pass and
 * then add 2 to the resulting offset.
 */

#define _PACKET_IN_DATA_OFFSET(obj) \
    (_OFFSET_FOLLOWING_MATCH_V3((obj), (obj)->version == OF_VERSION_1_2 ? \
(26 - 2) : (34 - 2)) + 2)

/**
 * Macro to calculate variable offset of data (packet) member in packet_out
 * @param obj An object of type of_packet_out_t
 *
 * Find the length in the actions_len variable and add to the fixed len
 * Applies only to version 1.2 and 1.3
 */

#define _PACKET_OUT_DATA_OFFSET(obj) (_PACKET_OUT_ACTION_LEN(obj) + \
     of_object_fixed_len[(obj)->version][OF_PACKET_OUT])

/**
 * Macro to map port numbers that changed across versions
 * @param port The port_no_t variable holding the value
 * @param ver The OpenFlow version from which the value was extracted
 */
#define OF_PORT_NO_VALUE_CHECK(port, ver) \
    if (((ver) == OF_VERSION_1_0) && ((port) > 0xff00)) (port) += 0xffff0000

/**
 * Macro to detect if an object ID falls in the "flow mod" family of objects
 * This includes add, modify, modify_strict, delete and delete_strict
 */
#define IS_FLOW_MOD_SUBTYPE(object_id)                 \
    (((object_id) == OF_FLOW_MODIFY) ||                \
     ((object_id) == OF_FLOW_MODIFY_STRICT) ||         \
     ((object_id) == OF_FLOW_DELETE) ||                \
     ((object_id) == OF_FLOW_DELETE_STRICT) ||         \
     ((object_id) == OF_FLOW_ADD))

/**
 * Macro to calculate variable offset of value member in of_bsn_gentable_entry_add
 * @param obj An object of type of_bsn_gentable_entry_add_t
 */

#define _BSN_GENTABLE_ENTRY_ADD_VALUE_OFFSET(obj) \
    (of_object_u16_get(obj, 18) + \
        of_object_fixed_len[(obj)->version][OF_BSN_GENTABLE_ENTRY_ADD])

#define _BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY_VALUE_OFFSET(obj) \
    (of_object_u16_get(obj, 2) + \
        of_object_fixed_len[(obj)->version][OF_BSN_GENTABLE_ENTRY_DESC_STATS_ENTRY])

#define _BSN_GENTABLE_ENTRY_STATS_ENTRY_STATS_OFFSET(obj) \
    (of_object_u16_get(obj, 2) + \
        of_object_fixed_len[(obj)->version][OF_BSN_GENTABLE_ENTRY_STATS_ENTRY])

/* Optical Extensions */

/**
 * Macro to calculate offset of instructions member in of_calient_flow_stats_entry
 * @param obj An object of type of_calient_flow_stats_entry_t
 */

#define _CALIENT_FLOW_STATS_ENTRY_INSTRUCTIONS_OFFSET(obj) \
    (of_object_fixed_len[(obj)->version][OF_CALIENT_FLOW_STATS_ENTRY] + \
        sizeof(of_match_t))

/**
 * Macro to calculate offset of value mask_member in of_oxm_exp_odu_sigid_masked.
 * Offset is base length + tpn of member 'value' + tsmap length of member 'value' +
 * tsmap of member 'value'.
 * @param obj An object of type of_oxm_exp_odu_sigid_maksked_t
 */

#define _OXM_EXP_ODU_SIGID_MASKED_VALUE_MASK_OFFSET(obj) \
    (of_object_u16_get(obj, 10) + 4 + \
        of_object_fixed_len[(obj)->version][OF_OXM_EXP_ODU_SIGID_MASKED])

#endif /* __LOCI_INT_H__ */