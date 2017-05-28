/* louder-sidebar-row.c
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

#include "louder-sidebar-row.h"

struct _LouderSidebarRow
{
	GtkListBoxRow parent;
};

typedef struct
{
	GtkWidget *label_widget;
	GtkWidget *icon_widget;
} LouderSidebarRowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderSidebarRow, louder_sidebar_row, GTK_TYPE_LIST_BOX_ROW)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderSidebarRow *
louder_sidebar_row_new (void)
{
	return g_object_new (LOUDER_TYPE_SIDEBAR_ROW, NULL);
}

static void
louder_sidebar_row_finalize (GObject *object)
{
	LouderSidebarRow *self = (LouderSidebarRow *)object;
	LouderSidebarRowPrivate *priv = louder_sidebar_row_get_instance_private (self);

	G_OBJECT_CLASS (louder_sidebar_row_parent_class)->finalize (object);
}

static void
louder_sidebar_row_get_property (GObject    *object,
																 guint       prop_id,
																 GValue     *value,
																 GParamSpec *pspec)
{
	LouderSidebarRow *self = LOUDER_SIDEBAR_ROW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_sidebar_row_set_property (GObject      *object,
																 guint         prop_id,
																 const GValue *value,
																 GParamSpec   *pspec)
{
	LouderSidebarRow *self = LOUDER_SIDEBAR_ROW (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_sidebar_row_class_init (LouderSidebarRowClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class,
																							 "/org/vyasg/louder/ui/louder-sidebar-row.ui");

	object_class->finalize = louder_sidebar_row_finalize;
	object_class->get_property = louder_sidebar_row_get_property;
	object_class->set_property = louder_sidebar_row_set_property;

	gtk_widget_class_bind_template_child_private (widget_class, LouderSidebarRow, label_widget);
	gtk_widget_class_bind_template_child_private (widget_class, LouderSidebarRow, icon_widget);
	//gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (object_class), LouderSidebarRow, );
}

static void
louder_sidebar_row_init (LouderSidebarRow *self)
{
	gchar *str = "Feed";
	gtk_widget_init_template (GTK_WIDGET (self));
	LouderSidebarRowPrivate *priv = louder_sidebar_row_get_instance_private (self);
	gtk_label_set_label (GTK_LABEL (priv->label_widget), str);
	gtk_image_set_from_resource (GTK_IMAGE (priv->icon_widget), "/org/vyasg/louder/ui/playlist.png");
	gtk_widget_show_all (GTK_WIDGET (self));
}
