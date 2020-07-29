#ifndef __MENU__

#define __MENU__



int menu_get_input_file(char * user_filename);

long menu_insert_from_file(char * user_filename,Table table, float* avg);

int menu_search(Table table);

int menu_insert(Table table);

int menu_statistics_total_collisions(Table table);

int menu_statistics_max_collisions(Table table,int * position);

int menu_statistics_min_collisions(Table table,int * position);

void menu_quit(Table table);

void menu_search_from_file(char * user_filename,Table table);

void menu_print(Table table);
int menu(void);



#endif
