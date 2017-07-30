/* sc-api.c
 *
 * Copyright (C) 2017 Vyas Giridharan <vyasgiridhar27@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sc-api.h"

struct _ScApi
{
    GObject parent_instance;
};

typedef struct {
    char* key;
} ScApiPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ScApi, sc_api, G_TYPE_OBJECT)

enum {
    PROP_0,
    N_PROPS
};

static GParamSpec *properties [N_PROPS];

ScApi *
sc_api_new (void)
{
    return g_object_new (SC_TYPE_API, NULL);
}

static void
sc_api_finalize (GObject *object)
{
    ScApi *self = (ScApi *)object;

    G_OBJECT_CLASS (sc_api_parent_class)->finalize (object);
}

static void
sc_api_get_property (GObject    *object,
                     guint       prop_id,
                     GValue     *value,
                     GParamSpec *pspec)
{
    ScApi *self = SC_API (object);

    switch (prop_id)
      {
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      }
}

static void
sc_api_set_property (GObject      *object,
                     guint         prop_id,
                     const GValue *value,
                     GParamSpec   *pspec)
{
    ScApi *self = SC_API (object);

    switch (prop_id)
      {
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      }
}

static void
sc_api_class_init (ScApiClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->finalize = sc_api_finalize;
    object_class->get_property = sc_api_get_property;
    object_class->set_property = sc_api_set_property;
}

static void
sc_api_init (ScApi *self)
{
}
