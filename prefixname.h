/*
 *  prefixname.h
 *
 *  Created on: Apr 12, 2013
 *      Author: szhu
 */

#ifndef _PREFIX_NAME_H_
#define _PREFIX_NAME_H_

#include <glib-object.h>

#define PREFIX_TYPE_NAME               (prefix_name_get_type ())
#define PREFIX_NAME(object)            (G_TYPE_CHECK_INSTANCE_CAST ((object), PREFIX_TYPE_NAME, PrefixName))
#define PREFIX_IS_NAME(object)         (G_TYPE_CHECK_INSTANCE_TYPE ((object), PREFIX_TYPE_NAME))
#define PREFIX_NAME_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass), PREFIX_TYPE_NAME, PrefixNameClass))
#define PREFIX_IS_NAME_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass), PREFIX_TYPE_NAME))
#define PREFIX_NAME_GET_CLASS(object)  (G_TYPE_INSTANCE_GET_CLASS ((object), PREFIX_TYPE_NAME, PrefixNameClass))

typedef struct _PrefixName          PrefixName;
typedef struct _PrefixNameClass     PrefixNameClass;
typedef struct _PrefixNamePrivate   PrefixNamePrivate;

struct _PrefixName {
    GObject parent;

    PrefixNamePrivate *priv;
};

struct _PrefixNameClass {
    GObjectClass parent_class;
};

GType prefix_name_get_type (void);
PrefixName *prefix_name_new (void);
void prefix_name_do_action (PrefixName *self);

#endif
