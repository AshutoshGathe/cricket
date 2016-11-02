/*****************************************************************************************************************
Cricket : Its fun												*
Copyright (C) 2016 Ashutosh Gajanan Gathe									*
License GPLv3+: GNU GPL version 3 of later <http://gnu.org/licenses/gpl.html>                                   *
This is free software , you are free to cahnge and redistribute it.						*
Thereis NO WARRANTY, to the extent permitted by the law.							*
Any changes will be helpful.											*
														*
													        * 															*                 															*
														* 														
******************************************************************************************************************/









#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.c"
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);/*initialize gtk*/
 	char ch;
	if(argc == 2) {
		if(!strcmp(argv[1], "-h")) {
			FILE *fp;
			fp = fopen("usage.txt", "r");
			if(fp == NULL) {
				printf("Can't open file");
				return 0;
			}
			while(fscanf(fp, "%c", &ch) != -1) {
				printf("%c", ch);
			}
			fclose(fp);
		}
		else
			printf("usage needed -h");
		return 0;
	}
	if(argc > 2) {
		printf("usage needed -h");
		return 0;
	}


/*--------------------------------------creating menu------------------------------------------*/
	GtkWidget *window, *menu_bar, *menu_item, *file_menu, *help_menu, *vbox, *label, *image;/*variables*/	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window),1920, 1080);
        gtk_window_set_title(GTK_WINDOW(window), "CRIC");
        gtk_container_set_border_width(GTK_CONTAINER(window), 10);


	
	label = gtk_label_new("Welcome to world of cricket");
	GdkColor blue = {0, 0x0000, 0xffff, 0xffff};
	GdkColor red = {0, 0xffff, 0x0000, 0x0000};
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &blue);
	gtk_widget_modify_text ( GTK_WIDGET(label), GTK_STATE_NORMAL, &red);
	
	g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

	
	image = gtk_image_new_from_file("./data/cricketpic.jpg");
	gtk_widget_set_size_request(image, 500, 500);
	

	menu_bar = gtk_menu_bar_new();
	file_menu = gtk_menu_new();
	help_menu = gtk_menu_new();

	menu_item=gtk_menu_item_new_with_label("NEW MATCH");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), file_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

	menu_item = gtk_menu_item_new_with_label("PREVIOUS");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), help_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
	
	menu_item = gtk_menu_item_new_with_label("ODI");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);/*adding submenu to menu*/
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response_1), NULL);/*conencting menuitems for callback*/

	menu_item = gtk_menu_item_new_with_label("T20");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);/*adding submenu to menu*/
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response_1), NULL);/*conencting menuitems for callback*/

	menu_item = gtk_menu_item_new_with_label("PRE ODI");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);/*conencting menuitems for callback*/

	menu_item = gtk_menu_item_new_with_label("PRE T20");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);/*conencting menuitems for callback*/

	menu_item = gtk_menu_item_new_with_label("PRE TEST");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);/*conencting menuitems for callback*/
	
	vbox = gtk_vbox_new(0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), menu_bar, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), image, 0, 0, 0);	
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}























































































