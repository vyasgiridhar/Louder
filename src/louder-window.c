/* louder-window.c
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

#include "louder-window.h"


struct _LouderWindow
{
  GtkApplicationWindow parent;
};

typedef struct
{
  GtkWidget *stack;
} LouderWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderWindow, louder_window, GTK_TYPE_APPLICATION_WINDOW)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderWindow *
louder_window_new (void)
{
	return g_object_new (LOUDER_TYPE_WINDOW, NULL);
}

static void
louder_window_finalize (GObject *object)
{
	LouderWindow *self = (LouderWindow *)object;
	LouderWindowPrivate *priv = louder_window_get_instance_private (self);

	G_OBJECT_CLASS (louder_window_parent_class)->finalize (object);
}

static void
louder_window_get_property (GObject    *object,
                            guint       prop_id,
                            GValue     *value,
                            GParamSpec *pspec)
{
	LouderWindow *self = LOUDER_WINDOW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_window_set_property (GObject      *object,
                            guint         prop_id,
                            const GValue *value,
                            GParamSpec   *pspec)
{
	LouderWindow *self = LOUDER_WINDOW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_window_dispose (GObject *object)
{

}
static void
louder_window_class_init (LouderWindowClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (object_class),
                                               	     "/org/vyasg/louder/ui/window.ui");
	object_class->finalize = louder_window_finalize;
	object_class->get_property = louder_window_get_property;
	object_class->set_property = louder_window_set_property;
}

static void
louder_window_init (LouderWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
}
