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
typedef struct batnodi {
	char *name [11];
	int score[11];
	int six[11];
	float sr[11];
}batnodi;
batnodi tno[3];

typedef struct bowlnodi {
	char *name[11];
	int ov[11];
	int wic[11];
}bowlnodi;
bowlnodi blno[3];

void startnodi() {
	FILE *fp;
	fp = fopen("pscore.txt", "r");
	int i;
	for(i = 1; i <= 11; i++) {
		tno[0].name[i] = (char *) malloc((i + 1) * sizeof(int));	
		fscanf(fp, "%s%d%d%f", tno[0].name[i], &tno[0].score[i], &tno[0].six[i], &tno[0].sr[i]);		
	}
	for(i = 1; i <= 5; i++) {
		blno[0].name[i] = (char *) malloc((i + 1) * sizeof(int));
		fscanf(fp, "%s%d%d", blno[0].name[i], &blno[0].ov[i], &blno[0].wic[i]);
	}
	fclose(fp);
}
void startnodii() {
	FILE *fpt;
	fpt = fopen("pscore1.txt", "r");
	int i;
	for(i = 1; i <= 11; i++) {
		tno[1].name[i] = (char *) malloc((i + 1) * sizeof(int));	
		fscanf(fpt, "%s%d%d%f", tno[1].name[i], &tno[1].score[i], &tno[1].six[i], &tno[1].sr[i]);		
	}
	for(i = 1; i <= 5; i++) {
		blno[1].name[i] = (char *) malloc((i + 1) * sizeof(int));
		fscanf(fpt, "%s%d%d", blno[1].name[i], &blno[1].ov[i], &blno[1].wic[i]);
	}
	fclose(fpt);
}
static void bestbat_nodi(GtkWidget *button, gpointer window) {
	char s[10];
	int i, j, max = 0, x, y;
	startnodi();
	startnodii();

	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(tno[0].score[i] > max) {
			max = tno[0].score[i];
			x = i;
		}
		if( max == tno[0].score[j]) {
				if(tno[0].sr[j] > tno[0].sr[i]) { 
					x = j;
				}	
				
				else {
					x = i;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(tno[1].score[i] > max) {
			max = tno[1].score[i];
			y = i;
		}
		if( max == tno[1].score[j]) {
				if(tno[1].sr[j] > tno[1].sr[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
		
	
	}
	if(tno[0].score[x] > tno[1].score[y]) {
		strcpy(s, tno[0].name[x]);
	}
	else {
		strcpy(s, tno[1].name[y]);
	}
	
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", s);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best batsman");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
}
static void bestbow_nodi(GtkWidget *button, gpointer window) {
	char str[10];
	int i, j, max, x, y;
	max = 0;
	startnodi();
	startnodii();
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(blno[0].wic[i] > max) {
			max = blno[0].wic[i];
			x = i;
		}
		if( max == blno[0].wic[j]) {
				if(blno[0].ov[j] > blno[0].ov[i]) { 
					x = i;
				}	
				
				else {
					x = j;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(blno[1].wic[i] > max) {
			max = blno[1].wic[i];
			y = i;
		}
		if( max == blno[1].wic[j]) {
				if(blno[1].ov[j] > blno[1].ov[i]) { 
					y = i;
				}	
				
				else {
					y = j;
				}
		}
	}
	if(blno[0].wic[x] > blno[1].wic[y]) {
		strcpy(str, blno[0].name[x]);
	}
	else if(blno[0].wic[x] == blno[1].wic[y]) {
			if(blno[0].ov[x] > blno[1].ov[y]) {
				strcpy(str, blno[0].name[y]);
			}
			else {
				strcpy(str, blno[1].name[x]);
			}
				
	}
	else if(blno[0].wic[x] < blno[1].wic[y]) {
		strcpy(str, blno[1].name[y]);
	}			
	
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", str);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best bowler");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
	
}
static void boundary_hit_nodi(GtkWidget *button, gpointer window) {
	int i, j, max, x, y;
	char bhit[10], bhit1[10];
	startnodi();
	startnodii();
	GtkWidget *window_m, *label, *label1, *vbox;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(window_m), "Boundary hit");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	start();
	max = 0;
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(tno[0].six[i] > max) {
			max = tno[0].six[i];
			x = i;
		}
		if( max == tno[0].six[j]) {
				if(tno[0].score[i] > tno[0].score[j]) {
					x = i;
				}
				else {
					x = j;
				}
						
		}		
	
	}

	max = 0;
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(tno[1].six[i] > max) {
			max = tno[1].six[i];
			y = i;
		}
		if( max == tno[1].six[j]) {
				if(tno[1].score[j] > tno[1].score[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
	}	
	if(tno[0].six[x] > tno[1].six[y]) {
		strcpy(bhit,tno[0].name[x]);
	} 
	if(tno[0].six[x] < tno[1].six[y]) {
		strcpy(bhit,tno[1].name[y]);
	}
	if(tno[0].six[x] == tno[1].six[y]) {
		strcpy(bhit,tno[0].name[x]);
		strcpy(bhit1, tno[1].name[y]);
	}
	vbox = gtk_vbox_new(0, 0);
	label = gtk_label_new(bhit);
	label1 = gtk_label_new(bhit1);
	gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
	
}

