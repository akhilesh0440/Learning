#include<stdio.h>

#pragma pack1
struct  store
{
    double price;
    union{
        struct{
            char *titile;
            char *author;
            int num_pages;
        }book;

        struct {
            int color;
            int size;
            char *design;
        } shirt;
        
    };
};
