/*
 * prefixname.c
 *
 *  Created on: Apr 12, 2013
 *      Author: szhu
 */

#include "prefixname.h"

G_DEFINE_TYPE (PrefixName, prefix_name, G_TYPE_OBJECT)

struct _PrefixNamePrivate
{
    int temp;
};

#define REFIX_NAME_GET_PRIVATE(obj) \
    (G_TYPE_INSTANCE_GET_PRIVATE ((obj), PREFIX_TYPE_NAME, PrefixNamePrivate))

static void prefix_name_dispose(GObject *object);
static void prefix_name_finalize(GObject *object);
static void prefix_name_constructed (GObject *object);

static
void prefix_name_class_init (PrefixNameClass *klass){
    GObjectClass *base_class = G_OBJECT_CLASS (klass);

    g_print("[%s::%d::%s]\n", __FILE__, __LINE__, __func__);

    base_class->constructed  = prefix_name_constructed;
    base_class->dispose      = prefix_name_dispose;
    base_class->finalize     = prefix_name_finalize;

    g_type_class_add_private (klass, sizeof(PrefixNamePrivate));
}

static
void prefix_name_init (PrefixName *self){
    PrefixNamePrivate *priv;

    g_print("[%s::%d::%s]\n", __FILE__, __LINE__, __func__);

    self->priv = priv = REFIX_NAME_GET_PRIVATE (self);
}

static void
prefix_name_constructed (GObject *object)
{
    PrefixName *self = PREFIX_NAME(object);
}

static
void prefix_name_dispose(GObject *object){
    PrefixName *self = PREFIX_NAME(object);
    g_print("[%s::%d::%s]\n", __FILE__, __LINE__, __func__);

    G_OBJECT_CLASS(prefix_name_parent_class)->dispose(object);
}

static
void prefix_name_finalize(GObject *object){
    PrefixName *self = PREFIX_NAME(object);
    g_print("[%s::%d::%s]\n", __FILE__, __LINE__, __func__);
    G_OBJECT_CLASS(prefix_name_parent_class)->finalize(object);
}

PrefixName *
prefix_name_new (void)
{
    return g_object_new(PREFIX_TYPE_NAME, NULL);
}

void
prefix_name_do_action (PrefixName *self)
{
    g_return_if_fail(PREFIX_IS_NAME(self));

}

