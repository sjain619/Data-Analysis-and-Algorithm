
typedef struct table
{
    int value[30][30];
    char back_pointer[30][30];
}table;
table t;

typedef struct V
{
    int key;
    int parent;
    int color;
}V;
V vertex[30];
