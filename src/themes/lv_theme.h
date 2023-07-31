/**
 *@file lv_theme.h
 *
 */

#ifndef LV_THEME_H
#define LV_THEME_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *    INCLUDES
 *********************/
#include "../core/lv_obj.h"

/*********************
 *    DEFINES
 *********************/

/**********************
 *    TYPEDEFS
 **********************/

struct _lv_theme_t;
struct _lv_disp_t;

typedef void (*lv_theme_apply_cb_t)(struct _lv_theme_t *, lv_obj_t *);

typedef struct _lv_theme_t {
    lv_theme_apply_cb_t apply_cb;
    struct _lv_theme_t * parent;    /**< Apply the current theme's style on top of this theme.*/
    void * user_data;
    struct _lv_disp_t * disp;
    lv_color_t color_primary;
    lv_color_t color_secondary;
    const lv_font_t * font_small;
    const lv_font_t * font_normal;
    const lv_font_t * font_large;
    uint32_t flags;                 /*Any custom flag used by the theme*/
} lv_theme_t;

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

/**
 * Get the theme assigned to the display of the object
 * @param obj       pointer to a theme object
 * @return          the theme of the object's display (can be NULL)
 */
lv_theme_t  * lv_theme_get_from_obj(lv_obj_t * obj);

/**
 * Set an apply callback for a theme.
 * The apply callback is used to add styles to different objects
 * @param theme pointer to theme which callback should be set
 * @param apply_cb pointer to the callback
 */
void lv_theme_set_apply_cb(lv_theme_t * theme, lv_theme_apply_cb_t apply_cb);

/**
 * Get the small font of the theme
 * @param obj pointer to an object
 * @return pointer to the font
 */
const lv_font_t * lv_theme_get_font_small(lv_obj_t * obj);
/**
 * Get the normal font of the theme
 * @param obj pointer to an object
 * @return pointer to the font
 */
const lv_font_t * lv_theme_get_font_normal(lv_obj_t * obj);

/**
 * Get the subtitle font of the theme
 * @param obj pointer to an object
 * @return pointer to the font
 */
const lv_font_t * lv_theme_get_font_large(lv_obj_t * obj);

/**
 * Get the primary color of the theme
 * @param obj pointer to an object
 * @return the color
 */
lv_color_t lv_theme_get_color_primary(lv_obj_t * obj);

/**
 * Get the secondary color of the theme
 * @param obj pointer to an object
 * @return the color
 */
lv_color_t lv_theme_get_color_secondary(lv_obj_t * obj);

/**********************
 *    MACROS
 **********************/


#include "default/lv_theme_default.h"
#include "mono/lv_theme_mono.h"
#include "basic/lv_theme_basic.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_THEME_H*/
