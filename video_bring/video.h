#pragma once
#include <stdio.h>

typedef struct  Video
{
	char *videoname;
	char *year;
	struct Video*link;
}Video;

typedef struct User
{
	char *name;
	char *id;
	char *phonennum;
	char *money;
	struct User*link;

}User;
typedef struct Bring
{
	char * name;
	Video *title;
	struct Bring *link;
}Bring;

int usersearch();
void search();
void allprint();
void return_vd();
void user_add();
void video_add();
void video_trade();
void save();
int load();
char* moneycheck();
void vd_fresh();
void us_fresh();
void br_fresh();
void moneyplus();