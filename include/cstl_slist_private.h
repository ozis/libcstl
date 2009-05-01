/*
 *  The slist struct and private interface.
 *  Copyright (C)  2008 2009  Wangbo
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  Author e-mail: activesys.wb@gmail.com
 *                 activesys@sina.com.cn
 */

#ifndef _CSTL_SLIST_PRIVATE_H
#define _CSTL_SLIST_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/** include section **/

/** constant declaration and macro section **/

/** data type declaration and struct, union, enum section **/
/*
 * +----------------+
 * | next node      |
 * +----------------+
 * | data  ...      |
 * |     . . .      |
 * +----------------+
 */
typedef struct _tagslistnode
{
    struct _tagslistnode* _pt_next;
    char                  _pc_data[1];   /* the element value */
}slistnode_t;

typedef struct _tagslist
{
    /* element identify */
    size_t          _t_typesize;                          /* element size */
    char            _sz_typename[_ELEM_TYPE_NAME_SIZE+1]; /* element name */

    /* memory allocate */
    alloc_t         _t_allocater;

    /* slist core struct */
    slistnode_t     _t_head;

    /* 
     * the compare function :
     * < 0  : element first < element second.
     * == 0 : element first == element second.
     * > 0  : element first > element second. 
     */
    int (*_pfun_cmp)(const void*, const void*);
}slist_t;

/** exported global variable declaration section **/

/** exported function prototype section **/
/*
 * Create and initialize slist_t.
 */
extern slist_t _create_slist(size_t t_typesize, const char* s_typename);
extern void _slist_init_elem(slist_t* pt_slist, size_t t_count, ...);
extern void _slist_init_elem_varg(
    slist_t* pt_slist, size_t t_count, va_list val_elemlist);

/*
 * Assign operator functions.
 */
extern void _slist_assign_elem(slist_t* pt_slist, size_t t_count, ...);
extern void _slist_assign_elem_varg(
    slist_t* pt_slist, size_t t_count, va_list val_elemlist);

/*
 * Push front function.
 */
extern void _slist_push_front(slist_t* pt_slist, ...);
extern void _slist_push_front_varg(slist_t* pt_slist, va_list val_elemlist);

/*
 * Remove element form slist.
 */
extern void _slist_remove(slist_t* pt_slist, ...);
extern void _slist_remove_varg(slist_t* pt_slist, va_list val_elemlist);

/*
 * Reset slist_t size.
 */
extern void _slist_resize_elem(slist_t* pt_slist, size_t t_resize, ...);
extern void _slist_resize_elem_varg(
    slist_t* pt_slist, size_t t_resize, va_list val_elemlist);

/*
 * Insert operation functions.
 */
extern void _slist_insert_after_n_varg(
    slist_t* pt_slist, slist_iterator_t t_pos, size_t t_count, va_list val_elemlist);
extern slist_iterator_t _slist_insert_after(
    slist_t* pt_slist, slist_iterator_t t_pos, ...);
extern void _slist_insert_after_n(
    slist_t* pt_slist, slist_iterator_t t_pos, size_t t_count, ...);
extern slist_iterator_t _slist_insert(
    slist_t* pt_slist, slist_iterator_t t_pos, ...);
extern void _slist_insert_n(
    slist_t* pt_slist, slist_iterator_t t_pos, size_t t_count, ...);

#ifdef __cplusplus
}
#endif

#endif /* _CSTL_SLIST_PRIVATE_H */
/** eof **/
