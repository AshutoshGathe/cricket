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

int totalscoret1 = 0;
int totalscoret2 = 0;

typedef struct bat {
	char *name [11];
	int score[11];
	int six[11];
	float sr[11];
}bat;
bat t[2];
typedef struct bowl {
	char *name[11];
	float ov[11];
	int run[11];
	int wic[11];
	float eco[11];
}bowl;
bowl bl[2];
/*------------------------------------------storing file data in array--------------------------------------------------*/
void start() {
	FILE *fp;
fp = fopen("odi_1.txt", "r");
	int i , j;
	for(i = 1; i <= 6; i++) {
		t[0].name[i] = (char *) malloc((i + 1) *sizeof(int));	
		fscanf(fp, "%s %d %d %f", t[0].name[i], &t[0].score[i], &t[0].six[i], &t[0].sr[i]);		
	}
	for(j = 1; j <= 7; j++) {
		bl[0].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %f %d %d %f", bl[0].name[j], &bl[0].ov[j], &bl[0].run[j], &bl[0].wic[j], &bl[0].eco[j]);
	}
	for(j = 1; j <= 5; j++) {
		t[1].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %f", t[1].name[j], &t[1].score[j], &t[1].six[j], &t[1].sr[j]);
	}
	for(j = 1; j <= 6; j++) {
		bl[1].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %f %d %d %f", bl[1].name[j], &bl[1].ov[j], &bl[1].run[j], &bl[1].wic[j], &bl[1].eco[j]);
	}

	fclose(fp);
}
static void best_batsman(GtkWidget *button, gpointer window) {
	int i, j, max =0, x, y;
	char str[10];
	start();
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(t[0].score[i] > max) {
			max = t[0].score[i];
			x = i;
		}
		if( max == t[0].score[j]) {
				if(t[0].sr[j] > t[0].sr[i]) { 
					x = j;
				}	
				
				else {
					x = i;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(t[1].score[i] > max) {
			max = t[1].score[i];
			y = i;
		}
		if( max == t[1].score[j]) {
				if(t[1].sr[j] > t[1].sr[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
		
	
	}
	if(t[0].score[x] > t[1].score[y]) {
		strcpy(str, t[0].name[x]);
	}
	else {
		strcpy(str, t[0].name[y]);
	}
	
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", str);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best batsman");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
}

static void best_bowler(GtkWidget *button, gpointer window) {
	int i, j , max = 0, x, y;
	char s[10];
	start();
	for(i = 1, j = 2; i <= 7 && j <= 7; i++, j++) {
		if(bl[0].wic[i] >= max) {
			max = bl[0].wic[i];
			x = i;
		}
		if( max == bl[0].wic[j]) {
				if(bl[0].run[j] > bl[0].run[i]) { 
					x = i;
				}	
				
				else {
					x = j;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(bl[1].wic[i] > max) {
			max = bl[1].wic[i];
			y = i;
		}
		if( max == bl[1].wic[j]) {
				if(bl[1].run[j] > bl[1].run[i]) { 
					y = i;
				}	
				
				else {
					y = j;
				}
		}
	}
	if(bl[0].wic[x] > bl[1].wic[y]) {
		strcpy(s, bl[0].name[x]);
	}
	else if(bl[0].wic[x] == bl[1].wic[y]) {
			if(bl[0].run[x] > bl[1].run[y]) {
				strcpy(s, bl[1].name[y]);
			}
			else {
				strcpy(s, bl[0].name[x]);
			}
				
	}
	else if(bl[0].wic[x] < bl[1].wic[y]) {
		strcpy(s, bl[1].name[y]);
	}			
	
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", s);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best bowler");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
	
}

static void boundary_hit(GtkWidget *button, gpointer window) {
	int i, j, max =0, x, y;
	char bhit[10], bhit1[10];
	GtkWidget *window_m, *label, *label1, *vbox;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(window_m), "Boundary hit");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	start();
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(t[0].six[i] > max) {
			max = t[0].six[i];
			x = i;
		}
		if( max == t[0].six[j]) {
				if(t[0].score[i] > t[0].score[j]) {
					x = i;
				}
				else {
					x = j;
				}
						
		}		
	
	}

	max = 0;
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(t[1].six[i] > max) {
			max = t[1].six[i];
			y = i;
		}
		if( max == t[1].six[j]) {
				if(t[1].score[j] > t[1].score[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
	}	
	if(t[0].six[x] > t[1].six[y]) {
		strcpy(bhit, t[0].name[x]);
	} 
	if(t[0].six[x] < t[1].six[y]) {
		strcpy(bhit, t[1].name[y]);
	}
	if(t[0].six[x] == t[1].six[y]) {
		strcpy(bhit, t[0].name[x]);
		strcpy(bhit1, t[1].name[y]);
	}
	vbox = gtk_vbox_new(0, 0);
	label = gtk_label_new(bhit);
	label1 = gtk_label_new(bhit1);
	gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
	
}
static void eco_bowler(GtkWidget *button, gpointer window) {
	int i, j, x, y;
	char ecobowl[20];
	start();
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(bl[0].eco[i] < bl[0].eco[j]) {
			x = i;
		}
		if( bl[0].eco[i] == bl[1].eco[j]) {
				if(bl[0].ov[i] > bl[0].ov[j]) {
					x = i;
				}
				else {
					x = j;
				}
						
		}		
	
	}
	for(i = 1, j = 2; i <= 6 && j <= 6; i++, j++) {
		if(bl[1].eco[i] < bl[1].eco[j]) {
			y = i;
		}
		if( bl[1].eco[i] == bl[1].eco[j]) {
				if(bl[1].ov[i] > bl[1].ov[j]) {
					y = i;
				}
				else {
					y = j;
				}
						
		}		
	}

	if(bl[0].eco[x] > bl[1].eco[y]) {
		strcpy(ecobowl, bl[1].name[y]);
	}
	if(bl[0].eco[x] == bl[0].eco[y]) {
		if(bl[0].ov[x] > bl[0].ov[y]) {
			strcpy(ecobowl, bl[0].name[x]);
		}
		else {
			strcpy(ecobowl, bl[1].name[y]);
		}
	}
	if(bl[0].eco[x] < bl[1].eco[y]) {
		strcpy(ecobowl, bl[0].name[x]);
	}
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", ecobowl);
	gtk_window_set_title(GTK_WINDOW(dialog), "Economic bowler");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);
	
}
/*----------------------display scorecard of team1 bat and team2 bowl*---------------------------------------------------*/	
static void team1_score(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *label, *label1, *label2, *vbox, *totalscore, *totalwickets,*teamscore, *teamwickets;
	int wicketst1 = 0;
	char tscore[5], twickets[5];
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	vbox = gtk_vbox_new(0, 0);
	
	
	start();
	
	//gtk_widget_destroy(GTK_WIDGET(window));
	char line [100];
	int i;
	
	FILE *file;
	file = fopen("odi_1.txt", "r");
	label1 = gtk_label_new("TEAM\n\nName\t\tScore\tSix\tStrikeRate\n");	
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	
	for(i = 1; i <= 6; i++) {
		fgets(line, sizeof line, file);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
		totalscoret1 = t[0].score[i] +  totalscoret1;
	}
	totalscore = gtk_label_new("TotalScore = ");
	gtk_box_pack_start(GTK_BOX(vbox), totalscore, 0, 0, 0);
	sprintf(tscore, "%d", totalscoret1);
	teamscore = gtk_label_new(tscore);
	gtk_box_pack_start(GTK_BOX(vbox), teamscore, 0, 0, 0);

	label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");	
	gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);
	for(i = 1; i <= 8; i++) {
		fgets(line, sizeof line, file);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
		wicketst1 = bl[0].wic[i] + wicketst1;
	}
	totalwickets = gtk_label_new("Wickets = ");
	sprintf(twickets, "%d", wicketst1);
	teamwickets = gtk_label_new(twickets);
	gtk_box_pack_start(GTK_BOX(vbox), totalwickets, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(vbox), teamwickets, 0, 0, 0);

	fclose(file);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
}

/*----------------------display scorecard of team2 bat and team1 bowl*---------------------------------------------------*/
static void team2_score(GtkWidget *button, gpointer window) {
	int i;
	int wicketst1 = 0;
	char tscore[5], twickets[5];
	GtkWidget *window_m, *label,*label1, *label2, *vbox, *totalscore, *totalwickets,*teamscore, *teamwickets;/*disply score on window*/
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 2");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	start();

	char line [100];
	FILE *file;
	file = fopen("odi_1.txt", "r");

	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);
	
	for(i = 1; i <= 15; i++) {
		fgets(line, sizeof line, file); 
	}
	for(i = 1; i <= 6; i++) {
		fgets(line, sizeof line, file); 
 		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
	       totalscoret2 = t[1].score[i] +  totalscoret2;
        }
        totalscore = gtk_label_new("TotalScore = ");
        gtk_box_pack_start(GTK_BOX(vbox), totalscore, 0, 0, 0);
        sprintf(tscore, "%d", totalscoret2);
        teamscore = gtk_label_new(tscore);
        gtk_box_pack_start(GTK_BOX(vbox), teamscore, 0, 0, 0);

        label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");
        gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);
        for(i = 1; i <= 6; i++) {
                fgets(line, sizeof line, file);
                label = gtk_label_new(line);
                gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
                wicketst1 = bl[1].wic[i] + wicketst1;
        }
        totalwickets = gtk_label_new("Wickets = ");
        sprintf(twickets, "%d", wicketst1);
        teamwickets = gtk_label_new(twickets);
	gtk_box_pack_start(GTK_BOX(vbox), totalwickets, 0, 0, 0);
        gtk_box_pack_start(GTK_BOX(vbox), teamwickets, 0, 0, 0);

                                                    
	fclose(file);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
}
/*----------------------display of statistics of match1---------------------------------------------------*/	
static void stats_match1(GtkWidget *button, gpointer window) {
	GtkWidget  *window_m, *batsman, *bowler, *boundary, *econo, *table;

	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),500, 500);
        gtk_window_set_title(GTK_WINDOW(window), "MATCH 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);

	batsman	= gtk_button_new_with_label("Best Batsman");
	bowler = gtk_button_new_with_label("Best Bowler");
	boundary = gtk_button_new_with_label("Max Boundaries hit by");	
	econo = gtk_button_new_with_label("Economic bowler");
	table = gtk_table_new(5, 5, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), batsman, 0 ,1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler, 0 ,1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), boundary, 0 ,1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), econo, 0 ,1, 3, 4);
	gtk_container_add(GTK_CONTAINER(window_m), table);

	g_signal_connect(batsman, "clicked", G_CALLBACK(best_batsman), window_m);
	g_signal_connect(bowler, "clicked", G_CALLBACK(best_bowler), window_m);
	g_signal_connect(boundary, "clicked", G_CALLBACK(boundary_hit), window_m);
	g_signal_connect(econo, "clicked", G_CALLBACK(eco_bowler), window_m);
	
	gtk_widget_show_all(window_m);
}
static void matc1_preodi(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *team1, *team2, *stats, *table ;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "MATCH 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	
	team1 = gtk_button_new_with_label("TEAM 1");
	team2 = gtk_button_new_with_label("TEAM 2");
	stats = gtk_button_new_with_label("STATS");

	table = gtk_table_new(13, 7, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), team1, 0 ,1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), team2, 1 ,2, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), stats, 2 ,3, 0, 1);
	
	g_signal_connect(team1, "clicked", G_CALLBACK(team1_score), window_m);
	g_signal_connect(team2, "clicked", G_CALLBACK(team2_score), window_m);
	g_signal_connect(stats, "clicked", G_CALLBACK(stats_match1), window_m);

	gtk_container_add(GTK_CONTAINER(window_m), table);
	
	gtk_widget_show_all(window_m);
}

