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
#include "preodi_1.c"
#include "preodi_2.c"
#include "pret20_1.c"
#include "pret20_2.c"
#include "pretest_1.c"
#include "function.c"


/*-----------------------selecting team 1or team 2 to input score---------------------*/
static void data_window(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *vbox, *team1bat, *team2bat, *stats;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
   	gtk_window_set_title(GTK_WINDOW(window_m), "MATCH 1 ODI'S");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	
	team1bat = gtk_button_new_with_label("TEAM1 BAT");
	team2bat = gtk_button_new_with_label("TEAM2 BAT");
	stats = gtk_button_new_with_label("STATS");
	
	
	vbox = gtk_vbox_new(TRUE, 2);

	gtk_box_pack_start(GTK_BOX(vbox), team1bat, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), team2bat, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), stats, TRUE, TRUE, 5);

	g_signal_connect(team1bat, "clicked", G_CALLBACK(team1_bat), window_m);
	g_signal_connect(team2bat, "clicked", G_CALLBACK(team2_bat), window_m);
	g_signal_connect(stats, "clicked", G_CALLBACK(stats_nodi), window_m);
	
	gtk_container_add(GTK_CONTAINER(window_m), vbox);
	gtk_widget_show_all(window_m);
	

}

/*--------------------------------------------new match odi to input scores-----------------------*/	
static void menu_response_1(GtkWidget *menu_item, gpointer data) {
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "ODI") == 0) {
		GtkWidget *window, *label, *vbox;
		GtkWidget *match1;
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        				
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
                gtk_window_set_default_size(GTK_WINDOW(window),100, 200);
               	gtk_window_set_title(GTK_WINDOW(window), "ODI");
                gtk_container_set_border_width(GTK_CONTAINER(window), 30);

		label = gtk_label_new("MATCHES");

		match1 = gtk_button_new_with_label("Match 1");
	
	
		vbox = gtk_vbox_new(TRUE, 5);

		gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(vbox), match1, TRUE, TRUE, 0);
		
		
		g_signal_connect(match1, "clicked", G_CALLBACK(data_window), window);
		
		gtk_container_add(GTK_CONTAINER(window), vbox);
		gtk_widget_show_all(window);	
	}
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "T20") == 0) {
		GtkWidget *window, *label, *vbox;
		GtkWidget *match1;
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        				
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
               	gtk_window_set_title(GTK_WINDOW(window), "T20");
                gtk_container_set_border_width(GTK_CONTAINER(window), 30);

		label = gtk_label_new("MATCHES");

		match1 = gtk_button_new_with_label("Match 1");
	
		vbox = gtk_vbox_new(TRUE, 5);

		gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(vbox), match1, TRUE, TRUE, 0);
		
		gtk_container_add(GTK_CONTAINER(window), vbox);
		gtk_widget_show_all(window);	
	}
}
static void menu_response(GtkWidget *menu_item, gpointer data) {
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "PRE ODI") == 0) {
		GtkWidget *window, *vbox;
				
		GtkWidget *match1;
		GtkWidget *match2;
		
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
                gtk_window_set_default_size(GTK_WINDOW(window),300, 300);
               	gtk_window_set_title(GTK_WINDOW(window), " PRE ODI's");
                gtk_container_set_border_width(GTK_CONTAINER(window), 30);

               	vbox = gtk_vbox_new(TRUE, 5);
      		
      		match1 = gtk_button_new_with_label("Match1");
		match2 = gtk_button_new_with_label("Match2");
			
		g_signal_connect(match1, "clicked", G_CALLBACK(matc1_preodi), window);
		g_signal_connect(match2, "clicked", G_CALLBACK(match2_preodi), window);
			
	
		gtk_box_pack_start(GTK_BOX(vbox), match1, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(vbox), match2, TRUE, TRUE, 0);
                      
		gtk_container_add(GTK_CONTAINER(window), vbox);
		gtk_widget_show_all(window);

	}
		
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "PRE T20") == 0) {
		GtkWidget *window, *vbox;
				
		GtkWidget *match1;
		GtkWidget *match2;
		
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
                gtk_window_set_default_size(GTK_WINDOW(window),300, 300);
               	gtk_window_set_title(GTK_WINDOW(window), " PRE T20's");
                gtk_container_set_border_width(GTK_CONTAINER(window), 30);

               	vbox = gtk_vbox_new(TRUE, 5);
      		
      		match1 = gtk_button_new_with_label("Match1");
		match2 = gtk_button_new_with_label("Match2");
		
		g_signal_connect(match1, "clicked", G_CALLBACK(match1_pret20), window);
		g_signal_connect(match2, "clicked", G_CALLBACK(match2_pret20), window);
			
		gtk_box_pack_start(GTK_BOX(vbox), match1, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(vbox), match2, TRUE, TRUE, 0);
                        
                gtk_container_add(GTK_CONTAINER(window), vbox);
		gtk_widget_show_all(window);
		}
		
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "PRE TEST") == 0) {
		GtkWidget *window, *vbox;
				
		GtkWidget *match1;
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
                gtk_window_set_default_size(GTK_WINDOW(window),100, 100);
               	gtk_window_set_title(GTK_WINDOW(window), " PRE TEST's");
                gtk_container_set_border_width(GTK_CONTAINER(window), 30);

               	vbox = gtk_vbox_new(TRUE, 5);
      		
      		match1 = gtk_button_new_with_label("Match1");
		g_signal_connect(match1, "clicked", G_CALLBACK(match1_pretest), window);
			
		gtk_box_pack_start(GTK_BOX(vbox), match1, TRUE, TRUE, 0);
                gtk_container_add(GTK_CONTAINER(window), vbox);
		 gtk_widget_show_all(window);
		}
		
		
}

