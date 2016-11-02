
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
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct batte1 {
	char *name [11];
	int score[11];
	int six[11];
	float sr[11];
}batte1;
batte1 te1[3];
typedef struct bowlte {
	char *name[11];
	float ov[11];
	int run[11];
	int wic[11];
	float eco[11];
}bowlte;
bowlte bte1[3];
void startte1() {
	FILE *fp;
	fp = fopen("test_1.txt", "r");
	int i, j;
	for(i = 1; i <= 11; i++) {
		te1[0].name[i] = (char *) malloc((i + 1) *sizeof(int));	
		fscanf(fp, "%s %d %d %f", te1[0].name[i], &te1[0].score[i], &te1[0].six[i], &te1[0].sr[i]);		
	}
	for(j = 1; j <= 5; j++) {
		bte1[0].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %f %d %d %f", bte1[0].name[j], &bte1[0].ov[j], &bte1[0].run[j], &bte1[0].wic[j], &bte1[0].eco[j]);
	}
	for(j = 1; j <= 11; j++) {
		te1[1].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %f", te1[1].name[j], &te1[1].score[j], &te1[1].six[j], &te1[1].sr[j]);
	}
	for(j = 1; j <= 6; j++) {
		bte1[1].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %f %d %d %f", bte1[1].name[j], &bte1[1].ov[j], &bte1[1].run[j], &bte1[1].wic[j], &bte1[1].eco[j]);
	}

	for(j = 1; j <= 7; j++) {
		te1[2].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %f", te1[2].name[j], &te1[2].score[j], &te1[2].six[j], &te1[2].sr[j]);
	}

	

	for(j = 1; j <= 7; j++) {
		bte1[2].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %f %d %d %f", bte1[2].name[j], &bte1[2].ov[j], &bte1[2].run[j], &bte1[2].wic[j], &bte1[2].eco[j]);
	}

	for(j = 1; j <= 11; j++) {
		te1[3].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %d %d %f", te1[3].name[j], &te1[3].score[j], &te1[3].six[j], &te1[3].sr[j]);
	}

	for(j = 1; j <= 5; j++) {
		bte1[3].name[j] = (char *) malloc((i + 1) *sizeof(int));
		fscanf(fp, "%s %f %d %d %f", bte1[3].name[j], &bte1[3].ov[j], &bte1[3].run[j], &bte1[3].wic[j], &bte1[3].eco[j]);
	}
	
	fclose(fp);
}
static void best_batsmante1(GtkWidget *button, gpointer window) {
	int i, j, max = 0, x, y, z, w;	
	char s[20];
	startte1();
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(te1[0].score[i] > max) {
			max = te1[0].score[i];
			x = i;
		}
		if( max == te1[0].score[j]) {
				if(te1[0].sr[j] > te1[0].sr[i]) { 
					x = j;
				}	
				
				else {
					x = i;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(te1[1].score[i] > max) {
			max = te1[1].score[i];
			y = i;
		}
		if( max == te1[1].score[j]) {
				if(te1[1].sr[j] > te1[1].sr[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
		
	
	}

	max = 0;
	for(i = 1, j = 2; i <= 7 && j <= 7; i++, j++) {
		if(te1[2].score[i] > max) {
			max = te1[2].score[i];
			z = i;
		}
		if( max == te1[1].score[j]) {
				if(te1[2].sr[j] > te1[2].sr[i]) { 
					z = j;
				}	
				
				else {
					z = i;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(te1[3].score[i] > max) {
			max = te1[3].score[i];
			w = i;
		}
		if( max == te1[3].score[j]) {
				if(te1[3].sr[j] > te1[3].sr[i]) { 
					w = j;
				}	
				
				else {
					w = i;
				}
		}
		
	
	}
	if(te1[0].score[x] > te1[1].score[y] && te1[0].score[x] > te1[2].score[z] && te1[0].score[x] > te1[3].score[w]) {
                strcpy(s, te1[0].name[x]);
        }
	else if(te1[1].score[y] > te1[0].score[x] && te1[1].score[y] > te1[2].score[z] && te1[1].score[y] > te1[3].score[w]) {
                strcpy(s, te1[1].name[y]);
        }
	else if(te1[2].score[z] > te1[0].score[x] && te1[2].score[z] > te1[1].score[y] && te1[2].score[z] > te1[3].score[w]) {
                strcpy(s, te1[2].name[z]);
        }
	else if(te1[3].score[w] > te1[0].score[x] && te1[3].score[w] > te1[1].score[y] && te1[3].score[w] > te1[3].score[z]) {
                strcpy(s, te1[3].name[w]);
        }
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", s);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best batsman");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);

}
static void best_bowlerte1(GtkWidget *button, gpointer window) {
	int i, j, max = 0, x, y, z, w;	
	char s[20];
	max = 0;
	startte1();
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(bte1[0].wic[i] > max) {
			max = bte1[0].wic[i];
			x = i;
		}
		if( max == bte1[0].wic[j]) {
				if(bte1[0].run[j] > bte1[0].run[i]) { 
					x = i;
				}	
				
				else {
					x = j;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(bte1[1].wic[i] >= max) {
			max = bte1[1].wic[i];
			y = i;
		}
		if( max == bte1[0].wic[j]) {
				if(bte1[1].run[j] > bte1[1].run[i]) { 
					y = i;
				}	
				
				else {
					y = j;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(bte1[2].wic[i] > max) {
			max = bte1[2].wic[i];
			z = i;
		}
		if( max == bte1[2].wic[j]) {
				if(bte1[2].run[j] > bte1[2].run[i]) { 
					z = i;
				}	
				
				else {
					z = j;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 5 && j <= 5; i++, j++) {
		if(bte1[3].wic[i] > max) {
			max = bte1[3].wic[i];
			w = i;
		}
		if( max == bte1[2].wic[j]) {
				if(bte1[3].run[j] > bte1[3].run[i]) { 
					w = i;
				}	
				
				else {
					w = j;
				}
		}

	}

	if(bte1[0].wic[x] > bte1[1].wic[y] && bte1[0].wic[x] > bte1[2].wic[z] && bte1[0].wic[x] > bte1[3].wic[w]) {
		strcpy(s, bte1[0].name[x]);
	}
	else if(bte1[1].wic[y] > bte1[0].wic[x] && bte1[1].wic[y] > bte1[2].wic[z] && bte1[1].wic[y] > bte1[3].wic[w]) {
		strcpy(s, bte1[1].name[y]);
	}
	else if(bte1[2].wic[z] > bte1[0].wic[x] && bte1[2].wic[z] > bte1[1].wic[y] && bte1[2].wic[z] > bte1[3].wic[w]) {
		strcpy(s, bte1[2].name[z]);
	}
	else if(bte1[3].wic[w] > bte1[0].wic[x] && bte1[3].wic[w] > bte1[1].wic[y] && bte1[3].wic[w] > bte1[2].wic[z]) {
		strcpy(s, bte1[3].name[w]);
	}

	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", s);
	gtk_window_set_title(GTK_WINDOW(dialog), "Best bowler");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);

}

static void boundary_hit_te1(GtkWidget *button, gpointer window) {
	int i, j, max = 0, x, y, z, w;	
	char s[20];
	startte1();
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(te1[0].six[i] > max) {
			max = te1[0].six[i];
			x = i;
		}
		if( max == te1[0].six[j]) {
				if(te1[0].score[j] > te1[0].score[i]) { 
					x = j;
				}	
				
				else {
					x = i;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(te1[1].six[i] > max) {
			max = te1[1].six[i];
			y = i;
		}
		if( max == te1[1].six[j]) {
				if(te1[1].score[j] > te1[1].score[i]) { 
					y = j;
				}	
				
				else {
					y = i;
				}
		}
		
	
	}

	max = 0;
	for(i = 1, j = 2; i <= 7 && j <= 7; i++, j++) {
		if(te1[2].six[i] > max) {
			max = te1[2].six[i];
			z = i;
		}
		if( max == te1[1].six[j]) {
				if(te1[2].score[j] > te1[2].score[i]) { 
					z = j;
				}	
				
				else {
					z = i;
				}
		}
		
	
	}
	max = 0;
	for(i = 1, j = 2; i <= 11 && j <= 11; i++, j++) {
		if(te1[3].six[i] > max) {
			max = te1[3].six[i];
			w = i;
		}
		if( max == te1[3].score[j]) {
				if(te1[3].score[j] > te1[3].score[i]) { 
					w = j;
				}	
				
				else {
					w = i;
				}
		}
		
	
	}
	if(te1[0].six[x] > te1[1].six[y] && te1[0].six[x] > te1[2].six[z] && te1[0].six[x] > te1[3].six[w]) {
		strcpy(s, te1[0].name[x]);
	}
	else if(te1[1].six[y] > te1[0].six[x] && te1[1].six[y] > te1[2].six[z] && te1[1].six[y] > te1[3].six[w]) {
		strcpy(s, te1[1].name[y]);	
	}

	else if(te1[2].six[z] > te1[0].six[x] && te1[2].six[z] > te1[1].six[y] && te1[2].six[z] > te1[3].six[w]) {
		strcpy(s, te1[2].name[z]);
	}
	else if(te1[3].six[w] > te1[0].six[x] && te1[3].six[w] > te1[1].six[y] && te1[3].six[w] > te1[2].six[y]) {
		strcpy(s, te1[3].name[w]);
	}
	GtkWidget *dialog;
  
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", s);
	gtk_window_set_title(GTK_WINDOW(dialog), "Boundarie hit by");
    	gtk_dialog_run(GTK_DIALOG(dialog));
    	gtk_widget_destroy(dialog);

}

static void te1_team1_first(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *label, *label1, *label2, *vbox;
       
        window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
        vbox = gtk_vbox_new(0, 0);
	startt1();
	char line [100];
	int i;
	
	FILE *fp;
	fp = fopen("test_1.txt", "r");
	label1 = gtk_label_new("TEAM\n\nName\t\tScore\tSix\tStrikeRate\n");	
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0, 0, 0);
	
	for(i = 1; i <= 11; i++) {
		fgets(line, sizeof line, fp);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
	}

	label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");	
	gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);
	for(i = 1; i <= 6; i++) {
		fgets(line, sizeof line, fp);
		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
	}

	fclose(fp);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);

}
static void te1_team2_first(GtkWidget *button, gpointer window) {
	int i;
	GtkWidget *window_m, *label,*label1, *label2, *vbox;/*disply score on window*/
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 2");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	startt1();

	char line [100];
	FILE *fp;
	fp = fopen("test_1.txt", "r");

	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);
	
	for(i = 1; i <= 18; i++) {
		fgets(line, sizeof line, fp); 
	}
	for(i = 1; i <= 12; i++) {
		fgets(line, sizeof line, fp); 
 		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
	 
        }
      
        label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");
        gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);

        for(i = 1; i <= 6; i++) {
                fgets(line, sizeof line, fp);
                label = gtk_label_new(line);
                gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
         
        }                                            
	fclose(fp);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
}
static void te1_team1_second(GtkWidget *button, gpointer window) {
	int i;
	GtkWidget *window_m, *label,*label1, *label2, *vbox;/*disply score on window*/
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 2");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	startt1();

	char line [100];
	FILE *fp;
	fp = fopen("test_1.txt", "r");

	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);
	
	for(i = 1; i <= 37; i++) {
		fgets(line, sizeof line, fp); 
	}
	for(i = 1; i <= 8; i++) {
		fgets(line, sizeof line, fp); 
 		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
	 
        }
      
        label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");
        gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);

        for(i = 1; i <= 8; i++) {
                fgets(line, sizeof line, fp);
                label = gtk_label_new(line);
                gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
         
        }                                            
	fclose(fp);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
}
static void te1_team2_second(GtkWidget *button, gpointer window) {
	int i;
	GtkWidget *window_m, *label,*label1, *label2, *vbox;/*disply score on window*/
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),1000, 500);
        gtk_window_set_title(GTK_WINDOW(window), "TEAM 2");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	startt1();

	char line [100];
	FILE *fp;
	fp = fopen("test_1.txt", "r");

	vbox = gtk_vbox_new(0, 0);
	label1 = gtk_label_new("TEAM 2\nName\t\tScore\t\tSix\t\tStrikerate");
	gtk_box_pack_start(GTK_BOX(vbox), label1, 0,0,0);
	
	for(i = 1; i <= 53; i++) {
		fgets(line, sizeof line, fp); 
	}
	for(i = 1; i <= 12; i++) {
		fgets(line, sizeof line, fp); 
 		label = gtk_label_new(line);
		gtk_box_pack_start(GTK_BOX(vbox), label, 0,0,0);
	 
        }
      
        label2 = gtk_label_new("Name\tOvers\tWickets\tEconomy");
        gtk_box_pack_start(GTK_BOX(vbox), label2, 0, 0, 0);

        for(i = 1; i <= 6; i++) {
                fgets(line, sizeof line, fp);
                label = gtk_label_new(line);
                gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
         
        }                                            
	fclose(fp);
	gtk_container_add(GTK_CONTAINER(window_m),vbox);
	gtk_widget_show_all(window_m);
}
static void te1_stats_match1(GtkWidget *button, gpointer window) {
	GtkWidget  *window_m,*batsman, *bowler, *boundary, *table;

	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size(GTK_WINDOW(window_m),500, 500);
        gtk_window_set_title(GTK_WINDOW(window), "MATCH 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);

	batsman	= gtk_button_new_with_label("Best Batsman");
	bowler = gtk_button_new_with_label("Best Bowler");
	boundary = gtk_button_new_with_label("maximum Boundaries hit by");	

	table = gtk_table_new(5, 5, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), batsman, 0 ,1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), bowler, 0 ,1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), boundary, 0 ,1, 2, 3);

	gtk_container_add(GTK_CONTAINER(window_m), table);

	g_signal_connect(batsman, "clicked", G_CALLBACK(best_batsmante1), window_m);
	g_signal_connect(bowler, "clicked", G_CALLBACK(best_bowlerte1), window_m);
	g_signal_connect(boundary, "clicked", G_CALLBACK(boundary_hit_te1), window_m);
	
	
	gtk_widget_show_all(window_m);
}


static void match1_pretest(GtkWidget *button, gpointer window) {
	GtkWidget *window_m, *team1f, *team2f, *team1ff, *team2ff,*stats, *table ;
	window_m = gtk_window_new(GTK_WINDOW_TOPLEVEL);		        
	gtk_window_set_position(GTK_WINDOW(window_m), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(window), "MATCH 1");
        gtk_container_set_border_width(GTK_CONTAINER(window_m), 30);
	
	team1f = gtk_button_new_with_label("TEAM 1 1st inning");
	team2f = gtk_button_new_with_label("TEAM 2 1st inning");
	team1ff = gtk_button_new_with_label("TEAM 1 2nd inning");
	team2ff = gtk_button_new_with_label("TEAM 2 2nd inning");
	
	stats = gtk_button_new_with_label("STATS");

	table = gtk_table_new(7, 7, TRUE);

	gtk_table_attach_defaults(GTK_TABLE(table), team1f, 0 ,1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), team2f, 0 ,1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), team1ff, 0 ,1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), team2ff, 0 ,1, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), stats, 0 ,1, 4, 5);
	
	g_signal_connect(team1f, "clicked", G_CALLBACK(te1_team1_first), window_m);
	g_signal_connect(team2f, "clicked", G_CALLBACK(te1_team2_first), window_m);
	g_signal_connect(team1ff, "clicked", G_CALLBACK(te1_team1_second), window_m);
	g_signal_connect(team2ff, "clicked", G_CALLBACK(te1_team2_second), window_m);
	g_signal_connect(stats, "clicked", G_CALLBACK(te1_stats_match1), window_m);

	gtk_container_add(GTK_CONTAINER(window_m), table);
	
	gtk_widget_show_all(window_m);
}
                                    
